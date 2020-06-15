#include "DelayProcessor.h"

void DelayProcessor::setLengthMs (double lengthMs, bool force)
{
    auto newLength = lengthMs * sampleRate / 1000.0;
    newLength = jmin (newLength, (double) bufferSize);

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
