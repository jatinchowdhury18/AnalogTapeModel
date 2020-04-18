#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ChowtapeModelAudioProcessorEditor::ChowtapeModelAudioProcessorEditor (ChowtapeModelAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    mainControls.reset (new MainControls (processor));
    addAndMakeVisible (mainControls.get());

    biasControls.reset (new HysteresisControls (processor));
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

void ChowtapeModelAudioProcessorEditor::createSlider (Slider& slider, AudioProcessorValueTreeState& vts, String paramID,
                                                      std::unique_ptr<SliderAttachment>& attachment, Component& comp, LookAndFeel& myLNF,
                                                      String suffix, std::function<void()> onValueChange,
                                                      std::function<String (double)> textFromValue, std::function<double (String)> valueFromText)
{
    comp.addAndMakeVisible (slider);
    attachment.reset (new SliderAttachment (vts, paramID, slider));

    slider.setName (vts.getParameter (paramID)->name);
    slider.textFromValueFunction = textFromValue;
    slider.valueFromTextFunction = valueFromText;
    slider.setNumDecimalPlacesToDisplay (2);
    slider.setTextValueSuffix (suffix);
    slider.onValueChange = onValueChange;

    slider.setLookAndFeel (&myLNF);
    slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    slider.setColour(Slider::rotarySliderFillColourId, Colours::black);
    slider.setColour(Slider::rotarySliderOutlineColourId, Colours::darkred);
    slider.setColour(Slider::thumbColourId, Colours::antiquewhite);
    slider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    slider.setColour(Slider::textBoxTextColourId, Colours::antiquewhite);
    slider.setColour(Slider::textBoxOutlineColourId, Colours::antiquewhite);
}

void ChowtapeModelAudioProcessorEditor::createComboBox (ComboBox& box, AudioProcessorValueTreeState& vts, String paramID,
                                                        std::unique_ptr<ComboBoxAttachment>& attachment, Component* comp,
                                                        StringArray choices)
{
    attachment.reset (new ComboBoxAttachment (vts, paramID, box));

    box.setName (vts.getParameter (paramID)->name);
    box.addItemList (choices, 1);
    box.setSelectedItemIndex ((int) *vts.getRawParameterValue (paramID), dontSendNotification);

    box.setColour (ComboBox::backgroundColourId, Colours::black);
    box.setColour (ComboBox::outlineColourId, Colours::saddlebrown);
    box.setColour (ComboBox::textColourId, Colours::antiquewhite);
    box.setColour (ComboBox::arrowColourId, Colours::antiquewhite);

    comp->addAndMakeVisible (box);
}

void ChowtapeModelAudioProcessorEditor::createLabel (Label& label, String name, Component* comp)
{
    label.setText (name, dontSendNotification);
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
