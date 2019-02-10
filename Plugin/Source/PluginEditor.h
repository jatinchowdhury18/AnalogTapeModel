#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ChowtapeModelAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Slider::Listener,
                                           public ComboBox::Listener
{
public:
    ChowtapeModelAudioProcessorEditor (ChowtapeModelAudioProcessor&);
    ~ChowtapeModelAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged (Slider* slider) override {}
    void comboBoxChanged (ComboBox* box) override {}

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ChowtapeModelAudioProcessor& processor;

    Slider gainInKnob;
    Slider gainOutKnob;

    ComboBox oversampling;
    ComboBox tapeSpeed;

    void createSlider(Slider& slide, AudioParameterFloat* param, float step = 0.1f);
    void createComboBox (ComboBox& box, AudioParameterChoice* choice);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessorEditor)
};
