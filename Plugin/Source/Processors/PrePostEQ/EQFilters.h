#ifndef EQFILTERS_H_INCLUDED
#define EQFILTERS_H_INCLUDED

#include "JuceHeader.h"

/** First order Filter */
class EQFilter
{
public:
    EQFilter()
    {
        cutoff.reset (smoothSteps);
    }

    void reset (float sampleRate)
    {
        fs = sampleRate;

        cutoff.skip (smoothSteps);
        calcCoefs (cutoff.getCurrentValue());
    }

    void setCutoff (float newFc)
    {
        if (cutoff.getTargetValue() != newFc)
            cutoff.setTargetValue (jlimit (5.0f, fs / 2.0f - 100.0f, newFc));
    }

    template <class FloatType>
    void processBlock (FloatType* buffer, const int numSamples)
    {
        for (int n = 0; n < numSamples; ++n)
        {
            if (cutoff.isSmoothing())
                calcCoefs (cutoff.getNextValue());
            buffer[n] = process (buffer[n]);
        }
    }

    template <class FloatType>
    inline FloatType process (FloatType x)
    {
        FloatType y = z[1] + x * b[0];
        z[1] = (float) x * b[1] - (float) y * a[1];
        return y;
    }

    virtual void calcCoefs (float /*cutoff*/) = 0;

protected:
    float fs = 48000.0f;
    float a[2] = {1.0f, 0.0f};
    float b[2] = {1.0f, 0.0f};

private:
    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> cutoff = 1.0f;
    const int smoothSteps = 200;

    float z[2] = {1.0f, 0.0f};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQFilter)
};

/** First order LPF */
class LPF1 : public EQFilter
{
public:
    LPF1() {}

    void calcCoefs (float newFc)
    {
        float wc = MathConstants<float>::twoPi * newFc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float a0 = c  + 1.0f;

        b[0] = 1.0f / a0;
        b[1] = b[0];
        a[1] = (1.0f - c) / a0;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LPF1)
};

/** First order HPF */
class HPF1 : public EQFilter
{
public:
    HPF1() {}

    void calcCoefs (float newFc)
    {
        float wc = MathConstants<float>::twoPi * newFc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float a0 = c  + 1.0f;

        b[0] = c / a0;
        b[1] = -b[0];
        a[1] = (1.0f - c) / a0;
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HPF1)
};

#endif //EQFILTERS_H_INCLUDED
