#include "Processors/Hysteresis/HysteresisProcessing.h"

class HysteresisOpsTest : public UnitTest
{
public:
    using Vec2 = dsp::SIMDRegister<double>;

    HysteresisOpsTest() : UnitTest ("HysteresisOpsTest")
    {
    }

    void testLangevin()
    {
#if HYSTERESIS_USE_SIMD
        double x[] = { 1.0, 2.0, 0.0, -1.0, -0.5 };
        for (auto x_val : x)
        {
            auto coth = 1.0 / std::tanh (x_val);

            auto near_zero = x_val < 0.001 && x_val > -0.001;
            auto near_zero_vec = Vec2::lessThan (x_val, (Vec2) 0.001) & Vec2::greaterThan (x_val, (Vec2) -0.001);

            auto double_val = ! near_zero ? (coth) - (1.0 / x_val) : x_val / 3.0;
            auto vec_val = HysteresisOps::langevin ((Vec2) x_val, (Vec2) coth, near_zero_vec).get (0);
            expectWithinAbsoluteError (double_val, vec_val, 1.0e-12);

            double_val = ! near_zero ? (1.0 / (x_val * x_val)) - (coth * coth) + 1.0 : (1.0 / 3.0);
            vec_val = HysteresisOps::langevinD ((Vec2) x_val, (Vec2) coth, near_zero_vec).get (0);
            expectWithinAbsoluteError (double_val, vec_val, 1.0e-12);

            double_val = ! near_zero ? 2.0 * coth * (coth * coth - 1.0) - (2.0 / (x_val * x_val * x_val)) : (-2.0 / 15.0) * x_val;
            vec_val = HysteresisOps::langevinD2 ((Vec2) x_val, (Vec2) coth, near_zero_vec).get (0);
            expectWithinAbsoluteError (double_val, vec_val, 1.0e-12);
        }
#endif
    }

    void testSignOps()
    {
#if HYSTERESIS_USE_SIMD
        auto testFunc = [=] (Vec2 H_d, Vec2 M_diff, Vec2 nc, double kap1_exp, double f1_exp) {
            const auto delta = ((Vec2) 1.0 & Vec2::greaterThanOrEqual (H_d, (Vec2) 0.0)) - ((Vec2) 1.0 & Vec2::lessThan (H_d, (Vec2) 0.0));
            const auto delta_M = Vec2::equal (chowdsp::signumSIMD (delta), chowdsp::signumSIMD (M_diff));

            auto kap1 = (Vec2) nc & delta_M;
            auto f1 = (Vec2) nc * delta;

            expectWithinAbsoluteError (kap1.get (0), kap1_exp, 1.0e-12);
            expectWithinAbsoluteError (f1.get (0), f1_exp, 1.0e-12);
        };

        testFunc (0.0, 0.0, 1.0, 0.0, 1.0);
        testFunc (0.5, 0.5, 1.0, 1.0, 1.0);
        testFunc (-0.5, 0.5, 1.0, 0.0, -1.0);
        testFunc (-0.5, -0.5, 1.0, 1.0, -1.0);
#endif
    }

    void testFullHysteresis()
    {
        double x[10] = { 1.0, 2.0, 0.0, -1.0, -0.5, -0.1, -0.0, 0.0000012, 0.25, 0.0 };
        double y[10] = { 0.000645624, 0.00145275, 0.000202604, -0.000795881, -0.000370124, -0.000108995, 1.76298e-05, -1.28477e-05, 0.000171267, 3.31988e-05 };

        HysteresisProcessing hProc;
        hProc.setSampleRate (48000.0);
        hProc.reset();
        hProc.cook (0.5, 0.5, 0.5, false);

#if HYSTERESIS_USE_SIMD
    for (int n = 0; n < 10; ++n)
    {
        x[n] = hProc.process<SolverType::NR4> ((Vec2) (x[n] * 0.001)).get (0);
        expectWithinAbsoluteError (x[n], y[n], 1.0e-6);
    }
#else
    for (int n = 0; n < 10; ++n)
        x[n] = hProc.process<SolverType::NR4> (x[n] * 0.001);
    
    std::copy(x, x + 10, std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
#endif
    }

    void runTest() override
    {
        beginTest ("Langevin Test");
        testLangevin();
        
        beginTest ("Sign Ops Test");
        testSignOps();

        beginTest ("Hysteresis Process Test");
        testFullHysteresis();
    }
};

static HysteresisOpsTest hysteresisOpsTest;
