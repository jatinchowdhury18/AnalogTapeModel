#include "CompressionProcessor.h"

CompressionProcessor::CompressionProcessor (AudioProcessorValueTreeState& vts)
{
    using namespace chowdsp::ParamUtils;
    onOff = vts.getRawParameterValue ("comp_onoff");
    loadParameterPointer (amountParam, vts, "comp_amt");
    loadParameterPointer (attackParam, vts, "comp_attack");
    loadParameterPointer (releaseParam, vts, "comp_release");
}

void CompressionProcessor::createParameterLayout (chowdsp::Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    emplace_param<chowdsp::BoolParameter> (params, "comp_onoff", "Compression On/Off", false);
    createGainDBParameter (params, "comp_amt", "Compression Amount", 0.0f, 9.0f, 0.0f, 3.0f);
    createTimeMsParameter (params, "comp_attack", "Compression Attack", createNormalisableRange (0.1f, 50.0f, 10.0f), 5.0f);
    createTimeMsParameter (params, "comp_release", "Compression Release", createNormalisableRange (10.0f, 1000.0f, 100.0f), 200.0f);
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

template <typename T>
inline T compressionDB (const T& xDB, float dbPlus)
{
    using namespace chowdsp::SIMDUtils;
    CHOWDSP_USING_XSIMD_STD (log);

    if (dbPlus <= 0.0f)
        return (T) dbPlus;

    auto window = 2.0f * dbPlus;
    auto belowWin = xDB < -window;
    return select (belowWin, (T) dbPlus, log (xDB + window + 1.0f) - dbPlus - xDB);
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
        dbPlusSmooth[ch].setTargetValue (amountParam->getCurrentValue());

        auto* x = osBlock.getChannelPointer ((size_t) ch);
        FloatVectorOperations::copy (xDBVec.data(), x, numSamples);
        FloatVectorOperations::abs (xDBVec.data(), xDBVec.data(), numSamples);

        constexpr auto inc = xsimd::batch<float>::size;
        size_t n = 0;
        for (; n < (size_t) numSamples; n += inc)
        {
            auto xDB = xsimd::load_aligned (&xDBVec[n]);

            xDB = chowdsp::SIMDUtils::gainToDecibels (xDB);
            auto compDB = compressionDB (xDB, dbPlusSmooth[ch].skip ((int) inc));
            auto compGain = chowdsp::SIMDUtils::decibelsToGain (compDB);

            xsimd::store_aligned (&xDBVec[n], xDB);
            xsimd::store_aligned (&compGainVec[n], compGain);
        }

        // remaining samples that can't be vectorized
        for (; n < (size_t) numSamples; ++n)
        {
            xDBVec[n] = Decibels::gainToDecibels (xDBVec[n]);
            auto compDB = compressionDB (xDBVec[n], dbPlusSmooth[ch].getNextValue());
            compGainVec[n] = Decibels::decibelsToGain (compDB);
        }

        // since the slew will be applied to the gain, we need to reverse the attack and release parameters!
        slewLimiter[ch].setParameters (releaseParam->getCurrentValue(), attackParam->getCurrentValue());
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
