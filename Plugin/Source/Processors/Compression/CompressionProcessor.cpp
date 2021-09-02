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
    params.push_back (std::make_unique<AudioParameterBool> ("comp_onoff", "Compression On/Off", false));
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_amt", "Compression Amount", 0.0f, 9.0f, 0.0f));

    static NormalisableRange<float> attRange { 0.1f, 100.0f };
    attRange.setSkewForCentre (10.0f);
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_attack", "Compression Attack", attRange, 5.0f,
                                                             String(), AudioProcessorParameter::genericParameter,
                                                             [] (float value, int) { return String (value, 2); }));

    static NormalisableRange<float> relRange { 1.0f, 1000.0f };
    relRange.setSkewForCentre (100.0f);
    params.push_back (std::make_unique<AudioParameterFloat> ("comp_release", "Compression Release", relRange, 25.0f,
                                                             String(), AudioProcessorParameter::genericParameter,
                                                             [] (float value, int) { return String (value, 2); }));
}

void CompressionProcessor::prepare (double sr, int samplesPerBlock)
{
    for (int ch = 0; ch < 2; ++ch)
        slewLimiter[ch].prepare ({ sr, (uint32) samplesPerBlock, 1 });

    bypass.prepare (samplesPerBlock, bypass.toBool (onOff));

    xDBVec.resize ((size_t) samplesPerBlock, 0.0f);
    compGainVec.resize ((size_t) samplesPerBlock, 0.0f);
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

    auto dbPlus = amountParam->load();
    const auto numSamples = buffer.getNumSamples();
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        FloatVectorOperations::copy (xDBVec.data(), x, numSamples);
        FloatVectorOperations::abs (xDBVec.data(), xDBVec.data(), numSamples);

        constexpr auto inc = dsp::SIMDRegister<float>::size();
        size_t n = 0;
        for (; n < (size_t) numSamples; n += inc)
        {
            auto xDB = dsp::SIMDRegister<float>::fromRawArray (&xDBVec[n]);

            xDB = chowdsp::SIMDUtils::gainToDecibels (xDB);
            auto compDB = compressionDB (xDB, dbPlus);
            auto compGain = chowdsp::SIMDUtils::decibelsToGain (compDB);

            xDB.copyToRawArray (&xDBVec[n]);
            compGain.copyToRawArray (&compGainVec[n]);
        }

        // remaining samples that can't be vectorized
        for (; n < (size_t) numSamples; ++n)
        {
            xDBVec[n] = Decibels::gainToDecibels (xDBVec[n]);
            auto compDB = compressionDB (xDBVec[n], dbPlus);
            compGainVec[n] = Decibels::decibelsToGain (compDB);
        }

        // since the slew will be applied to the gain, we need to reverse the attack and release parameters!
        slewLimiter[ch].setParameters (releaseParam->load(), attackParam->load());
        for (size_t n = 0; n < (size_t) numSamples; ++n)
            compGainVec[n] = jmin(compGainVec[n], slewLimiter[ch].processSample (compGainVec[n]));

        FloatVectorOperations::multiply (x, compGainVec.data(), numSamples);
    }

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}
