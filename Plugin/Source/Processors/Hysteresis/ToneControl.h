#ifndef TONECONTROL_H_INCLUDED
#define TONECONTROL_H_INCLUDED

#include <JuceHeader.h>

using SmoothGain = SmoothedValue<float, ValueSmoothingTypes::Multiplicative>;

struct ToneStage
{
    std::vector<chowdsp::ShelfFilter<float>> tone;
    std::vector<SmoothGain> lowGain, highGain, tFreq;
    float fs = 44100.0f;

    ToneStage();

    void prepare (double sampleRate, int numChannels);
    void processBlock (AudioBuffer<float>& buffer);
    void setLowGain (float lowGainDB);
    void setHighGain (float highGainDB);
    void setTransFreq (float newTFreq);
};

class ToneControl
{
public:
    ToneControl (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);
    void prepare (double sampleRate, int numChannels);
    void setDBScale (float newDBScale) { dbScale = newDBScale; };

    void processBlockIn (AudioBuffer<float>& buffer);
    void processBlockOut (AudioBuffer<float>& buffer);

private:
    ToneStage toneIn, toneOut;

    std::atomic<float>* onOffParam = nullptr;
    chowdsp::FloatParameter* bassParam = nullptr;
    chowdsp::FloatParameter* trebleParam = nullptr;
    chowdsp::FloatParameter* tFreqParam = nullptr;

    float dbScale = 1.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneControl)
};

#endif // TONECONTROL_H_INCLUDED
