#include "DegradeProcessor.h"

DegradeProcessor::DegradeProcessor (AudioProcessorValueTreeState& vts)
{
    depthParam = vts.getRawParameterValue ("deg_depth");
    amtParam   = vts.getRawParameterValue ("deg_amt");
    varParam   = vts.getRawParameterValue ("deg_var");
}

void DegradeProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_depth", "Depth",    0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_amt",   "Amount",   0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_var",   "Variance", 0.0f, 1.0f, 0.0f));
}

void DegradeProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        noiseProc[ch].prepare();
        filterProc[ch].reset ((float) sampleRate);
    }

    gainProc.prepareToPlay (sampleRate, samplesPerBlock);
}

void DegradeProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi)
{
    float freqHz = 200.0f * powf (20000.0f / 200.0f, 1.0f - *amtParam);
    float gainDB = -24.0f * *depthParam;

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        noiseProc[ch].setGain (0.5f * *depthParam * *amtParam);
        noiseProc[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());

        filterProc[ch].setFreq (jmin (freqHz + (*varParam * (freqHz / 0.6f) * (random.nextFloat() - 0.5f)), 22000.0f));
        filterProc[ch].process (buffer.getWritePointer (ch), buffer.getNumSamples());
    }

    gainProc.setGain (Decibels::decibelsToGain (jmin (gainDB + (*varParam * 36.0f * (random.nextFloat() - 0.5f)), 3.0f)));
    gainProc.processBlock (buffer, midi);
}
