#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "GUI Extras/MyLNF.h"

class ChowSlider : public Slider
{
public:
    ChowSlider() {}

    void setDefaultValue (const float value) { defaultValue = value; }

    void mouseDoubleClick (const MouseEvent&) override
    {
        setValue (defaultValue);
    }

private:
    float defaultValue = 0.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowSlider)
};

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

    void comboBoxChanged (ComboBox* box) override {}

private:
    AudioParameterFloat* getParamForSlider (Slider* slider);
    void sliderValueChanged (Slider* slider) override;
    void sliderDragStarted (Slider* slider) override;
    void sliderDragEnded (Slider* slider) override;

    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    ChowSlider gainInKnob;
    ChowSlider gainOutKnob;

    ComboBox oversampling;
    ComboBox tapeSpeed;

    void createSlider (ChowSlider& slide, AudioParameterFloat* param, String suffix = String(), float step = 0.1f);
    void createComboBox (ComboBox& box, AudioParameterChoice* choice);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessorEditor)
};
