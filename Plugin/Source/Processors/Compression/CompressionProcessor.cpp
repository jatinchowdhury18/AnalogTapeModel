#include "CompressionProcessor.h"

CompressionProcessor::CompressionProcessor (AudioProcessorValueTreeState& vts)
{
    onOff = vts.getRawParameterValue ("comp_onoff");
    amountParam = vts.getRawParameterValue ("comp_amt");
    attackParam = vts.getRawParameterValue ("comp_attack");
    releaseParam = vts.getRawParameterValue ("comp_release");
}

void CompressionProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    auto twoDecimalFloat = [] (float value, int) { return String (value, 2); };

    params.push_back (std::make_unique<AudioParameterBool> ("comp_onoff", "Compression On/Off", false));

    static NormalisableRange<float> amtRange { 0.0f, 9.0f };
    amtRange.setSkewForCentre (3.0f);
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_amt", "Compression Amount", amtRange, 0.0f, String(), AudioProcessorParameter::genericParameter, twoDecimalFloat));

    static NormalisableRange<float> attRange { 0.1f, 50.0f };
    attRange.setSkewForCentre (10.0f);
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_attack", "Compression Attack", attRange, 5.0f, String(), AudioProcessorParameter::genericParameter, twoDecimalFloat));

    static NormalisableRange<float> relRange { 10.0f, 1000.0f };
    relRange.setSkewForCentre (100.0f);
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_release", "Compression Release", relRange, 200.0f, String(), AudioProcessorParameter::genericParameter, twoDecimalFloat));
}

void CompressionProcessor::prepare (double sr, int samplesPerBlock, int numChannels)
{
    oversample = std::make_unique<dsp::Oversampling<float>> (numChannels, 1, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR, true, true);
    oversample->initProcessing ((size_t) samplesPerBlock);
    auto osFactor = oversample->getOversamplingFactor();
    bypass.prepare (samplesPerBlock, numChannels, bypass.toBool (onOff));

    slewLimiter.clear();
    dbPlusSmooth.clear();
    for (int ch = 0; ch < numChannels; ++ch)
    {
        slewLimiter.emplace_back();
        dbPlusSmooth.emplace_back();

        slewLimiter[ch].prepare ({ sr, (uint32) samplesPerBlock, 1 });
        dbPlusSmooth[ch].reset (sr, 0.05);
    }

    xDBVec.resize (osFactor * (size_t) samplesPerBlock, 0.0f);
    compGainVec.resize (osFactor * (size_t) samplesPerBlock, 0.0f);
}

inline float compressionDB (float xDB, float dbPlus)
{
    auto window = 2.0f * dbPlus;

    if (dbPlus <= 0.0f || xDB < -window)
        return dbPlus;

    return std::log (xDB + window + 1.0f) - dbPlus - xDB;
}

inline dsp::SIMDRegister<float> compressionDB (dsp::SIMDRegister<float> xDB, float dbPlus)
{
    using namespace chowdsp::SIMDUtils;

    if (dbPlus <= 0.0f)
        return (vec4) dbPlus;

    auto window = 2.0f * dbPlus;
    auto belowWin = vec4::lessThan (xDB, -window);
    return ((logSIMD (xDB + window + 1.0f) - dbPlus - xDB) & ~belowWin) + ((vec4) dbPlus & belowWin);
}

void CompressionProcessor::processBlock (AudioBuffer<float>& buffer)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOff)))
        return;

    dsp::AudioBlock<float> block (buffer);
    auto osBlock = oversample->processSamplesUp (block);

    const auto numSamples = (int) osBlock.getNumSamples();
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        dbPlusSmooth[ch].setTargetValue (amountParam->load());

        auto* x = osBlock.getChannelPointer ((size_t) ch);
        FloatVectorOperations::copy (xDBVec.data(), x, numSamples);
        FloatVectorOperations::abs (xDBVec.data(), xDBVec.data(), numSamples);

        constexpr auto inc = dsp::SIMDRegister<float>::size();
        size_t n = 0;
        for (; n < (size_t) numSamples; n += inc)
        {
            auto xDB = dsp::SIMDRegister<float>::fromRawArray (&xDBVec[n]);

            xDB = chowdsp::SIMDUtils::gainToDecibels (xDB);
            auto compDB = compressionDB (xDB, dbPlusSmooth[ch].skip ((int) inc));
            auto compGain = chowdsp::SIMDUtils::decibelsToGain (compDB);

            xDB.copyToRawArray (&xDBVec[n]);
            compGain.copyToRawArray (&compGainVec[n]);
        }

        // remaining samples that can't be vectorized
        for (; n < (size_t) numSamples; ++n)
        {
            xDBVec[n] = Decibels::gainToDecibels (xDBVec[n]);
            auto compDB = compressionDB (xDBVec[n], dbPlusSmooth[ch].getNextValue());
            compGainVec[n] = Decibels::decibelsToGain (compDB);
        }

        // since the slew will be applied to the gain, we need to reverse the attack and release parameters!
        slewLimiter[ch].setParameters (releaseParam->load(), attackParam->load());
        for (size_t k = 0; k < (size_t) numSamples; ++k)
            compGainVec[k] = jmin (compGainVec[k], slewLimiter[ch].processSample (compGainVec[k]));

        FloatVectorOperations::multiply (x, compGainVec.data(), numSamples);
    }

    oversample->processSamplesDown (block);

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}

float CompressionProcessor::getLatencySamples() const noexcept
{
    if (oversample == nullptr)
        return 0.0f;

    return onOff->load() == 1.0f ? oversample->getLatencyInSamples() // on
                                 : 0.0f; // off
}
