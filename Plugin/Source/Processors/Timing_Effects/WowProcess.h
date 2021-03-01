#ifndef WOWPROCESS_H_INCLUDED
#define WOWPROCESS_H_INCLUDED

#include "OHProcess.h"
#include <JuceHeader.h>

class WowProcess
{
public:
    WowProcess() = default;

    void prepare (double sampleRate, int samplesPerBlock);
    void prepareBlock (float curDepth, float wowFreq, float wowVar, float wowDrift, int numSamples);
    void plotBuffer (foleys::MagicPlotSource* plot);

    inline bool shouldTurnOff() const noexcept { return depthSlew[0].getTargetValue() == depthSlewMin; }
    inline void updatePhase (int ch) noexcept { phase[ch] += angleDelta; }

    inline std::pair<float, float> getLFO (int n, int ch) noexcept
    {
        updatePhase (ch);
        auto curDepth = depthSlew[ch].getNextValue() * amp;
        wowPtrs[ch][n] = curDepth * (std::cos (phase[ch]) + ohProc.process (n, ch));
        return std::make_pair (wowPtrs[ch][n], curDepth);
    }

    inline void boundPhase (int ch) noexcept
    {
        while (phase[ch] >= MathConstants<float>::twoPi)
            phase[ch] -= MathConstants<float>::twoPi;
    }


private:
    float angleDelta = 0.0f;
    float amp = 0.0f;
    float phase[2] = { 0.0f, 0.0f };
    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> depthSlew[2];

    AudioBuffer<float> wowBuffer;
    float** wowPtrs = nullptr;
    float fs = 44100.0f;

    OHProcess ohProc;
    Random driftRand;

    static constexpr float depthSlewMin = 0.001f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowProcess)
};

#endif // WOWPROCESS_H_INCLUDED
