#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include "DCBlocker.h"
#include "HysteresisProcessing.h"

/* Hysteresis Processor for tape. */
class HysteresisProcessor
{
public:
    HysteresisProcessor (AudioProcessorValueTreeState& vts);

    /* Reset fade buffers, filters, and processors. Prepare oversampling */
    void prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels);

    /* Reset oversampling */
    void releaseResources();

    /* Proceess a buffer. */
    void processBlock (AudioBuffer<float>& buffer);

    static void createParameterLayout (chowdsp::Parameters& params);

    float getLatencySamples() const noexcept;
    auto& getOSManager() { return osManager; }

private:
    void setSolver (int newSolver);
    void setDrive (float newDrive);
    void setSaturation (float newSat);
    void setWidth (float newWidth);
    void setOversampling();
    double calcMakeup();
    void calcBiasFreq();

    template <SolverType solverType, typename T>
    void process (chowdsp::AudioBlock<T>& block);
    template <SolverType solverType, typename T>
    void processSmooth (chowdsp::AudioBlock<T>& block);
    template <typename T>
    void processV1 (chowdsp::AudioBlock<T>& block);
    template <typename T>
    void processSmoothV1 (chowdsp::AudioBlock<T>& block);
    void applyDCBlockers (AudioBuffer<float>& buffer);

    chowdsp::FloatParameter* driveParam = nullptr;
    chowdsp::FloatParameter* satParam = nullptr;
    chowdsp::FloatParameter* widthParam = nullptr;
    std::atomic<float>* modeParam = nullptr;
    std::atomic<float>* onOffParam = nullptr;

    std::vector<SmoothedValue<double, ValueSmoothingTypes::Linear>> drive;
    std::vector<SmoothedValue<double, ValueSmoothingTypes::Linear>> width;
    std::vector<SmoothedValue<double, ValueSmoothingTypes::Linear>> sat;
    SmoothedValue<double, ValueSmoothingTypes::Multiplicative> makeup;

    double fs = 44100.0f;
    chowdsp::VariableOversampling<double> osManager; // needs oversampling to avoid aliasing
    std::vector<HysteresisProcessing> hProcs;
    SolverType solver = SolverType::RK4;
    std::vector<DCBlocker> dcBlocker;

    static constexpr double dcFreq = 35.0;

    double biasGain = 10.0;
    double biasFreq = 48000.0;
    std::vector<double> biasAngle;
    bool wasV1 = false, useV1 = false;
    float clipLevel = 20.0f;

    AudioBuffer<double> doubleBuffer;
    BypassProcessor bypass;

#if HYSTERESIS_USE_SIMD
    using Vec2 = xsimd::batch<double>;
    chowdsp::AudioBlock<Vec2> interleavedBlock;
    chowdsp::AudioBlock<double> zeroBlock;

    HeapBlock<char> interleavedBlockData, zeroData;
    std::vector<const double*> channelPointers;
#endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
