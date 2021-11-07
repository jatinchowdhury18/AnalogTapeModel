#include "MidSideProcessor.h"

MidSideProcessor::MidSideProcessor (AudioProcessorValueTreeState& vts)
{
    // set up parameter handle here
    midSideParam = vts.getRawParameterValue ("mid_side");
}

void MidSideProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    // add parameters here...
    params.push_back (std::make_unique<AudioParameterBool> ("mid_side", "Mid/Side Mode", false));
}

void MidSideProcessor::processInput (AudioBuffer<float>& buffer)
{
    const auto numSamples = buffer.getNumSamples();

    if (prevMS != *midSideParam)
        bufferCopy.makeCopyOf (buffer, true);

    //mid - side encoding logic here
    if (*midSideParam && buffer.getNumChannels() != 1)
    {
        buffer.addFrom (0, 0, buffer, 1, 0, numSamples); // make channel 0 = left + right = mid
        buffer.addFrom (1, 0, buffer, 1, 0, numSamples); // make channel 1 = right + right = 2 * right
        buffer.addFrom (1, 0, buffer, 0, 0, numSamples, -1.0f); // make channel 1 = (2 * right) - (left + right) = right - left
        buffer.applyGain (1, 0, numSamples, -1.0f); // make channel 1 = -1 * (right - left) = left - right = side
    }

    if (prevMS != *midSideParam)
    {
        auto midSideGain = *midSideParam == 1.0f ? 0.0f : 1.0f;
        // fade buffers here
        buffer.applyGainRamp (0, numSamples, midSideGain, 1.0f - midSideGain);
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            buffer.addFromWithRamp (ch, 0, bufferCopy.getReadPointer (ch), numSamples, 1.0f - midSideGain, midSideGain);
    }
}

void MidSideProcessor::prepareToPlay (int numChannels, int samplesPerBlock)
{
    prevMS = *midSideParam;
    bufferCopy.setSize (numChannels, samplesPerBlock);
}

void MidSideProcessor::processOutput (AudioBuffer<float>& buffer)
{
    const auto numSamples = buffer.getNumSamples();

    if (prevMS != *midSideParam)
        bufferCopy.makeCopyOf (buffer, true);

    //mid - side encoding logic here
    if (*midSideParam && buffer.getNumChannels() != 1)
    {
        buffer.applyGain (1, 0, numSamples, -1.0f); // channel 1 = (L - R) * -1 = R - L
        buffer.addFrom (0, 0, buffer, 1, 0, numSamples, -1.0f); // channel 0 = (L + R) - (R - L) = 2L
        buffer.applyGain (0, 0, numSamples, 0.5f); // channel 0: 0.5 * (2L) = L
        buffer.addFrom (1, 0, buffer, 0, 0, numSamples); // channel 1 = (R - L) + L = R
    }

    if (prevMS != *midSideParam)
    {
        auto leftRightGain = *midSideParam == 1.0f ? 1.0f : 0.0f;
        // fade buffers here
        buffer.applyGainRamp (0, numSamples, leftRightGain, 1.0f - leftRightGain);
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            buffer.addFromWithRamp (ch, 0, bufferCopy.getReadPointer (ch), numSamples, 1.0f - leftRightGain, leftRightGain);
    }
    prevMS = *midSideParam;
}