#ifndef LOSSFILTER_H_INCLUDED
#define LOSSFILTER_H_INCLUDED

#include "../BypassProcessor.h"
#include "AzimuthProc.h"
#include "FIRFilter.h"

class LossFilter
{
public:
    LossFilter (AudioProcessorValueTreeState& vts, int order = 64);
    ~LossFilter() {}

    static void createParameterLayout (chowdsp::Parameters& params);

    void prepare (float sampleRate, int samplesPerBlock, int numSamples);
    void processBlock (AudioBuffer<float>& buffer);
    float getLatencySamples() const noexcept;

private:
    using MultiChannelIIR = dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>;

    void calcCoefs (MultiChannelIIR& filter);
    static void calcHeadBumpFilter (float speedIps, float gapMeters, double fs, MultiChannelIIR& filter);

    std::vector<FIRFilter> filters[2];
    MultiChannelIIR bumpFilter[2];
    int activeFilter = 0;
    int fadeCount = 0;
    int fadeLength = 1024;
    AudioBuffer<float> fadeBuffer;

    std::atomic<float>* onOff = nullptr;
    chowdsp::FloatParameter* speed = nullptr;
    chowdsp::FloatParameter* spacing = nullptr;
    chowdsp::FloatParameter* thickness = nullptr;
    chowdsp::FloatParameter* gap = nullptr;
    chowdsp::FloatParameter* azimuth = nullptr;

    float prevSpeed = 0.5f;
    float prevSpacing = 0.5f;
    float prevThickness = 0.5f;
    float prevGap = 0.5f;

    float fs = 44100.0f;
    float fsFactor = 1.0f;
    float binWidth = fs / 100.0f;

    const int order;
    int curOrder = order;
    Array<float> currentCoefs;
    Array<float> Hcoefs;

    AzimuthProc azimuthProc;
    BypassProcessor bypass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossFilter)
};

#endif //LOSSFILTER_H_INCLUDED
