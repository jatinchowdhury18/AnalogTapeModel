#include "PresetComp.h"

PresetComp::PresetComp (ChowtapeModelAudioProcessor& proc, PresetManager& manager) :
    proc (proc),
    manager (manager)
{
    manager.addListener (this);

    setColour (backgroundColourId, Colour (0xFF595C6B));
    setColour (textColourId, Colours::white);

    addAndMakeVisible (presetBox);
    presetBox.setColour (ComboBox::ColourIds::backgroundColourId, Colours::transparentWhite);
    presetBox.setJustificationType (Justification::centred);
    presetBox.addItemList (manager.getPresetChoices(), 1);

    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
    presetBox.onChange  = [=, &proc, &manager] { proc.setCurrentProgram (presetBox.getSelectedItemIndex()); };
}

PresetComp::~PresetComp()
{
    manager.removeListener (this);
}

void PresetComp::paint (Graphics& g)
{
    const auto cornerSize = 5.0f;   

    presetBox.setColour (PopupMenu::ColourIds::backgroundColourId, findColour (backgroundColourId));
    g.setColour (findColour (backgroundColourId));
    g.fillRoundedRectangle (getLocalBounds().toFloat(), cornerSize);
}

void PresetComp::resized()
{
    presetBox.setBounds (getLocalBounds());
    repaint();
}

void PresetComp::presetUpdated()
{
    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
}
