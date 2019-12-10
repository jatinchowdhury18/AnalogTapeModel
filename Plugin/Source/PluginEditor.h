#pragma once

#include "PluginProcessor.h"
#include "GUI Extras/MyLNF.h"
#include "GUI Extras/ChowSlider.h"
#include "GUI Components/HysteresisControls.h"
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

    overWidth = 90,
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

    static void createSlider (Slider& slider, AudioProcessorValueTreeState& vts, String paramID,
                              std::unique_ptr<SliderAttachment>& attachment, Component& comp, LookAndFeel& myLNF,
                              String suffix =  "", std::function<void()> onValueChange = {},
                              std::function<String (double)> textFromValue = {}, std::function<double (String)> valueFromText = {});
    static void createComboBox (ComboBox& box, AudioProcessorValueTreeState& vts, String paramID,
                                std::unique_ptr<ComboBoxAttachment>& attachment, Component* comp, StringArray choices);
    static void createLabel (Label& label, String name, Component* comp);

private: 
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    std::unique_ptr<MainControls> mainControls;
    std::unique_ptr<HysteresisControls> biasControls;
    std::unique_ptr<LossControls> lossControls;
    std::unique_ptr<TimingControls> timingControls;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessorEditor)
};
