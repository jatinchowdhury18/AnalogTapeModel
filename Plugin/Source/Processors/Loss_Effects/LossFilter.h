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

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (float sampleRate, int samplesPerBlock);
    void processBlock (AudioBuffer<float>& buffer);
    float getLatencySamples() const noexcept;

private:
    using StereoIIR = dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>;

    void calcCoefs (StereoIIR& filter);
    static void calcHeadBumpFilter (float speedIps, float gapMeters, double fs, StereoIIR& filter);

    OwnedArray<FIRFilter> filters[2];
    StereoIIR bumpFilter[2];
    int activeFilter = 0;
    int fadeCount = 0;
    int fadeLength = 1024;
    AudioBuffer<float> fadeBuffer;

    std::atomic<float>* onOff = nullptr;
    std::atomic<float>* speed = nullptr;
    std::atomic<float>* spacing = nullptr;
    std::atomic<float>* thickness = nullptr;
    std::atomic<float>* gap = nullptr;
    std::atomic<float>* azimuth = nullptr;

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
