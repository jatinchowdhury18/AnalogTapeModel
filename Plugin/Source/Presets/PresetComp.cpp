#include "PresetComp.h"

PresetComp::PresetComp (ChowtapeModelAudioProcessor& proc, PresetManager& manager) : proc (proc),
                                                                                     manager (manager),
                                                                                     presetsLeft ("", DrawableButton::ImageOnButtonBackground),
                                                                                     presetsRight ("", DrawableButton::ImageOnButtonBackground)
{
    manager.addListener (this);

    presetBox.setName ("Preset Manager");
    presetBox.setTooltip ("Use this menu to select presets, and to save and manage user presets.");

    setColour (backgroundColourId, Colour (0xFF595C6B));
    setColour (textColourId, Colours::white);

    addAndMakeVisible (presetBox);
    presetBox.setColour (ComboBox::ColourIds::backgroundColourId, Colours::transparentWhite);
    presetBox.setJustificationType (Justification::centred);
    presetBox.setTextWhenNothingSelected ("No Preset selected...");
    loadPresetChoices();

    addChildComponent (presetNameEditor);
    presetNameEditor.setColour (TextEditor::backgroundColourId, Colour (0xFF595C6B));
    presetNameEditor.setColour (TextEditor::textColourId, Colours::white);
    presetNameEditor.setColour (TextEditor::highlightColourId, Colour (0xFF8B3232));
    presetNameEditor.setColour (CaretComponent::caretColourId, Colour (0xFF8B3232));
    presetNameEditor.setFont (Font (16.0f).boldened());
    presetNameEditor.setMultiLine (false, false);
    presetNameEditor.setJustification (Justification::centred);

    auto setupButton = [=, &manager] (DrawableButton& button, Drawable* image, int presetOffset)
    {
        addAndMakeVisible (button);
        button.setImages (image, image, image);
        button.setWantsKeyboardFocus (false);
        button.setColour (ComboBox::outlineColourId, Colours::transparentBlack);
        button.setColour (TextButton::buttonColourId, Colours::transparentBlack);
        button.onClick = [=, &manager] {
            auto idx = negativeAwareModulo (presetBox.getSelectedId() + presetOffset, manager.getNumPresets());
            presetBox.setSelectedId (idx, sendNotification);
        };
    };

    std::unique_ptr<Drawable> leftImage (Drawable::createFromImageData (BinaryData::LeftArrow_svg, BinaryData::LeftArrow_svgSize));
    std::unique_ptr<Drawable> rightImage (Drawable::createFromImageData (BinaryData::RightArrow_svg, BinaryData::RightArrow_svgSize));

    setupButton (presetsLeft, leftImage.get(), -1);
    setupButton (presetsRight, rightImage.get(), 1);

    presetUpdated();
    presetBox.onChange = [=, &proc] {
        const auto selectedId = presetBox.getSelectedId();
        if (selectedId >= 1000 || selectedId <= 0)
            return;

        proc.setCurrentProgram (presetBox.getSelectedId() - 1);
    };
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
        if (category == "User") // user presets are treated specially
            continue;
        category = (category == choice) ? "CHOW" : category;
        String presetName = choice.fromLastOccurrenceOf ("_", false, false);

        if (presetChoicesMap.find (category) == presetChoicesMap.end())
            presetChoicesMap[category] = PopupMenu();

        presetChoicesMap[category].addItem (i + 1, presetName);
    }

    for (auto& presetGroup : presetChoicesMap)
        presetBox.getRootMenu()->addSubMenu (presetGroup.first, presetGroup.second);

    // add user presets
    auto& userPresetMenu = manager.getUserPresetMenu();
    if (userPresetMenu.containsAnyActiveItems())
        presetBox.getRootMenu()->addSubMenu ("User", userPresetMenu);

    addPresetOptions();
}

void PresetComp::addPresetOptions()
{
    auto menu = presetBox.getRootMenu();
    menu->addSeparator();

    PopupMenu::Item saveItem { "Save" };
    saveItem.itemID = 1001;
    saveItem.action = [=] { saveUserPreset(); };
    menu->addItem (saveItem);

    PopupMenu::Item goToFolderItem { "Go to Preset folder..." };
    goToFolderItem.itemID = 1002;
    goToFolderItem.action = [=] {
        presetUpdated();
        auto folder = manager.getUserPresetFolder();
        if (folder.isDirectory())
            folder.startAsProcess();
        else
            manager.chooseUserPresetFolder();
    };
    menu->addItem (goToFolderItem);

    PopupMenu::Item chooseFolderItem { "Choose Preset folder..." };
    chooseFolderItem.itemID = 1003;
    chooseFolderItem.action = [=] { presetUpdated(); manager.chooseUserPresetFolder(); };
    menu->addItem (chooseFolderItem);
}

void PresetComp::paint (Graphics& g)
{
    constexpr auto cornerSize = 5.0f;

    presetBox.setColour (PopupMenu::ColourIds::backgroundColourId, findColour (backgroundColourId));
    g.setColour (findColour (backgroundColourId));

    g.fillRoundedRectangle (getLocalBounds().toFloat().reduced (22.0f, 0.0f), cornerSize);
}

void PresetComp::resized()
{
    auto b = getLocalBounds();
    presetsLeft.setBounds (b.removeFromLeft (20));
    presetsRight.setBounds (b.removeFromRight (20));

    Rectangle<int> presetsBound { 22, 0, getWidth() - 44, getHeight() };
    presetBox.setBounds (presetsBound);
    presetNameEditor.setBounds (presetsBound);
    repaint();
}

void PresetComp::presetUpdated()
{
    presetBox.setSelectedId (proc.getCurrentProgram() + 1, dontSendNotification);
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

        if (manager.saveUserPreset (presetName, proc.getVTS()))
        {
            loadPresetChoices();
            proc.setCurrentProgram (manager.getNumPresets() - 1);
        }
        else
        {
            presetUpdated();
        }
    };
}
