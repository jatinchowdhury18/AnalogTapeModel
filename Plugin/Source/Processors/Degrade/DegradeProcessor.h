#ifndef DEGRADEPROCESSOR_H_INCLUDED
#define DEGRADEPROCESSOR_H_INCLUDED

#include "../GainProcessor.h"
#include "DegradeNoise.h"
#include "DegradeFilter.h"

class DegradeProcessor
{
public:
    DegradeProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi);

private:
    float* depthParam = nullptr;
    float* amtParam   = nullptr;
    float* varParam   = nullptr;

    DegradeNoise noiseProc[2];
    DegradeFilter filterProc[2];
    GainProcessor gainProc;

    Random random;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DegradeProcessor)
};

#endif // DEGRADEPROCESSOR_H_INCLUDED
