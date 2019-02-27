#include "HysteresisProcessor.h"

HysteresisProcessor::HysteresisProcessor() : ProcessorBase ("HysteresisProcessor")
{
    overSample2.reset (new dsp::Oversampling<float> (2, 1, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR));
    overSample4.reset (new dsp::Oversampling<float> (2, 2, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR));
    overSample8.reset (new dsp::Oversampling<float> (2, 3, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR));
    overSample16.reset (new dsp::Oversampling<float> (2, 4, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR));
}

void HysteresisProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    hProcs[0].setSampleRate ((float) (sampleRate * overSamplingFactor));
    hProcs[1].setSampleRate ((float) (sampleRate * overSamplingFactor));

    if (overSamplingFactor == 16)
        overSample16->initProcessing (samplesPerBlock);
    else if (overSamplingFactor == 8)
        overSample8->initProcessing (samplesPerBlock);
    else if (overSamplingFactor == 4)
        overSample4->initProcessing (samplesPerBlock);
    else
        overSample2->initProcessing (samplesPerBlock);

    currentSampleRate = (float) sampleRate * overSamplingFactor;
    updateAngleDelta();

    fadeIn = true;
}

void HysteresisProcessor::releaseResources()
{
    overSample2->reset();
    overSample4->reset();
    overSample8->reset();
    overSample16->reset();
}

void HysteresisProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midi*/)
{
    if (fadeIn)
    {
        buffer.applyGainRamp (0, buffer.getNumSamples(), 0.0f, 1.0f);
        fadeIn = false;
    }

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> osBlock;
    
    if (overSamplingFactor == 16)
        osBlock = overSample16->processSamplesUp (block);
    else if (overSamplingFactor == 8)
        osBlock = overSample8->processSamplesUp (block);
    else if (overSamplingFactor == 4)
        osBlock = overSample4->processSamplesUp (block);
    else
        osBlock = overSample2->processSamplesUp (block);

    float* ptrArray[] = { osBlock.getChannelPointer(0), osBlock.getChannelPointer(1) };
    AudioBuffer<float> osBuffer (ptrArray, 2, static_cast<int> (osBlock.getNumSamples()));

    for (int channel = 0; channel < osBuffer.getNumChannels(); ++channel)
    {
        auto* x = osBuffer.getWritePointer (channel);
        for (int samp = 0; samp < osBuffer.getNumSamples(); samp++)
        {
            //x[samp] = hProcs[channel].process ((float) 5e4 * (x[samp]));
            x[samp] = hProcs[channel].process ((float) 5e3 * (x[samp] + biasGain * sinf (currentAngle[channel])));
            //x[samp] = biasGain * sinf (currentAngle[channel]);

            currentAngle[channel] += angleDelta;
            if (currentAngle[channel] > MathConstants<float>::twoPi)
                currentAngle[channel] -= MathConstants<float>::twoPi; 
        }
    }

    if (overSamplingFactor == 16)
        overSample16->processSamplesDown (block);
    else if (overSamplingFactor == 8)
        overSample8->processSamplesDown (block);
    else if (overSamplingFactor == 4)
        overSample4->processSamplesDown (block);
    else
        overSample2->processSamplesDown (block);

    buffer.applyGain (10.0f);
}

void HysteresisProcessor::updateAngleDelta()
{
    auto cyclesPerSample = biasFreq / currentSampleRate;
    angleDelta = cyclesPerSample * 2.0f * MathConstants<float>::pi; 
}

void HysteresisProcessor::setOverSamplingFactor (String osFactor)
{
    //osFactor = "8x";
    auto factor = overSamplingFactor;   
    if (osFactor == "2x")
        factor = 2; // set overSample factor 2 = 2^1
    else if (osFactor == "4x")
        factor = 4; // set overSample factor 4 = 2^2
    else if (osFactor == "8x")
        factor = 8; // set overSample factor 8 = 2^3
    else if (osFactor == "16x")
        factor = 16; //set overSample factor 16 = 2^4

    if (factor != overSamplingFactor)
    {
        overSamplingFactor = factor;
        releaseResources();
        prepareToPlay (getSampleRate(), getBlockSize());
    }
}

void HysteresisProcessor::setBiasFreq (float newFreqKHz)
{
    biasFreq = newFreqKHz * 1000.0f;
    updateAngleDelta();
}

void HysteresisProcessor::setBiasGain (float newGainDB)
{
    biasGain = newGainDB; //Decibels::decibelsToGain (newGainDB);
}

double HysteresisProcessor::getTailLengthSeconds() const
{
    if (overSamplingFactor == 16)
        return overSample16->getLatencyInSamples() * getSampleRate();
    else if (overSamplingFactor == 8)
        return overSample8->getLatencyInSamples() * getSampleRate();
    else if (overSamplingFactor == 4)
        return overSample4->getLatencyInSamples() * getSampleRate();
    else
        return overSample2->getLatencyInSamples() * getSampleRate();
}
