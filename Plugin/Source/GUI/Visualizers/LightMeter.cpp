#include "LightMeter.h"

void LightMeter::pushSamples (const juce::AudioBuffer<float>& buffer)
{
    rms = buffer.getRMSLevel (0, 0, buffer.getNumSamples());

    if (std::isnan (rms.load()))
        rms = 0.0f;

    resetLastDataFlag();
}

void LightMeter::createPlotPaths (juce::Path& path, juce::Path& filledPath, juce::Rectangle<float> bounds, foleys::MagicPlotComponent&)
{
    const auto centre = bounds.getCentre();
    const auto maxDiameter = jmin (bounds.getHeight(), bounds.getWidth());

    const auto diameter = maxDiameter * jlimit (0.0f, 1.0f, rms.load());
    const auto ellipseRect = Rectangle<float> (diameter, diameter).withCentre (centre);

    path.clear();
    path.addEllipse (ellipseRect);

    filledPath = path;
}
