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
    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void processBlock (AudioBuffer<float>&, MidiBuffer&);

private:
    void processWetBuffer (AudioBuffer<float>& buffer);
    void processBypassed (const AudioBuffer<float>& buffer);

    std::atomic<float>* flutterOnOff = nullptr;
    std::atomic<float>* flutterRate = nullptr;
    std::atomic<float>* flutterDepth = nullptr;
    std::atomic<float>* wowRate = nullptr;
    std::atomic<float>* wowDepth = nullptr;
    std::atomic<float>* wowVariance = nullptr;
    std::atomic<float>* wowDrift = nullptr;

    BypassProcessor bypass;
    float fs = 48000.0f;

    WowProcess wowProcessor;
    FlutterProcess flutterProcessor;
    foleys::MagicPlotSource *wowPlot = nullptr, *flutterPlot = nullptr;

    enum
    {
        HISTORY_SIZE = 1 << 21,
    };

    dsp::DelayLine<float, dsp::DelayLineInterpolationTypes::Lagrange3rd> delay { HISTORY_SIZE };
    DCBlocker dcBlocker[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowFlutterProcessor)
};

#endif //WOWFLUTTRPROCESSOR_H_INCLUDED
