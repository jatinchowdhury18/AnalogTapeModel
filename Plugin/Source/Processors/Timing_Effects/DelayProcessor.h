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
    
    inline float delay (float x)
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

    inline void resetPtrs() { readPtr = 0; }
    inline void setReadPtr (int maxLength)
    {
        readPtr++;
        if (readPtr >= maxLength) //wrap
            readPtr = 0;
    }

    float sampleRate = 48000.0f;

    AudioBuffer<float> delayBuffer;
    int bufferSize = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayProcessor)
};

#endif //DELAYPROCESSOR_H_INCLUDED
