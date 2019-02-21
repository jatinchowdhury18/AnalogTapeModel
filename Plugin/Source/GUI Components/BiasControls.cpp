#include "BiasControls.h"
#include "../PluginEditor.h"

BiasControls::BiasControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    ChowtapeModelAudioProcessorEditor::createSlider (biasFreqSlide, processor.biasFreq, myLNF, this, String ("kHz"), 1.0f);
    biasFreqSlide.setSkewFactorFromMidPoint (55.0);

    ChowtapeModelAudioProcessorEditor::createSlider (biasGainSlide, processor.biasGain, myLNF, this, String ("dB"));
    biasGainSlide.setSkewFactorFromMidPoint (14.0);

    ChowtapeModelAudioProcessorEditor::createLabel (biasFreqLabel, processor.biasFreq, this);
    ChowtapeModelAudioProcessorEditor::createLabel (biasGainLabel, processor.biasGain, this);
}

void BiasControls::paint (Graphics& g)
{
    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());

    g.drawFittedText ("Biasing Parameters:", Rectangle<int> (xOffset, yOffset, width, labelHeight),
                       Justification::centredLeft, 1);
}

void BiasControls::resized()
{
    biasFreqLabel.setBounds (0, 2 * yOffset + labelY, sliderWidth, labelHeight);
    biasFreqSlide.setBounds (0, 2 * yOffset + sliderY, sliderWidth, sliderWidth);
    
    biasGainLabel.setBounds (biasFreqSlide.getRight(), 2 * yOffset + labelY, sliderWidth, labelHeight);
    biasGainSlide.setBounds (biasFreqSlide.getRight(), 2 * yOffset + sliderY, sliderWidth, sliderWidth);
}

void BiasControls::sliderValueChanged (Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        *param = (float) slider->getValue();
}

void BiasControls::sliderDragStarted(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->beginChangeGesture();
}

void BiasControls::sliderDragEnded(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->endChangeGesture();
}
