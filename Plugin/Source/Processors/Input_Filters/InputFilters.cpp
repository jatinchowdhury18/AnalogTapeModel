#include "InputFilters.h"

namespace
{
constexpr float minFreq = 20.0f;
constexpr float maxFreq = 22000.0f;
} // namespace

InputFilters::InputFilters (AudioProcessorValueTreeState& vts)
{
    lowCutParam = vts.getRawParameterValue ("ifilt_low");
    highCutParam = vts.getRawParameterValue ("ifilt_high");
    makeupParam = vts.getRawParameterValue ("ifilt_makeup");
    onOffParam = vts.getRawParameterValue ("ifilt_onoff");
}

void InputFilters::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    NormalisableRange lowFreqRange { minFreq, 2000.0f };
    lowFreqRange.setSkewForCentre (250.0f);

    NormalisableRange highFreqRange { 2000.0f, maxFreq };
    highFreqRange.setSkewForCentre (10000.0f);

    auto freqToString = [] (float freq, int) -> String
    {
        String suffix = " Hz";
        if (freq > 1000.0f)
        {
            freq /= 1000.0f;
            suffix = " kHz";
        }
        return String (freq, 2, false) + suffix;
    };

    auto stringToFreq = [] (const String& string) -> float
    {
        float freq = string.getFloatValue();
        if (string.getLastCharacter() == 'k')
            freq *= 1000.0f;

        return freq;
    };

    params.push_back (std::make_unique<AudioParameterBool> ("ifilt_onoff", "Input Filters On/Off", false));
    params.push_back (std::make_unique<AudioParameterFloat> ("ifilt_low", "Input Low Cut", lowFreqRange, minFreq, String(), AudioProcessorParameter::genericParameter, freqToString, stringToFreq));
    params.push_back (std::make_unique<AudioParameterFloat> ("ifilt_high", "Input High Cut", highFreqRange, maxFreq, String(), AudioProcessorParameter::genericParameter, freqToString, stringToFreq));
    params.push_back (std::make_unique<AudioParameterBool> ("ifilt_makeup", "Input Cut Makeup", false));
}

void InputFilters::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;
    dsp::ProcessSpec spec { sampleRate, (uint32) samplesPerBlock, 2 };
    lowCutFilter.prepare (spec);
    highCutFilter.prepare (spec);
    makeupDelay.prepare (spec);

    lowCutBuffer.setSize (2, samplesPerBlock);
    highCutBuffer.setSize (2, samplesPerBlock);
    makeupBuffer.setSize (2, samplesPerBlock);

    bypass.prepare (samplesPerBlock, bypass.toBool (onOffParam));
    makeupBypass.prepare (samplesPerBlock, bypass.toBool (onOffParam));
}

void InputFilters::processBlock (AudioBuffer<float>& buffer)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOffParam)))
        return;

    lowCutFilter.setCutoff (lowCutParam->load());
    highCutFilter.setCutoff (jmin (highCutParam->load(), fs * 0.48f));

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* data = buffer.getWritePointer (ch);
        auto* cutLowSignal = lowCutBuffer.getWritePointer (ch);
        auto* cutHighSignal = highCutBuffer.getWritePointer (ch);

        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            lowCutFilter.processSample ((size_t) ch, data[n], cutLowSignal[n], data[n]);
            highCutFilter.processSample ((size_t) ch, data[n], data[n], cutHighSignal[n]);
        }
    }

    bypass.processBlockOut (buffer, bypass.toBool (onOffParam));

    lowCutFilter.snapToZero();
    highCutFilter.snapToZero();
}

void InputFilters::processBlockMakeup (AudioBuffer<float>& buffer)
{
    if (! makeupBypass.processBlockIn (buffer, bypass.toBool (onOffParam)))
        return;

    if (! static_cast<bool> (makeupParam->load()))
    {
        makeupBypass.processBlockOut (buffer, bypass.toBool (onOffParam));
        return;
    }

    // compile makeup signal
    makeupBuffer.setSize (2, buffer.getNumSamples(), false, false, true);
    dsp::AudioBlock<float> lowCutBlock (lowCutBuffer);
    dsp::AudioBlock<float> highCutBlock (highCutBuffer);
    dsp::AudioBlock<float> makeupBlock (makeupBuffer);

    makeupBlock.fill (0.0f);
    makeupBlock += lowCutBlock;
    makeupBlock += highCutBlock;

    // delay makeup signal to be in phase with everything else
    dsp::ProcessContextReplacing<float> context (makeupBlock);
    makeupDelay.process (context);

    // add makeup back to main buffer
    dsp::AudioBlock<float> outputBlock (buffer);
    outputBlock += makeupBlock;

    makeupBypass.processBlockOut (buffer, bypass.toBool (onOffParam));
}
