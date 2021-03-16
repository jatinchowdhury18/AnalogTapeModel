/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "GUI/AutoUpdating.h"
#include "GUI/MyLNF.h"
#include "GUI/OnOffManager.h"
#include "GUI/TapeScope.h"
#include "MixGroups/MixGroupsController.h"
#include "Presets/PresetManager.h"
#include "Processors/Chew/ChewProcessor.h"
#include "Processors/Degrade/DegradeProcessor.h"
#include "Processors/DryWetProcessor.h"
#include "Processors/GainProcessor.h"
#include "Processors/Hysteresis/HysteresisProcessor.h"
#include "Processors/Hysteresis/ToneControl.h"
#include "Processors/Input_Filters/InputFilters.h"
#include "Processors/Loss_Effects/LossFilter.h"
#include "Processors/Timing_Effects/WowFlutterProcessor.h"
#include <JuceHeader.h>

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
    void processBlockBypassed (AudioBuffer<float>&, MidiBuffer&) override;

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
    using DryDelayType = chowdsp::DelayLine<float, chowdsp::DelayLineInterpolationTypes::Lagrange5th>;

    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void latencyCompensation();

    AudioProcessorValueTreeState vts;

    GainProcessor inGain;
    InputFilters inputFilters;
    ToneControl toneControl;
    HysteresisProcessor hysteresis;
    DegradeProcessor degrade;
    ChewProcessor chewer;
    LossFilter lossFilter;
    WowFlutterProcessor flutter;
    DryWetProcessor dryWet;
    DryDelayType dryDelay { 1 << 21 };
    GainProcessor outGain;
    OnOffManager onOffManager;

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
