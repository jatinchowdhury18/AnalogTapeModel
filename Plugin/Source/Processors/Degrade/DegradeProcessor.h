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

    static void createParameterLayout (chowdsp::Parameters& params);

    void cookParams();
    void prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels);
    void processBlock (AudioBuffer<float>& buffer);

private:
    void processShortBlock (AudioBuffer<float>& buffer);

    std::atomic<float>* point1xParam = nullptr;
    std::atomic<float>* onOffParam = nullptr;
    chowdsp::FloatParameter* depthParam = nullptr;
    chowdsp::FloatParameter* amtParam = nullptr;
    chowdsp::FloatParameter* varParam = nullptr;
    chowdsp::FloatParameter* envParam = nullptr;

    std::vector<DegradeFilter> filterProc;
    GainProcessor gainProc;

    AudioBuffer<float> noiseBuffer;
    std::vector<DegradeNoise> noiseProc;

    AudioBuffer<float> levelBuffer;
    chowdsp::LevelDetector<float> levelDetector;

    Random random;

    float fs = 44100.0f;

    BypassProcessor bypass;

    static constexpr int smallBlockSize = 2048;
    int sampleCounter = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DegradeProcessor)
};

#endif // DEGRADEPROCESSOR_H_INCLUDED
