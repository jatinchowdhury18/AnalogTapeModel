#include "PluginProcessor.h"
#include "PluginEditor.h"

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
                       )
#endif
{
    //Main Controls
    addParameter (inGain = new AudioParameterFloat (String ("inGain"), String ("Input Gain"), -30.0f, 30.0f, 0.0f));
    inGain->addListener (this);

    addParameter (outGain = new AudioParameterFloat (String ("outGain"), String ("Output Gain"), -30.0f, 30.0f, 0.0f));
    outGain->addListener (this);

    addParameter (overSampling = new AudioParameterChoice (String ("overSampling"), String ("Upsample"),
                                                           StringArray ({ "2x", "4x", "8x", "16x" }), 3));
    overSampling->addListener (this);

    addParameter (tapeSpeed = new AudioParameterChoice (String ("tapeSpeed"), String ("Speed"),
                                                        StringArray ({ "3.75 ips", "7.5 ips", "15 ips" }), 1));
    tapeSpeed->addListener (this);

    addParameter (tapeType = new AudioParameterChoice (String ("tapeType"), String ("Tape Type"),
                                                       StringArray ({ "Iron Oxide", "Chromium Oxide" }), 0));
    tapeType->addListener(this);

    //Bias Controls
    addParameter (biasFreq = new AudioParameterFloat (String ("biasFreq"), String ("Bias Frequency"), 45.0f, 55.0f, 50.0));
    biasFreq->addListener (this);

    addParameter (biasGain = new AudioParameterFloat (String ("biasGain"), String ("Bias Gain"), 0.0f, 10.0f, 5.0f));
    biasGain->addListener (this);

    //Loss Controls
    addParameter (tapeSpacing = new AudioParameterFloat (String ("tapeSpacing"), String ("Spacing"), 0.0f, 50.0f, 0.001f));
    tapeSpacing->addListener (this);

    addParameter (tapeThickness = new AudioParameterFloat (String ("tapeThickness"), String ("Thickness"), 0.0f, 50.0f, 10.0f));
    tapeThickness->addListener (this);

    addParameter (gapWidth = new AudioParameterFloat (String ("gapWidth"), String ("Gap Width"), 2.5f, 12.0f, 3.0f));
    gapWidth->addListener (this);

    //Timing Controls
    addParameter (flutterDepth = new AudioParameterFloat (String ("flutterDepth"), String ("Flutter Depth"), 0.0f, 5.0f, 1.0f));
    flutterDepth->addListener (this);

    lossEffects.setSpeed (*tapeSpeed);
    hysteresis.setOverSamplingFactor (*overSampling);
    hysteresis.setBiasFreq (*biasFreq);
    timingEffect.setDepth (*flutterDepth);
}

ChowtapeModelAudioProcessor::~ChowtapeModelAudioProcessor()
{
}

void ChowtapeModelAudioProcessor::parameterValueChanged (int paramIndex, float /*newValue*/)
{
    if (paramIndex == inGain->getParameterIndex())
        inGainProc.setGain (Decibels::decibelsToGain ((float) *inGain));
    else if (paramIndex == outGain->getParameterIndex())
        outGainProc.setGain (Decibels::decibelsToGain ((float) *outGain));
    //else if (paramIndex == overSampling->getParameterIndex())
    //    hysteresis.setOverSamplingFactor (*overSampling);
    else if (paramIndex == tapeSpeed->getParameterIndex())
    {
        lossEffects.setSpeed (*tapeSpeed);
        timingEffect.setTapeSpeed (*tapeSpeed);
    }
    //else if (paramIndex == tapeType->getParameterIndex())
    //    return; //@TODO
    //else if (paramIndex == biasFreq->getParameterIndex())
    //    hysteresis.setBiasFreq (*biasFreq);
    else if (paramIndex == biasGain->getParameterIndex())
        hysteresis.setBiasGain (*biasGain);
    else if (paramIndex == tapeSpacing->getParameterIndex())
        lossEffects.setSpacing (*tapeSpacing);
    else if (paramIndex == tapeThickness->getParameterIndex())
        lossEffects.setThickness (*tapeThickness);
    else if (paramIndex == gapWidth->getParameterIndex())
        lossEffects.setGap (*gapWidth);
    else if (paramIndex == flutterDepth->getParameterIndex())
        timingEffect.setDepth (*flutterDepth);
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

void ChowtapeModelAudioProcessor::setCurrentProgram (int /*index*/)
{
}

const String ChowtapeModelAudioProcessor::getProgramName (int /*index*/)
{
    return {};
}

void ChowtapeModelAudioProcessor::changeProgramName (int /*index*/, const String& /*newName*/)
{
}

//==============================================================================
void ChowtapeModelAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    inGainProc.prepareToPlay (sampleRate, samplesPerBlock);
    hysteresis.prepareToPlay (sampleRate, samplesPerBlock);
    timingEffect.prepareToPlay (sampleRate, samplesPerBlock);
    lossEffects.prepareToPlay (sampleRate, samplesPerBlock);
    outGainProc.prepareToPlay (sampleRate, samplesPerBlock);
}

void ChowtapeModelAudioProcessor::releaseResources()
{
    inGainProc.releaseResources();
    hysteresis.releaseResources();
    timingEffect.releaseResources();
    lossEffects.releaseResources();
    outGainProc.releaseResources();
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
    
    inGainProc.processBlock (buffer, midiMessages);

    hysteresis.processBlock (buffer, midiMessages);

    timingEffect.processBlock (buffer, midiMessages);

    lossEffects.processBlock (buffer, midiMessages);

    outGainProc.processBlock (buffer, midiMessages);
}

//==============================================================================
bool ChowtapeModelAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ChowtapeModelAudioProcessor::createEditor()
{
    return new ChowtapeModelAudioProcessorEditor (*this);
}

//==============================================================================
void ChowtapeModelAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    std::unique_ptr<XmlElement> xml (new XmlElement ("ChowTapeXmlData"));

    xml->setAttribute ("inGain", (double) *inGain);
    xml->setAttribute ("outGain", (double) *outGain);
    xml->setAttribute ("tapeSpeed", tapeSpeed->getIndex());
    xml->setAttribute ("biasGain", (double) *biasGain);
    xml->setAttribute ("tapeSpacing", (double) *tapeSpacing);
    xml->setAttribute ("tapeThickness", (double) *tapeThickness);
    xml->setAttribute ("gapWidth", (double) *gapWidth);
    xml->setAttribute ("flutterDepth", (double) *flutterDepth);

    copyXmlToBinary (*xml, destData);
}

void ChowtapeModelAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState.get() != nullptr)
    {
        if (xmlState->hasTagName ("ChowTapeXmlData"))
        {
            *inGain = (float) xmlState->getDoubleAttribute ("inGain", 0.0);
            *outGain = (float) xmlState->getDoubleAttribute ("outGain", 0.0);
            *tapeSpeed = xmlState->getIntAttribute ("tapeSpeed", 0);
            *biasGain= (float) xmlState->getDoubleAttribute ("biasGain", 0.0);
            *tapeSpacing = (float) xmlState->getDoubleAttribute ("tapeSpacing", 0.0);
            *tapeThickness = (float) xmlState->getDoubleAttribute ("tapeThickness", 0.0);
            *gapWidth= (float) xmlState->getDoubleAttribute ("gapWidth", 0.0);
            *flutterDepth= (float) xmlState->getDoubleAttribute ("flutterDepth", 0.0);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ChowtapeModelAudioProcessor();
}
