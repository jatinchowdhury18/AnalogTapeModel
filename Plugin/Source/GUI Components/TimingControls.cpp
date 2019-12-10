#include "TimingControls.h"
#include "../PluginEditor.h"

TimingControls::TimingControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    auto createSliderAndLabel = [=, &proc] (FullSlider& slider, String id)
    {
        ChowtapeModelAudioProcessorEditor::createSlider (slider.slider, proc.getVTS(), id, slider.attach, *this, myLNF);
        ChowtapeModelAudioProcessorEditor::createLabel (slider.label, slider.slider.getName(), this);
    };

    createSliderAndLabel (depthSlide, "depth");
    createSliderAndLabel (rateSlide,  "rate");
}

void TimingControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Flutter Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
        Justification::centredLeft, 1);
}

void TimingControls::resized()
{
    rateSlide.label.setBounds  (0, 2 * yOffset + labelY,  sliderWidth, labelHeight);
    rateSlide.slider.setBounds (0, 2 * yOffset + sliderY, sliderWidth, sliderWidth);

    depthSlide.label.setBounds  (rateSlide.slider.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    depthSlide.slider.setBounds (rateSlide.slider.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);
}
