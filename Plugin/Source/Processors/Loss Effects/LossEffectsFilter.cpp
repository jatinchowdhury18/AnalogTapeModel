#include "LossEffectsFilter.h"

void LossEffectsFilter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    lossProcessors[0].init ((float) sampleRate, speed);
    lossProcessors[1].init ((float) sampleRate, speed);
}

void LossEffectsFilter::releaseResources()
{
}

void LossEffectsFilter::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/)
{
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* x = buffer.getWritePointer (channel);
        for (int n = 0; n < buffer.getNumSamples(); n++)
        {
            x[n] = lossProcessors[channel].process (x[n]);
        }
    }
}

void LossEffectsFilter::setSpeed (String newSpeed)
{
    if (newSpeed == "3.75 ips")
        speed = 3.75f;
    else if (newSpeed == "7.5 ips")
        speed = 7.5f;
    else if (newSpeed == "15 ips")
        speed = 15.0f;

    prepareToPlay (getSampleRate(), getBlockSize());
}
