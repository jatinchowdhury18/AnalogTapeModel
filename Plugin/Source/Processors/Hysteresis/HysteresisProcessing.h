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
    void setSampleRate (double newSR);

    void cook (float drive, float width, float sat, bool v1);
    void setSolver (SolverType solverType);

    /* Process a single sample */
    inline double process (double H) noexcept
    {
        double H_d = deriv (H, H_n1, H_d_n1);
        double M = (this->*solver) (H, H_d);

        if (std::isnan (M) || M > upperLim)
        {
            M = 0.0;
        }

        M_n1 = M;
        H_n1 = H;
        H_d_n1 = H_d;

        return M;
    }

private:
    inline double langevin (double x) const noexcept;    // Langevin function
    inline double langevinD (double x) const noexcept;   // Derivative of Langevin function
    inline double langevinD2 (double x) const noexcept;  // 2nd derivative of Langevin function
    inline double deriv (double x_n, double x_n1, double x_d_n1) const noexcept // Derivative by alpha transform
    {
        constexpr double dAlpha = 0.9;
        return (((1.0 + dAlpha) / T) * (x_n - x_n1)) - dAlpha * x_d_n1;
    }

    // hysteresis function dM/dt
    inline double hysteresisFunc (double M, double H, double H_d) noexcept;

    // derivative of hysteresis func w.r.t M (depends on cached values from computing hysteresisFunc)
    inline double hysteresisFuncPrime (double H_d, double dMdt) noexcept;

    // runge-kutta solvers
    inline double RK2 (double H, double H_d) noexcept;
    inline double RK4 (double H, double H_d) noexcept;

    // newton-raphson solvers
    inline double NR (double H, double H_d) noexcept;
    int numIter = 0;

    // solver function pointer
    using Solver = double (HysteresisProcessing::*) (double, double);
    Solver solver = &HysteresisProcessing::NR;

    // parameter values
    double fs = 48000.0;
    double T = 1.0 / fs;
    double Talpha = T / 1.9;
    double M_s = 1.0;
    double a = M_s / 4.0;
    const double alpha = 1.6e-3;
    double k = 0.47875;
    double c = 1.7e-1;
    double upperLim = 20.0;

    // Save calculations
    double nc = 1-c;
    double M_s_oa = M_s / a;
    double M_s_oa_talpha = alpha * M_s / a;
    double M_s_oa_tc = c * M_s / a;
    double M_s_oa_tc_talpha = alpha * c * M_s / a;
    double M_s_oaSq_tc_talpha = alpha * c * M_s / (a * a);
    double M_s_oaSq_tc_talphaSq = alpha * alpha * c * M_s / (a * a);

    // state variables
    double M_n1 = 0.0;
    double H_n1 = 0.0;
    double H_d_n1 = 0.0;

    // temp vars
    double Q, M_diff, delta, delta_M, L_prime, kap1, f1Denom, f1, f2, f3;
    double coth = 0.0;
    bool nearZero = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessing)
};

#endif
