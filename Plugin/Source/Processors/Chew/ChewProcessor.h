#ifndef CHEWPROCESSOR_H_INCLUDED
#define CHEWPROCESSOR_H_INCLUDED

#include "Dropout.h"
#include "../Degrade/DegradeFilter.h"

class ChewProcessor
{
public:
    ChewProcessor (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void prepare (double sr);
    void processBlock (AudioBuffer<float>& buffer);
    void processShortBlock (AudioBuffer<float>& buffer);

private:
    float* depth = nullptr;
    float* freq = nullptr;
    float mix = 0.0f;
    float power = 0.0f;

    Dropout dropout;
    DegradeFilter filt[2];

    Random random;
    int samplesUntilChange = 1000;
    bool isCrinkled = false;
    int sampleCounter = 0;

    float sampleRate = 44100.0f;

    inline int getDryTime()
    {
        auto tScale = pow (*freq, 0.1f);
        return random.nextInt (Range<int> ((int) ((1.0 - tScale) * sampleRate),
            (int) ((2 - 1.99 * tScale) * sampleRate)));
    }

    inline int getWetTime()
    {
        auto tScale = pow (*freq, 0.1f);
        auto start = 0.2 + 0.8 * *depth;
        auto end = start - (0.001 + 0.01 * *depth);

        return random.nextInt (Range<int> ((int) ((1.0 - tScale) * sampleRate),
            (int) (((1.0 - tScale) + start - end * tScale) * sampleRate)));
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChewProcessor)
};

#endif // CHEWPROCESSOR_H_INCLUDED
