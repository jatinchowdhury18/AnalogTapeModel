/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "GUI/ModulatableSlider.h"
#include "GUI/OnOff/PowerButton.h"
#include "GUI/OversamplingMenu.h"
#include "GUI/SettingsButton.h"
#include "GUI/TitleComp.h"
#include "GUI/TooltipComp.h"
#include "GUI/Visualizers/MixGroupViz.h"
#include "GUI/WowFlutterMenu.h"
#include "Presets/PresetManager.h"

#if JUCE_IOS
#include "GUI/IOSOnly/ScrollView.h"
#include "GUI/IOSOnly/TipJar.h"
#endif

namespace
{
const String settingsFilePath = "ChowdhuryDSP/ChowTape/.plugin_settings.json";

const String isStereoTag = "plugin:is_stereo";

const String inGainTag = "ingain";
const String outGainTag = "outgain";
const String dryWetTag = "drywet";
} // namespace

//==============================================================================
ChowtapeModelAudioProcessor::ChowtapeModelAudioProcessor() : inputFilters (vts),
                                                             midSideController (vts),
                                                             toneControl (vts),
                                                             compressionProcessor (vts),
                                                             hysteresis (vts),
                                                             degrade (vts),
                                                             chewer (vts),
                                                             lossFilter (vts),
                                                             flutter (vts),
                                                             onOffManager (vts, this),
                                                             mixGroupsController (vts, this)
{
    pluginSettings->initialise (settingsFilePath);

    chowdsp::ParamUtils::loadParameterPointer (inGainDBParam, vts, inGainTag);
    chowdsp::ParamUtils::loadParameterPointer (outGainDBParam, vts, outGainTag);
    chowdsp::ParamUtils::loadParameterPointer (dryWetParam, vts, dryWetTag);

    presetManager = std::make_unique<PresetManager> (vts);

    positionInfo.bpm = 120.0;
    positionInfo.timeSigNumerator = 4;

    scope = magicState.createAndAddObject<TapeScope> ("scope");
    flutter.initialisePlots (magicState);

    LookAndFeel::setDefaultLookAndFeel (&myLNF);

    PluginHostType hostType;
    if (hostType.isRenoise()) // Renoise has different gain staging, so we handle that here
        toneControl.setDBScale (12.0f);
    else
        toneControl.setDBScale (18.0f);
}

void ChowtapeModelAudioProcessor::addParameters (Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    createGainDBParameter (params, inGainTag, "Input Gain", -30.0f, 6.0f, 0.0f);
    createGainDBParameter (params, outGainTag, "Output Gain", -30.0f, 30.0f, 0.0f);
    createPercentParameter (params, dryWetTag, "Dry/Wet", 1.0f);

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
}

void ChowtapeModelAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    const auto numChannels = getTotalNumInputChannels();
    setRateAndBufferSizeDetails (sampleRate, samplesPerBlock);

    inGain.prepareToPlay (sampleRate, samplesPerBlock);
    inputFilters.prepareToPlay (sampleRate, samplesPerBlock, numChannels);
    midSideController.prepare (sampleRate, samplesPerBlock);
    toneControl.prepare (sampleRate, numChannels);
    compressionProcessor.prepare (sampleRate, samplesPerBlock, numChannels);
    hysteresis.prepareToPlay (sampleRate, samplesPerBlock, numChannels);
    degrade.prepareToPlay (sampleRate, samplesPerBlock, numChannels);
    chewer.prepare (sampleRate, samplesPerBlock, numChannels);
    lossFilter.prepare ((float) sampleRate, samplesPerBlock, numChannels);

    dryDelay.prepare ({ sampleRate, (uint32) samplesPerBlock, (uint32) numChannels });
    dryDelay.setDelay (calcLatencySamples());

    flutter.prepareToPlay (sampleRate, samplesPerBlock, numChannels);
    outGain.prepareToPlay (sampleRate, samplesPerBlock);

    scope->setNumChannels (numChannels);
    scope->prepareToPlay (sampleRate, samplesPerBlock);

    dryWet.setDryWet (*vts.getRawParameterValue ("drywet") / 100.0f);
    dryWet.reset();
    dryBuffer.setSize (numChannels, samplesPerBlock);

    setLatencySamples (roundToInt (calcLatencySamples()));
    magicState.getPropertyAsValue (isStereoTag).setValue (numChannels == 2);
}

void ChowtapeModelAudioProcessor::releaseResources()
{
    hysteresis.releaseResources();
}

float ChowtapeModelAudioProcessor::calcLatencySamples() const noexcept
{
    return lossFilter.getLatencySamples() + hysteresis.getLatencySamples() + compressionProcessor.getLatencySamples();
}

bool ChowtapeModelAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return ((! layouts.getMainInputChannelSet().isDiscreteLayout())
            && (! layouts.getMainOutputChannelSet().isDiscreteLayout())
            && (layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet())
            && (! layouts.getMainInputChannelSet().isDisabled()));
}

void ChowtapeModelAudioProcessor::processBlockBypassed (AudioBuffer<float>& buffer, MidiBuffer&)
{
    ScopedNoDenormals noDenormals;

    dryBuffer.makeCopyOf (buffer, true);
    latencyCompensation();
    buffer.makeCopyOf (dryBuffer, true);
}

void ChowtapeModelAudioProcessor::processAudioBlock (AudioBuffer<float>& buffer)
{
    if (auto* playhead = getPlayHead())
        playhead->getCurrentPosition (positionInfo);

    inGain.setGain (Decibels::decibelsToGain (inGainDBParam->getCurrentValue()));
    outGain.setGain (Decibels::decibelsToGain (outGainDBParam->getCurrentValue()));
    dryWet.setDryWet (dryWetParam->getCurrentValue());

    dryBuffer.makeCopyOf (buffer, true);
    inGain.processBlock (buffer);
    inputFilters.processBlock (buffer);

    scope->pushSamplesIO (buffer, TapeScope::AudioType::Input);

    midSideController.processInput (buffer);
    toneControl.processBlockIn (buffer);
    compressionProcessor.processBlock (buffer);
    hysteresis.processBlock (buffer);
    toneControl.processBlockOut (buffer);
    chewer.processBlock (buffer);
    degrade.processBlock (buffer);
    flutter.processBlock (buffer);
    lossFilter.processBlock (buffer);

    latencyCompensation();

    midSideController.processOutput (buffer);
    inputFilters.processBlockMakeup (buffer);
    outGain.processBlock (buffer);
    dryWet.processBlock (dryBuffer, buffer);

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
    {
        dryDelay.setDelay ((float) latencySamp);
    }
    else
    {
        dryDelay.setDelay (latencySampFloat);
    }

    dsp::AudioBlock<float> block { dryBuffer };
    dryDelay.process (dsp::ProcessContextReplacing<float> { block });
}

AudioProcessorEditor* ChowtapeModelAudioProcessor::createEditor()
{
    if (openGLHelper == nullptr)
        openGLHelper = std::make_unique<chowdsp::OpenGLHelper>();

    auto builder = std::make_unique<foleys::MagicGUIBuilder> (magicState);
    builder->registerJUCEFactories();
    builder->registerFactory ("presets", &chowdsp::PresetsItem<ChowtapeModelAudioProcessor>::factory);
    builder->registerFactory ("TooltipComp", &TooltipItem::factory);
    builder->registerFactory ("ModSlider", &ModSliderItem::factory);
    builder->registerFactory ("TitleComp", &TitleItem::factory);
    builder->registerFactory ("MixGroupViz", &MixGroupVizItem::factory);
    builder->registerFactory ("PowerButton", &PowerButtonItem::factory);
    builder->registerFactory ("OversamplingMenu", &chowdsp::OversamplingMenuItem<ChowtapeModelAudioProcessor, OversamplingMenu>::factory);
    builder->registerFactory ("SettingsButton", &SettingsButtonItem::factory);
    builder->registerFactory ("InfoComp", &chowdsp::InfoItem<ChowtapeModelAudioProcessor>::factory);

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
            magicState.addTrigger ("set_speed_" + String (speed, 2, false), [speedHandle, speed] {
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
#endif

    // we need to set resize limits for StandalonePluginHolder
    editor->setResizeLimits (10, 10, 2000, 2000);

    openGLHelper->setComponent (editor);

    return editor;
}

void ChowtapeModelAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto xml = std::make_unique<XmlElement> ("state");
    xml->setAttribute ("version", chowdsp::VersionUtils::Version (JucePlugin_VersionString).getVersionString());

    auto state = vts.copyState();
    xml->addChildElement (state.createXml().release());
    xml->addChildElement (presetManager->saveXmlState().release());

    copyXmlToBinary (*xml, destData);
}

void ChowtapeModelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto xmlState = getXmlFromBinary (data, sizeInBytes);
    if (xmlState == nullptr)
    {
        // let's check if state was saved with Foley's methods
        auto tree = ValueTree::readFromData (data, size_t (sizeInBytes));
        if (tree.isValid())
            vts.replaceState (tree);

        return;
    }

    if (xmlState->hasAttribute ("version"))
    {
        auto* vtsXml = xmlState->getChildByName (vts.state.getType());
        if (vtsXml == nullptr) // invalid ValueTreeState
            return;

        presetManager->loadXmlState (xmlState->getChildByName (chowdsp::PresetManager::presetStateTag));
        vts.replaceState (ValueTree::fromXml (*vtsXml));
    }
    else
    {
        // state was saved before we started tracking the version with the state,
        // so let's load state the old way...
        if (xmlState->hasTagName (vts.state.getType()))
            vts.replaceState (juce::ValueTree::fromXml (*xmlState));
    }
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChowtapeModelAudioProcessor();
}
