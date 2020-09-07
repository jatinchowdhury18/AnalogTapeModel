#include "ToneControl.h"

namespace
{
    constexpr double slewTime = 0.05;
    constexpr float transFreq = 600.0f;
}

ToneStage::ToneStage()
{
    for (int ch = 0; ch < 2; ++ch)
    {
        lowGain[ch] = 1.0f;
        highGain[ch] = 1.0f;
    }
}

void ToneStage::prepare (double sampleRate)
{
    fs = (float) sampleRate;

    for (int ch = 0; ch < 2; ++ch)
    {
        lowGain[ch].reset (sampleRate, slewTime);
        lowGain[ch].setCurrentAndTargetValue (lowGain[ch].getTargetValue());
        highGain[ch].reset (sampleRate, slewTime);
        highGain[ch].setCurrentAndTargetValue (highGain[ch].getTargetValue());

        tone[ch].reset();
        tone[ch].calcCoefs (lowGain[ch].getTargetValue(), highGain[ch].getTargetValue(), transFreq, fs);
    }
}

void ToneStage::setLowGain (float lowGainDB)
{
    auto newLowGain = Decibels::decibelsToGain (lowGainDB);
    if (newLowGain == lowGain[0].getTargetValue())
        return;

    lowGain[0].setTargetValue (newLowGain);
    lowGain[1].setTargetValue (newLowGain);
}

void ToneStage::setHighGain (float highGainDB)
{
    auto newHighGain = Decibels::decibelsToGain (highGainDB);
    if (newHighGain == highGain[0].getTargetValue())
        return;

    highGain[0].setTargetValue (newHighGain);
    highGain[1].setTargetValue (newHighGain);
}

void ToneStage::processBlock (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        if (lowGain[ch].isSmoothing() || highGain[ch].isSmoothing())
        {
            auto* x = buffer.getWritePointer (ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                tone[ch].calcCoefs (lowGain[ch].getNextValue(), highGain[ch].getNextValue(), transFreq, fs);
                x[n] = tone[ch].processSample (x[n]);
            }
        }
        else
        {
            tone[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
        }
    }
}
