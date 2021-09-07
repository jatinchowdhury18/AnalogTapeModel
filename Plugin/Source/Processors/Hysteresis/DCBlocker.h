#ifndef DCBLOCKER_H_INCLUDED
#define DCBLOCKER_H_INCLUDED

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
        for (auto& filt : hpf)
            filt.reset();

        fs = (float) sampleRate;

        calcCoefs (dcFreq);
    }

    void calcCoefs (float fc)
    {
        const static auto butterQs = chowdsp::QValCalcs::butterworth_Qs<float, 2 * NFilt>();

        float wc = MathConstants<float>::twoPi * fc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float phi = c * c;

        float b[3];
        float a[3];
        for (int i = 0; i < NFilt; ++i)
        {
            float K = c / butterQs[i];
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
        for (auto& filt : hpf)
            filt.processBlock (buffer, numSamples);
    }

private:
    static constexpr int NFilt = 1;
    std::array<chowdsp::IIRFilter<2>, NFilt> hpf;

    float fs = 44100.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DCBlocker)
};

#endif // DCBLOCKER_H_INCLUDED
