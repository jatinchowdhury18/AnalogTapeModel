#ifndef LIGHTMETER_H_INCLUDED
#define LIGHTMETER_H_INCLUDED

#include "JuceHeader.h"

class LightMeter : public foleys::MagicPlotSource,
                   public SettableTooltipClient
{
public:
    LightMeter() { rms = 0.0f; }

    /**
     This method is called by the MagicProcessorState to allow the plot computation to be set up
     */
    void prepareToPlay (double, int) override {}

    /**
     This is the callback whenever new sample data arrives. It is the subclasses
     responsibility to put that into a FIFO and return as quickly as possible.
     */
    void pushSamples (const juce::AudioBuffer<float>& buffer) override;

    /**
     This is the callback that creates the plot for drawing.

     @param path is the path instance that is constructed by the MagicPlotSource
     @param filledPath is the path instance that is constructed by the MagicPlotSource to be filled
     @param bounds the bounds of the plot
     @param component grants access to the plot component, e.g. to find the colours from it
     */
    void createPlotPaths (juce::Path& path, juce::Path& filledPath, juce::Rectangle<float> bounds, foleys::MagicPlotComponent& component) override;

private:
    std::atomic<float> rms;

    JUCE_DECLARE_WEAK_REFERENCEABLE (LightMeter)
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LightMeter)
};

#endif // LIGHTMETER_H_INCLUDED
