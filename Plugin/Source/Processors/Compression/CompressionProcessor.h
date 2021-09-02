#ifndef COMPRESSIONPROCESSOR_H_INCLUDED
#define COMPRESSIONPROCESSOR_H_INCLUDED

#include <JuceHeader.h>

class CompressionProcessor
{
public:
    CompressionProcessor (AudioProcessorValueTreeState& /*vts*/) {}

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
    {
        params.push_back (std::make_unique<AudioParameterBool> ("comp_onoff", "Compression On/Off", false));
        params.push_back (std::make_unique<AudioParameterFloat> ("comp_amt", "Compression Amount", 0.0f, 1.0f, 0.0f));
        params.push_back (std::make_unique<AudioParameterFloat> ("comp_attack", "Compression Attack", 0.0f, 1.0f, 0.0f));
        params.push_back (std::make_unique<AudioParameterFloat> ("comp_release", "Compression Release", 0.0f, 1.0f, 0.0f));
    }
};

#endif // COMPRESSIONPROCESSOR_H_INCLUDED
