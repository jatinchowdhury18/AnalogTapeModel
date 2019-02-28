#include "MainControls.h"
#include "../PluginEditor.h"

MainControls::MainControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    ChowtapeModelAudioProcessorEditor::createSlider (gainInKnob, processor.inGain, myLNF, this, String ("dB"));
    ChowtapeModelAudioProcessorEditor::createSlider (gainOutKnob, processor.outGain, myLNF, this, String ("dB"));
    ChowtapeModelAudioProcessorEditor::createComboBox (oversampling, processor.overSampling, this);
    ChowtapeModelAudioProcessorEditor::createComboBox (tapeSpeed, processor.tapeSpeed, this);
    //ChowtapeModelAudioProcessorEditor::createComboBox (tapeType, processor.tapeType, this);
    oversampling.setEnabled (false);

    ChowtapeModelAudioProcessorEditor::createLabel (inGainLabel, processor.inGain, this);
    ChowtapeModelAudioProcessorEditor::createLabel (outGainLabel, processor.outGain, this);
    ChowtapeModelAudioProcessorEditor::createLabel (oversampleLabel, processor.overSampling, this);
    ChowtapeModelAudioProcessorEditor::createLabel (speedLabel, processor.tapeSpeed, this);
    //ChowtapeModelAudioProcessorEditor::createLabel (typeLabel, processor.tapeType, this);
}

void MainControls::paint (Graphics&) {}

void MainControls::resized()
{
    inGainLabel.setBounds (0, labelY, sliderWidth, labelHeight);
    gainInKnob.setBounds (0, sliderY, sliderWidth, sliderWidth);

    oversampleLabel.setBounds (gainInKnob.getRight() - 7 * xOffset, 2 * labelY + yOffset, tapeWidth, labelHeight);
    oversampling.setBounds (gainInKnob.getRight(), oversampleLabel.getBottom(), overWidth, boxHeight);

    speedLabel.setBounds (oversampling.getRight(), 2 * labelY + yOffset, tapeWidth, labelHeight);
    tapeSpeed.setBounds (oversampling.getRight() + 2 * xOffset, speedLabel.getBottom(), tapeWidth, boxHeight);

    typeLabel.setBounds (gainInKnob.getRight(), oversampling.getBottom() + yOffset, typeWidth, labelHeight);
    tapeType.setBounds (gainInKnob.getRight(), typeLabel.getBottom(), typeWidth, boxHeight);

    outGainLabel.setBounds (tapeSpeed.getRight(), labelY, sliderWidth, labelHeight);
    gainOutKnob.setBounds (tapeSpeed.getRight(), sliderY, sliderWidth, sliderWidth);
}

void MainControls::sliderValueChanged (Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        *param = (float) slider->getValue();
}

void MainControls::sliderDragStarted(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->beginChangeGesture();
}

void MainControls::sliderDragEnded(Slider* slider)
{
    if (AudioParameterFloat* param = ChowtapeModelAudioProcessorEditor::getParamForSlider (slider, processor))
        param->endChangeGesture();
}

void MainControls::comboBoxChanged (ComboBox* box)
{
    if (AudioParameterChoice* param = ChowtapeModelAudioProcessorEditor::getParamForBox (box, processor))
        *param = box->getSelectedItemIndex();
}
