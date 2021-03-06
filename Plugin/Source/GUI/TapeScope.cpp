#include "TapeScope.h"

using namespace foleys;

namespace
{
constexpr int rmsMS = 5000; // rms window milliseconds
constexpr float xPad = 3.0f;
} // namespace

TapeScope::TapeScope (int numChannels) : numChannels (numChannels)
{
}

void TapeScope::prepareToPlay (double newSampleRate, int samplesPerBlockExpected)
{
    MagicOscilloscope::prepareToPlay (newSampleRate, samplesPerBlockExpected);
    inputSource.setupSource (numChannels, newSampleRate, rmsMS, rmsMS);
    outputSource.setupSource (numChannels, newSampleRate, rmsMS, rmsMS);
}

void TapeScope::pushSamplesIO (const AudioBuffer<float>& buffer, AudioType type)
{
    switch (type)
    {
        case Input:
            inputSource.pushSamples (buffer);
            return;

        case Output:
            outputSource.pushSamples (buffer);
            MagicOscilloscope::pushSamples (buffer);
    }
}

void TapeScope::createPlotPaths (Path& path, Path& filledPath, Rectangle<float> bounds, MagicPlotComponent& component)
{
    // plot normal scope, with no fill
    MagicOscilloscope::createPlotPaths (path, filledPath, bounds, component);
    filledPath.clear();

    // get strings for I/O dB meters
    auto getDBString = [] (const MagicLevelSource& source, AudioType type) -> String {
        String prefix = type == Input ? "IN: " : "OUT: ";
        auto dBVal = Decibels::gainToDecibels (source.getRMSvalue (0), -80.0f);
        return prefix + String (dBVal, 1) + " dB";
    };

    String inputMeter = getDBString (inputSource, Input);
    String outputMeter = getDBString (outputSource, Output);

    // draw label text
    const auto b = bounds.toFloat();
    const auto labelHeight = b.getProportion (Rectangle<float> { 0.0f, 0.2f }).getHeight();
    const auto fontHeight = labelHeight * 0.9f;
    const auto font = Font (fontHeight);

    auto drawLabel = [b, &filledPath, labelHeight, font] (const String& textStr, float x) {
        auto width = font.getStringWidthFloat (textStr);
        x = x < b.getCentreX() ? x : x - width;

        GlyphArrangement text;
        text.addFittedText (font, textStr, x, b.getY(), width, labelHeight, Justification::left, 1);
        text.createPath (filledPath);
    };

    drawLabel (inputMeter, b.getX() + xPad);
    drawLabel (outputMeter, b.getRight() - xPad);
}
