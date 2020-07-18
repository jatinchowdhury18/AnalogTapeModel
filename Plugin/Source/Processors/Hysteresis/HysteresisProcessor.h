#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "HysteresisProcessing.h"
#include "DCFilters.h"

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

    void toggleOnOff (bool shouldBeOn);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    float getLatencySamples() const noexcept;

private:
    void setSolver (int newSolver);
    void setDrive (float newDrive);
    void setSaturation (float newSat);
    void setWidth (float newWidth);
    float calcMakeup();

    std::atomic<float>* driveParam = nullptr;
    std::atomic<float>* satParam = nullptr;
    std::atomic<float>* widthParam = nullptr;
    std::atomic<float>* osParam = nullptr;
    std::atomic<float>* solverParam = nullptr;

    SmoothedValue<float, ValueSmoothingTypes::Linear> drive[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> width[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> sat[2];
    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> makeup[2];

    float fs = 44100.0f;
    int prevOS = 0;
    HysteresisProcessing hProcs[2];
    std::unique_ptr<dsp::Oversampling<float>> overSample[5]; // needs oversampling to avoid aliasing
    TransformerHPF dcBlocker[2];
    // TransformerShelf dcLower[2];

    AudioBuffer<float> fadeBuffer;
    bool isOn = false;
    bool isChanging = true;

    int overSamplingFactor = 2;
    const float dcFreq = 10.0f;
    const float dcShelfFreq = 60.0f;

    int resetCount = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
