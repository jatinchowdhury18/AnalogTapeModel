#ifndef TAPESCOPE_H_INCLUDED
#define TAPESCOPE_H_INCLUDED

#include <JuceHeader.h>

class TapeScope : public foleys::MagicOscilloscope
{
public:
    TapeScope (int numChannels);
    ~TapeScope() = default;

    enum AudioType
    {
        Input,
        Output,
    };

    void prepareToPlay (double sampleRate, int samplesPerBlockExpected) override;
    void pushSamplesIO (const AudioBuffer<float>& buffer, AudioType type);

    void createPlotPaths (Path& path, Path& filledPath, Rectangle<float> bounds, foleys::MagicPlotComponent& component) override;

private:
    foleys::MagicLevelSource inputSource;
    foleys::MagicLevelSource outputSource;

    const int numChannels;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapeScope)
};

#endif // TAPESCOPE_H_INCLUDED
