#include "PluginProcessor.h"
#include "PluginEditor.h"

enum
{
    width = 375,
    height = 150,

    nameHeight = 20,

    xOffset = 2,
    yOffset = 5,

    sliderWidth = 110,
    sliderY = 20,

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

    createSlider (gainInKnob, processor.inGain);
    createSlider (gainOutKnob, processor.outGain);

    createComboBox (oversampling, processor.overSampling);
    createComboBox (tapeSpeed, processor.tapeSpeed);
}

ChowtapeModelAudioProcessorEditor::~ChowtapeModelAudioProcessorEditor()
{
}

void ChowtapeModelAudioProcessorEditor::createSlider(Slider& slide, AudioParameterFloat* param, float step){
    slide.setName(param->name);
    slide.setRange(param->range.start, param->range.end, step);
    slide.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    slide.setColour(Slider::rotarySliderFillColourId, Colours::darkred);
    slide.setColour(Slider::rotarySliderOutlineColourId, Colours::black);
    slide.setColour(Slider::thumbColourId, Colours::navajowhite);
    slide.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    slide.setColour(Slider::textBoxTextColourId, Colours::antiquewhite);
    slide.setColour(Slider::textBoxOutlineColourId, Colours::antiquewhite);
    slide.setValue(*param);
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
    gainInKnob.setBounds (0, sliderY, sliderWidth, sliderWidth);

    oversampling.setBounds (gainInKnob.getRight(), boxY, overWidth, boxHeight);
    tapeSpeed.setBounds (oversampling.getRight() + 2 * xOffset, boxY, tapeWidth, boxHeight);

    gainOutKnob.setBounds (tapeSpeed.getRight(), sliderY, sliderWidth, sliderWidth);
}
