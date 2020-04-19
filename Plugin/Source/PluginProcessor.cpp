/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"

//==============================================================================
ChowtapeModelAudioProcessor::ChowtapeModelAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    vts (*this, nullptr, Identifier ("Parameters"), createParameterLayout()),
    hysteresis (vts),
    degrade (vts),
    flutter (vts)
{
    for (int ch = 0; ch < 2; ++ch)
        lossFilter[ch].reset (new LossFilter (vts));

    scope = magicState.addPlotSource ("scope", std::make_unique<foleys::MagicOscilloscope>());
}

ChowtapeModelAudioProcessor::~ChowtapeModelAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout ChowtapeModelAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;

    params.push_back (std::make_unique<AudioParameterFloat> ("ingain",  "Input Gain [dB]",  -30.0f, 6.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("outgain", "Output Gain [dB]", -30.0f, 30.0f, 0.0f));

    HysteresisProcessor::createParameterLayout (params);
    LossFilter::createParameterLayout (params);
    Flutter::createParameterLayout (params);
    DegradeProcessor::createParameterLayout (params);

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
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ChowtapeModelAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ChowtapeModelAudioProcessor::setCurrentProgram (int index)
{
}

const String ChowtapeModelAudioProcessor::getProgramName (int index)
{
    return {};
}

void ChowtapeModelAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ChowtapeModelAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    inGain.prepareToPlay (sampleRate, samplesPerBlock);
    hysteresis.prepareToPlay (sampleRate, samplesPerBlock);
    degrade.prepareToPlay (sampleRate, samplesPerBlock);

    for (int ch = 0; ch < 2; ++ch)
        lossFilter[ch]->prepare ((float) sampleRate, samplesPerBlock);

    flutter.prepareToPlay (sampleRate, samplesPerBlock);
    outGain.prepareToPlay (sampleRate, samplesPerBlock);

    scope->prepareToPlay (sampleRate, samplesPerBlock);
}

void ChowtapeModelAudioProcessor::releaseResources()
{
    hysteresis.releaseResources();
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

void ChowtapeModelAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    
    inGain.setGain  (Decibels::decibelsToGain (*vts.getRawParameterValue ("ingain")));
    outGain.setGain (Decibels::decibelsToGain (*vts.getRawParameterValue ("outgain")));

    inGain.processBlock (buffer, midiMessages);
    hysteresis.processBlock (buffer, midiMessages);
    degrade.processBlock (buffer, midiMessages);
    
    flutter.processBlock (buffer, midiMessages);

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        lossFilter[ch]->processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());

    outGain.processBlock (buffer, midiMessages);

    scope->pushSamples (buffer);
}

//==============================================================================
bool ChowtapeModelAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ChowtapeModelAudioProcessor::createEditor()
{
    return new foleys::MagicPluginEditor (magicState, BinaryData::gui_xml, BinaryData::gui_xmlSize);
}

//==============================================================================
void ChowtapeModelAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    magicState.getStateInformation (destData);
}

void ChowtapeModelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    magicState.setStateInformation (data, sizeInBytes);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChowtapeModelAudioProcessor();
}
