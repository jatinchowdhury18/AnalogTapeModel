#ifndef HYSTERESISSTN_H_INCLUDED
#define HYSTERESISSTN_H_INCLUDED

// #include "RTNeural/src/Model.h"
#include <JuceHeader.h>
#include <RTNeural/RTNeural.h>
#include "STNModel.h"

/**
 * Class that implements a "State Transition Network" for
 * solving a state space formulation of the hysteresis algorithm.
 *
 * For more information, see: Parker et. al., 2019 (http://dafx2019.bcu.ac.uk/papers/DAFx2019_paper_42.pdf)
 */
class HysteresisSTN
{
public:
    HysteresisSTN();

    static constexpr size_t inputSize = 5;
    static constexpr double diffMakeup = 1.0 / 6.0e4;

    void prepare (double sampleRate);
    void setParams (float saturation, float width);

    inline double process (const double* input) noexcept
    {
        return stnModels[widthIdx][satIdx].forward (input) * sampleRateCorr;
    }

    enum
    {
        numWidthModels = 11,
        numSatModels = 21
    };

private:
    STNSpace::STNModel stnModels[numWidthModels][numSatModels];
    double sampleRateCorr = 1.0;
    size_t widthIdx = 0;
    size_t satIdx = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisSTN)
};

#endif // HYSTERESISSTN_H_INCLUDED
