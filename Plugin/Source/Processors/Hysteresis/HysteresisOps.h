#pragma once

#include <JuceHeader.h>
#include <cmath>

#define HYSTERESIS_USE_SIMD 1

namespace HysteresisOps
{
using namespace chowdsp::SIMDUtils;

/** SIMD implementation of std::tanh */
template <typename T>
inline juce::dsp::SIMDRegister<T> tanhSIMD (juce::dsp::SIMDRegister<T> x)
{
    using x_type = xsimd::batch<T>;
    return (juce::dsp::SIMDRegister<T>) xsimd::tanh ((x_type) x.value);
}

/** Signum function to determine the sign of the input. */
template <typename T>
inline juce::dsp::SIMDRegister<T> signumSIMD (juce::dsp::SIMDRegister<T> val)
{
    auto positive = juce::dsp::SIMDRegister<T> ((T) 1) & juce::dsp::SIMDRegister<T>::lessThan (juce::dsp::SIMDRegister<T> ((T) 0), val);
    auto negative = juce::dsp::SIMDRegister<T> ((T) 1) & juce::dsp::SIMDRegister<T>::lessThan (val, juce::dsp::SIMDRegister<T> ((T) 0));
    return positive - negative;
}

/** SIMD implementation of std::isnan */
template <typename T>
inline typename juce::dsp::SIMDRegister<T>::vMaskType isnanSIMD (juce::dsp::SIMDRegister<T> x)
{
    using x_type = xsimd::batch<T>;

    // For some reason, xsimd::isnan returns a batch of doubles when using SSE
    // but returns a batch of unsigned ints when using ARM NEON.
#if JUCE_ARM
    return (chowdsp::SampleTypeHelpers::vMaskTypeSIMD<T>) xsimd::isnan ((x_type) x.value);
#else
    using Vec = juce::dsp::SIMDRegister<T>;
    return Vec::notEqual ((Vec) xsimd::isnan ((x_type) x.value), (Vec) 0);
#endif
}

/**
JUCE doesn't implement the divide operator for
SIMDRegister, so here's a simple implementation.
Based on: https://forum.juce.com/t/divide-by-simdregister/28968/18
*/

#if defined(__i386__) || defined(__amd64__) || defined(_M_X64) || defined(_X86_) || defined(_M_IX86)
/** Divides another SIMDRegister to the receiver. */
inline juce::dsp::SIMDRegister<double> operator/ (const juce::dsp::SIMDRegister<double>& l, const juce::dsp::SIMDRegister<double>& r)
{
    return _mm_div_pd (l.value, r.value);
}

#elif defined(_M_ARM64) || defined(__arm64__) || defined(__aarch64__)
/** Divides another SIMDRegister to the receiver. */
inline juce::dsp::SIMDRegister<double> operator/ (const juce::dsp::SIMDRegister<double>& l, const juce::dsp::SIMDRegister<double>& r)
{
    return vdivq_f64 (l.value, r.value);
}

#else
JUCE_COMPILER_WARNING ("SIMD divide not implemented for this platform... using non-vectorized implementation")
#endif

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
    dsp::SIMDRegister<double> Q, M_diff, L_prime, kap1, f1Denom, f1, f2, f3;
    dsp::SIMDRegister<double> coth = 0.0;
    dsp::SIMDRegister<double>::vMaskType nearZero;
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
    auto notNearZero = ~nearZero;
    return ((coth - ((Float) 1.0 / x)) & notNearZero) + ((x / 3.0) & nearZero);
#else
    return ! nearZero ? (coth) - (1.0 / x) : x / 3.0;
#endif
}

/** Derivative of Langevin function */
template <typename Float, typename Bool>
static inline Float langevinD (Float x, Float coth, Bool nearZero) noexcept
{
#if HYSTERESIS_USE_SIMD
    auto notNearZero = ~nearZero;
    return ((((Float) 1.0 / (x * x)) - (coth * coth) + 1.0) & notNearZero) + ((Float) ONE_THIRD & nearZero);
#else
    return ! nearZero ? (1.0 / (x * x)) - (coth * coth) + 1.0 : ONE_THIRD;
#endif
}

/** 2nd derivative of Langevin function */
template <typename Float, typename Bool>
static inline Float langevinD2 (Float x, Float coth, Bool nearZero) noexcept
{
#if HYSTERESIS_USE_SIMD
    auto notNearZero = ~nearZero;
    return (((Float) 2.0 * coth * (coth * coth - 1.0) - ((Float) 2.0 / (x * x * x))) & notNearZero)
           + ((x * NEG_TWO_OVER_15) & nearZero);
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
    hp.Q = (H + M * hp.alpha) * (1.0 / hp.a);

#if HYSTERESIS_USE_SIMD
    hp.coth = (Float) 1.0 / tanhSIMD (hp.Q);
    hp.nearZero = Float::lessThan (hp.Q, (Float) 0.001) & Float::greaterThan (hp.Q, (Float) -0.001);
#else
    hp.coth = 1.0 / std::tanh (hp.Q);
    hp.nearZero = hp.Q < 0.001 && hp.Q > -0.001;
#endif

    hp.M_diff = langevin (hp.Q, hp.coth, hp.nearZero) * hp.M_s - M;

#if HYSTERESIS_USE_SIMD
    const auto delta = ((Float) 1.0 & Float::greaterThanOrEqual (H_d, (Float) 0.0)) - ((Float) 1.0 & Float::lessThan (H_d, (Float) 0.0));
    const auto delta_M = Float::equal (signumSIMD (delta), signumSIMD (hp.M_diff));
    hp.kap1 = (Float) hp.nc & delta_M;
#else
    const auto delta = (Float) ((H_d >= 0.0) - (H_d < 0.0));
    const auto delta_M = (Float) (sign (delta) == sign (hp.M_diff));
    hp.kap1 = (Float) hp.nc * delta_M;
#endif

    hp.L_prime = langevinD (hp.Q, hp.coth, hp.nearZero);

    hp.f1Denom = ((Float) hp.nc * delta) * hp.k - (Float) hp.alpha * hp.M_diff;
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

    const Float f1_p = hp.kap1 * ((M_diff2 / hp.f1Denom) + hp.M_diff * hp.alpha * M_diff2 / (hp.f1Denom * hp.f1Denom));
    const Float f2_p = L_prime2 * hp.M_s_oaSq_tc_talpha;
    const Float f3_p = L_prime2 * (-hp.M_s_oaSq_tc_talphaSq);

    return H_d * (f1_p + f2_p) / hp.f3 - dMdt * f3_p / hp.f3;
}

} // namespace HysteresisOps
