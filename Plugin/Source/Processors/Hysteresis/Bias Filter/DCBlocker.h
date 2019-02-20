#ifndef DCBLOCKER_H_INCLUDED
#define DCBLOCKER_H_INCLUDED

#include "../../ProcessorBase.h"

class DCBlocker : public ProcessorBase
{
public:
    DCBlocker() : ProcessorBase ("DC Blocker") {}

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer&) override;

private:
     float dcBlock (float x, int ch);

    float y1[2] = { 0.0f, 0.0f };
    float x1[2] = { 0.0f, 0.0f };
    const float R = 0.995f; //@TODO: Tune this

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DCBlocker)
};

#endif //DCBLOCKER_H_INCLUDED
