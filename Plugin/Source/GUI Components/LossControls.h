#ifndef LOSSCONTROLS_H_INCLUDED
#define LOSSCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"
#include "HysteresisControls.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class LossControls : public Component
{
public:
    LossControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    FullSlider speedSlider;
    FullSlider spacingSlider;
    FullSlider thicknessSlider;
    FullSlider gapSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossControls)
};

#endif //LOSSCONTROLS_H_INCLUDED
