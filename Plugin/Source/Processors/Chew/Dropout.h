#ifndef DROPOUT_H_INCLUDED
#define DROPOUT_H_INCLUDED

#include "JuceHeader.h"

class Dropout
{
public:
    Dropout() {}

    void setMix (float newMix) { curMix = newMix; }
    void setPow (float newPow) { power = newPow; }

    void prepare (int maxBufferSize)
    {
        dryBuffer.setSize (2, maxBufferSize);

        prevMix = curMix;
    }

    void process (AudioBuffer<float>& buffer)
    {
        if (curMix == 0.0f)
            return;

        // copy dry buffer
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        {
            dryBuffer.copyFrom (ch, 0, buffer.getReadPointer (ch), buffer.getNumSamples());

            auto* x = buffer.getWritePointer (ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
                x[n] = dropout (x[n]);
        }

        if (curMix == prevMix)
        {
            buffer.applyGain (curMix);

            for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
                buffer.addFrom (ch, 0, dryBuffer.getReadPointer (ch), buffer.getNumSamples(), (1.0f - curMix));
        }
        else
        {
            buffer.applyGainRamp (0, buffer.getNumSamples(), prevMix, curMix);

            for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
                buffer.addFromWithRamp (ch, 0, dryBuffer.getReadPointer (ch), buffer.getNumSamples(), (1.0f - prevMix), (1.0f - curMix));

            prevMix = curMix;
        }
    }

    inline float dropout (float x)
    {
        float sign = 0.0f;
        if (x < 0.0f)
            sign = -1.0f;
        else if (x > 0.0f)
            sign = 1.0f;

        return std::powf (abs (x), power) * sign / power;
    }

private:
    float curMix = 0.0f;
    float prevMix = curMix;
    float power = 1.0f;

    AudioBuffer<float> dryBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dropout)
};

#endif // DROPOUT_H_INCLUDED
