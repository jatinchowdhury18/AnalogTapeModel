#ifndef TONECONTROL_H_INCLUDED
#define TONECONTROL_H_INCLUDED

#include "ToneFilter.h"

using SmoothGain = SmoothedValue<float, ValueSmoothingTypes::Multiplicative>;

struct ToneStage
{
    ToneFilter tone[2];
    SmoothGain lowGain[2], highGain[2];
    float fs = 44100.0f;

    ToneStage();

    void prepare (double sampleRate);
    void processBlock (AudioBuffer<float>& buffer);
    void setLowGain (float lowGainDB);
    void setHighGain (float highGainDB);
};

class ToneControl
{
public:
    ToneControl() = default;

    void prepare (double sampleRate)
    {
        toneIn.prepare (sampleRate);
        toneOut.prepare (sampleRate);

        toneIn.setLowGain (-3.0f);
        toneIn.setHighGain (3.0f);
        
        toneOut.setLowGain (3.0f);
        toneOut.setHighGain (-3.0f);
    }

    void processBlockIn (AudioBuffer<float>& buffer)
    {
        toneIn.processBlock (buffer);
    }

    void processBlockOut (AudioBuffer<float>& buffer)
    {
        toneOut.processBlock (buffer);
    }

private:
    ToneStage toneIn, toneOut;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneControl)
};

#endif // TONECONTROL_H_INCLUDED
