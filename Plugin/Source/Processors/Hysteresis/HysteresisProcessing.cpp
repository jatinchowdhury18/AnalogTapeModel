#include "HysteresisProcessing.h"
#include <math.h>

namespace
{
    constexpr double ONE_THIRD =  1.0 / 3.0;
    constexpr double NEG_TWO_OVER_15 = -2.0 / 15.0;
}

inline int sign (double x)
{
    return (x > 0.0) - (x < 0.0);
}

HysteresisProcessing::HysteresisProcessing()
{
}

void HysteresisProcessing::reset()
{
    M_n1 = 0.0;
    H_n1 = 0.0;
    H_d_n1 = 0.0;

    coth = 0.0;
    nearZero = false;
}

void HysteresisProcessing::setSampleRate (double newSR)
{ 
    fs = newSR;
    T = 1.0 / fs;
    Talpha = T / 1.9;
}

void HysteresisProcessing::cook (float drive, float width, float sat, bool v1)
{
    M_s = 0.5 + 1.5 * (1.0 - (double) sat);
    a = M_s / (0.01 + 6.0 * (double) drive);
    c = std::sqrt (1.0f - (double) width) - 0.01;
    k = 0.47875;
    upperLim = 20.0;

    if (v1)
    {
        k = 27.0e3;
        c = 1.7e-1;
        M_s *= 50000.0;
        a = M_s / (0.01 + 40.0 * (double) drive);
        upperLim = 100000.0;
    }

    nc = 1.0 - c;
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

inline double HysteresisProcessing::langevin (double x) const noexcept
{
    if (! nearZero)
        return (coth) - (1.0 / x);
    else
        return x / 3.0;
}

inline double HysteresisProcessing::langevinD (double x) const noexcept
{
    if (! nearZero)
        return (1.0 / (x * x)) - (coth * coth) + 1.0;
    else
        return ONE_THIRD;
}

inline double HysteresisProcessing::langevinD2 (double x) const noexcept
{
    if (! nearZero)
        return 2.0 * coth * (coth * coth - 1.0) - (2.0 / (x * x * x));
    else
        return NEG_TWO_OVER_15 * x;;
}

inline double HysteresisProcessing::hysteresisFunc (double M, double H, double H_d) noexcept
{
    Q = (H + alpha * M) / a;
    coth = 1.0 / std::tanh (Q);
    nearZero = Q < 0.001 && Q > -0.001;

    M_diff = M_s * langevin (Q) - M;

    delta = (double) ((H_d >= 0.0) - (H_d < 0.0));
    delta_M = (double) (sign (delta) == sign (M_diff));

    L_prime = langevinD (Q);

    kap1 = nc * delta_M;
    f1Denom = nc * delta * k - alpha * M_diff;
    f1 = kap1 * M_diff / f1Denom;
    f2 = M_s_oa_tc * L_prime;
    f3 = 1.0 - (M_s_oa_tc_talpha * L_prime);

    return H_d * (f1 + f2) / f3;
}

inline double HysteresisProcessing::hysteresisFuncPrime (double H_d, double dMdt) noexcept
{
    const double L_prime2 = langevinD2 (Q);
    const double M_diff2 = M_s_oa_talpha * L_prime - 1.0;

    const double f1_p = kap1 * ((M_diff2 / f1Denom) + M_diff * alpha * M_diff2 / (f1Denom * f1Denom));
    const double f2_p = M_s_oaSq_tc_talpha * L_prime2;
    const double f3_p = -M_s_oaSq_tc_talphaSq * L_prime2;

    return H_d * (f1_p + f2_p) / f3 - dMdt * f3_p / f3;
}

inline double HysteresisProcessing::RK2 (double H, double H_d) noexcept
{
    const double k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const double k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0), (H + H_n1) / 2.0, (H_d + H_d_n1) / 2.0);

    return M_n1 + k2;
}

double HysteresisProcessing::RK4 (double H, double H_d) noexcept
{
    const double H_1_2 = (H + H_n1) / 2.0;
    const double H_d_1_2 = (H_d + H_d_n1) / 2.0;

    const double k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const double k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0), H_1_2, H_d_1_2);
    const double k3 = T * hysteresisFunc (M_n1 + (k2 / 2.0), H_1_2, H_d_1_2);
    const double k4 = T * hysteresisFunc (M_n1 + k3, H, H_d);

    return M_n1 + k1 / 6.0 + k2 / 3.0 + k3 / 3.0 + k4 / 6.0;
}

inline double HysteresisProcessing::NR (double H, double H_d) noexcept
{
    double M = M_n1;
    const double last_dMdt = hysteresisFunc (M_n1, H_n1, H_d_n1);
    for (int n = 0; n < numIter; ++n)
    {
        const double dMdt = hysteresisFunc (M, H, H_d);
        const double dMdtPrime = hysteresisFuncPrime (H_d, dMdt);

        const double deltaNR = (M - M_n1 - Talpha * (dMdt + last_dMdt)) / (1.0 - Talpha * dMdtPrime);
        M -= deltaNR;
    }

    return M;
}
