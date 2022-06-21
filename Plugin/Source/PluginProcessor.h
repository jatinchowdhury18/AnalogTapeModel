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
JUCE_BEGIN_IGNORE_WARNINGS_GCC_LIKE ("-Wunused-parameter")
#include "clap-juce-extensions/clap-juce-extensions.h"
JUCE_END_IGNORE_WARNINGS_GCC_LIKE
#endif

#if CHOWDSP_AUTO_UPDATE
#include "GUI/AutoUpdating.h"
#endif

class ChowtapeModelAudioProcessor : public chowdsp::PluginBase<ChowtapeModelAudioProcessor>
{
public:
    ChowtapeModelAudioProcessor();

    static void addParameters (Parameters& params);

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processAudioBlock (AudioBuffer<float>&) override;
    void processBlockBypassed (AudioBuffer<float>&, MidiBuffer&) override;
    float calcLatencySamples() const noexcept;

    AudioProcessorEditor* createEditor() override;

    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    const AudioProcessorValueTreeState& getVTS() const { return vts; }
    AudioProcessorValueTreeState& getVTS() { return vts; }
    const AudioPlayHead::CurrentPositionInfo& getPositionInfo() const { return positionInfo; }
    auto* getOpenGLHelper() { return openGLHelper.get(); }
    auto& getOversampling() { return hysteresis.getOSManager(); }

private:
    using DryDelayType = chowdsp::DelayLine<float, chowdsp::DelayLineInterpolationTypes::Lagrange5th>;
    void latencyCompensation();

    chowdsp::SharedPluginSettings pluginSettings;

    chowdsp::FloatParameter* inGainDBParam = nullptr;
    chowdsp::FloatParameter* outGainDBParam = nullptr;
    chowdsp::FloatParameter* dryWetParam = nullptr;

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

    MyLNF myLNF;
    MixGroupsController mixGroupsController;
    AudioPlayHead::CurrentPositionInfo positionInfo;

    std::unique_ptr<chowdsp::OpenGLHelper> openGLHelper = nullptr;

#if CHOWDSP_AUTO_UPDATE
    AutoUpdater updater;
#endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowtapeModelAudioProcessor)
};
