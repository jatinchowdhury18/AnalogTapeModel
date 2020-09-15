#include "ToneControl.h"

namespace
{
    constexpr double slewTime = 0.05;
    constexpr float transFreq = 500.0f;
    constexpr float dbScale = 12.0f;
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
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
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

//===================================================
ToneControl::ToneControl (AudioProcessorValueTreeState& vts)
{
    bassParam   = vts.getRawParameterValue ("h_bass");
    trebleParam = vts.getRawParameterValue ("h_treble");
}

void ToneControl::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("h_bass",   "Bass",   -1.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("h_treble", "Treble", -1.0f, 1.0f, 0.0f));
}

void ToneControl::prepare (double sampleRate)
{
    toneIn.prepare (sampleRate);
    toneOut.prepare (sampleRate);
}

void ToneControl::processBlockIn (AudioBuffer<float>& buffer)
{
    toneIn.setLowGain  (dbScale * bassParam->load());
    toneIn.setHighGain (dbScale * trebleParam->load());

    toneIn.processBlock (buffer);
}

void ToneControl::processBlockOut (AudioBuffer<float>& buffer)
{
    toneOut.setLowGain  (-1.0f * dbScale * bassParam->load());
    toneOut.setHighGain (-1.0f * dbScale * trebleParam->load());
    
    toneOut.processBlock (buffer);
}

