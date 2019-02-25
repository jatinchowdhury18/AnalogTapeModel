#include "TimingControls.h"
#include "../PluginEditor.h"

TimingControls::TimingControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    ChowtapeModelAudioProcessorEditor::createSlider (flutterDepthSlide, processor.flutterDepth, myLNF, this);
    flutterDepthSlide.setSkewFactorFromMidPoint (1.0);

    ChowtapeModelAudioProcessorEditor::createLabel (flutterDepthLabel, processor.flutterDepth, this);
}

void TimingControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Timing Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
        Justification::centredLeft, 1);
}

void TimingControls::resized()
{
    flutterDepthLabel.setBounds (0, 2 * yOffset + labelY, sliderWidth, labelHeight);
    flutterDepthSlide.setBounds (0, 2 * yOffset + sliderY, sliderWidth, sliderWidth);
}

void TimingControls::sliderValueChanged (Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        *param = (float) slider->getValue();
}

void TimingControls::sliderDragStarted(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->beginChangeGesture();
}

void TimingControls::sliderDragEnded(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->endChangeGesture();
}

