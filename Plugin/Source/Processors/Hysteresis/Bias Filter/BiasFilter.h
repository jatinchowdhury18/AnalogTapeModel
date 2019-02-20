#ifndef BIASFILTER_H_INCLUDED
#define BIASFILTER_H_INCLUDED

#include "FilterProcessor.h"
#include "DCBlocker.h"

/** 8th order Butterworth lowpass plus dc blocker */
class BiasFilter : public ProcessorBase
{
public:
    BiasFilter();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer) override;

    void setFreq (float newFreq);

private:
    DCBlocker dcBlocker;
    FilterProcessor filter[4];
    float freq = 24000.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BiasFilter)
};

#endif //BIASFILTER_H_INCLUDED
