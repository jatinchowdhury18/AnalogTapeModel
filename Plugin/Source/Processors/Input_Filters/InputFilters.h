#ifndef INPUTFILTERS_H_INCLUDED
#define INPUTFILTERS_H_INCLUDED

#include "../BypassProcessor.h"
#include "LinkwitzRileyFilter.h"

class InputFilters
{
public:
    InputFilters (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (chowdsp::Parameters& params);
    void prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels);
    void setMakeupDelay (float newDelaySamples) { makeupDelay.setDelay (newDelaySamples); }

    void processBlock (AudioBuffer<float>& buffer);
    void processBlockMakeup (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* onOffParam = nullptr;
    chowdsp::FloatParameter* lowCutParam = nullptr;
    chowdsp::FloatParameter* highCutParam = nullptr;
    std::atomic<float>* makeupParam = nullptr;

    float fs = 44100.0f;
    LinkwitzRileyFilter<float> lowCutFilter;
    LinkwitzRileyFilter<float> highCutFilter;
    dsp::DelayLine<float, dsp::DelayLineInterpolationTypes::Lagrange3rd> makeupDelay { 1 << 21 };

    AudioBuffer<float> lowCutBuffer, highCutBuffer, makeupBuffer;
    BypassProcessor bypass;
    BypassProcessor makeupBypass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputFilters)
};

#endif // !INPUTFILTERS_H_INCLUDED
