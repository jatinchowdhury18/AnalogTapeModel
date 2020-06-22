#include "PresetComp.h"

PresetComp::PresetComp (ChowtapeModelAudioProcessor& proc, PresetManager& manager) :
    proc (proc),
    manager (manager)
{
    manager.addListener (this);

    setColour (backgroundColourId, Colour (0xFF434352));
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
    presetBox.setColour (PopupMenu::ColourIds::backgroundColourId, findColour (backgroundColourId));
    g.fillAll (findColour (backgroundColourId));

    g.setColour (findColour (textColourId));
    g.setFont (getHeight() * 0.6f);
    auto presetBounds = presetBox.getBounds();
    presetBounds.setWidth (100);
    presetBounds.translate (-110, 0);
    g.drawFittedText ("Presets:", presetBounds, Justification::centredRight, 1);

    g.setFont (getHeight() * 0.4f);
    auto versionBounds = getLocalBounds().removeFromRight (50);
    g.drawFittedText ("v" + String (JucePlugin_VersionString), versionBounds, Justification::centred, 1);
}

void PresetComp::resized()
{
    auto boxWidth = jmin (getWidth() / 3, 200);
    presetBox.setBounds ((getWidth() - boxWidth) / 2, 2, boxWidth, getHeight() - 4);
    repaint();
}

void PresetComp::presetUpdated()
{
    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
}
