#ifndef BIASCONTROLS_H_INCLUDED
#define BIASCONTROLS_H_INCLUDED

#include "../PluginProcessor.h"
#include "../GUI Extras/ChowSlider.h"
#include "../GUI Extras/MyLNF.h"

class BiasControls : public Component,
                     public Slider::Listener
{
public:
    BiasControls (ChowtapeModelAudioProcessor& proc);

    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (Slider* slider) override;
    void sliderDragStarted (Slider* slider) override;
    void sliderDragEnded (Slider* slider) override;

    MyLNF myLNF;

    ChowtapeModelAudioProcessor& processor;

    ChowSlider biasFreqSlide;
    ChowSlider biasGainSlide;

    Label biasFreqLabel;
    Label biasGainLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BiasControls)
};

#endif //BIASCONTROLS_H_INCLUDED
