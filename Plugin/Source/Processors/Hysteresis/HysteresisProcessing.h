#ifndef HYSTERESISPROCESSING_H_INCLUDED
#define HYSTERESISPROCESSING_H_INCLUDED

#include "HysteresisOps.h"
#include "HysteresisSTN.h"

enum SolverType
{
    RK2 = 0,
    RK4,
    NR4,
    NR8,
    STN,
    NUM_SOLVERS
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
    void setSampleRate (double newSR);

    void cook (float drive, float width, float sat, bool v1);

    /* Process a single sample */
    template <SolverType solver, typename Float>
    inline Float process (Float H) noexcept
    {
        auto H_d = HysteresisOps::deriv (H, H_n1, H_d_n1, (Float) T);

        Float M;
        switch (solver)
        {
            case RK2:
                M = RK2Solver (H, H_d);
                break;
            case RK4:
                M = RK4Solver (H, H_d);
                break;
            case NR4:
                M = NRSolver<4> (H, H_d);
                break;
            case NR8:
                M = NRSolver<8> (H, H_d);
                break;
            case STN:
                M = STNSolver (H, H_d);
                break;

            default:
                M = 0.0;
        };

                // check for instability
#if HYSTERESIS_USE_SIMD
        auto notIllCondition = ~(chowdsp::SIMDUtils::isnanSIMD (M) | Float::greaterThan (M, (Float) upperLim));
        M = M & notIllCondition;
        H_d = H_d & notIllCondition;
#else
        bool illCondition = std::isnan (M) || M > upperLim;
        M = illCondition ? 0.0 : M;
        H_d = illCondition ? 0.0 : H_d;
#endif

        M_n1 = M;
        H_n1 = H;
        H_d_n1 = H_d;

        return M;
    }

private:
    // runge-kutta solvers
    template <typename Float>
    inline Float RK2Solver (Float H, Float H_d) noexcept
    {
        const Float k1 = HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState) * T;
        const Float k2 = HysteresisOps::hysteresisFunc (M_n1 + (k1 * 0.5), (H + H_n1) * 0.5, (H_d + H_d_n1) * 0.5, hpState) * T;

        return M_n1 + k2;
    }

    template <typename Float>
    inline Float RK4Solver (Float H, Float H_d) noexcept
    {
        const Float H_1_2 = (H + H_n1) * 0.5;
        const Float H_d_1_2 = (H_d + H_d_n1) * 0.5;

        const Float k1 = HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState) * T;
        const Float k2 = HysteresisOps::hysteresisFunc (M_n1 + (k1 * 0.5), H_1_2, H_d_1_2, hpState) * T;
        const Float k3 = HysteresisOps::hysteresisFunc (M_n1 + (k2 * 0.5), H_1_2, H_d_1_2, hpState) * T;
        const Float k4 = HysteresisOps::hysteresisFunc (M_n1 + k3, H, H_d, hpState) * T;

        constexpr double oneSixth = 1.0 / 6.0;
        constexpr double oneThird = 1.0 / 3.0;
        return M_n1 + k1 * oneSixth + k2 * oneThird + k3 * oneThird + k4 * oneSixth;
    }

    // newton-raphson solvers
    template <int nIterations, typename Float>
    inline Float NRSolver (Float H, Float H_d) noexcept
    {
        using namespace chowdsp::SIMDUtils;

        Float M = M_n1;
        const Float last_dMdt = HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState);

        Float dMdt;
        Float dMdtPrime;
        Float deltaNR;
        for (int n = 0; n < nIterations; ++n)
        {
            dMdt = HysteresisOps::hysteresisFunc (M, H, H_d, hpState);
            dMdtPrime = HysteresisOps::hysteresisFuncPrime (H_d, dMdt, hpState);
            deltaNR = (M - M_n1 - (Float) Talpha * (dMdt + last_dMdt)) / (Float (1.0) - (Float) Talpha * dMdtPrime);
            M -= deltaNR;
        }

        return M;
    }

    // state transition network solver
    template <typename Float>
    inline Float STNSolver (Float H, Float H_d) noexcept
    {
#if HYSTERESIS_USE_SIMD
        double H_arr alignas (16)[2];
        double H_d_arr alignas (16)[2];
        double H_n1_arr alignas (16)[2];
        double H_d_n1_arr alignas (16)[2];
        double M_n1_arr alignas (16)[2];
        double M_out alignas (16)[2];

        H.copyToRawArray (H_arr);
        H_d.copyToRawArray (H_d_arr);
        H_n1.copyToRawArray (H_n1_arr);
        H_d_n1.copyToRawArray (H_d_n1_arr);
        M_n1.copyToRawArray (M_n1_arr);

        for (int ch = 0; ch < 2; ++ch)
        {
            double input alignas (16)[5] = { H_arr[ch], H_d_arr[ch], H_n1_arr[ch], H_d_n1_arr[ch], M_n1_arr[ch] };

            // scale derivatives
            input[1] *= HysteresisSTN::diffMakeup;
            input[3] *= HysteresisSTN::diffMakeup;
            FloatVectorOperations::multiply (input, 0.7071 / hpState.a, 4); // scale by drive param

            M_out[ch] = hysteresisSTN.process (input) + M_n1_arr[ch];
        }

        return Float::fromRawArray (M_out);

#else
        double input alignas (16)[5] = { H, H_d, H_n1, H_d_n1, M_n1 };

        // scale derivatives
        input[1] *= HysteresisSTN::diffMakeup;
        input[3] *= HysteresisSTN::diffMakeup;
        FloatVectorOperations::multiply (input, 0.7071 / hpState.a, 4); // scale by drive param

        return hysteresisSTN.process (input) + M_n1;
#endif
    }

    // parameter values
    double fs = 48000.0;
    double T = 1.0 / fs;
    double Talpha = T / 1.9;
    double upperLim = 20.0;

    // state variables
#if HYSTERESIS_USE_SIMD
    dsp::SIMDRegister<double> M_n1 = 0.0;
    dsp::SIMDRegister<double> H_n1 = 0.0;
    dsp::SIMDRegister<double> H_d_n1 = 0.0;
#else
    double M_n1 = 0.0;
    double H_n1 = 0.0;
    double H_d_n1 = 0.0;
#endif

    HysteresisSTN hysteresisSTN;
    HysteresisOps::HysteresisState hpState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessing)
};

#endif
