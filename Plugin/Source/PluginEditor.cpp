#include "PluginProcessor.h"
#include "PluginEditor.h"

enum
{
    width = 375,
    height = 150,

    nameHeight = 20,

    xOffset = 2,
    yOffset = 5,

    labelY = 15,
    labelHeight = 20,

    sliderWidth = 110,
    sliderY = 25,

    overWidth = 65,
    tapeWidth = 90,
    boxHeight = 25,
    boxY = 75,
};

//==============================================================================
ChowtapeModelAudioProcessorEditor::ChowtapeModelAudioProcessorEditor (ChowtapeModelAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (width, height);

    createSlider (gainInKnob, processor.inGain, String ("dB"));
    createSlider (gainOutKnob, processor.outGain, String ("dB"));

    createComboBox (oversampling, processor.overSampling);
    createComboBox (tapeSpeed, processor.tapeSpeed);

    createLabel (inGainLabel, processor.inGain);
    createLabel (outGainLabel, processor.outGain);
    createLabel (oversampleLabel, processor.overSampling);
    createLabel (speedLabel, processor.tapeSpeed);
}

ChowtapeModelAudioProcessorEditor::~ChowtapeModelAudioProcessorEditor()
{
}

void ChowtapeModelAudioProcessorEditor::createSlider (ChowSlider& slide, AudioParameterFloat* param, String suffix, float step){
    slide.setName(param->name);
    slide.setRange(param->range.start, param->range.end, step);
    slide.setDefaultValue (param->convertFrom0to1 (dynamic_cast<AudioProcessorParameterWithID*> (param)->getDefaultValue()));
    slide.setValue(*param);

    slide.setLookAndFeel (&myLNF);
    slide.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    slide.setColour(Slider::rotarySliderFillColourId, Colours::black);
    slide.setColour(Slider::rotarySliderOutlineColourId, Colours::darkred);
    slide.setColour(Slider::thumbColourId, Colours::antiquewhite);
    slide.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    slide.setColour(Slider::textBoxTextColourId, Colours::antiquewhite);
    slide.setColour(Slider::textBoxOutlineColourId, Colours::antiquewhite);

    if (suffix.isNotEmpty())
        slide.setTextValueSuffix (" " + suffix);

    slide.addListener(this);
    addAndMakeVisible (slide);
}

void ChowtapeModelAudioProcessorEditor::createComboBox (ComboBox& box, AudioParameterChoice* choice)
{
    box.setName (choice->name);
    box.addItemList (choice->getAllValueStrings(), 1);
    box.setSelectedItemIndex (*choice);

    box.setColour (ComboBox::backgroundColourId, Colours::black);
    box.setColour (ComboBox::outlineColourId, Colours::saddlebrown);
    box.setColour (ComboBox::textColourId, Colours::antiquewhite);
    box.setColour (ComboBox::arrowColourId, Colours::antiquewhite);
    getLookAndFeel().setColour (PopupMenu::backgroundColourId, Colours::black);
    getLookAndFeel().setColour (PopupMenu::textColourId, Colours::antiquewhite);
    getLookAndFeel().setColour (PopupMenu::highlightedBackgroundColourId, Colours::darkgrey);

    box.addListener (this);
    addAndMakeVisible (box);
}

void ChowtapeModelAudioProcessorEditor::createLabel (Label& label, AudioProcessorParameterWithID* param)
{
    label.setText (param->name, dontSendNotification);
    label.setJustificationType (Justification::centred);
    label.setColour (Label::textColourId, Colours::antiquewhite);
    label.setFont (17.0f);
    addAndMakeVisible (label);
}

//==============================================================================
void ChowtapeModelAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::saddlebrown);

    g.setColour (Colours::antiquewhite);
    g.setFont (Font ((float) nameHeight).boldened());
    g.drawFittedText ("CHOW Tape Model", getLocalBounds().removeFromTop (nameHeight), Justification::centred, 1);
}

void ChowtapeModelAudioProcessorEditor::resized()
{
    inGainLabel.setBounds (0, labelY, sliderWidth, labelHeight);
    gainInKnob.setBounds (0, sliderY, sliderWidth, sliderWidth);

    oversampleLabel.setBounds (gainInKnob.getRight() - 7 * xOffset, 3 * labelY + yOffset, tapeWidth, labelHeight);
    oversampling.setBounds (gainInKnob.getRight(), boxY, overWidth, boxHeight);

    speedLabel.setBounds (oversampling.getRight(), 3 * labelY + yOffset, tapeWidth, labelHeight);
    tapeSpeed.setBounds (oversampling.getRight() + 2 * xOffset, boxY, tapeWidth, boxHeight);

    outGainLabel.setBounds (tapeSpeed.getRight(), labelY, sliderWidth, labelHeight);
    gainOutKnob.setBounds (tapeSpeed.getRight(), sliderY, sliderWidth, sliderWidth);
}

AudioParameterFloat* ChowtapeModelAudioProcessorEditor::getParamForSlider (Slider* slider)
{
    if (processor.inGain->name == slider->getName())
        return processor.inGain;
    else if (processor.outGain->name == slider->getName())
        return processor.outGain;
    else
        return nullptr;
}

AudioParameterChoice* ChowtapeModelAudioProcessorEditor::getParamForBox (ComboBox* box)
{
    if (processor.overSampling->name == box->getName())
        return processor.overSampling;
    else if (processor.tapeSpeed->name == box->getName())
        return processor.tapeSpeed;
    else
        return nullptr;
}

void ChowtapeModelAudioProcessorEditor::comboBoxChanged (ComboBox* box)
{
    if (AudioParameterChoice* param = getParamForBox (box))
        *param = box->getSelectedItemIndex();
}

void ChowtapeModelAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if (AudioParameterFloat* param = getParamForSlider (slider))
        *param = (float) slider->getValue();
}

void ChowtapeModelAudioProcessorEditor::sliderDragStarted(Slider* slider)
{
    if (AudioParameterFloat* param = getParamForSlider (slider))
        param->beginChangeGesture();
}

void ChowtapeModelAudioProcessorEditor::sliderDragEnded(Slider* slider)
{
    if (AudioParameterFloat* param = getParamForSlider (slider))
        param->endChangeGesture();
}
