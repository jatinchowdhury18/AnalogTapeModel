#ifndef LOSSFILTER_H_INCLUDED
#define LOSSFILTER_H_INCLUDED

#include "FIRFilter.h"

class LossFilter
{
public:
    LossFilter (AudioProcessorValueTreeState& vts, int order = 100);
    ~LossFilter() {}

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (float sampleRate, int samplesPerBlock);
    void calcCoefs();
    void processBlock (float* buffer, const int numSamples);

private:
    OwnedArray<FIRFilter> filters;
    int activeFilter = 0;
    int fadeCount = 0;
    const int fadeLength = 512;
    AudioBuffer<float> fadeBuffer;
    bool starting = false;

    std::atomic<float>* speed = nullptr;
    std::atomic<float>* spacing = nullptr;
    std::atomic<float>* thickness = nullptr;
    std::atomic<float>* gap = nullptr;

    float prevSpeed;
    float prevSpacing;
    float prevThickness;
    float prevGap;

    float fs = 44100.0f;
    float fsFactor =  1.0f;
    float binWidth = fs / 100.0f;

    const int order;
    Array<float> currentCoefs;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LossFilter)
};

#endif //LOSSFILTER_H_INCLUDED
