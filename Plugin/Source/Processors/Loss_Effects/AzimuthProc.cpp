#include "AzimuthProc.h"

namespace
{
static constexpr float inches2meters (float inches)
{
    return inches / 39.370078740157f;
}

static constexpr float deg2rad (float deg)
{
    return deg * MathConstants<float>::pi / 180.0f;
}

constexpr float tapeWidth = inches2meters (0.25f);
}

void AzimuthProc::prepare (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    for (int ch = 0; ch < 2; ++ch)
    {
        delays[ch] = std::make_unique<ADelayLine> (1 << 18);
        delays[ch]->prepare ({ sampleRate, (uint32) samplesPerBlock, 1 });

        delaySampSmooth[ch].reset (sampleRate, 0.05);
    }
}

void AzimuthProc::setAzimuthAngle (float angleDeg, float tapeSpeedIps)
{
    const size_t delayIdx = size_t (angleDeg < 0.0f);
    const auto tapeSpeed = inches2meters (tapeSpeedIps);
    const auto azimuthAngle = deg2rad (std::abs (angleDeg));

    auto delayDist = tapeWidth * std::sin (azimuthAngle);
    auto delaySamp = (delayDist * tapeSpeed) * fs;

    delaySampSmooth[delayIdx].setTargetValue (delaySamp);
    delaySampSmooth[1 - delayIdx].setTargetValue (0.0f);
}

void AzimuthProc::processBlock (AudioBuffer<float>& buffer)
{
    if (buffer.getNumChannels() != 2) // needs to be stereo!
        return;

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        if (delaySampSmooth[ch].isSmoothing())
        {
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                delays[ch]->setDelay (delaySampSmooth[ch].getNextValue());
                delays[ch]->pushSample (0, x[n]);
                x[n] = delays[ch]->popSample (0);
            }
        }
        else
        {
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                delays[ch]->pushSample (0, x[n]);
                x[n] = delays[ch]->popSample (0);
            }
        }
    }
}
