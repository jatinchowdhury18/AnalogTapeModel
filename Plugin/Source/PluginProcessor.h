/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Processors/GainProcessor.h"
#include "Processors/Hysteresis/HysteresisProcessor.h"
#include "Processors/Hysteresis/ToneControl.h"
#include "Processors/Loss_Effects/LossFilter.h"
#include "Processors/Timing_Effects/Flutter.h"
#include "Processors/Degrade/DegradeProcessor.h"
#include "Processors/Chew/ChewProcessor.h"
#include "Processors/DryWetProcessor.h"
#include "Processors/InputFilters.h"
#include "Presets/PresetManager.h"
#include "GUI/MyLNF.h"
#include "GUI/AutoUpdating.h"
#include "GUI/TapeScope.h"
#include "MixGroups/MixGroupsController.h"

//==============================================================================
/**
*/
class ChowtapeModelAudioProcessor : public AudioProcessor
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
    float calcLatencySamples() const noexcept;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    PresetManager& getPresetManager() { return presetManager; }
    const AudioProcessorValueTreeState& getVTS() { return vts; }
    
private:
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void latencyCompensation();

    AudioProcessorValueTreeState vts;

    GainProcessor inGain;
    InputFilters inputFilters;
    ToneControl toneControl;
    HysteresisProcessor hysteresis;
    DegradeProcessor degrade;
    ChewProcessor chewer;
    std::unique_ptr<LossFilter> lossFilter[2];
    Flutter flutter;
    DryWetProcessor dryWet;
    dsp::DelayLine<float, dsp::DelayLineInterpolationTypes::Lagrange3rd> dryDelay { 1 << 21 };
    GainProcessor outGain;

    AudioBuffer<float> dryBuffer;
    
    foleys::MagicProcessorState magicState { *this, vts };
    TapeScope* scope = nullptr;

    PresetManager presetManager;
    MyLNF myLNF;
    AutoUpdater updater;
    MixGroupsController mixGroupsController;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessor)
};
