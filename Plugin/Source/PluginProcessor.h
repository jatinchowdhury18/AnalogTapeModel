#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Processors/Hysteresis/HysteresisProcessor.h"
#include "Processors/GainProcessor.h"
#include "Processors/Speed Filters/SpeedFilterProcessor.h"
#include "Processors/Loss Effects/LossEffectsFilter.h"

//==============================================================================
/**
*/
class ChowtapeModelAudioProcessor  : public AudioProcessor,
                                     public AudioProcessorParameter::Listener
{
public:
    //==============================================================================
    ChowtapeModelAudioProcessor();
    ~ChowtapeModelAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    AudioParameterFloat* inGain;
    AudioParameterFloat* outGain;
    AudioParameterChoice* overSampling;
    AudioParameterChoice* tapeSpeed;

    void parameterValueChanged (int paramIndex, float newValue) override;
    void parameterGestureChanged (int /*paramIndex*/, bool /*gestureIsStarting*/) override {}

private:
    SpeedFilterProcessor speedFilter;
    HysteresisProcessor hysteresis;
    LossEffectsFilter lossEffects;

    GainProcessor inGainProc;
    GainProcessor outGainProc;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessor)
};
