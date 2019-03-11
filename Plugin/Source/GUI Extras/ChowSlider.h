#ifndef CHOWSLIDER_H_INCLUDED
#define CHOWSLIDER_H_INCLUDED

#include "JuceHeader.h"

class ChowSlider : public Slider
{
public:
    ChowSlider() {}

    void setDefaultValue (const float value) { defaultValue = value; }

    void mouseDoubleClick (const MouseEvent&) override
    {
        setValue (defaultValue);
    }

private:
    float defaultValue = 0.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowSlider)
};

#endif //CHOWSLIDER_H_INCLUDED
