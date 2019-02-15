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

private:
    LossEffects lossProcessors[2];
    float speed = 15.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossEffectsFilter)
};

#endif //LOSSEFFECTSFILTER_H_INCLUDED
