#ifndef COMPRESSIONPROCESSOR_H_INCLUDED
#define COMPRESSIONPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include <xsimd/xsimd.hpp>

class CompressionProcessor
{
public:
    CompressionProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (double sr, int samplesPerBlock);
    void processBlock (AudioBuffer<float>& buffer);

    float getLatencySamples() const noexcept;

private:
    std::atomic<float>* onOff = nullptr;
    std::atomic<float>* amountParam = nullptr;
    std::atomic<float>* attackParam = nullptr;
    std::atomic<float>* releaseParam = nullptr;

    chowdsp::LevelDetector<float> slewLimiter[2];
    BypassProcessor bypass;

    dsp::Oversampling<float> oversample { 2, 1, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR, true, true };

    SmoothedValue<float, ValueSmoothingTypes::Linear> dbPlusSmooth[2];

    std::vector<float, XSIMD_DEFAULT_ALLOCATOR (float)> xDBVec;
    std::vector<float, XSIMD_DEFAULT_ALLOCATOR (float)> compGainVec;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressionProcessor)
};

#endif // COMPRESSIONPROCESSOR_H_INCLUDED
