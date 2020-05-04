#ifndef FLUTTER_H_INCLUDED
#define FLUTTER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DelayProcessor.h"

class Flutter
{
public:
    Flutter (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void processBlock (AudioBuffer<float>&, MidiBuffer&);

private:
    std::atomic<float>* rate = nullptr;
    std::atomic<float>* depth = nullptr;

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

    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> depthSlew[2];

    DelayProcessor delay[2];

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Flutter)
};

#endif //FLUTTER_H_INCLUDED
