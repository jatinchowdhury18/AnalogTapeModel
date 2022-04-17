#ifndef DROPOUT_H_INCLUDED
#define DROPOUT_H_INCLUDED

#include "JuceHeader.h"

class Dropout
{
public:
    Dropout() {}

    void setMix (float newMix)
    {
        for (auto& mix : mixSmooth)
            mix.setTargetValue (newMix);
    }

    void setPower (float newPow)
    {
        for (auto& power : powerSmooth)
            power.setTargetValue (newPow);
    }

    void prepare (double sr, int numChannels)
    {
        mixSmooth.resize ((size_t) numChannels);
        for (auto& mix : mixSmooth)
            mix.reset (sr, 0.01);

        for (auto& power : powerSmooth)
            power.reset (sr, 0.005);
    }

    void process (AudioBuffer<float>& buffer)
    {
        if (mixSmooth[0].getTargetValue() == 0.0f && ! mixSmooth[0].isSmoothing())
            return;

        for (size_t ch = 0; ch < (size_t) buffer.getNumChannels(); ++ch)
        {
            auto* x = buffer.getWritePointer ((int) ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                auto mix = mixSmooth[ch].getNextValue();
                x[n] = mix * dropout (x[n], ch) + (1.0f - mix) * x[n];
            }
        }
    }

    inline float dropout (float x, size_t ch)
    {
        auto sign = (float) chowdsp::signum (x);
        return pow (abs (x), powerSmooth[ch].getNextValue()) * sign;
    }

private:
    std::vector<LinearSmoothedValue<float>> mixSmooth;
    std::vector<LinearSmoothedValue<float>> powerSmooth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dropout)
};

#endif // DROPOUT_H_INCLUDED
