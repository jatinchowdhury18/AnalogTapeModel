#include "MainControls.h"
#include "../PluginEditor.h"

MainControls::MainControls (ChowtapeModelAudioProcessor& proc) :
    processor (proc)
{
    ChowtapeModelAudioProcessorEditor::createSlider (gainInKnob,  proc.getVTS(), "ingain",  gainInAttach,  *this, myLNF, " dB");
    ChowtapeModelAudioProcessorEditor::createSlider (gainOutKnob, proc.getVTS(), "outgain", gainOutAttach, *this, myLNF, " dB");
    ChowtapeModelAudioProcessorEditor::createComboBox (oversampling, proc.getVTS(), "os", osAttach, this, StringArray ({"2x", "4x", "8x", "16x"}));
    ChowtapeModelAudioProcessorEditor::createButton (prePostEQButton, proc.getVTS(), "prepost", prePostAttach, this, "ON/OFF",
                                                     Colours::darkred.withMultipliedBrightness (1.2f));

    // ChowtapeModelAudioProcessorEditor::createComboBox (oversampling, processor.overSampling, this);
    // ChowtapeModelAudioProcessorEditor::createComboBox (tapeSpeed, processor.tapeSpeed, this);
    // //ChowtapeModelAudioProcessorEditor::createComboBox (tapeType, processor.tapeType, this);
    // oversampling.setEnabled (false);

    ChowtapeModelAudioProcessorEditor::createLabel (inGainLabel, gainInKnob.getName(), this);
    ChowtapeModelAudioProcessorEditor::createLabel (outGainLabel, gainOutKnob.getName(), this);
    ChowtapeModelAudioProcessorEditor::createLabel (oversampleLabel, oversampling.getName(), this);
    ChowtapeModelAudioProcessorEditor::createLabel (prePostEQLabel, prePostEQButton.getName(), this);

    // ChowtapeModelAudioProcessorEditor::createLabel (speedLabel, processor.tapeSpeed, this);
    // //ChowtapeModelAudioProcessorEditor::createLabel (typeLabel, processor.tapeType, this);
}

void MainControls::paint (Graphics&) {}

void MainControls::resized()
{
    inGainLabel.setBounds (0, labelY, sliderWidth, labelHeight);
    gainInKnob.setBounds (0, sliderY, sliderWidth, sliderWidth);

    oversampleLabel.setBounds (gainInKnob.getRight() - 7 * xOffset, 2 * labelY + yOffset, tapeWidth, labelHeight);
    oversampling.setBounds (gainInKnob.getRight(), oversampleLabel.getBottom(), overWidth, boxHeight);

    prePostEQLabel.setBounds (oversampleLabel.getX(), oversampling.getBottom() + 5, tapeWidth, labelHeight);
    prePostEQButton.setBounds (prePostEQLabel.getX() + 15, prePostEQLabel.getBottom() + 3, overWidth * 4 / 5, boxHeight);

    // speedLabel.setBounds (oversampling.getRight(), 2 * labelY + yOffset, tapeWidth, labelHeight);
    // tapeSpeed.setBounds (oversampling.getRight() + 2 * xOffset, speedLabel.getBottom(), tapeWidth, boxHeight);
    // 
    // typeLabel.setBounds (gainInKnob.getRight(), oversampling.getBottom() + yOffset, typeWidth, labelHeight);
    // tapeType.setBounds (gainInKnob.getRight(), typeLabel.getBottom(), typeWidth, boxHeight);

    outGainLabel.setBounds (getWidth() - sliderWidth, labelY, sliderWidth, labelHeight);
    gainOutKnob.setBounds  (getWidth() - sliderWidth, sliderY, sliderWidth, sliderWidth);
}
