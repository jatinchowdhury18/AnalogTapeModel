#include "LossControls.h"
#include "../PluginEditor.h"

LossControls::LossControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    std::function<String (double)> mmFunc = [] (double value) { return String (value * 1000.0f, 2, true) + " mm"; };

    auto createSliderAndLabel = [=, &proc] (FullSlider& slider, String id, String suffix= {}, std::function<String (double)> textFromValue = {})
    {
        ChowtapeModelAudioProcessorEditor::createSlider (slider.slider, proc.getVTS(), id, slider.attach, *this, myLNF, suffix, {}, textFromValue);
        ChowtapeModelAudioProcessorEditor::createLabel (slider.label, slider.slider.getName(), this);
    };

    createSliderAndLabel (speedSlider,     "speed",   " ips");
    createSliderAndLabel (spacingSlider,   "spacing", "", mmFunc);
    createSliderAndLabel (thicknessSlider, "thick",   "", mmFunc);
    createSliderAndLabel (gapSlider,       "gap",     "", mmFunc);
}

void LossControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Playhead Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
                      Justification::centredLeft, 1);
}

void LossControls::resized()
{
    const int smallSliderWidth = 90;

    spacingSlider.label.setBounds  (0, 2 * yOffset + labelY,  smallSliderWidth, labelHeight);
    spacingSlider.slider.setBounds (0, 2 * yOffset + sliderY, smallSliderWidth, sliderWidth);

    thicknessSlider.label.setBounds  (spacingSlider.slider.getRight(), 2 * yOffset + labelY,  smallSliderWidth, labelHeight);
    thicknessSlider.slider.setBounds (spacingSlider.slider.getRight(), 2 * yOffset + sliderY, smallSliderWidth, sliderWidth);

    gapSlider.label.setBounds  (thicknessSlider.slider.getRight(), 2 * yOffset + labelY,  smallSliderWidth, labelHeight);
    gapSlider.slider.setBounds (thicknessSlider.slider.getRight(), 2 * yOffset + sliderY, smallSliderWidth, sliderWidth);

    speedSlider.label.setBounds  (gapSlider.slider.getRight(), 2 * yOffset + labelY,  smallSliderWidth, labelHeight);
    speedSlider.slider.setBounds (gapSlider.slider.getRight(), 2 * yOffset + sliderY, smallSliderWidth, sliderWidth);
}
