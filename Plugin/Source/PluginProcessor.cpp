/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "GUI/InfoComp.h"
#include "GUI/MixGroupViz.h"
#include "GUI/PowerButton.h"
#include "GUI/ScreenshotHelper.h"
#include "GUI/TitleComp.h"
#include "GUI/TooltipComp.h"

namespace
{
constexpr int maxNumPresets = 999;
}

//==============================================================================
ChowtapeModelAudioProcessor::ChowtapeModelAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                          .withInput ("Input", AudioChannelSet::stereo(), true)
#endif
                          .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                          ),
#endif
      vts (*this, nullptr, Identifier ("Parameters"), createParameterLayout()),
      inputFilters (vts),
      toneControl (vts),
      hysteresis (vts),
      degrade (vts),
      chewer (vts),
      lossFilter (vts),
      flutter (vts),
      onOffManager (vts, this),
      mixGroupsController (vts, this)
{
    scope = magicState.createAndAddObject<TapeScope> ("scope");
    flutter.initialisePlots (magicState);

    LookAndFeel::setDefaultLookAndFeel (&myLNF);

    PluginHostType hostType;
    if (hostType.isRenoise()) // Renoise has different gain staging, so we handle that here
        toneControl.setDBScale (12.0f);
    else
        toneControl.setDBScale (18.0f);
}

ChowtapeModelAudioProcessor::~ChowtapeModelAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout ChowtapeModelAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;

    params.push_back (std::make_unique<AudioParameterFloat> ("ingain", "Input Gain [dB]", -30.0f, 6.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("outgain", "Output Gain [dB]", -30.0f, 30.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("drywet", "Dry/Wet", 0.0f, 100.0f, 100.0f));
    params.push_back (std::make_unique<AudioParameterInt> ("preset", "Preset", 0, maxNumPresets, 0));

    InputFilters::createParameterLayout (params);
    ToneControl::createParameterLayout (params);
    HysteresisProcessor::createParameterLayout (params);
    LossFilter::createParameterLayout (params);
    Flutter::createParameterLayout (params);
    DegradeProcessor::createParameterLayout (params);
    ChewProcessor::createParameterLayout (params);
    MixGroupsController::createParameterLayout (params);

    return { params.begin(), params.end() };
}

//==============================================================================
const String ChowtapeModelAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ChowtapeModelAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool ChowtapeModelAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool ChowtapeModelAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double ChowtapeModelAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ChowtapeModelAudioProcessor::getNumPrograms()
{
    return presetManager.getNumPresets();
}

int ChowtapeModelAudioProcessor::getCurrentProgram()
{
    return (int) *vts.getRawParameterValue ("preset");
}

void ChowtapeModelAudioProcessor::setCurrentProgram (int index)
{
    if (index > maxNumPresets)
        return;

    auto& presetParam = *vts.getRawParameterValue ("preset");
    if ((int) presetParam == index)
        return;

    if (presetManager.setPreset (vts, index))
    {
        presetParam = (float) index;
        presetManager.presetUpdated();
        updateHostDisplay();
    }
}

const String ChowtapeModelAudioProcessor::getProgramName (int index)
{
    return presetManager.getPresetName (index);
}

void ChowtapeModelAudioProcessor::changeProgramName (int index, const String& newName)
{
    ignoreUnused (index, newName);
}

//==============================================================================
void ChowtapeModelAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    inGain.prepareToPlay (sampleRate, samplesPerBlock);
    inputFilters.prepareToPlay (sampleRate, samplesPerBlock);
    toneControl.prepare (sampleRate);
    hysteresis.prepareToPlay (sampleRate, samplesPerBlock);
    degrade.prepareToPlay (sampleRate, samplesPerBlock);
    chewer.prepare (sampleRate, samplesPerBlock);
    lossFilter.prepare ((float) sampleRate, samplesPerBlock);

    dryDelay.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
    dryDelay.setDelay (calcLatencySamples());

    flutter.prepareToPlay (sampleRate, samplesPerBlock);
    outGain.prepareToPlay (sampleRate, samplesPerBlock);

    scope->prepareToPlay (getMainBusNumInputChannels(), sampleRate, samplesPerBlock);

    dryWet.setDryWet (*vts.getRawParameterValue ("drywet") / 100.0f);
    dryWet.reset();
    dryBuffer.setSize (2, samplesPerBlock);

    setLatencySamples (roundToInt (calcLatencySamples()));
}

void ChowtapeModelAudioProcessor::releaseResources()
{
    hysteresis.releaseResources();
}

float ChowtapeModelAudioProcessor::calcLatencySamples() const noexcept
{
    return lossFilter.getLatencySamples() + hysteresis.getLatencySamples();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ChowtapeModelAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

        // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif

    return true;
#endif
}
#endif

void ChowtapeModelAudioProcessor::processBlockBypassed (AudioBuffer<float>& buffer, MidiBuffer&)
{
    ScopedNoDenormals noDenormals;

    dryBuffer.makeCopyOf (buffer, true);
    latencyCompensation();
    buffer.makeCopyOf (dryBuffer, true);
}

void ChowtapeModelAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;

    inGain.setGain (Decibels::decibelsToGain (vts.getRawParameterValue ("ingain")->load()));
    outGain.setGain (Decibels::decibelsToGain (vts.getRawParameterValue ("outgain")->load()));
    dryWet.setDryWet (*vts.getRawParameterValue ("drywet") / 100.0f);

    dryBuffer.makeCopyOf (buffer, true);
    inGain.processBlock (buffer, midiMessages);
    inputFilters.processBlock (buffer);

    scope->pushSamples (buffer, TapeScope::AudioType::Input);

    toneControl.processBlockIn (buffer);
    hysteresis.processBlock (buffer, midiMessages);
    toneControl.processBlockOut (buffer);
    chewer.processBlock (buffer);
    degrade.processBlock (buffer, midiMessages);
    flutter.processBlock (buffer, midiMessages);
    lossFilter.processBlock (buffer);

    latencyCompensation();

    inputFilters.processBlockMakeup (buffer);
    outGain.processBlock (buffer, midiMessages);
    dryWet.processBlock (dryBuffer, buffer);

    scope->pushSamples (buffer, TapeScope::AudioType::Output);
}

void ChowtapeModelAudioProcessor::latencyCompensation()
{
    // delay dry buffer to avoid phase issues
    const auto latencySampFloat = calcLatencySamples();
    const auto latencySamp = roundToInt (latencySampFloat);
    setLatencySamples (latencySamp);

    // delay makeup block from input filters
    inputFilters.setMakeupDelay (latencySampFloat);

    // For "true bypass" use integer sample delay to avoid delay
    // line interpolation freq. response issues
    if (dryWet.getDryWet() < 0.15f)
        dryDelay.setDelay ((float) latencySamp);
    else
        dryDelay.setDelay (latencySampFloat);

    dsp::AudioBlock<float> block { dryBuffer };
    dryDelay.process (dsp::ProcessContextReplacing<float> { block });
}

bool ChowtapeModelAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* ChowtapeModelAudioProcessor::createEditor()
{
    auto builder = std::make_unique<foleys::MagicGUIBuilder> (magicState);
    builder->registerJUCEFactories();
    presetManager.registerPresetsComponent (*builder);
    builder->registerFactory ("TooltipComp", &TooltipItem::factory);
    builder->registerFactory ("InfoComp", &InfoItem::factory);
    builder->registerFactory ("TitleComp", &TitleItem::factory);
    builder->registerFactory ("MixGroupViz", &MixGroupVizItem::factory);
    builder->registerFactory ("PowerButton", &PowerButtonItem::factory);

    builder->registerJUCELookAndFeels();
    builder->registerLookAndFeel ("MyLNF", std::make_unique<MyLNF>());
    builder->registerLookAndFeel ("ComboBoxLNF", std::make_unique<ComboBoxLNF>());
    builder->registerLookAndFeel ("PresetsLNF", std::make_unique<PresetsLNF>());
    builder->registerLookAndFeel ("SpeedButtonLNF", std::make_unique<SpeedButtonLNF>());

    auto* speedHandle = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("speed"));
    for (auto speed : { 3.75f, 7.5f, 15.0f, 30.0f })
    {
        magicState.addTrigger ("set_speed_" + String (speed, 2, false), [speedHandle, speed] {
            speedHandle->beginChangeGesture();
            speedHandle->setValueNotifyingHost (speedHandle->convertTo0to1 (speed));
            speedHandle->endChangeGesture();
        });
    }

    auto* editor = new foleys::MagicPluginEditor (magicState, BinaryData::gui_xml, BinaryData::gui_xmlSize, std::move (builder));
    onOffManager.setOnOffForNewEditor (editor);
    updater.showUpdaterScreen (editor);
    return editor;
}

//==============================================================================
void ChowtapeModelAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    magicState.getStateInformation (destData);
}

void ChowtapeModelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    MessageManagerLock mml;
    magicState.setStateInformation (data, sizeInBytes, getActiveEditor());
    presetManager.presetUpdated();
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
#ifdef TAKE_SCREENSHOTS
    ScreenshotHelper::takeScreenshots (std::make_unique<ChowtapeModelAudioProcessor>());
#endif

    return new ChowtapeModelAudioProcessor();
}
