#include "ChewProcessor.h"

ChewProcessor::ChewProcessor (AudioProcessorValueTreeState& vts)
{
    depth = vts.getRawParameterValue ("chew_depth");
    freq  = vts.getRawParameterValue ("chew_freq");
}

void ChewProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("chew_depth", "Depth", 0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("chew_freq",  "Freq",  0.0f, 1.0f, 0.0f));
}

void ChewProcessor::prepare (double sr, int samplesPerBlock)
{
    sampleRate = (float) sr;

    dropout.prepare (sr, samplesPerBlock);

    isCrinkled = false;
    samplesUntilChange = getDryTime();
    sampleCounter = 0;
}

void ChewProcessor::processBlock (AudioBuffer<float>& buffer)
{
    const int shortBlockSize = 64;
    if (buffer.getNumSamples() <= shortBlockSize)
    {
        processShortBlock (buffer);
        return;
    }

    int sampleIdx = 0;
    for(; sampleIdx + shortBlockSize <= buffer.getNumSamples(); sampleIdx += shortBlockSize)
    {
        AudioBuffer<float> shortBuff (buffer.getArrayOfWritePointers(),
            buffer.getNumChannels(), sampleIdx, shortBlockSize);

        processShortBlock (shortBuff);
    }

    if (sampleIdx < buffer.getNumSamples())
    {
        AudioBuffer<float> shortBuff (buffer.getArrayOfWritePointers(),
            buffer.getNumChannels(), sampleIdx, buffer.getNumSamples() - sampleIdx);

        processShortBlock (shortBuff);
    }
}

void ChewProcessor::processShortBlock (AudioBuffer<float>& buffer)
{
    if (*freq == 0.0f)
    {
        mix = 0.0f;
    }
    else if (*freq == 1.0f)
    {
        mix = 1.0f;
        power = 3.0f * *depth;
    }
    else if (sampleCounter >= samplesUntilChange)
    {
        sampleCounter = 0;
        isCrinkled = ! isCrinkled;
    
        if (isCrinkled) // start crinkle
        {
            mix = 1.0f;
            power = (1.0f + 2.0f * random.nextFloat()) * *depth;
            samplesUntilChange = getWetTime();
        }
        else            // end crinkle
        {
            mix = 0.0f;
            samplesUntilChange = getDryTime();
        }
    }
    else
    {
        power = (1.0f + 2.0f * random.nextFloat()) * *depth;
    }

    dropout.setMix (mix);
    dropout.setPower (1.0f + power);
     
    dropout.process (buffer);

    sampleCounter += buffer.getNumSamples();
}
