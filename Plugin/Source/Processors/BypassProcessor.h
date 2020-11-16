#ifndef BYPASSPROCESSOR_H_INCLUDED
#define BYPASSPROCESSOR_H_INCLUDED

#include <JuceHeader.h>

/** Utility class for *smoothly* bypassing a processor */
class BypassProcessor
{
public:
    BypassProcessor() = default;

    static bool toBool (const std::atomic<float>* param)
    {
        return static_cast<bool> (param->load());
    }

    void prepare (int samplesPerBlock, bool onOffParam)
    {
        prevOnOffParam = onOffParam;
        fadeBuffer.setSize (2, samplesPerBlock);
    }

    /**
      * Call this at the start of your processBlock().
      * If it returns false, you can safely skip all other
      * processing.
      */
    bool processBlockIn (AudioBuffer<float>& block, bool onOffParam)
    {
        if (onOffParam == false && prevOnOffParam == false)
            return false;

        if (onOffParam != prevOnOffParam)
            fadeBuffer.makeCopyOf (block, true);

        return true;
    }

    void processBlockOut (AudioBuffer<float>& block, bool onOffParam)
    {
        if (onOffParam == prevOnOffParam)
            return;

        const auto numChannels = block.getNumChannels();
        const auto numSamples = block.getNumSamples();

        float startGain = onOffParam == false ? 1.0f  // fade out
                                              : 0.0f; // fade in
        float endGain = 1.0f - startGain;

        block.applyGainRamp (0, numSamples, startGain, endGain);
        for (int ch = 0; ch < numChannels; ++ch)
            block.addFromWithRamp (ch, 0, fadeBuffer.getReadPointer (ch), numSamples,
                1.0f - startGain, 1.0f - endGain);

        prevOnOffParam = onOffParam;
    }

private:
    bool prevOnOffParam = false;
    AudioBuffer<float> fadeBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BypassProcessor)
};

#endif // BYPASSPROCESSOR_H_INCLUDED
