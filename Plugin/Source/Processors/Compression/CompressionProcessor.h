#ifndef COMPRESSIONPROCESSOR_H_INCLUDED
#define COMPRESSIONPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include <xsimd/xsimd.hpp>

class CompressionProcessor
{
public:
    CompressionProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (double sr, int samplesPerBlock, int numChannels);
    void processBlock (AudioBuffer<float>& buffer);

    float getLatencySamples() const noexcept;

private:
    std::atomic<float>* onOff = nullptr;
    std::atomic<float>* amountParam = nullptr;
    std::atomic<float>* attackParam = nullptr;
    std::atomic<float>* releaseParam = nullptr;

    std::vector<chowdsp::LevelDetector<float>> slewLimiter;
    BypassProcessor bypass;

    std::unique_ptr<dsp::Oversampling<float>> oversample;

    std::vector<SmoothedValue<float, ValueSmoothingTypes::Linear>> dbPlusSmooth;

    std::vector<float, xsimd::aligned_allocator<float>> xDBVec;
    std::vector<float, xsimd::aligned_allocator<float>> compGainVec;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressionProcessor)
};

#endif // COMPRESSIONPROCESSOR_H_INCLUDED
