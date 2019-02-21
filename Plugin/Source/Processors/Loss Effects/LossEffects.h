#ifndef LOSSEFFECTS_H_INCLUDED
#define LOSSEFFECTS_H_INCLUDED

#include "JuceHeader.h"

namespace
{
    constexpr float inchesToMeters = 0.0254f;

    enum
    {
        order = 100,
    };
}

class LossEffects
{
public:
    LossEffects();

    void init (float sampleRate, float speed, float spacing, float thickness, float gap);
    float process (float in);

private:
    float h[order];
    float x[order];
    int xPtr = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossEffects)
};

#endif //LOSSEFFECTS_H_INCLUDED
