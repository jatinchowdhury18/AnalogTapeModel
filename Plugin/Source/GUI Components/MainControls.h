#ifndef MAINCONTROLS_H_INCLUDED
#define MAINCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;
using ComboBoxAttachment = AudioProcessorValueTreeState::ComboBoxAttachment;
using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

class MainControls : public Component
{
public:
    MainControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    Slider gainInKnob;
    Slider gainOutKnob;

    std::unique_ptr<SliderAttachment> gainInAttach;
    std::unique_ptr<SliderAttachment> gainOutAttach;

    ComboBox oversampling;
    std::unique_ptr<ComboBoxAttachment> osAttach;

    TextButton prePostEQButton;
    std::unique_ptr<ButtonAttachment> prePostAttach;

    // ComboBox tapeSpeed;
    // ComboBox tapeType;

    Label inGainLabel;
    Label outGainLabel;
    Label oversampleLabel;
    Label prePostEQLabel;
    // Label speedLabel;
    // Label typeLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainControls)
};

#endif //MAINCONTROLS_H_INCLUDED
