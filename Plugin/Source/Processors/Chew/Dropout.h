#ifndef DROPOUT_H_INCLUDED
#define DROPOUT_H_INCLUDED

#include "JuceHeader.h"

class Dropout
{
public:
    Dropout() {}

    void setMix (float newMix)
    {
        for (int ch = 0; ch < 2; ++ch)
            mixSmooth[ch].setTargetValue (newMix);
    }

    void setPower (float newPow)
    {
        for (int ch = 0; ch < 2; ++ch)
            powerSmooth[ch].setTargetValue (newPow);
    }

    void prepare (double sr)
    {
        for (int ch = 0; ch < 2; ++ch)
        {
            mixSmooth[ch].reset (sr, 0.01);
            mixSmooth[ch].setCurrentAndTargetValue (mixSmooth[ch].getTargetValue());

            powerSmooth[ch].reset (sr, 0.005);
            powerSmooth[ch].setCurrentAndTargetValue (powerSmooth[ch].getTargetValue());
        }
    }

    void process (AudioBuffer<float>& buffer)
    {
        if (mixSmooth[0].getTargetValue() == 0.0f && ! mixSmooth[0].isSmoothing())
            return;

        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        {
            auto* x = buffer.getWritePointer (ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                auto mix = mixSmooth[ch].getNextValue();
                x[n] = mix * dropout (x[n], ch) + (1.0f - mix) * x[n];
            }
        }
    }

    inline float dropout (float x, int ch)
    {
        float sign = 0.0f;
        if (x > 0.0f)
            sign = 1.0f;
        else if (x < 0.0f)
            sign = -1.0f;

        return pow (abs (x), powerSmooth[ch].getNextValue()) * sign;
    }

private:
    LinearSmoothedValue<float> mixSmooth[2];
    LinearSmoothedValue<float> powerSmooth[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dropout)
};

#endif // DROPOUT_H_INCLUDED
