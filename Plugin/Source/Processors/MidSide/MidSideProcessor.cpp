#include "MidSideProcessor.h"

namespace
{
constexpr auto balanceGainDB = 6.0f;
}

MidSideProcessor::MidSideProcessor (AudioProcessorValueTreeState& vts)
{
    // set up parameter handle here
    midSideParam = vts.getRawParameterValue ("mid_side");
    balanceParam = vts.getRawParameterValue ("stereo_balance");
    makeupParam = vts.getRawParameterValue ("stereo_makeup");
}

void MidSideProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    using namespace chowdsp::ParamUtils;
    params.push_back (std::make_unique<AudioParameterBool> ("mid_side", "Mid/Side Mode", false));
    params.push_back (std::make_unique<VTSParam> ("stereo_balance", "Stereo Balance", String(), NormalisableRange { -1.0f, 1.0f }, 0.0f, &percentValToString, &stringToPercentVal));
    params.push_back (std::make_unique<AudioParameterBool> ("stereo_makeup", "Stereo Makeup", true));
}

void MidSideProcessor::prepare (double sampleRate, int samplesPerBlock)
{
    fadeSmooth.reset (sampleRate, 0.04);

    for (auto& inGain : inBalanceGain)
    {
        inGain.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
        inGain.setRampDurationSeconds (0.05);
    }

    for (auto& outGain : outBalanceGain)
    {
        outGain.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
        outGain.setRampDurationSeconds (0.05);
    }

    curMS = *midSideParam == 1.0f;
    prevMS = curMS;
}

void MidSideProcessor::processInput (AudioBuffer<float>& buffer)
{
    if (buffer.getNumChannels() != 2) // needs to be stereo!
        return;

    //mid - side encoding logic here
    const auto numSamples = buffer.getNumSamples();
    if (curMS)
    {
        buffer.addFrom (0, 0, buffer, 1, 0, numSamples); // make channel 0 = left + right = mid
        buffer.applyGain (1, 0, numSamples, 2.0f); // make channel 1 = 2 * right
        buffer.addFrom (1, 0, buffer, 0, 0, numSamples, -1.0f); // make channel 1 = (2 * right) - (left + right) = right - left
        buffer.applyGain (1, 0, numSamples, -1.0f); // make channel 1 = -1 * (right - left) = left - right = side

        buffer.applyGain (Decibels::decibelsToGain (-3.0f)); // -3 dB Normalization
    }

    // balance processing
    const auto curBalance = balanceParam->load();
    auto&& stereoBlock = dsp::AudioBlock<float> { buffer };
    auto&& leftBlock = stereoBlock.getSingleChannelBlock (0);
    auto&& rightBlock = stereoBlock.getSingleChannelBlock (1);

    inBalanceGain[0].setGainDecibels (curBalance * balanceGainDB);
    inBalanceGain[0].process (dsp::ProcessContextReplacing<float> { leftBlock });

    inBalanceGain[1].setGainDecibels (curBalance * -balanceGainDB);
    inBalanceGain[1].process (dsp::ProcessContextReplacing<float> { rightBlock });
}

void MidSideProcessor::processOutput (AudioBuffer<float>& buffer)
{
    if (buffer.getNumChannels() != 2) // needs to be stereo!
        return;

    if (prevMS != (*midSideParam == 1.0f) && ! fadeSmooth.isSmoothing())
    {
        fadeSmooth.setCurrentAndTargetValue (1.0f);
        fadeSmooth.setTargetValue (0.0f);
    }

    // inverse balance processing
    if (*makeupParam == 1.0f)
    {
        const auto curBalance = balanceParam->load();
        auto&& stereoBlock = dsp::AudioBlock<float> { buffer };
        auto&& leftBlock = stereoBlock.getSingleChannelBlock (0);
        auto&& rightBlock = stereoBlock.getSingleChannelBlock (1);

        outBalanceGain[0].setGainDecibels (curBalance * -balanceGainDB);
        outBalanceGain[0].process (dsp::ProcessContextReplacing<float> { leftBlock });

        outBalanceGain[1].setGainDecibels (curBalance * balanceGainDB);
        outBalanceGain[1].process (dsp::ProcessContextReplacing<float> { rightBlock });
    }

    //mid - side decoding logic here
    const auto numSamples = buffer.getNumSamples();
    if (curMS)
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
