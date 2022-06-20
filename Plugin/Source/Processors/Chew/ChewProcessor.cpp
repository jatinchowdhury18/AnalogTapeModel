#include "ChewProcessor.h"

ChewProcessor::ChewProcessor (AudioProcessorValueTreeState& vts)
{
    using namespace chowdsp::ParamUtils;
    loadParameterPointer (depth, vts, "chew_depth");
    loadParameterPointer (freq, vts, "chew_freq");
    loadParameterPointer (var, vts, "chew_var");
    onOff = vts.getRawParameterValue ("chew_onoff");
}

void ChewProcessor::createParameterLayout (chowdsp::Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    emplace_param<chowdsp::BoolParameter> (params, "chew_onoff", "Chew On/Off", false);
    emplace_param<chowdsp::FloatParameter> (params, "chew_depth", "Chew Depth", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "chew_freq", "Chew Freq", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "chew_var", "Chew Variance", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
}

void ChewProcessor::prepare (double sr, int samplesPerBlock, int numChannels)
{
    sampleRate = (float) sr;

    dropout.prepare (sr, numChannels);

    filt.resize ((size_t) numChannels);
    for (auto& filter : filt)
        filter.reset (sampleRate, int (sr * 0.02));

    isCrinkled = false;
    samplesUntilChange = getDryTime();
    sampleCounter = 0;

    bypass.prepare (samplesPerBlock, numChannels, bypass.toBool (onOff));
}

void ChewProcessor::processBlock (AudioBuffer<float>& buffer)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOff)))
        return;

    const int shortBlockSize = 64;
    if (buffer.getNumSamples() <= shortBlockSize)
    {
        processShortBlock (buffer);
    }
    else
    {
        int sampleIdx = 0;
        for (; sampleIdx + shortBlockSize <= buffer.getNumSamples(); sampleIdx += shortBlockSize)
        {
            AudioBuffer<float> shortBuff (buffer.getArrayOfWritePointers(),
                                          buffer.getNumChannels(),
                                          sampleIdx,
                                          shortBlockSize);

            processShortBlock (shortBuff);
        }

        if (sampleIdx < buffer.getNumSamples())
        {
            AudioBuffer<float> shortBuff (buffer.getArrayOfWritePointers(),
                                          buffer.getNumChannels(),
                                          sampleIdx,
                                          buffer.getNumSamples() - sampleIdx);

            processShortBlock (shortBuff);
        }
    }

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}

void ChewProcessor::processShortBlock (AudioBuffer<float>& buffer)
{
    const float highFreq = jmin (22000.0f, 0.49f * sampleRate);
    const float freqChange = highFreq - 5000.0f;

    if (*freq == 0.0f)
    {
        mix = 0.0f;
        for (auto& filter : filt)
            filter.setFreq (highFreq);
    }
    else if (*freq == 1.0f)
    {
        mix = 1.0f;
        power = 3.0f * *depth;
        const auto filterFreq = highFreq - freqChange * *depth;
        for (auto& filter : filt)
            filter.setFreq (filterFreq);
    }
    else if (sampleCounter >= samplesUntilChange)
    {
        sampleCounter = 0;
        isCrinkled = ! isCrinkled;

        if (isCrinkled) // start crinkle
        {
            mix = 1.0f;
            power = (1.0f + 2.0f * random.nextFloat()) * *depth;
            const auto filterFreq = highFreq - freqChange * *depth;
            for (auto& filter : filt)
                filter.setFreq (filterFreq);

            samplesUntilChange = getWetTime();
        }
        else // end crinkle
        {
            mix = 0.0f;
            for (auto& filter : filt)
                filter.setFreq (highFreq);
            samplesUntilChange = getDryTime();
        }
    }
    else
    {
        power = (1.0f + 2.0f * random.nextFloat()) * *depth;
        if (isCrinkled)
        {
            const auto filterFreq = highFreq - freqChange * *depth;
            for (auto& filter : filt)
                filter.setFreq (filterFreq);
        }
    }

    dropout.setMix (mix);
    dropout.setPower (1.0f + power);

    dropout.process (buffer);
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        filt[ch].process (buffer.getWritePointer (ch), buffer.getNumSamples());

    sampleCounter += buffer.getNumSamples();
}
