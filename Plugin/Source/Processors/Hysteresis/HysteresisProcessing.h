#ifndef HYSTERESISPROCESSING_H_INCLUDED
#define HYSTERESISPROCESSING_H_INCLUDED

#include "JuceHeader.h"

/*
    Hysteresis processing for a model of a Sowter 3575f Transformer.
    For more information on the DSP happening here, see:
    https://ccrma.stanford.edu/~jatin/420/tape/TapeModel_DAFx.pdf
*/
class HysteresisProcessing
{
public:
    HysteresisProcessing();

    /* Process a single sample */
    float process (float H);

    void reset();
    void setSampleRate (float newSR) { fs = newSR; T = 1.0f / fs; twoFs = 2.0f * fs; }

    void cook (float drive,  float width, float sat);

private:
    /* Continued fraction approximation for hyperbolic cotangent */
    inline float cothApprox (float x);

    inline float langevin (float x);    // Langevin function
    inline float langevinD (float x);   // Derivative of Langevin function
    inline float deriv (float x_n, float x_n1, float x_d_n1);   // Derivative by trapezoidal rule

    inline float hysteresisFunc (float M, float H, float H_d);
    float M_n (float M_n1, float k1, float k2, float k3, float k4);

    float fs = 48000.0f;
    float T = 1.0f / fs;
    float M_s = (float) 1;
    float a = M_s / 4.0f;
    const float alpha = (float) 1.6e-3;
    const float k = 0.47875f;
    float c = (float) 1.7e-1;

    // Save calculations
    float twoFs = 2.0f * fs;
    float nc = 1-c;
    float M_s_oa = M_s / a;
    float M_s_oa_tc = c * M_s / a;
    float M_s_oa_tc_talpha = alpha * c * M_s / a;

    float M_n1 = 0.0f;
    float H_n1 = 0.0f;
    float H_d_n1 = 0.0f;

    // temp vars
    float Q, M_diff, delta, delta_M, L_prime;

    float coth = 0.0f;
    bool nearZero = false;

    // JUCE_DECLARE_NONCOPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessing)
};

#endif
