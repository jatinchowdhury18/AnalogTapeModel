/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "GUI/OnOff/PowerButton.h"
#include "GUI/OversamplingMenu.h"
#include "GUI/TitleComp.h"
#include "GUI/TooltipComp.h"
#include "GUI/Visualizers/MixGroupViz.h"
#include "GUI/WowFlutterMenu.h"

#if JUCE_IOS
#include "GUI/IOSOnly/ScrollView.h"
#include "GUI/IOSOnly/TipJar.h"
#endif

namespace
{
constexpr int maxNumPresets = 999;
}

//==============================================================================
ChowtapeModelAudioProcessor::ChowtapeModelAudioProcessor()
    : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true).withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      vts (*this, nullptr, Identifier ("Parameters"), createParameterLayout()),
      inputFilters (vts),
      toneControl (vts),
      compressionProcessor (vts),
      hysteresis (vts, *this),
      degrade (vts),
      chewer (vts),
      lossFilter (vts),
      flutter (vts),
      onOffManager (vts, this),
      mixGroupsController (vts, this),
      midSideController (vts)
{
    positionInfo.bpm = 120.0;
    positionInfo.timeSigNumerator = 4;

    scope = magicState.createAndAddObject<TapeScope> ("scope", getMainBusNumInputChannels());
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

    params.push_back (std::make_unique<AudioParameterFloat> ("ingain", "Input Gain", -30.0f, 6.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("outgain", "Output Gain", -30.0f, 30.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("drywet", "Dry/Wet", 0.0f, 100.0f, 100.0f));
    params.push_back (std::make_unique<AudioParameterInt> ("preset", "Preset", 0, maxNumPresets, 0));

    InputFilters::createParameterLayout (params);
    ToneControl::createParameterLayout (params);
    CompressionProcessor::createParameterLayout (params);
    HysteresisProcessor::createParameterLayout (params);
    LossFilter::createParameterLayout (params);
    WowFlutterProcessor::createParameterLayout (params);
    DegradeProcessor::createParameterLayout (params);
    ChewProcessor::createParameterLayout (params);
    MidSideProcessor::createParameterLayout (params);
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
    midSideController.prepareToPlay (this->getNumInputChannels(), samplesPerBlock);

    inGain.prepareToPlay (sampleRate, samplesPerBlock);
    inputFilters.prepareToPlay (sampleRate, samplesPerBlock);
    toneControl.prepare (sampleRate);
    compressionProcessor.prepare (sampleRate, samplesPerBlock);
    hysteresis.prepareToPlay (sampleRate, samplesPerBlock);
    degrade.prepareToPlay (sampleRate, samplesPerBlock);
    chewer.prepare (sampleRate, samplesPerBlock);
    lossFilter.prepare ((float) sampleRate, samplesPerBlock);

    dryDelay.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
    dryDelay.setDelay (calcLatencySamples());

    flutter.prepareToPlay (sampleRate, samplesPerBlock);
    outGain.prepareToPlay (sampleRate, samplesPerBlock);

    scope->prepareToPlay (sampleRate, samplesPerBlock);

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
    return lossFilter.getLatencySamples() + hysteresis.getLatencySamples() + compressionProcessor.getLatencySamples();
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

    if (auto playhead = getPlayHead())
        playhead->getCurrentPosition (positionInfo);

    midSideController.processInput (buffer);
    inGain.setGain (Decibels::decibelsToGain (vts.getRawParameterValue ("ingain")->load()));
    outGain.setGain (Decibels::decibelsToGain (vts.getRawParameterValue ("outgain")->load()));
    dryWet.setDryWet (*vts.getRawParameterValue ("drywet") / 100.0f);

    dryBuffer.makeCopyOf (buffer, true);
    inGain.processBlock (buffer, midiMessages);
    inputFilters.processBlock (buffer);

    scope->pushSamplesIO (buffer, TapeScope::AudioType::Input);

    toneControl.processBlockIn (buffer);
    compressionProcessor.processBlock (buffer);
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

    midSideController.processOutput (buffer);
    scope->pushSamplesIO (buffer, TapeScope::AudioType::Output);
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
    builder->registerFactory ("InfoComp", &chowdsp::InfoItem::factory);
    builder->registerFactory ("TitleComp", &TitleItem::factory);
    builder->registerFactory ("MixGroupViz", &MixGroupVizItem::factory);
    builder->registerFactory ("PowerButton", &PowerButtonItem::factory);
    builder->registerFactory ("OversamplingMenu", &OversamplingMenu::factory);

    builder->registerFactory ("FlutterMenu", [] (foleys::MagicGUIBuilder& b, const ValueTree& node) -> std::unique_ptr<foleys::GuiItem> { return std::make_unique<WowFlutterMenuItem> (b, node, "Flutter"); });

    builder->registerFactory ("WowMenu", [] (foleys::MagicGUIBuilder& b, const ValueTree& node) -> std::unique_ptr<foleys::GuiItem> { return std::make_unique<WowFlutterMenuItem> (b, node, "Wow"); });

    builder->registerJUCELookAndFeels();
    builder->registerLookAndFeel ("MyLNF", std::make_unique<MyLNF>());
    builder->registerLookAndFeel ("ComboBoxLNF", std::make_unique<ComboBoxLNF>());
    builder->registerLookAndFeel ("PresetsLNF", std::make_unique<PresetsLNF>());
    builder->registerLookAndFeel ("SpeedButtonLNF", std::make_unique<SpeedButtonLNF>());

    if (auto* speedHandle = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("speed")))
    {
        for (auto speed : { 3.75f, 7.5f, 15.0f, 30.0f })
        {
            magicState.addTrigger ("set_speed_" + String (speed, 2, false), [speedHandle, speed]
                                   {
                                       speedHandle->beginChangeGesture();
                                       speedHandle->setValueNotifyingHost (speedHandle->convertTo0to1 (speed));
                                       speedHandle->endChangeGesture();
                                   });
        }
    }
    else
    {
        // speedHandle was nullptr!
        jassertfalse;
    }

#if JUCE_IOS
    builder->registerFactory ("ScrollView", &ScrollView::factory);
    builder->registerFactory ("TipJar", &TipJarItem::factory);
    auto* editor = new foleys::MagicPluginEditor (magicState, BinaryData::gui_ios_xml, BinaryData::gui_ios_xmlSize, std::move (builder));
#else
    auto* editor = new foleys::MagicPluginEditor (magicState, BinaryData::gui_xml, BinaryData::gui_xmlSize, std::move (builder));
#endif

    onOffManager.setOnOffForNewEditor (editor);

#if CHOWDSP_AUTO_UPDATE
    updater.showUpdaterScreen (editor);
#endif // CHOWDSP_AUTO_UPDATE

    // we need to set resize limits for StandalonePluginHolder
    editor->setResizeLimits (10, 10, 2000, 2000);

    return editor;
}

//==============================================================================
void ChowtapeModelAudioProcessor::getStateInformation (MemoryBlock& destData)
{
#if JUCE_IOS
    auto state = vts.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
#else
    magicState.getStateInformation (destData);
#endif
}

void ChowtapeModelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
#if JUCE_IOS
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (vts.state.getType()))
            vts.replaceState (juce::ValueTree::fromXml (*xmlState));
#else
    MessageManagerLock mml;
    magicState.setStateInformation (data, sizeInBytes, getActiveEditor());
#endif
    presetManager.presetUpdated();
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChowtapeModelAudioProcessor();
}
