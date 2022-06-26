#pragma once

#include <JuceHeader.h>
#include <cmath>

#define HYSTERESIS_USE_SIMD 1

namespace HysteresisOps
{
using namespace chowdsp::SIMDUtils;

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
#if HYSTERESIS_USE_SIMD
    xsimd::batch<double> Q, M_diff, L_prime, kap1, f1Denom, f1, f2, f3;
    xsimd::batch<double> coth = 0.0;
    xsimd::batch_bool<double> nearZero;
#else
    double Q, M_diff, L_prime, kap1, f1Denom, f1, f2, f3;
    double coth = 0.0;
    bool nearZero = false;
#endif
};

constexpr double ONE_THIRD = 1.0 / 3.0;
constexpr double NEG_TWO_OVER_15 = -2.0 / 15.0;

constexpr inline int sign (double x)
{
    return int (x > 0.0) - int (x < 0.0);
}

/** Langevin function */
template <typename Float, typename Bool>
static inline Float langevin (Float x, Float coth, Bool nearZero) noexcept
{
#if HYSTERESIS_USE_SIMD
    return xsimd::select (nearZero, x / 3.0, coth - ((Float) 1.0 / x));
#else
    return ! nearZero ? (coth) - (1.0 / x) : x / 3.0;
#endif
}

/** Derivative of Langevin function */
template <typename Float, typename Bool>
static inline Float langevinD (Float x, Float coth, Bool nearZero) noexcept
{
#if HYSTERESIS_USE_SIMD
    return xsimd::select (nearZero, (Float) ONE_THIRD, ((Float) 1.0 / (x * x)) - (coth * coth) + 1.0);
#else
    return ! nearZero ? (1.0 / (x * x)) - (coth * coth) + 1.0 : ONE_THIRD;
#endif
}

/** 2nd derivative of Langevin function */
template <typename Float, typename Bool>
static inline Float langevinD2 (Float x, Float coth, Bool nearZero) noexcept
{
#if HYSTERESIS_USE_SIMD
    return xsimd::select (nearZero, x * NEG_TWO_OVER_15, (Float) 2.0 * coth * (coth * coth - 1.0) - ((Float) 2.0 / (x * x * x)));
#else
    return ! nearZero
               ? 2.0 * coth * (coth * coth - 1.0) - (2.0 / (x * x * x))
               : NEG_TWO_OVER_15 * x;
#endif
}

/** Derivative by alpha transform */
template <typename Float>
static inline Float deriv (Float x_n, Float x_n1, Float x_d_n1, Float T) noexcept
{
    const Float dAlpha = 0.75;
    return ((((Float) 1.0 + dAlpha) / T) * (x_n - x_n1)) - dAlpha * x_d_n1;
}

/** hysteresis function dM/dt */
template <typename Float>
static inline Float hysteresisFunc (Float M, Float H, Float H_d, HysteresisState& hp) noexcept
{
    hp.Q = (H + M * HysteresisState::alpha) * (1.0 / hp.a);

#if HYSTERESIS_USE_SIMD
    hp.coth = (Float) 1.0 / xsimd::tanh (hp.Q);
    hp.nearZero = (hp.Q < 0.001) && (hp.Q > -0.001);
#else
    hp.coth = 1.0 / std::tanh (hp.Q);
    hp.nearZero = hp.Q < 0.001 && hp.Q > -0.001;
#endif

    hp.M_diff = langevin (hp.Q, hp.coth, hp.nearZero) * hp.M_s - M;

#if HYSTERESIS_USE_SIMD
    const auto delta = xsimd::select (H_d >= 0.0, (Float) 1, (Float) -1);
    const auto delta_M = chowdsp::Math::sign (delta) == chowdsp::Math::sign (hp.M_diff);
    hp.kap1 = xsimd::select (delta_M, (Float) hp.nc, (Float) 0);
#else
    const auto delta = (Float) ((H_d >= 0.0) - (H_d < 0.0));
    const auto delta_M = (Float) (sign (delta) == sign (hp.M_diff));
    hp.kap1 = (Float) hp.nc * delta_M;
#endif

    hp.L_prime = langevinD (hp.Q, hp.coth, hp.nearZero);

    hp.f1Denom = ((Float) hp.nc * delta) * hp.k - (Float) HysteresisState::alpha * hp.M_diff;
    hp.f1 = hp.kap1 * hp.M_diff / hp.f1Denom;
    hp.f2 = hp.L_prime * hp.M_s_oa_tc;
    hp.f3 = (Float) 1.0 - (hp.L_prime * hp.M_s_oa_tc_talpha);

    return H_d * (hp.f1 + hp.f2) / hp.f3;
}

// derivative of hysteresis func w.r.t M (depends on cached values from computing hysteresisFunc)
template <typename Float>
static inline Float hysteresisFuncPrime (Float H_d, Float dMdt, HysteresisState& hp) noexcept
{
    const Float L_prime2 = langevinD2 (hp.Q, hp.coth, hp.nearZero);
    const Float M_diff2 = hp.L_prime * hp.M_s_oa_talpha - 1.0;

    const Float f1_p = hp.kap1 * ((M_diff2 / hp.f1Denom) + hp.M_diff * HysteresisState::alpha * M_diff2 / (hp.f1Denom * hp.f1Denom));
    const Float f2_p = L_prime2 * hp.M_s_oaSq_tc_talpha;
    const Float f3_p = L_prime2 * (-hp.M_s_oaSq_tc_talphaSq);

    return H_d * (f1_p + f2_p) / hp.f3 - dMdt * f3_p / hp.f3;
}

} // namespace HysteresisOps
