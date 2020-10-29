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

    addChildComponent (presetNameEditor);
    presetNameEditor.setColour (TextEditor::backgroundColourId, Colour (0xFF595C6B));
    presetNameEditor.setColour (TextEditor::textColourId, Colours::white);
    presetNameEditor.setColour (TextEditor::highlightColourId, Colour (0xFF8B3232));
    presetNameEditor.setColour (CaretComponent::caretColourId, Colour (0xFF8B3232));
    presetNameEditor.setFont (Font (16.0f).boldened());
    presetNameEditor.setMultiLine (false, false);
    presetNameEditor.setJustification (Justification::centred);

    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
    presetBox.onChange  = [=, &proc] { proc.setCurrentProgram (presetBox.getSelectedId() - 1); };
}

PresetComp::~PresetComp()
{
    manager.removeListener (this);
}

void PresetComp::loadPresetChoices()
{
    presetBox.getRootMenu()->clear();

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

    addPresetOptions();
}

void PresetComp::addPresetOptions()
{
    auto menu = presetBox.getRootMenu();
    menu->addSeparator();

    PopupMenu::Item loadItem { "Load" };
    loadItem.itemID = 998;
    loadItem.action = [=] { loadUserPreset(); };
    menu->addItem (loadItem);

    PopupMenu::Item saveItem { "Save" };
    saveItem.itemID = 999;
    saveItem.action = [=] { saveUserPreset(); };
    menu->addItem (saveItem);
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
    presetNameEditor.setBounds (getLocalBounds());
    repaint();
}

void PresetComp::presetUpdated()
{
    presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
}

void PresetComp::loadUserPreset()
{
    FileChooser fileChooser ("Load Preset", File(), "*.chowpreset");

    if (fileChooser.browseForFileToOpen())
    {
        auto result = fileChooser.getResult();
        manager.loadUserPreset (result);
        loadPresetChoices();
    }
}

void PresetComp::saveUserPreset()
{
    presetNameEditor.setVisible (true);
    presetNameEditor.toFront (true);
    presetNameEditor.setText ("MyPreset");
    presetNameEditor.setHighlightedRegion ({ 0, 10 });

    presetNameEditor.onReturnKey = [=] {
        auto presetName = presetNameEditor.getText();
        presetNameEditor.setVisible (false);
        manager.saveUserPreset (presetName, proc.getVTS());
        loadPresetChoices();
    };
}
