#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include "DCBlocker.h"
#include "HysteresisProcessing.h"
#include "OversamplingManager.h"

/* Hysteresis Processor for tape. */
class HysteresisProcessor
{
public:
    HysteresisProcessor (AudioProcessorValueTreeState& vts, const AudioProcessor& p);

    /* Reset fade buffers, filters, and processors. Prepare oversampling */
    void prepareToPlay (double sampleRate, int samplesPerBlock);

    /* Reset oversampling */
    void releaseResources();

    /* Proceess a buffer. */
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    float getLatencySamples() const noexcept;
    const OversamplingManager& getOSManager() const { return osManager; }

private:
    void setSolver (int newSolver);
    void setDrive (float newDrive);
    void setSaturation (float newSat);
    void setWidth (float newWidth);
    void setOversampling();
    double calcMakeup();
    void calcBiasFreq();

    template <SolverType solverType>
    void process (dsp::AudioBlock<double>& block);
    template <SolverType solverType>
    void processSmooth (dsp::AudioBlock<double>& block);
    void processV1 (dsp::AudioBlock<double>& block);
    void processSmoothV1 (dsp::AudioBlock<double>& block);
    void applyDCBlockers (AudioBuffer<float>& buffer);

    std::atomic<float>* driveParam = nullptr;
    std::atomic<float>* satParam = nullptr;
    std::atomic<float>* widthParam = nullptr;
    std::atomic<float>* modeParam = nullptr;
    std::atomic<float>* onOffParam = nullptr;

    SmoothedValue<double, ValueSmoothingTypes::Linear> drive[2];
    SmoothedValue<double, ValueSmoothingTypes::Linear> width[2];
    SmoothedValue<double, ValueSmoothingTypes::Linear> sat[2];
    SmoothedValue<double, ValueSmoothingTypes::Multiplicative> makeup;

    double fs = 44100.0f;
    HysteresisProcessing hProcs[2];
    SolverType solver;
    OversamplingManager osManager; // needs oversampling to avoid aliasing
    DCBlocker dcBlocker[2];

    static constexpr double dcFreq = 35.0;

    double biasGain = 10.0;
    double biasFreq = 48000.0;
    double biasAngle[2];
    bool wasV1 = false, useV1 = false;
    double clipLevel = 20.0;

    AudioBuffer<double> doubleBuffer;
    BypassProcessor bypass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
