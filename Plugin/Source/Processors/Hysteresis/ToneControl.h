#ifndef TONECONTROL_H_INCLUDED
#define TONECONTROL_H_INCLUDED

#include "ToneFilter.h"

using SmoothGain = SmoothedValue<float, ValueSmoothingTypes::Multiplicative>;

struct ToneStage
{
    ToneFilter tone[2];
    SmoothGain lowGain[2], highGain[2], tFreq[2];
    float fs = 44100.0f;

    ToneStage();

    void prepare (double sampleRate);
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
    void prepare (double sampleRate);

    void processBlockIn (AudioBuffer<float>& buffer);
    void processBlockOut (AudioBuffer<float>& buffer);

private:
    ToneStage toneIn, toneOut;

    std::atomic<float>* onOffParam = nullptr;
    std::atomic<float>* bassParam = nullptr;
    std::atomic<float>* trebleParam = nullptr;
    std::atomic<float>* tFreqParam = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneControl)
};

#endif // TONECONTROL_H_INCLUDED
