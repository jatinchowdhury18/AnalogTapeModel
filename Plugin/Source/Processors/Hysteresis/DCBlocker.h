#ifndef DCBLOCKER_H_INCLUDED
#define DCBLOCKER_H_INCLUDED

#include "../IIRFilter.h"
#include <JuceHeader.h>

/** DC blocking filter */
class DCBlocker
{
public:
    DCBlocker() = default;

    /** Prepare the DC blocker to process samples
      *
      * @param dcFreq: the cutoff frequency of the highpass filter.
      */
    void prepare (double sampleRate, float dcFreq)
    {
        hpf[0].reset();
        hpf[1].reset();

        fs = (float) sampleRate;

        calcCoefs (dcFreq);
    }

    void calcCoefs (float fc)
    {
        // Q values for 4th-order Butterworth filter
        // (https://en.wikipedia.org/wiki/Butterworth_filter#Normalized_Butterworth_polynomials)
        constexpr float Qs[] = { 1.0f / 0.7654f, 1.0f / 1.8478f };

        float wc = MathConstants<float>::twoPi * fc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float phi = c * c;

        float b[3], a[3];
        for (int i = 0; i < 2; ++i)
        {
            float K = c / Qs[i];
            float a0 = phi + K + 1.0f;

            b[0] = phi / a0;
            b[1] = -2.0f * b[0];
            b[2] = b[0];
            a[1] = 2.0f * (1.0f - phi) / a0;
            a[2] = (phi - K + 1.0f) / a0;

            hpf[i].setCoefs (b, a);
        }
    }

    void processBlock (float* buffer, const int numSamples)
    {
        hpf[0].processBlock (buffer, numSamples);
        hpf[1].processBlock (buffer, numSamples);
    }

private:
    chowdsp::IIRFilter<2> hpf[2];

    float fs = 44100.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DCBlocker)
};

#endif // DCBLOCKER_H_INCLUDED
