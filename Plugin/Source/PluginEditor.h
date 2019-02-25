#pragma once

#include "PluginProcessor.h"
#include "GUI Extras/MyLNF.h"
#include "GUI Extras/ChowSlider.h"
#include "GUI Components/BiasControls.h"
#include "GUI Components/MainControls.h"
#include "GUI Components/LossControls.h"
#include "GUI Components/TimingControls.h"

enum
{
    width = 375,
    sectionHeight = 150,
    height = 4 * sectionHeight,

    nameHeight = 20,

    xOffset = 2,
    yOffset = 5,

    labelY = 15,
    labelHeight = 20,

    sliderWidth = 110,
    sliderY = 25,

    overWidth = 65,
    tapeWidth = 90,
    typeWidth = 150,
    speedWidth = 150,
    boxHeight = 25,
};

class ChowtapeModelAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ChowtapeModelAudioProcessorEditor (ChowtapeModelAudioProcessor&);
    ~ChowtapeModelAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    static void createSlider (ChowSlider& slide, AudioParameterFloat* param, LookAndFeel& lnf,
                              Component* comp, String suffix = String(), float step = 0.1f);
    static void createComboBox (ComboBox& box, AudioParameterChoice* choice, Component* comp);
    static void createLabel (Label& label, AudioProcessorParameterWithID* param, Component* comp);

    static AudioParameterFloat* getParamForSlider (Slider* slider, ChowtapeModelAudioProcessor& proc);
    static AudioParameterChoice* getParamForBox (ComboBox* box, ChowtapeModelAudioProcessor& proc);

private: 
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    std::unique_ptr<MainControls> mainControls;
    std::unique_ptr<BiasControls> biasControls;
    std::unique_ptr<LossControls> lossControls;
    std::unique_ptr<TimingControls> timingControls;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessorEditor)
};
