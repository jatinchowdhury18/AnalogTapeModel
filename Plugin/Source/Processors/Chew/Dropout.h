#ifndef DROPOUT_H_INCLUDED
#define DROPOUT_H_INCLUDED

#include "JuceHeader.h"

class Dropout
{
public:
    Dropout() {}

    void setMix (float newMix)
    { 
        curMix = newMix; 

        for (int ch = 0; ch < 2; ++ch)
            mixSmooth[ch].setTargetValue (newMix);
    }

    void setPower (float newPow)
    { 
        power = newPow;

        for (int ch = 0; ch < 2; ++ch)
            powerSmooth[ch].setTargetValue (newPow);
    }

    void prepare (double sr, int maxBufferSize)
    {
        for (int ch = 0; ch < 2; ++ch)
        {
            mixSmooth[ch].reset (sr, 0.01);
            mixSmooth[ch].setCurrentAndTargetValue (mixSmooth[ch].getTargetValue());

            powerSmooth[ch].reset (sr, 0.01);
            powerSmooth[ch].setCurrentAndTargetValue (powerSmooth[ch].getTargetValue());
        }

        dryBuffer.setSize (2, maxBufferSize);

        prevMix = curMix;
    }

    void process (AudioBuffer<float>& buffer)
    {
        if (mixSmooth[0].getTargetValue() == 0.0f && ! mixSmooth[0].isSmoothing())
            return;
        // if (curMix == 0.0f && prevMix == 0.0f)
        //     return;

        // copy dry buffer
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        {
            dryBuffer.copyFrom (ch, 0, buffer.getReadPointer (ch), buffer.getNumSamples());
        
            auto* x = buffer.getWritePointer (ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                auto mix = mixSmooth[ch].getNextValue();
                x[n] = mix * dropout (x[n], ch) + (1.0f - mix) * x[n];
            }
        }

        // if (curMix == prevMix)
        // {
        //     buffer.applyGain (curMix);
        // 
        //     for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        //         buffer.addFrom (ch, 0, dryBuffer.getReadPointer (ch), buffer.getNumSamples(), (1.0f - curMix));
        // }
        // else
        // {
        //     buffer.applyGainRamp (0, buffer.getNumSamples(), prevMix, curMix);
        // 
        //     for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        //         buffer.addFromWithRamp (ch, 0, dryBuffer.getReadPointer (ch), buffer.getNumSamples(), (1.0f - prevMix), (1.0f - curMix));
        // 
        //     prevMix = curMix;
        // }
    }

    inline float dropout (float x, int ch)
    {
        float sign = 0.0f;
        if (x > 0.0f)
            sign = 1.0f;
        else if (x < 0.0f)
            sign = -1.0f;

        return pow (abs (x), powerSmooth[ch].getNextValue()) * sign; // / power;
    }

private:
    float curMix = 0.0f;
    float prevMix = curMix;
    float power = 1.0f;

    LinearSmoothedValue<float> mixSmooth[2];
    LinearSmoothedValue<float> powerSmooth[2];

    AudioBuffer<float> dryBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dropout)
};

#endif // DROPOUT_H_INCLUDED
