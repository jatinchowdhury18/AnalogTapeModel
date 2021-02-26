#ifndef WOWFLUTTERPROCESSOR_H_INCLUDED
#define WOWFLUTTERPROCESSOR_H_INCLUDED

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

    void processWetBuffer (AudioBuffer<float>& buffer);
    void processBypassed (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* flutterOnOff = nullptr;
    std::atomic<float>* flutterRate = nullptr;
    std::atomic<float>* flutterDepth = nullptr;
    std::atomic<float>* wowRate = nullptr;
    std::atomic<float>* wowDepth = nullptr;

    bool isOff = false;
    AudioBuffer<float> fadeBuffer;
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
