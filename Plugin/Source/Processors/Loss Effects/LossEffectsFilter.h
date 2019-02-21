#ifndef LOSSEFFECTSFILTER_H_INCLUDED
#define LOSSEFFECTSFILTER_H_INCLUDED

#include "LossEffects.h"
#include "../ProcessorBase.h"

class LossEffectsFilter : public ProcessorBase
{
public:
    LossEffectsFilter() : ProcessorBase ("Loss Effects Filter") {}

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/) override;

    void setSpeed (String newSpeed);
    void setSpacing (float newSpacingMicrons);
    void setThickness (float newThicknessMicrons);
    void setGap (float newGapMicrons);

private:
    LossEffects lossProcessors[2];
    
    float speed = 15.0f;
    float spacing = (float) 1e-9;
    float gap = (float) 3e-6;
    float thickness = (float) 10e-6;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossEffectsFilter)
};

#endif //LOSSEFFECTSFILTER_H_INCLUDED
