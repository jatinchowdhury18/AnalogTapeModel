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
}

inline float compressionDB (float xDB, float dbPlus)
{
    auto window = 2.0f * dbPlus;

    if (dbPlus <= 0.0f || xDB < -window)
        return dbPlus;

    return std::log (xDB + window + 1.0f) - dbPlus - xDB;
}

void CompressionProcessor::processBlock (AudioBuffer<float>& buffer)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOff)))
        return;

    auto dbPlus = amountParam->load();
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        // since the slew will be applied to the gain, we need to reverse the attack and release parameters!
        slewLimiter[ch].setParameters (releaseParam->load(), attackParam->load());

        auto* x = buffer.getWritePointer (ch);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            auto xDB = Decibels::gainToDecibels (std::abs (x[n]));
            auto compDB = compressionDB (xDB, dbPlus);
            auto compGain = Decibels::decibelsToGain (compDB);
            compGain = slewLimiter[ch].processSample (compGain);
            x[n] *= compGain;
        }
    }

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}
