#ifndef MAINCONTROLS_H_INCLUDED
#define MAINCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

class MainControls : public Component,
                     public Slider::Listener,
                     public ComboBox::Listener
{
public:
    MainControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    void comboBoxChanged (ComboBox* box) override;
    void sliderValueChanged (Slider* slider) override;
    void sliderDragStarted (Slider* slider) override;
    void sliderDragEnded (Slider* slider) override;

    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    ChowSlider gainInKnob;
    ChowSlider gainOutKnob;

    ComboBox oversampling;
    ComboBox tapeSpeed;
    ComboBox tapeType;

    Label inGainLabel;
    Label outGainLabel;
    Label oversampleLabel;
    Label speedLabel;
    Label typeLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainControls)
};

#endif //MAINCONTROLS_H_INCLUDED
