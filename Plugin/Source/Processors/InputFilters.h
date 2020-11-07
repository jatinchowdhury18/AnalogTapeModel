#ifndef INPUTFILTERS_H_INCLUDED
#define INPUTFILTERS_H_INCLUDED

#include <JuceHeader.h>

class InputFilters
{
public:
    InputFilters (AudioProcessorValueTreeState& vts);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

private:
    std::atomic<float>* lowCutParam  = nullptr;
    std::atomic<float>* highCutParam = nullptr;
    std::atomic<float>* makeupParam  = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputFilters)
};

#endif // !INPUTFILTERS_H_INCLUDED

