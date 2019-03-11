#ifndef LOSSCONTROLS_H_INCLUDED
#define LOSSCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

class LossControls : public Component,
                     public Slider::Listener
{
public:
    LossControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (Slider* slider) override;
    void sliderDragStarted (Slider* slider) override;
    void sliderDragEnded (Slider* slider) override;

    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    ChowSlider spacingSlider;
    ChowSlider thicknessSlider;
    ChowSlider gapSlider;

    Label spacingLabel;
    Label thicknessLabel;
    Label gapLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossControls)
};

#endif //LOSSCONTROLS_H_INCLUDED
