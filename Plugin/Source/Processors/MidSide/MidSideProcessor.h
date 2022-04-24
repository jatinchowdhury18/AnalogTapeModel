#pragma once

#include <JuceHeader.h>

class MidSideProcessor
{
public:
    MidSideProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (double sampleRate, int samplesPerBlock);

    void processInput (AudioBuffer<float>& buffer);
    void processOutput (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* midSideParam = nullptr; // parameter handle
    std::atomic<float>* balanceParam = nullptr;
    std::atomic<float>* makeupParam = nullptr;

    bool curMS = false;
    bool prevMS = false;

    SmoothedValue<float, ValueSmoothingTypes::Linear> fadeSmooth;

    dsp::Gain<float> inBalanceGain[2];
    dsp::Gain<float> outBalanceGain[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideProcessor)
};
