#pragma once

#include <JuceHeader.h>

class OversamplingManager
{
public:
    OversamplingManager (const AudioProcessorValueTreeState& vts, const AudioProcessor& p);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    int getOSFactor() const noexcept { return overSamplingFactor; }
    bool updateOSFactor();

    float getLatencySamples() const noexcept { return overSample[curOS]->getLatencyInSamples(); }
    dsp::Oversampling<float>* getOversampler() { return overSample[curOS].get(); }

private:
    std::atomic<float>* osParam = nullptr;
    std::atomic<float>* osModeParam = nullptr;
    std::atomic<float>* osOfflineParam = nullptr;
    std::atomic<float>* osOfflineModeParam = nullptr;
    std::atomic<float>* osOfflineSameParam = nullptr;

    int curOS = 0, prevOS = 0;
    int overSamplingFactor = 2;

    static constexpr int numOSChoices = 5;
    std::unique_ptr<dsp::Oversampling<float>> overSample[2 * numOSChoices];

    const AudioProcessor& proc;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OversamplingManager)
};
