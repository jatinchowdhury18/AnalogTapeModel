#ifndef LINKWITZRILEYFILTER_H_INCLUDED
#define LINKWITZRILEYFILTER_H_INCLUDED

#include <JuceHeader.h>

/** 4th-order L-R Filter */
template <typename SampleType>
class LinkwitzRileyFilter
{
public:
    LinkwitzRileyFilter()
    {
        update();
    }

    /** Sets the cutoff frequency of the filter in Hz. */
    void setCutoff (SampleType newCutoffFrequencyHz)
    {
        jassert (isPositiveAndBelow (newCutoffFrequencyHz, static_cast<SampleType> (sampleRate * 0.5)));
        cutoffFrequency = newCutoffFrequencyHz;
        update();
    }

    /** Initialises the filter. */
    void prepare (const dsp::ProcessSpec& spec)
    {
        jassert (spec.sampleRate > 0);
        jassert (spec.numChannels > 0);

        state.resize (spec.numChannels, {});

        sampleRate = spec.sampleRate;
        update();
        reset();
    }

    /** Resets the internal state variables of the filter. */
    void reset()
    {
        for (auto& s : state)
            std::fill (s.begin(), s.end(), static_cast<SampleType> (0));
    }

    /** Performs the filter operation on a single sample at a time, and returns both
    the low-pass and the high-pass outputs of the TPT structure.
    */
    inline void processSample (size_t ch, SampleType x, SampleType& outputLow, SampleType& outputHigh) noexcept
    {
        auto yH = (x - (R2 + g) * state[ch][0] - state[ch][1]) * h;

        auto tB = g * yH;
        auto yB = tB + state[ch][0];
        state[ch][0] = tB + yB;

        auto tL = g * yB;
        auto yL = tL + state[ch][1];
        state[ch][1] = tL + yL;

        auto yH2 = (yL - (R2 + g) * state[ch][2] - state[ch][3]) * h;

        auto tB2 = g * yH2;
        auto yB2 = tB2 + state[ch][2];
        state[ch][2] = tB2 + yB2;

        auto tL2 = g * yB2;
        auto yL2 = tL2 + state[ch][3];
        state[ch][3] = tL2 + yL2;

        outputLow = yL2;
        outputHigh = yL - R2 * yB + yH - yL2;
    }

    /** Ensure that the state variables are rounded to zero if the state
    variables are denormals. This is only needed if you are doing
    sample by sample processing.
    */
    inline void snapToZero() noexcept
    {
        for (auto& s : state)
            for (auto element : s)
                juce::dsp::util::snapToZero (element);
    }

private:
    void update()
    {
        g = (SampleType) std::tan (MathConstants<double>::pi * cutoffFrequency / sampleRate);
        h = (SampleType) (1.0 / (1.0 + R2 * g + g * g));
    }

    SampleType g, h;
    static constexpr SampleType R2 = static_cast<SampleType> (1.41421356237);
    std::vector<std::array<SampleType, 4>> state;

    double sampleRate = 44100.0;
    SampleType cutoffFrequency = 2000.0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LinkwitzRileyFilter)
};

#endif // LINKWITZRILEYFILTER_H_INCLUDED
