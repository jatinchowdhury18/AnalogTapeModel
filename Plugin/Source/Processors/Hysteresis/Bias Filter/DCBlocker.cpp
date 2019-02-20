#include "DCBlocker.h"

void DCBlocker::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    y1[0] = 0.0f;
    y1[1] = 0.0f;
    x1[0] = 0.0f;
    x1[1] = 0.0f;
}

void DCBlocker::releaseResources()
{
}

void DCBlocker::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/)
{
    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        float* x = buffer.getWritePointer(channel);
        for (int n = 0; n < buffer.getNumSamples(); n++)
            x[n] = dcBlock (x[n], channel);
    }
}

float DCBlocker::dcBlock (float x, int ch)
{
    float y = x - x1[ch] + R * y1[ch];
    x1[ch] = x;
    y1[ch] = y;
    return y;
}
