#include "LossControls.h"
#include "../PluginEditor.h"

LossControls::LossControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    ChowtapeModelAudioProcessorEditor::createSlider (spacingSlider, processor.tapeSpacing, myLNF, this, String ("um"));
    ChowtapeModelAudioProcessorEditor::createSlider (thicknessSlider, processor.tapeThickness, myLNF, this, String ("um"));
    ChowtapeModelAudioProcessorEditor::createSlider (gapSlider, processor.gapWidth, myLNF, this, String ("um"));

    ChowtapeModelAudioProcessorEditor::createLabel (spacingLabel, processor.tapeSpacing, this);
    ChowtapeModelAudioProcessorEditor::createLabel (thicknessLabel, processor.tapeThickness, this);
    ChowtapeModelAudioProcessorEditor::createLabel (gapLabel, processor.gapWidth, this);
}

void LossControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Loss Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
                      Justification::centredLeft, 1);
}

void LossControls::resized()
{
    spacingLabel.setBounds (0, 2 * yOffset + labelY, sliderWidth, labelHeight);
    spacingSlider.setBounds (0, 2 * yOffset + sliderY, sliderWidth, sliderWidth);

    thicknessLabel.setBounds (spacingSlider.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    thicknessSlider.setBounds (spacingSlider.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);

    gapLabel.setBounds (thicknessSlider.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    gapSlider.setBounds (thicknessSlider.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);
}

void LossControls::sliderValueChanged (Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        *param = (float) slider->getValue();
}

void LossControls::sliderDragStarted(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->beginChangeGesture();
}

void LossControls::sliderDragEnded(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->endChangeGesture();
}
