#ifndef WOWFLUTTERPROCESSOR_H_INCLUDED
#define WOWFLUTTERPROCESSOR_H_INCLUDED

#include "../Hysteresis/DCBlocker.h"
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
    AudioBuffer<float> dryBuffer;

    WowProcess wowProcessor;

    float phase1[2] = { 0.0f, 0.0f };
    float phase2[2] = { 0.0f, 0.0f };
    float phase3[2] = { 0.0f, 0.0f };

    float amp1 = 0.0f;
    float amp2 = 0.0f;
    float amp3 = 0.0f;
    float fs = 48000.0f;

    float dcOffset = 0.0f;
    const float phaseOff1 = 0.0f;
    const float phaseOff2 = 13.0f * MathConstants<float>::pi / 4.0f;
    const float phaseOff3 = -MathConstants<float>::pi / 10.0f;

    float angleDelta1 = 0.0f;
    float angleDelta2 = 0.0f;
    float angleDelta3 = 0.0f;

    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> depthSlewFlutter[2];

    AudioBuffer<float> flutterBuffer;
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
