#ifndef PREPOSTEQ_H_INCLUDED
#define PREPOSTEQ_H_INCLUDED

#include "EQFilters.h"
#include "../GainProcessor.h"

class PrePostEQ
{
public:
    PrePostEQ() {}
    ~PrePostEQ() {}

    void prepare (double sampleRate, int samplesPerBlock);
    void processPreBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages);
    void processPostBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages);

private:
    LPF1 preEQ[2];
    LPF1 postEQLow[2][6];
    HPF1 postEQ[2];

    GainProcessor preGain;
    GainProcessor postGain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PrePostEQ)
};

#endif //PREPOSTEQ_H_INCLUDED
