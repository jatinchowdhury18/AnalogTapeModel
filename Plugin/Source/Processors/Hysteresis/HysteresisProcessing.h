#ifndef HYSTERESISPROCESSING_H_INCLUDED
#define HYSTERESISPROCESSING_H_INCLUDED

#include "JuceHeader.h"

enum SolverType
{
    RK2 = 0,
    RK4,
    NR5,
    NR10,
};

/*
    Hysteresis processing for a model of an analog tape machine.
    For more information on the DSP happening here, see:
    https://ccrma.stanford.edu/~jatin/420/tape/TapeModel_DAFx.pdf
*/
class HysteresisProcessing
{
public:
    HysteresisProcessing();

    void reset();
    void setSampleRate (float newSR);

    void cook (float drive,  float width, float sat);
    void setSolver (SolverType solverType);

    /* Process a single sample */
    inline float process (float H) noexcept
    {
        float H_d = deriv (H, H_n1, H_d_n1);
        float M = (*this.*solver) (H, H_d);

        if (std::isnan (M) || abs (M) > 20.0f)
        {
            M = 0.0f;
        }

        M_n1 = M;
        H_n1 = H;
        H_d_n1 = H_d;

        return M;
    }

private:
    /* DEPRECATED (Continued fraction approximation for hyperbolic cotangent) */
    inline float cothApprox (float x) const noexcept;

    inline float langevin (float x) const noexcept;    // Langevin function
    inline float langevinD (float x) const noexcept;   // Derivative of Langevin function
    inline float langevinD2 (float x) const noexcept;  // 2nd derivative of Langevin function
    inline float deriv (float x_n, float x_n1, float x_d_n1) const noexcept // Derivative by alpha transform
    {
        constexpr float dAlpha = 0.9f;
        return (((1.0f + dAlpha) / T) * (x_n - x_n1)) - dAlpha * x_d_n1;
    }

    // hysteresis function dM/dt
    inline float hysteresisFunc (float M, float H, float H_d) noexcept;

    // derivative of hysteresis func w.r.t M (depends on cached values from computing hysteresisFunc)
    inline float hysteresisFuncPrime (float H_d, float dMdt) noexcept;

    // runge-kutta solvers
    inline float RK2 (float H, float H_d) noexcept;
    inline float RK4 (float H, float H_d) noexcept;

    // newton-raphson solvers
    inline float NR (float H, float H_d) noexcept;
    int numIter = 0;

    float (HysteresisProcessing::*solver) (float, float) = &HysteresisProcessing::NR;

    float fs = 48000.0f;
    float T = 1.0f / fs;
    float Talpha = T / 1.9f;
    float M_s = (float) 1;
    float a = M_s / 4.0f;
    const float alpha = (float) 1.6e-3;
    const float k = 0.47875f;
    float c = (float) 1.7e-1;

    // Save calculations
    float nc = 1-c;
    float M_s_oa = M_s / a;
    float M_s_oa_talpha = alpha * M_s / a;
    float M_s_oa_tc = c * M_s / a;
    float M_s_oa_tc_talpha = alpha * c * M_s / a;
    float M_s_oaSq_tc_talpha = alpha * c * M_s / (a * a);
    float M_s_oaSq_tc_talphaSq = alpha * alpha * c * M_s / (a * a);

    float M_n1 = 0.0f;
    float H_n1 = 0.0f;
    float H_d_n1 = 0.0f;

    // temp vars
    float Q, M_diff, delta, delta_M, L_prime, kap1, f1Denom, f1, f2, f3;

    float coth = 0.0f;
    bool nearZero = false;

    // JUCE_DECLARE_NONCOPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessing)
};

#endif
