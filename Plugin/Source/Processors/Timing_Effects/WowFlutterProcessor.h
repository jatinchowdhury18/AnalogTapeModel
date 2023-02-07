#ifndef WOWFLUTTERPROCESSOR_H_INCLUDED
#define WOWFLUTTERPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include "../Hysteresis/DCBlocker.h"
#include "FlutterProcess.h"
#include "WowProcess.h"

class WowFlutterProcessor
{
public:
    WowFlutterProcessor (AudioProcessorValueTreeState& vts);

    void initialisePlots (foleys::MagicGUIState& magicState);
    static void createParameterLayout (chowdsp::Parameters& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels);
    void processBlock (AudioBuffer<float>&);

private:
    void processWetBuffer (AudioBuffer<float>& buffer);
    void processBypassed (const AudioBuffer<float>& buffer);

    std::atomic<float>* flutterOnOff = nullptr;
    chowdsp::FloatParameter* flutterRate = nullptr;
    chowdsp::FloatParameter* flutterDepth = nullptr;
    chowdsp::FloatParameter* wowRate = nullptr;
    chowdsp::FloatParameter* wowDepth = nullptr;
    chowdsp::FloatParameter* wowVariance = nullptr;
    chowdsp::FloatParameter* wowDrift = nullptr;

    BypassProcessor bypass;
    float fs = 48000.0f;

    WowProcess wowProcessor;
    FlutterProcess flutterProcessor;
    foleys::MagicPlotSource *wowPlot = nullptr, *flutterPlot = nullptr;

    enum
    {
        HISTORY_SIZE = 1 << 21,
    };

    chowdsp::DelayLine<float, chowdsp::DelayLineInterpolationTypes::Lagrange3rd> delay { HISTORY_SIZE };
    std::vector<DCBlocker> dcBlocker;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowFlutterProcessor)
};

#endif //WOWFLUTTRPROCESSOR_H_INCLUDED
