#pragma once

#include <JuceHeader.h>

class MidSideProcessor
{
public:
    MidSideProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (double sampleRate);

    void processInput (AudioBuffer<float>& buffer);
    void processOutput (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* midSideParam = nullptr; // parameter handle
    
    bool curMS = false;
    bool prevMS = false;
    
    SmoothedValue<float, ValueSmoothingTypes::Linear> fadeSmooth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideProcessor)
};
