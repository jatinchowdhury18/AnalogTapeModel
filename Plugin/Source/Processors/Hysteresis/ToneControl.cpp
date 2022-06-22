#include "ToneControl.h"

namespace
{
constexpr double slewTime = 0.05;
constexpr float transFreq = 500.0f;
} // namespace

ToneStage::ToneStage() = default;

void ToneStage::prepare (double sampleRate, int numChannels)
{
    fs = (float) sampleRate;

    tone.resize ((size_t) numChannels);
    lowGain.resize ((size_t) numChannels);
    highGain.resize ((size_t) numChannels);
    tFreq.resize ((size_t) numChannels);

    for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
    {
        auto resetSmoothValue = [sampleRate] (SmoothGain& value, float startValue) {
            value.reset (sampleRate, slewTime);
            value.setCurrentAndTargetValue (startValue);
        };

        resetSmoothValue (lowGain[ch], 1.0f);
        resetSmoothValue (highGain[ch], 1.0f);
        resetSmoothValue (tFreq[ch], transFreq);

        tone[ch].reset();
        tone[ch].calcCoefs (lowGain[ch].getTargetValue(), highGain[ch].getTargetValue(), tFreq[ch].getTargetValue(), fs);
    }
}

void setSmoothValues (std::vector<SmoothGain>& values, float newValue)
{
    if (newValue == values[0].getTargetValue())
        return;

    for (auto& smoothedVal : values)
        smoothedVal.setTargetValue (newValue);
}

void ToneStage::setLowGain (float lowGainDB) { setSmoothValues (lowGain, Decibels::decibelsToGain (lowGainDB)); }
void ToneStage::setHighGain (float highGainDB) { setSmoothValues (highGain, Decibels::decibelsToGain (highGainDB)); }
void ToneStage::setTransFreq (float newTFreq) { setSmoothValues (tFreq, newTFreq); }

void ToneStage::processBlock (AudioBuffer<float>& buffer)
{
    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();

    for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
    {
        auto* data = buffer.getWritePointer ((int) ch);
        if (lowGain[ch].isSmoothing() || highGain[ch].isSmoothing() || tFreq[ch].isSmoothing())
        {
            for (int n = 0; n < numSamples; ++n)
            {
                tone[ch].calcCoefs (lowGain[ch].getNextValue(), highGain[ch].getNextValue(), tFreq[ch].getNextValue(), fs);
                data[n] = tone[ch].processSample (data[n]);
            }
        }
        else
        {
            tone[ch].processBlock (data, numSamples);
        }
    }
}

//===================================================
ToneControl::ToneControl (AudioProcessorValueTreeState& vts)
{
    using namespace chowdsp::ParamUtils;
    loadParameterPointer (bassParam, vts, "h_bass");
    loadParameterPointer (trebleParam, vts, "h_treble");
    loadParameterPointer (tFreqParam, vts, "h_tfreq");
    onOffParam = vts.getRawParameterValue ("tone_onoff");
}

void ToneControl::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    NormalisableRange freqRange { 100.0f, 4000.0f };
    freqRange.setSkewForCentre (transFreq);

    using namespace chowdsp::ParamUtils;
    emplace_param<chowdsp::BoolParameter> (params, "tone_onoff", "Tone On/Off", true);
    emplace_param<chowdsp::FloatParameter> (params, "h_bass", "Tone Bass", NormalisableRange { -1.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "h_treble", "Tone Treble", NormalisableRange { -1.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    createFreqParameter (params, "h_tfreq", "Tone Transition Frequency", 100.0f, 4000.0f, transFreq, transFreq);
}

void ToneControl::prepare (double sampleRate, int numChannels)
{
    toneIn.prepare (sampleRate, numChannels);
    toneOut.prepare (sampleRate, numChannels);
}

void ToneControl::processBlockIn (AudioBuffer<float>& buffer)
{
    if (static_cast<bool> (onOffParam->load()))
    {
        toneIn.setLowGain (dbScale * bassParam->getCurrentValue());
        toneIn.setHighGain (dbScale * trebleParam->getCurrentValue());
    }
    else
    {
        toneIn.setLowGain (0.0f);
        toneIn.setHighGain (0.0f);
    }
    toneIn.setTransFreq (tFreqParam->getCurrentValue());

    toneIn.processBlock (buffer);
}

void ToneControl::processBlockOut (AudioBuffer<float>& buffer)
{
    if (static_cast<bool> (onOffParam->load()))
    {
        toneOut.setLowGain (-1.0f * dbScale * bassParam->getCurrentValue());
        toneOut.setHighGain (-1.0f * dbScale * trebleParam->getCurrentValue());
    }
    else
    {
        toneOut.setLowGain (0.0f);
        toneOut.setHighGain (0.0f);
    }
    toneOut.setTransFreq (tFreqParam->getCurrentValue());

    toneOut.processBlock (buffer);
}
