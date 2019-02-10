#ifndef GAINPROCESSOR_H_INCLUDED
#define GAINPROCESSOR_H_INCLUDED

#include "ProcessorBase.h"

class GainProcessor : public ProcessorBase
{
public:
    GainProcessor() : ProcessorBase (String ("Gain Processor")) {}

    void prepareToPlay (double sampleRate, int maximumExpectedSamplesPerBlock) override
    { 
        setRateAndBufferSizeDetails (sampleRate, maximumExpectedSamplesPerBlock);
        oldGain = 0.0f;
    }

    void releaseResources() override {}
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/) override
    {
        if (curGain != oldGain)
        {
            buffer.applyGainRamp (0, buffer.getNumSamples(), oldGain, curGain);
            oldGain = curGain;
            return;
        }
        
        buffer.applyGain (curGain);
    }

    void setGain (float gain)
    {
        if (gain == curGain)
            return;

        oldGain = curGain;
        curGain = gain;
    }

    float getGain() const { return curGain; }

private:
    float curGain = 1.0f;
    float oldGain = 0.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainProcessor)
};

#endif //GAINPROCESSOR_H_INCLUDED
