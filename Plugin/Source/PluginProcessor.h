/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "GUI/MyLNF.h"
#include "GUI/OnOff/OnOffManager.h"
#include "GUI/Visualizers/TapeScope.h"
#include "MixGroups/MixGroupsController.h"
#include "Presets/PresetManager.h"
#include "Processors/Chew/ChewProcessor.h"
#include "Processors/Compression/CompressionProcessor.h"
#include "Processors/Degrade/DegradeProcessor.h"
#include "Processors/DryWetProcessor.h"
#include "Processors/GainProcessor.h"
#include "Processors/Hysteresis/HysteresisProcessor.h"
#include "Processors/Hysteresis/ToneControl.h"
#include "Processors/Input_Filters/InputFilters.h"
#include "Processors/Loss_Effects/LossFilter.h"
#include "Processors/MidSide/MidSideProcessor.h"
#include "Processors/Timing_Effects/WowFlutterProcessor.h"

#if HAS_CLAP_JUCE_EXTENSIONS
#include "clap-juce-extensions/clap-juce-extensions.h"
#endif

#if CHOWDSP_AUTO_UPDATE
#include "GUI/AutoUpdating.h"
#endif // CHOWDSP_AUTO_UPDATE

//==============================================================================
/**
*/
class ChowtapeModelAudioProcessor : public AudioProcessor
#if HAS_CLAP_JUCE_EXTENSIONS
    ,
                                    private clap_juce_extensions::clap_properties
#endif
{
public:
    //==============================================================================
    ChowtapeModelAudioProcessor();
    ~ChowtapeModelAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

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

    String getWrapperTypeString() const;
    PresetManager& getPresetManager() { return presetManager; }
    const AudioProcessorValueTreeState& getVTS() const { return vts; }
    AudioProcessorValueTreeState& getVTS() { return vts; }
    const AudioPlayHead::CurrentPositionInfo& getPositionInfo() const { return positionInfo; }
    HysteresisProcessor& getHysteresisProcessor() { return hysteresis; }
    auto* getOpenGLHelper() { return openGLHelper.get(); }
    auto& getOversampling() { return hysteresis.getOSManager(); }

private:
    using DryDelayType = chowdsp::DelayLine<float, chowdsp::DelayLineInterpolationTypes::Lagrange5th>;

    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void latencyCompensation();

    chowdsp::SharedPluginSettings pluginSettings;
    AudioProcessorValueTreeState vts;

    GainProcessor inGain;
    InputFilters inputFilters;
    MidSideProcessor midSideController;
    ToneControl toneControl;
    CompressionProcessor compressionProcessor;
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
    MixGroupsController mixGroupsController;
    AudioPlayHead::CurrentPositionInfo positionInfo;

    std::unique_ptr<chowdsp::OpenGLHelper> openGLHelper = nullptr;

#if CHOWDSP_AUTO_UPDATE
    AutoUpdater updater;
#endif // CHOWDSP_AUTO_UPDATE

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessor)
};
