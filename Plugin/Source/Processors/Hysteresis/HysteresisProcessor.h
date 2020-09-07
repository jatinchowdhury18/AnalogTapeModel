#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "HysteresisProcessing.h"
#include "DCBlocker.h"

/* Hysteresis Processor for tape. */
class HysteresisProcessor
{
public:
    HysteresisProcessor (AudioProcessorValueTreeState& vts);

    /* Reset fade buffers, filters, and processors. Prepare oversampling */
    void prepareToPlay (double sampleRate, int samplesPerBlock);

    /* Reset oversampling */
    void releaseResources();

    /* Proceess a buffer. */
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    float getLatencySamples() const noexcept;

private:
    void setSolver (int newSolver);
    void setDrive (float newDrive);
    void setSaturation (float newSat);
    void setWidth (float newWidth);
    void setOversampling();
    float calcMakeup();
    void calcBiasFreq();

    void process (dsp::AudioBlock<float>& block);
    void processSmooth (dsp::AudioBlock<float>& block);
    void processV1 (dsp::AudioBlock<float>& block);
    void processSmoothV1 (dsp::AudioBlock<float>& block);
    void applyDCBlockers (AudioBuffer<float>& buffer);

    std::atomic<float>* driveParam = nullptr;
    std::atomic<float>* satParam = nullptr;
    std::atomic<float>* widthParam = nullptr;
    std::atomic<float>* osParam = nullptr;
    std::atomic<float>* modeParam = nullptr;

    SmoothedValue<float, ValueSmoothingTypes::Linear> drive[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> width[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> sat[2];
    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> makeup[2];

    float fs = 44100.0f;
    int curOS = 0, prevOS = 0;
    HysteresisProcessing hProcs[2];
    std::unique_ptr<dsp::Oversampling<float>> overSample[5]; // needs oversampling to avoid aliasing
    DCBlocker dcBlocker[2];

    int overSamplingFactor = 2;
    const float dcFreq = 35.0f;

    float biasGain = 10.0f;
    float biasFreq = 48000.0f;
    float biasAngle[2];
    bool wasV1 = false, useV1 = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
