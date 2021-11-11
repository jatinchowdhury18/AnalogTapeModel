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

void MidSideProcessor::processInput (AudioBuffer<float>& buffer)
{
    const auto numSamples = buffer.getNumSamples();
    curMS = *midSideParam == 1.0f;

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

    if (prevMS != curMS)
    {
        counter = 3;
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

    if (counter > 0)
    {
        if (counter == 3)
            buffer.applyGainRamp (0, numSamples, 1.0f, 0.0f);
        else if (counter == 2)
            buffer.applyGain (0.0f);
        else if (counter == 1)
            buffer.applyGainRamp (0, numSamples, 0.0f, 1.0f);

        --counter;
    }

    prevMS = *midSideParam;
}
