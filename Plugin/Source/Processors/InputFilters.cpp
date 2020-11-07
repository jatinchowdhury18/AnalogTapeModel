#include "InputFilters.h"

InputFilters::InputFilters (AudioProcessorValueTreeState& vts)
{
    lowCutParam  = vts.getRawParameterValue ("ifilt_low");
    highCutParam = vts.getRawParameterValue ("ifilt_high");
    makeupParam  = vts.getRawParameterValue ("ifilt_makeup");
}

void InputFilters::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    NormalisableRange lowFreqRange { 20.0f, 1000.0f };
    lowFreqRange.setSkewForCentre (100.0f);

    NormalisableRange highFreqRange { 2000.0f, 22000.0f };
    highFreqRange.setSkewForCentre (10000.0f);

    auto freqToString = [] (float freq, int) -> String {
        String suffix = " Hz";
        if (freq > 1000.0f) { freq /= 1000.0f; suffix = " kHz"; }
        return String (freq, 2, false) + suffix;
    };

    auto stringToFreq = [] (const String& string) -> float {
        float freq = string.getFloatValue();
        if (string.getLastCharacter() == 'k')
            freq *= 1000.0f;

        return freq;
    };

    params.push_back (std::make_unique<AudioParameterFloat> ("ifilt_low",  "Low Cut",  lowFreqRange,  20.0f,
        String(), AudioProcessorParameter::genericParameter, freqToString, stringToFreq));
    params.push_back (std::make_unique<AudioParameterFloat> ("ifilt_high", "High Cut", highFreqRange, 22000.0f,
        String(), AudioProcessorParameter::genericParameter, freqToString, stringToFreq));
    params.push_back (std::make_unique<AudioParameterBool>  ("ifilt_makeup", "Cut Makeup", false));
}
