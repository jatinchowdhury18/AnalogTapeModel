#ifndef BIASCONTROLS_H_INCLUDED
#define BIASCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

struct FullSlider
{
    Slider slider;
    Label label;
    std::unique_ptr<SliderAttachment> attach;
};

class HysteresisControls : public Component
{
public:
    HysteresisControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    FullSlider driveSlide;
    FullSlider satSlide;
    FullSlider widthSlide;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisControls)
};

#endif //BIASCONTROLS_H_INCLUDED
