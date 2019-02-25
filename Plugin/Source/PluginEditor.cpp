#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ChowtapeModelAudioProcessorEditor::ChowtapeModelAudioProcessorEditor (ChowtapeModelAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    mainControls.reset (new MainControls (processor));
    addAndMakeVisible (mainControls.get());

    biasControls.reset (new BiasControls (processor));
    addAndMakeVisible (biasControls.get());

    lossControls.reset (new LossControls (processor));
    addAndMakeVisible (lossControls.get());

    timingControls.reset (new TimingControls (processor));
    addAndMakeVisible (timingControls.get());

    setSize (width, height);
}

ChowtapeModelAudioProcessorEditor::~ChowtapeModelAudioProcessorEditor()
{
}

void ChowtapeModelAudioProcessorEditor::createSlider (ChowSlider& slide, AudioParameterFloat* param, LookAndFeel& lnf,
                                                      Component* comp, String suffix, float step){
    slide.setName(param->name);
    slide.setRange(param->range.start, param->range.end, step);
    slide.setDefaultValue (param->convertFrom0to1 (dynamic_cast<AudioProcessorParameterWithID*> (param)->getDefaultValue()));
    slide.setValue(*param);

    slide.setLookAndFeel (&lnf);
    slide.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    slide.setColour(Slider::rotarySliderFillColourId, Colours::black);
    slide.setColour(Slider::rotarySliderOutlineColourId, Colours::darkred);
    slide.setColour(Slider::thumbColourId, Colours::antiquewhite);
    slide.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    slide.setColour(Slider::textBoxTextColourId, Colours::antiquewhite);
    slide.setColour(Slider::textBoxOutlineColourId, Colours::antiquewhite);

    if (suffix.isNotEmpty())
        slide.setTextValueSuffix (" " + suffix);

    slide.addListener (dynamic_cast<Slider::Listener*> (comp));
    comp->addAndMakeVisible (slide);
}

void ChowtapeModelAudioProcessorEditor::createComboBox (ComboBox& box, AudioParameterChoice* choice, Component* comp)
{
    box.setName (choice->name);
    box.addItemList (choice->getAllValueStrings(), 1);
    box.setSelectedItemIndex (*choice);

    box.setColour (ComboBox::backgroundColourId, Colours::black);
    box.setColour (ComboBox::outlineColourId, Colours::saddlebrown);
    box.setColour (ComboBox::textColourId, Colours::antiquewhite);
    box.setColour (ComboBox::arrowColourId, Colours::antiquewhite);

    box.addListener (dynamic_cast<ComboBox::Listener*> (comp));
    comp->addAndMakeVisible (box);
}

void ChowtapeModelAudioProcessorEditor::createLabel (Label& label, AudioProcessorParameterWithID* param, Component* comp)
{
    label.setText (param->name, dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setColour (Label::textColourId, Colours::antiquewhite);
    label.setFont (17.0f);

    comp->addAndMakeVisible (label);
}

//==============================================================================
void ChowtapeModelAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::saddlebrown);

    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());
    g.drawFittedText ("CHOW Tape Model", getLocalBounds().removeFromTop (nameHeight), Justification::centred, 1);

    g.drawHorizontalLine (sectionHeight, 0, width);
    g.drawHorizontalLine (2 * sectionHeight, 0, width);
    g.drawHorizontalLine (3 * sectionHeight, 0, width);
}

void ChowtapeModelAudioProcessorEditor::resized()
{
    mainControls->setBounds (0, 0, width, sectionHeight);
    biasControls->setBounds (0, sectionHeight, width, sectionHeight);
    lossControls->setBounds (0, 2 * sectionHeight, width, sectionHeight);
    timingControls->setBounds (0, 3 * sectionHeight, width, sectionHeight);
}

AudioParameterFloat* ChowtapeModelAudioProcessorEditor::getParamForSlider (Slider* slider, ChowtapeModelAudioProcessor& proc)
{
    if (proc.inGain->name == slider->getName())
        return proc.inGain;
    else if (proc.outGain->name == slider->getName())
        return proc.outGain;
    else if (proc.biasFreq->name == slider->getName())
        return proc.biasFreq;
    else if (proc.biasGain->name == slider->getName())
        return proc.biasGain;
    else if (proc.tapeSpacing->name == slider->getName())
        return proc.tapeSpacing;
    else if (proc.tapeThickness->name == slider->getName())
        return proc.tapeThickness;
    else if (proc.gapWidth->name == slider->getName())
        return proc.gapWidth;
    else if (proc.flutterDepth->name == slider->getName())
        return proc.flutterDepth;
    else
        return nullptr;
}

AudioParameterChoice* ChowtapeModelAudioProcessorEditor::getParamForBox (ComboBox* box, ChowtapeModelAudioProcessor& proc)
{
    if (proc.overSampling->name == box->getName())
        return proc.overSampling;
    else if (proc.tapeSpeed->name == box->getName())
        return proc.tapeSpeed;
    else if (proc.tapeType->name == box->getName())
        return proc.tapeType;
    else
        return nullptr;
}
