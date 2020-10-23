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
    loadPresetChoices();

    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
    presetBox.onChange  = [=, &proc] { proc.setCurrentProgram (presetBox.getSelectedItemIndex()); };
}

PresetComp::~PresetComp()
{
    manager.removeListener (this);
}

void PresetComp::loadPresetChoices()
{
    const auto& presetChoices = manager.getPresetChoices();
    std::map<String, PopupMenu> presetChoicesMap;
    for (int i = 0; i < presetChoices.size(); ++i)
    {
        const String& choice = presetChoices[i];
        String category = choice.upToFirstOccurrenceOf ("_", false, false);
        category = (category == choice) ? "CHOW" : category;
        String presetName = choice.fromLastOccurrenceOf ("_", false, false);
        
        if (presetChoicesMap.find (category) == presetChoicesMap.end())
            presetChoicesMap[category] = PopupMenu();

        presetChoicesMap[category].addItem (i+1, presetName);
    }

    for (auto& presetGroup : presetChoicesMap)
        presetBox.getRootMenu()->addSubMenu (presetGroup.first, presetGroup.second);
}

void PresetComp::paint (Graphics& g)
{
    constexpr auto cornerSize = 5.0f;   

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
