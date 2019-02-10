#ifndef MYLNF_H_INCLUDED
#define MYLNF_H_INCLUDED

#include "JuceHeader.h"

class MyLNF : public LookAndFeel_V4
{
public:
    MyLNF()
    {
        setColour (ComboBox::outlineColourId, Colours::darkorange);
    }

    Font getTextButtonFont (TextButton& button, int buttonHeight) override
    {
        return LookAndFeel_V4::getTextButtonFont (button, buttonHeight).boldened();
    }

    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
    {
        auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        auto fill    = slider.isEnabled() ? slider.findColour (Slider::rotarySliderFillColourId) : Colours::grey;

        auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin (5.0f, radius * 0.1f);
        auto arcRadius = radius - lineW;

        g.setColour (outline);
        g.fillEllipse (Rectangle<float> (radius * 2.0f, radius * 2.0f).withCentre (bounds.getCentre()));

        g.setColour (fill);
        g.fillEllipse (Rectangle<float> (arcRadius * 2.0f, arcRadius * 2.0f).withCentre (bounds.getCentre()));

        Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - MathConstants<float>::halfPi),
                                 bounds.getCentreY() + arcRadius * std::sin (toAngle - MathConstants<float>::halfPi));
        g.setColour (slider.findColour (Slider::thumbColourId));
        g.drawLine (bounds.getCentreX(), bounds.getCentreY(), thumbPoint.x, thumbPoint.y, lineW);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyLNF)
};

#endif //MYLNF_H_INCLUDED
