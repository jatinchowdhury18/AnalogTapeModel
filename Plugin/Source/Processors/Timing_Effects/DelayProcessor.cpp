#include "DelayProcessor.h"

void DelayProcessor::setReadPtr (int maxLength)
{
    readPtr++;
    if (readPtr >= maxLength) //wrap
        readPtr = 0;
}

void DelayProcessor::setLengthMs (double lengthMs, bool force)
{
    int newLength = (int) (lengthMs * sampleRate / 1000.0);
    newLength = jmin (newLength, bufferSize);

    if (! force)
        length.setTargetValue ((float) newLength);
    else
        length.setCurrentAndTargetValue ((float) newLength);
}

float DelayProcessor::getLengthMS () const
{
    return (length.getTargetValue() / sampleRate) * 1000.0f;
}

void DelayProcessor::setFeedback (float newFeedback)
{
    feedback = jlimit<float> (0.0f, 0.9f, newFeedback);
}

float DelayProcessor::getFeedback() const
{
    return feedback;
}

void DelayProcessor::prepareToPlay (double sr, int /*maximumExpectedSamplesPerBlock*/)
{
    sampleRate = (float) sr;
    bufferSize = (int) sampleRate * maxDelaySeconds;
    delayBuffer.setSize (1, bufferSize);
    delayBuffer.clear();

    length.reset (sampleRate, 5e-3);
    resetPtrs();
}

void DelayProcessor::process (float* buffer, int numSamples)
{
    for (int n = 0; n < numSamples; n++)
        buffer[n] += delay (buffer[n]);
}

float DelayProcessor::delay (float x)
{  
    // Erase head
    const int erasePtr = negativeAwareModulo (readPtr - 1, bufferSize);
    delayBuffer.setSample (0, erasePtr, 0.0f);

    // Write head
    const float len = length.getNextValue();

    float y = x;
    if (len > 0)
    {
        // Read head
        y = delayBuffer.getSample (0, readPtr);

        // write ptr
        const float fractionSample = len - (int) len;
        const int writePtr = (readPtr + (int) floorf (len)) % bufferSize;

        // feedback
        float writeSample = x + y * feedback;

        delayBuffer.addSample (0, writePtr, writeSample * (1.0f - fractionSample));
        delayBuffer.addSample (0, (writePtr + 1) % bufferSize, writeSample * fractionSample);
    }

    //update pointers
    setReadPtr (bufferSize);

    return y;
}
