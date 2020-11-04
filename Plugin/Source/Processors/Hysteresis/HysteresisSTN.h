#ifndef HYSTERESISSTN_H_INCLUDED
#define HYSTERESISSTN_H_INCLUDED

#include <JuceHeader.h>
#include "RTNeural//src/Model.h"

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

    void prepare (double sampleRate);
    void setParams (float drive, float saturation, float width);
    
    inline double process (std::array<double, 6> input) const noexcept
    {
        constexpr double diffMakeup = 1.0 / 6.0e4;

        input[0] *= driveValue;
        input[1] *= diffMakeup;
        input[2] *= driveValue;
        input[3] *= diffMakeup;
        input[4]  = driveValue;

        return stnModels[widthIdx][satIdx]->forward(input.data());
    }

    enum
    {
        numWidthModels = 11,
        numSatModels = 21,
    };

private:
    std::unique_ptr<MLUtils::Model<double>> stnModels[numWidthModels][numSatModels];
    double sampleRateCorr = 1.0;
    double driveValue = 0.0f;
    size_t widthIdx = 0;
    size_t satIdx = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisSTN)
};

#endif // HYSTERESISSTN_H_INCLUDED
