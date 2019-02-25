#ifndef TIMINGCONTROLS_H_INCLUDED
#define TIMINGCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

class TimingControls : public Component,
    public Slider::Listener
{
public:
    TimingControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (Slider* slider) override;
    void sliderDragStarted (Slider* slider) override;
    void sliderDragEnded (Slider* slider) override;

    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    ChowSlider flutterDepthSlide;
    Label flutterDepthLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimingControls)
};

#endif //TIMINGCONTROLS_H_INCLUDED
