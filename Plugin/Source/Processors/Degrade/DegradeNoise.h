#ifndef DEGRADENOISE_H_INCLUDED
#define DEGRADENOISE_H_INCLUDED

#include "JuceHeader.h"

/** Noise for tape degrade effect */
class DegradeNoise
{
public:
    DegradeNoise() = default;
    DegradeNoise (DegradeNoise&&) noexcept = default;

    void setGain (float newGain) { curGain = newGain; }

    void prepare()
    {
        prevGain = curGain;
    }

    void processBlock (float* buffer, int numSamples)
    {
        if (curGain == prevGain)
        {
            for (int n = 0; n < numSamples; ++n)
                buffer[n] += (random.nextFloat() - 0.5f) * curGain;
        }
        else
        {
            for (int n = 0; n < numSamples; ++n)
                buffer[n] += (random.nextFloat() - 0.5f) * ((curGain * (float) n / (float) numSamples) + (prevGain * (1.0f - (float) n / (float) numSamples)));

            prevGain = curGain;
        }
    }

private:
    float curGain = 0.0f;
    float prevGain = curGain;

    Random random;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DegradeNoise)
};

#endif // DEGRADENOISE_H_INCLUDED
