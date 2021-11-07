#include <JuceHeader.h>

class MidSideProcessor
{
public:
    MidSideProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);
    void processInput (AudioBuffer<float>& buffer);
    void prepareToPlay (int numChannels, int samplesPerBlock);
    void processOutput (AudioBuffer<float>& buffer);

private:
    float prevMS = 0.0f;
    std::atomic<float>* midSideParam = nullptr; // parameter handle
    juce::AudioBuffer<float> bufferCopy;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideProcessor)
};