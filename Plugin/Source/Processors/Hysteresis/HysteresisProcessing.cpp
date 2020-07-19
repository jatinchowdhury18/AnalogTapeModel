#include "HysteresisProcessing.h"
#include <math.h>

inline int sign (float x)
{
    return (x > 0.0f) - (x < 0.0f);
}

HysteresisProcessing::HysteresisProcessing()
{
}

void HysteresisProcessing::reset()
{
    M_n1 = 0.0f;
    H_n1 = 0.0f;
    H_d_n1 = 0.0f;

    coth = 0.0f;
    nearZero = false;
}

void HysteresisProcessing::setSampleRate (float newSR)
{ 
    fs = newSR;
    T = 1.0f / fs;
    Talpha = T / 1.9f;
}

void HysteresisProcessing::cook (float drive,  float width, float sat, bool v1)
{
    M_s = 0.5f + 1.5f * (1.0f - sat);
    a = M_s / (0.01f + 6.0f * drive);
    c = sqrtf (1.0f - width) - 0.01f;
    k = 0.47875f;

    if (v1)
    {
        k = (float) 27.0e3;
        c = (float) 1.7e-1;
        M_s *= 300000.0f;
        a = M_s / (0.01f + 25.0f * drive);
    }

    nc = 1.0f - c;
    M_s_oa = M_s / a;
    M_s_oa_talpha = alpha * M_s_oa;
    M_s_oa_tc = c * M_s_oa;
    M_s_oa_tc_talpha = alpha * M_s_oa_tc;
    M_s_oaSq_tc_talpha = M_s_oa_tc_talpha / a;
    M_s_oaSq_tc_talphaSq = alpha * M_s_oaSq_tc_talpha;
}

void HysteresisProcessing::setSolver (SolverType solverType)
{
    // defaults
    numIter = 0;
    solver = &HysteresisProcessing::NR;

    switch (solverType)
    {
    case SolverType::RK4:
        solver = &HysteresisProcessing::RK4;
        return;

    case SolverType::NR5:
        numIter = 5;
        return;

    case SolverType::NR10:
        numIter = 10;
        return;

    default: // RK2
        solver = &HysteresisProcessing::RK2;
    };
}

inline float HysteresisProcessing::cothApprox (float x) const noexcept
{
    const auto exp_2x = expf (2.0f * x); // expf_approx (2.0f * x);

    return (exp_2x + 1.0f) / (exp_2x - 1.0f);

    // const auto xSquare = x * x;

    // return (1.0f + (xSquare / (3.0f + (xSquare / (5.0f + (xSquare / (7.0f))))))) / x;
    // return (1.0f + (xSquare / (3.0f + (xSquare / (5.0f))))) / x;
    // return (1.0f + (xSquare / 3.0f)) / x;
}

inline float HysteresisProcessing::langevin (float x) const noexcept
{
    if (! nearZero)
        return (coth) - (1.0f / x);
    else
        return x / 3.0f;
}

inline float HysteresisProcessing::langevinD (float x) const noexcept
{
    if (! nearZero)
        return (1.0f / (x * x)) - (coth * coth) + 1.0f;
    else
        return 1.0f / 3.0f;
}

inline float HysteresisProcessing::langevinD2 (float x) const noexcept
{
    if (! nearZero)
        return 2.0f * coth * (coth * coth - 1) - (2.0f / (x * x * x));
    else
        return -2.0f * x / 15.0f;
}

inline float HysteresisProcessing::hysteresisFunc (float M, float H, float H_d) noexcept
{
    Q = (H + alpha * M) / a;
    coth = 1.0f / std::tanh (Q);
    nearZero = Q < 0.001f && Q > -0.001f;

    M_diff = M_s * langevin (Q) - M;

    delta = (float) ((H_d >= 0.0f) - (H_d < 0.0f));
    delta_M = (float) (sign (delta) == sign (M_diff));

    L_prime = langevinD (Q);

    kap1 = nc * delta_M;
    f1Denom = nc * delta * k - alpha * M_diff;
    f1 = kap1 * M_diff / f1Denom;
    f2 = M_s_oa_tc * L_prime;
    f3 = 1.0f - (M_s_oa_tc_talpha * L_prime);

    return H_d * (f1 + f2) / f3;
}

inline float HysteresisProcessing::hysteresisFuncPrime (float H_d, float dMdt) noexcept
{
    const float L_prime2 = langevinD2 (Q);
    const float M_diff2 = M_s_oa_talpha * L_prime - 1.0f;

    const float f1_p = kap1 * ((M_diff2 / f1Denom) + M_diff * alpha * M_diff2 / (f1Denom * f1Denom));
    const float f2_p = M_s_oaSq_tc_talpha * L_prime2;
    const float f3_p = -M_s_oaSq_tc_talphaSq * L_prime2;

    return H_d * (f1_p + f2_p) / f3 - dMdt * f3_p / f3;
}

inline float HysteresisProcessing::RK2 (float H, float H_d) noexcept
{
    const float k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const float k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0f), (H + H_n1) / 2.0f, (H_d + H_d_n1) / 2.0f);

    return M_n1 + k2;
}

float HysteresisProcessing::RK4 (float H, float H_d) noexcept
{
    const float H_1_2 = (H + H_n1) / 2.0f;
    const float H_d_1_2 = (H_d + H_d_n1) / 2.0f;

    const float k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const float k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0f), H_1_2, H_d_1_2);
    const float k3 = T * hysteresisFunc (M_n1 + (k2 / 2.0f), H_1_2, H_d_1_2);
    const float k4 = T * hysteresisFunc (M_n1 + k3, H, H_d);

    return M_n1 + k1 / 6.0f + k2 / 3.0f + k4 / 6.0f;
}

inline float HysteresisProcessing::NR (float H, float H_d) noexcept
{
    float M = M_n1;
    const float last_dMdt = hysteresisFunc (M_n1, H_n1, H_d_n1);
    for (int n = 0; n < numIter; ++n)
    {
        const float dMdt = hysteresisFunc (M, H, H_d);
        const float dMdtPrime = hysteresisFuncPrime (H_d, dMdt);

        const float deltaNR = (M - M_n1 - Talpha * (dMdt + last_dMdt)) / (1.0f - Talpha * dMdtPrime);
        M -= deltaNR;
    }

    return M;
}
