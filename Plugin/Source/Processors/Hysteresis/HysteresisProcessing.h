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
    void setSolver (SolverType solverType);

    /* Process a single sample */
    template<SolverType solver>
    inline double process (double H) noexcept
    {
        double H_d = HysteresisOps::deriv (H, H_n1, H_d_n1, T);

        double M;
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
        bool illCondition = std::isnan (M) || M > upperLim;
        M = illCondition ? 0.0 : M;
        H_d = illCondition ? 0.0 : H_d;

        M_n1 = M;
        H_n1 = H;
        H_d_n1 = H_d;

        return M;
    }

private:
    // runge-kutta solvers
    inline double RK2Solver (double H, double H_d) noexcept
    {
        const double k1 = T * HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState);
        const double k2 = T * HysteresisOps::hysteresisFunc (M_n1 + (k1 / 2.0), (H + H_n1) / 2.0, (H_d + H_d_n1) / 2.0, hpState);

        return M_n1 + k2;
    }

    inline double RK4Solver (double H, double H_d) noexcept
    {
        const double H_1_2 = (H + H_n1) / 2.0;
        const double H_d_1_2 = (H_d + H_d_n1) / 2.0;

        const double k1 = T * HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState);
        const double k2 = T * HysteresisOps::hysteresisFunc (M_n1 + (k1 / 2.0), H_1_2, H_d_1_2, hpState);
        const double k3 = T * HysteresisOps::hysteresisFunc (M_n1 + (k2 / 2.0), H_1_2, H_d_1_2, hpState);
        const double k4 = T * HysteresisOps::hysteresisFunc (M_n1 + k3, H, H_d, hpState);

        return M_n1 + k1 / 6.0 + k2 / 3.0 + k3 / 3.0 + k4 / 6.0;
    }

    // newton-raphson solvers
    template<int nIterations>
    inline double NRSolver (double H, double H_d) noexcept
    {
        double M = M_n1;
        const double last_dMdt = HysteresisOps::hysteresisFunc (M_n1, H_n1, H_d_n1, hpState);

        double dMdt, dMdtPrime, deltaNR;
        for (int n = 0; n < nIterations; ++n)
        {
            dMdt = HysteresisOps::hysteresisFunc (M, H, H_d, hpState);
            dMdtPrime = HysteresisOps::hysteresisFuncPrime (H_d, dMdt, hpState);
            deltaNR = (M - M_n1 - Talpha * (dMdt + last_dMdt)) / (1.0 - Talpha * dMdtPrime);
            M -= deltaNR;
        }

        return M;
    }

    // state transition network solver
    inline double STNSolver (double H, double H_d) noexcept
    {
        double input alignas (16)[5] = { H, H_d, H_n1, H_d_n1, M_n1 };

        // scale derivatives
        input[1] *= HysteresisSTN::diffMakeup;
        input[3] *= HysteresisSTN::diffMakeup;
        FloatVectorOperations::multiply (input, 0.7071 / hpState.a, 4); // scale by drive param

        return hysteresisSTN.process (input) + M_n1;
    }
    HysteresisSTN hysteresisSTN;

    // parameter values
    double fs = 48000.0;
    double T = 1.0 / fs;
    double Talpha = T / 1.9;
    double upperLim = 20.0;

    // state variables
    double M_n1 = 0.0;
    double H_n1 = 0.0;
    double H_d_n1 = 0.0;

    HysteresisOps::HysteresisState hpState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessing)
};

#endif
