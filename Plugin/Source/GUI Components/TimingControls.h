#ifndef TIMINGCONTROLS_H_INCLUDED
#define TIMINGCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"
#include "HysteresisControls.h"

class TimingControls : public Component
{
public:
    TimingControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    FullSlider rateSlide;
    FullSlider depthSlide;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimingControls)
};

#endif //TIMINGCONTROLS_H_INCLUDED
