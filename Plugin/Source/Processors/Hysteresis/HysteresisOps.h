#pragma once

#include <JuceHeader.h>
#include <cmath>

namespace HysteresisOps
{

struct HysteresisState
{
    // parameter values
    double M_s = 1.0;
    double a = M_s / 4.0;
    static constexpr double alpha = 1.6e-3;
    double k = 0.47875;
    double c = 1.7e-1;

    // Save calculations
    double nc = 1 - c;
    double M_s_oa = M_s / a;
    double M_s_oa_talpha = alpha * M_s / a;
    double M_s_oa_tc = c * M_s / a;
    double M_s_oa_tc_talpha = alpha * c * M_s / a;
    double M_s_oaSq_tc_talpha = alpha * c * M_s / (a * a);
    double M_s_oaSq_tc_talphaSq = alpha * alpha * c * M_s / (a * a);

    // temp vars
    double Q, M_diff, delta, delta_M, L_prime, kap1, f1Denom, f1, f2, f3;
    double coth = 0.0;
    bool nearZero = false;
};

constexpr double ONE_THIRD = 1.0 / 3.0;
constexpr double NEG_TWO_OVER_15 = -2.0 / 15.0;

constexpr inline int sign (double x)
{
    return (x > 0.0) - (x < 0.0);
}

/** Langevin function */
static inline double langevin (double x, double coth, bool nearZero) noexcept
{
    return ! nearZero ? (coth) - (1.0 / x) : x / 3.0;
}

/** Derivative of Langevin function */
static inline double langevinD (double x, double coth, bool nearZero) noexcept
{
    return ! nearZero ? (1.0 / (x * x)) - (coth * coth) + 1.0 : ONE_THIRD;
}

/** 2nd derivative of Langevin function */
static inline double langevinD2 (double x, double coth, bool nearZero) noexcept
{
    return ! nearZero
        ? 2.0 * coth * (coth * coth - 1.0) - (2.0 / (x * x * x))
        : NEG_TWO_OVER_15 * x;
}

/** Derivative by alpha transform */
static inline double deriv (double x_n, double x_n1, double x_d_n1, double T) noexcept
{
    constexpr double dAlpha = 0.75;
    return (((1.0 + dAlpha) / T) * (x_n - x_n1)) - dAlpha * x_d_n1;
}

/** hysteresis function dM/dt */
static inline double hysteresisFunc (double M, double H, double H_d, HysteresisState& hp) noexcept
{
    hp.Q = (H + hp.alpha * M) / hp.a;
    hp.coth = 1.0 / std::tanh (hp.Q);
    hp.nearZero = hp.Q < 0.001 && hp.Q > -0.001;

    hp.M_diff = hp.M_s * langevin (hp.Q, hp.coth, hp.nearZero) - M;

    hp.delta = (double) ((H_d >= 0.0) - (H_d < 0.0));
    hp.delta_M = (double) (sign (hp.delta) == sign (hp.M_diff));

    hp.L_prime = langevinD (hp.Q, hp.coth, hp.nearZero);

    hp.kap1 = hp.nc * hp.delta_M;
    hp.f1Denom = hp.nc * hp.delta * hp.k - hp.alpha * hp.M_diff;
    hp.f1 = hp.kap1 * hp.M_diff / hp.f1Denom;
    hp.f2 = hp.M_s_oa_tc * hp.L_prime;
    hp.f3 = 1.0 - (hp.M_s_oa_tc_talpha * hp.L_prime);

    return H_d * (hp.f1 + hp.f2) / hp.f3;
}

// derivative of hysteresis func w.r.t M (depends on cached values from computing hysteresisFunc)
static inline double hysteresisFuncPrime (double H_d, double dMdt, HysteresisState& hp) noexcept
{
    const double L_prime2 = langevinD2 (hp.Q, hp.coth, hp.nearZero);
    const double M_diff2 = hp.M_s_oa_talpha * hp.L_prime - 1.0;

    const double f1_p = hp.kap1 * ((M_diff2 / hp.f1Denom) + hp.M_diff * hp.alpha * M_diff2 / (hp.f1Denom * hp.f1Denom));
    const double f2_p = hp.M_s_oaSq_tc_talpha * L_prime2;
    const double f3_p = -hp.M_s_oaSq_tc_talphaSq * L_prime2;

    return H_d * (f1_p + f2_p) / hp.f3 - dMdt * f3_p / hp.f3;
}

} // namespace HysteresisOps
