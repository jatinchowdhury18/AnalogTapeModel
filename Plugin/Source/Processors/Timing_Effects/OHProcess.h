#ifndef OHPROCESS_H_INCLUDED
#define OHPROCESS_H_INCLUDED

#include <JuceHeader.h>

/**
 * Class to simulate the Ornstein-Uhlenbeck process.
 * Mostly lifted from https://github.com/mhampton/ZetaCarinaeModules
 * under the GPLv3 license.
 */
class OHProcess
{
public:
    OHProcess() = default;

    void prepare (double sampleRate, int samplesPerBlock)
    {
        dsp::ProcessSpec spec { sampleRate, (uint32) samplesPerBlock, 1 };

        noiseGen.setNoiseType (chowdsp::Noise<float>::Normal);
        noiseGen.setGainLinear (1.0f / 2.33f);
        noiseGen.prepare (spec);

        for (int ch = 0; ch < 2; ++ch)
        {
            lpf[ch].prepare (spec);
            lpf[ch].coefficients = dsp::IIR::Coefficients<float>::makeLowPass (sampleRate, 10.0f);
        }

        noiseBuffer.setSize (1, samplesPerBlock);
        rPtr = noiseBuffer.getReadPointer (0);

        sqrtdelta = 1.0f / std::sqrt ((float) sampleRate);
        T = 1.0f / (float) sampleRate;

        y[0] = 1.0f;
        y[1] = 0.0f;
    }

    void prepareBlock (float amtParam, int numSamples)
    {
        noiseBuffer.setSize (1, numSamples, false, false, true);
        noiseBuffer.clear();

        dsp::AudioBlock<float> noiseBlock (noiseBuffer);
        noiseGen.process (dsp::ProcessContextReplacing<float> (noiseBlock));

        amtParam = std::pow (amtParam, 1.25f);
        amt = amtParam;
        damping = amtParam * 20.0f + 1.0f;
        mean = amtParam;
    }

    inline float process (int n, int ch) noexcept
    {
        y[ch] += sqrtdelta * rPtr[n] * amt;
        y[ch] += damping * (mean - y[ch]) * T;
        return lpf[ch].processSample (y[ch]);
    }

private:
    float sqrtdelta = 1.0f / std::sqrt (48000.0f);
    float T = 1.0f / 48000.0f;
    float y[2] = { 0.0f, 0.0f };

    float amt = 0.0f;
    float mean = 0.0f;
    float damping = 0.0f;

    chowdsp::Noise<float> noiseGen;
    AudioBuffer<float> noiseBuffer;
    const float* rPtr = nullptr;

    dsp::IIR::Filter<float> lpf[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OHProcess)
};

#endif // OHPROCESS_H_INCLUDED
