#include "HysteresisControls.h"
#include "../PluginEditor.h"

HysteresisControls::HysteresisControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    auto createSliderAnbdLabel = [=, &proc] (FullSlider& slider, String id)
    {
        ChowtapeModelAudioProcessorEditor::createSlider (slider.slider, proc.getVTS(), id, slider.attach, *this, myLNF);
        ChowtapeModelAudioProcessorEditor::createLabel (slider.label, slider.slider.getName(), this);
    };

    createSliderAnbdLabel (driveSlide, "drive");
    createSliderAnbdLabel (satSlide, "sat");
    createSliderAnbdLabel (widthSlide, "width");
}

void HysteresisControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Hysteresis Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
                       Justification::centredLeft, 1);
}

void HysteresisControls::resized()
{
    driveSlide.label.setBounds  (0, 2 * yOffset + labelY, sliderWidth, labelHeight);
    driveSlide.slider.setBounds (0, 2 * yOffset + sliderY, sliderWidth, sliderWidth);
    
    satSlide.label.setBounds  (driveSlide.slider.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    satSlide.slider.setBounds (driveSlide.slider.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);

    widthSlide.label.setBounds  (satSlide.slider.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    widthSlide.slider.setBounds (satSlide.slider.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);
}
