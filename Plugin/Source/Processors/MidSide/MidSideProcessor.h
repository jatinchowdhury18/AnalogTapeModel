#pragma once

#include <JuceHeader.h>

class MidSideProcessor
{
public:
    MidSideProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void processInput (AudioBuffer<float>& buffer);
    void processOutput (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* midSideParam = nullptr; // parameter handle
    bool curMS = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideProcessor)
};
