#include "BiasFilter.h"

BiasFilter::BiasFilter() : ProcessorBase ("Bias Filter")
{
    filter[0].setQ (0.5098f);
    filter[1].setQ (0.6013f);
    filter[1].setQ (0.8999f);
    filter[1].setQ (2.5628f);
}

void BiasFilter::setFreq (float newFreq)
{
    filter[0].setFreq (newFreq);
    filter[1].setFreq (newFreq);
    filter[2].setFreq (newFreq);
    filter[3].setFreq (newFreq);
}

void BiasFilter::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi)
{
    filter[0].processBlock (buffer, midi);
    filter[1].processBlock (buffer, midi);
    filter[2].processBlock (buffer, midi);
    filter[3].processBlock (buffer, midi);

    dcBlocker.processBlock (buffer, midi);
}

void BiasFilter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    filter[0].prepareToPlay (sampleRate, samplesPerBlock);
    filter[1].prepareToPlay (sampleRate, samplesPerBlock);
    filter[2].prepareToPlay (sampleRate, samplesPerBlock);
    filter[3].prepareToPlay (sampleRate, samplesPerBlock);

    dcBlocker.prepareToPlay (sampleRate, samplesPerBlock);
}

void BiasFilter::releaseResources()
{
    filter[0].releaseResources();
    filter[1].releaseResources();
    filter[2].releaseResources();
    filter[3].releaseResources();

    dcBlocker.releaseResources();
}

