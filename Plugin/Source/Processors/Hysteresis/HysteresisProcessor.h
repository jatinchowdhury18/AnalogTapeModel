#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "../ProcessorBase.h"
#include "HysteresisProcessing.h"

class HysteresisProcessor : public ProcessorBase
{
public:
    HysteresisProcessor();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer) override;

    double getTailLengthSeconds() const override;

    void setOverSamplingFactor (String osFactor);
    void setBiasFreq (float newFreqKHz);
    void setBiasGain (float newGainDB);

private:
    HysteresisProcessing hProcs[2];
    std::unique_ptr<dsp::Oversampling<float>> overSample2;
    std::unique_ptr<dsp::Oversampling<float>> overSample4;
    std::unique_ptr<dsp::Oversampling<float>> overSample8;
    std::unique_ptr<dsp::Oversampling<float>> overSample16;

    int overSamplingFactor = 8;


    //////////////////////////////
    float biasFreq = 0.0f;
    float biasGain = 5.0f;
    float currentSampleRate = 0.0f;
    float angleDelta = 0.0f;
    float currentAngle[2] = { 0.0f, 0.0f };

    void updateAngleDelta();

    //int n[2] = { 0, 0 };

    bool fadeIn = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
