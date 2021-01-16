#ifndef DEGRADEPROCESSOR_H_INCLUDED
#define DEGRADEPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include "../GainProcessor.h"
#include "DegradeFilter.h"
#include "DegradeNoise.h"

class DegradeProcessor
{
public:
    DegradeProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void cookParams();
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi);

private:
    std::atomic<float>* onOffParam = nullptr;
    std::atomic<float>* depthParam = nullptr;
    std::atomic<float>* amtParam = nullptr;
    std::atomic<float>* varParam = nullptr;

    DegradeNoise noiseProc[2];
    DegradeFilter filterProc[2];
    GainProcessor gainProc;

    Random random;

    float fs = 44100.0f;

    BypassProcessor bypass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DegradeProcessor)
};

#endif // DEGRADEPROCESSOR_H_INCLUDED
