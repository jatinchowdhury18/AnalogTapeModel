#include "HysteresisProcessor.h"

HysteresisProcessor::HysteresisProcessor() : ProcessorBase ("HysteresisProcessor")
{
    overSample.reset (new dsp::Oversampling<float> (2, 1, dsp::Oversampling<float>::filterHalfBandFIREquiripple));
}

void HysteresisProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    hProcs[0].setSampleRate ((float) (sampleRate * overSamplingFactor));
    hProcs[1].setSampleRate ((float) (sampleRate * overSamplingFactor));

    overSample->factorOversampling = overSamplingFactor;
    overSample->initProcessing (samplesPerBlock);
}

void HysteresisProcessor::releaseResources()
{
    overSample->reset();
}

void HysteresisProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midi*/)
{
    auto totalNumInputChannels  = getTotalNumInputChannels();

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> osBlock = overSample->processSamplesUp(block);

    float* ptrArray[] = { osBlock.getChannelPointer(0), osBlock.getChannelPointer(1) };
    AudioBuffer<float> osBuffer (ptrArray, 2, static_cast<int> (osBlock.getNumSamples()));

    for (int channel = 0; channel < osBuffer.getNumChannels(); ++channel)
    {
        auto* x = osBuffer.getWritePointer (channel);
        for (int n = 0; n < osBuffer.getNumSamples(); n++)
        {
            x[n] = hProcs[channel].process (((float) 1e5) * x[n]);
        }
    }

    overSample->processSamplesDown(block);
}

void HysteresisProcessor::setOverSamplingFactor (String osFactor)
{
    int factor = overSamplingFactor;
    
    if (osFactor == "2x")
        factor = 2;
    else if (osFactor == "4x")
        factor = 4;
    else if (osFactor == "8x")
        factor = 8;

    overSamplingFactor = factor;
    overSample->reset();
    overSample->factorOversampling = overSamplingFactor;
    overSample->initProcessing (getBlockSize());
}
