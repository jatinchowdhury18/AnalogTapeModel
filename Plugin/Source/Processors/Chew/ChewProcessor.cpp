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

    dropout.prepare (samplesPerBlock);

    isCrinkled = false;
    samplesUntilChange = getDryTime();
    sampleCounter = 0;
}

void ChewProcessor::processBlock (AudioBuffer<float>& buffer)
{
    if (sampleCounter >= samplesUntilChange)
    {
        sampleCounter = 0;
        isCrinkled = ! isCrinkled;

        if (isCrinkled) // start crinkle
        {
            mix = 1.0f;
            power = *depth;
            samplesUntilChange = getWetTime();
        }
        else            // end crinkle
        {
            mix = 0.0f;
            power = 0.0f;
            samplesUntilChange = getDryTime();
        }
    }

    dropout.setMix (mix);
    dropout.setPow (1.0f + 4.0f * power);

    dropout.process (buffer);

    sampleCounter += buffer.getNumSamples();
}
