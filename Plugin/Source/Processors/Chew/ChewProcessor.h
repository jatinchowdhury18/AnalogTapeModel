#ifndef CHEWPROCESSOR_H_INCLUDED
#define CHEWPROCESSOR_H_INCLUDED

#include "../BypassProcessor.h"
#include "../Degrade/DegradeFilter.h"
#include "Dropout.h"

class ChewProcessor
{
public:
    ChewProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (chowdsp::Parameters& params);

    void prepare (double sr, int samplesPerBlock, int numChannels);
    void processBlock (AudioBuffer<float>& buffer);
    void processShortBlock (AudioBuffer<float>& buffer);

private:
    std::atomic<float>* onOff = nullptr;
    chowdsp::FloatParameter* depth = nullptr;
    chowdsp::FloatParameter* freq = nullptr;
    chowdsp::FloatParameter* var = nullptr;
    float mix = 0.0f;
    float power = 0.0f;

    Dropout dropout;
    std::vector<DegradeFilter> filt;

    Random random;
    int samplesUntilChange = 1000;
    bool isCrinkled = false;
    int sampleCounter = 0;

    float sampleRate = 44100.0f;
    BypassProcessor bypass;

    inline int getDryTime()
    {
        auto tScale = pow (*freq, 0.1f);
        auto varScale = pow (random.nextFloat() * 2.0f, var->getCurrentValue());
        return random.nextInt (Range<int> ((int) ((1.0 - tScale) * sampleRate * varScale),
                                           (int) ((2 - 1.99 * tScale) * sampleRate * varScale)));
    }

    inline int getWetTime()
    {
        auto tScale = pow (*freq, 0.1f);
        auto start = 0.2 + 0.8 * *depth;
        auto end = start - (0.001 + 0.01 * *depth);
        auto varScale = pow (random.nextFloat() * 2.0f, var->getCurrentValue());

        return random.nextInt (Range<int> ((int) ((1.0 - tScale) * sampleRate * varScale),
                                           (int) (((1.0 - tScale) + start - end * tScale) * sampleRate * varScale)));
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChewProcessor)
};

#endif // CHEWPROCESSOR_H_INCLUDED
