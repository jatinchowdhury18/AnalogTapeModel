#include "TimingEffect.h"

void TimingEffect::DelayChannel::setReadPtr (int maxLength)
{
    readPtr++;
    if (readPtr >= maxLength) //wrap
        readPtr = 0;
}

TimingEffect::TimingEffect() : ProcessorBase (String ("Timing Processor"))
{
    delayBuffer.setSize (2, maxDelaySamples);
}

double TimingEffect::getTailLengthSeconds() const
{
    int maxLengthSamples = 0;
    for (auto& ch : dChannels)
        maxLengthSamples = jmax ((int) ch.length.getTargetValue(), maxLengthSamples);

    return (double) maxLengthSamples / getSampleRate();
}

void TimingEffect::setLength (int channel, int lengthSamples)
{
    auto corrLength = roundToInt ((double) lengthSamples * getSampleRate() / fs_calc);
    int newLength = jmax (0, jmin (corrLength, (int) maxDelaySamples));
    dChannels[channel].length.setValue ((float) newLength);
}

int TimingEffect::getLength (int channel) const
{
    return roundToInt (dChannels[channel].length.getTargetValue());
}

void TimingEffect::setDepth (float newDepth)
{
    setLength (0, roundToInt (newDepth * dChannels[0].length.getTargetValue() / depth));
    setLength (1, roundToInt (newDepth * dChannels[1].length.getTargetValue() / depth));

    depth = newDepth;
}

void TimingEffect::prepareToPlay (double sampleRate, int maximumExpectedSamplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, maximumExpectedSamplesPerBlock);
    
    delayBuffer.clear();

    resetDelay();
}

void TimingEffect::releaseResources()
{
    delayBuffer.clear();

    for (auto& ch : dChannels)
        ch.resetPtrs();
}

void TimingEffect::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/)
{
    countFreq += buffer.getNumSamples();

    if (n >= periodLen)
        n = 0;

    if (countFreq > numSamplesFreq)
    {
        countFreq = 0;
        n++;

        updateDelay();
    }

    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        float* x = buffer.getWritePointer(channel);
        for (int samp = 0; samp < buffer.getNumSamples(); samp++)
            x[samp] = delay (channel, x[samp]);
    }
}

float TimingEffect::delay (int channel, float x)
{
    auto& ch = dChannels[channel];

    // Erase head
    const int erasePtr = negativeAwareModulo(ch.readPtr - 1, (int) maxDelaySamples);
    delayBuffer.setSample (channel, erasePtr, 0.0f);

    // Write head
    const float len = ch.length.getNextValue();
    const float fractionSample = len - (int) len;
    const int writePtr = (ch.readPtr + (int) floorf (len)) % (int) maxDelaySamples;

    delayBuffer.addSample (channel, writePtr, x * (1.0f - fractionSample));
    delayBuffer.addSample (channel, (writePtr + 1) % (int) maxDelaySamples, x * fractionSample);

    // Read head
    float y = delayBuffer.getSample (channel, ch.readPtr);

    //update pointers
    ch.setReadPtr ((int) maxDelaySamples);

    return y;
}

void TimingEffect::updateDelay()
{
    float t = 0;

    for (int i = 0; i < polyOrder+1; i++)
        t += coefs[i] * (float) pow (n, i);

    setLength (0, roundToInt (depth * t));
    setLength (1, roundToInt (depth * t));
}

void TimingEffect::resetDelay()
{
    n = 0;
    countFreq = 0;
    numSamplesFreq = roundToInt<double> ((1.0f / freq) * getSampleRate());

    for (auto& ch : dChannels)
        ch.length.reset (getSampleRate(), 1.0 / freq); //(1 / freq) seconds to interpolate
}

void TimingEffect::setTapeSpeed (String tapeSpeed)
{
    auto newFreq = freq;

    if (tapeSpeed == "3.75 ips")
        newFreq = 5.0f;
    else if (tapeSpeed == "7.5 ips")
        newFreq = 10.0f;
    else if (tapeSpeed == "15 ips")
        newFreq = 20.0f;

    if (newFreq != freq)
    {
        freq = newFreq;
        resetDelay();
    }
}
