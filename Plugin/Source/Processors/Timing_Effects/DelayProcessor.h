#ifndef DELAYPROCESSOR_H_INCLUDED
#define DELAYPROCESSOR_H_INCLUDED

#include "JuceHeader.h"

/** Mono Delay */
class DelayProcessor
{
public:
    DelayProcessor() {}

    void prepareToPlay (double sampleRate, int maxExpectedBlockSize);
    void process (float* buffer, int numSamples);
    float delay (float x);

    void setLengthMs (double lengthMs, bool force = false);
    float getLengthMS() const;

    void setFeedback (float newFeedback);
    float getFeedback() const;

private:
    enum
    {
        maxDelaySeconds = 5,
    };

    SmoothedValue<float, ValueSmoothingTypes::Linear> length = 0.0f;
    float feedback = 0.0f;
    int readPtr = 0;

    void resetPtrs() { readPtr = 0; }
    void setReadPtr (int maxLength);

    float sampleRate = 48000.0f;

    AudioBuffer<float> delayBuffer;
    int bufferSize = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayProcessor)
};

#endif //DELAYPROCESSOR_H_INCLUDED
