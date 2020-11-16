#ifndef INPUTFILTERS_H_INCLUDED
#define INPUTFILTERS_H_INCLUDED

#include "LinkwitzRileyFilter.h"
#include "../BypassProcessor.h"

class InputFilters
{
public:
    InputFilters (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void setMakeupDelay (float newDelaySamples) { makeupDelay.setDelay (newDelaySamples); }

    void processBlock (AudioBuffer<float>& buffer);
    void processBlockMakeup (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* onOffParam   = nullptr;
    std::atomic<float>* lowCutParam  = nullptr;
    std::atomic<float>* highCutParam = nullptr;
    std::atomic<float>* makeupParam  = nullptr;

    float fs = 44100.0f;
    LinkwitzRileyFilter<float, 2> lowCutFilter;
    LinkwitzRileyFilter<float, 2> highCutFilter;
    dsp::DelayLine<float, dsp::DelayLineInterpolationTypes::Lagrange3rd> makeupDelay { 1 << 21 };

    AudioBuffer<float> lowCutBuffer, highCutBuffer, makeupBuffer;
    BypassProcessor bypass;
    BypassProcessor makeupBypass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputFilters)
};

#endif // !INPUTFILTERS_H_INCLUDED

