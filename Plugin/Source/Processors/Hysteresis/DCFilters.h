#ifndef DCFILTERS_H_INCLUDED
#define DCFILTERS_H_INCLUDED

#include "JuceHeader.h"

/* High-pass filter to compensate for low frequency noise of transformer */
class TransformerHPF
{
public:
    TransformerHPF() {}

    void reset (double sampleRate)
    {
        for (int n = 0; n < 3; ++n)
            z[n] = 0.0f;

        fs = (float) sampleRate;
    }

    void calcCoefs (float fc, float Q)
    {
        float wc = MathConstants<float>::twoPi * fc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float phi = c * c;
        float K = c / Q;
        float a0 = phi + K + 1.0f;

        b[0] = phi / a0;
        b[1] = -2.0f * b[0];
        b[2] = b[0];
        a[1] = 2.0f * (1.0f - phi) / a0;
        a[2] = (phi - K + 1.0f) / a0;
    }

    void processBlock (float* buffer, const int numSamples)
    {
        for (int n = 0; n < numSamples; ++n)
            buffer[n] = processSample (buffer[n]);
    }

    inline float processSample (float x) noexcept
    {
        // direct form II transposed
        float y = z[1] + x * b[0];

        z[1] = z[2] + x*b[1] - y*a[1];
        z[2] = x*b[2] - y*a[2];

        return y;
    }

private:
    float a[3] = { 0.0f, 0.0f, 0.0f };
    float b[3] = { 1.0f, 0.0f, 0.0f };

    float z[3] = { 0.0f, 0.0f, 0.0f };

    float fs = 44100.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransformerHPF)
};

/* Low-shelf filter to compensate for low frequency noise of transformer 
class TransformerShelf
{
public:
TransformerShelf() {}

void reset (double sampleRate)
{
for (int n = 0; n < 3; ++n)
z[n] = 0.0f;

fs = (float) sampleRate;
}

void calcCoefs (float fc, float Q, float gain)
{
float A = sqrtf (gain);
float wc = MathConstants<float>::twoPi * fc / fs;
float wS = dsp::FastMathApproximations::sin (wc);
float wC = dsp::FastMathApproximations::cos (wc);
float beta = sqrtf (A) / Q;

float a0 = ((A+1.0f) + ((A-1.0f) * wC) + (beta*wS));

b[0] = A*((A+1.0f) - ((A-1.0f)*wC) + (beta*wS)) / a0;
b[1] = 2.0f*A * ((A-1.0f) - ((A+1.0f)*wC)) / a0;
b[2] = A*((A+1.0f) - ((A-1.0f)*wC) - (beta*wS)) / a0;

a[1] = -2.0f * ((A-1.0f) + ((A+1.0f)*wC)) / a0;
a[2] = ((A+1.0f) + ((A-1.0f)*wC)-(beta*wS)) / a0;
}

inline float processSample (float x)
{
// direct form II transposed
float y = z[1] + x * b[0];

z[1] = z[2] + x*b[1] - y*a[1];
z[2] = x*b[2] - y*a[2];

return y;
}

private:
float a[3] = { 0.0f, 0.0f, 0.0f };
float b[3] = { 1.0f, 0.0f, 0.0f };

float z[3] = { 0.0f, 0.0f, 0.0f };

float fs = 44100.0f;

JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransformerShelf)
};
*/

#endif // DCFILTERS_H_INCLUDED
