#include "MidSideProcessor.h"

MidSideProcessor::MidSideProcessor (AudioProcessorValueTreeState& vts)
{
    // set up parameter handle here
    midSideParam = vts.getRawParameterValue ("mid_side");
}

void MidSideProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    // add parameters here
    params.push_back (std::make_unique<AudioParameterBool> ("mid_side", "Mid/Side Mode", false));
}

void MidSideProcessor::prepare (double sampleRate)
{
    fadeSmooth.reset (sampleRate, 0.04);

    curMS = *midSideParam == 1.0f;
    prevMS = curMS;
}

void MidSideProcessor::processInput (AudioBuffer<float>& buffer)
{
    const auto numSamples = buffer.getNumSamples();

    //mid - side encoding logic here
    if (curMS && buffer.getNumChannels() != 1)
    {
        buffer.addFrom (0, 0, buffer, 1, 0, numSamples); // make channel 0 = left + right = mid
        buffer.applyGain (1, 0, numSamples, 2.0f); // make channel 1 = 2 * right
        buffer.addFrom (1, 0, buffer, 0, 0, numSamples, -1.0f); // make channel 1 = (2 * right) - (left + right) = right - left
        buffer.applyGain (1, 0, numSamples, -1.0f); // make channel 1 = -1 * (right - left) = left - right = side

        buffer.applyGain (Decibels::decibelsToGain (-3.0f)); // -3 dB Normalization
    }
}

void MidSideProcessor::processOutput (AudioBuffer<float>& buffer)
{
    const auto numSamples = buffer.getNumSamples();

    if (prevMS != (*midSideParam == 1.0f) && ! fadeSmooth.isSmoothing())
    {
        fadeSmooth.setCurrentAndTargetValue (1.0f);
        fadeSmooth.setTargetValue (0.0f);
    }

    //mid - side decoding logic here
    if (curMS && buffer.getNumChannels() != 1)
    {
        buffer.applyGain (Decibels::decibelsToGain (3.0f)); // undo -3 dB Normalization

        buffer.applyGain (1, 0, numSamples, -1.0f); // channel 1 = (L - R) * -1 = R - L
        buffer.addFrom (0, 0, buffer, 1, 0, numSamples, -1.0f); // channel 0 = (L + R) - (R - L) = 2L
        buffer.applyGain (0, 0, numSamples, 0.5f); // channel 0: 0.5 * (2L) = L
        buffer.addFrom (1, 0, buffer, 0, 0, numSamples); // channel 1 = (R - L) + L = R
    }

    if (fadeSmooth.isSmoothing())
    {
        float startGain = fadeSmooth.getCurrentValue();
        float endGain = fadeSmooth.skip (numSamples);

        buffer.applyGainRamp (0, numSamples, startGain, endGain);

        if (endGain == 0.0f)
        {
            fadeSmooth.setTargetValue (1.0f);

            // reset curMS at the "bottom" of the fade
            curMS = *midSideParam == 1.0f;
            prevMS = curMS;
        }
    }
}
