#include "OversamplingMenu.h"
#include "../PluginProcessor.h"

OversamplingMenu::OversamplingMenu (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node),
                                                                                               osManager (dynamic_cast<ChowtapeModelAudioProcessor*> (getMagicState()
                                                                                                          .getProcessor())->getHysteresisProcessor().getOSManager())
{
    setColourTranslation (
    {
        { "combo-background", ComboBox::backgroundColourId },
        { "combo-text", ComboBox::textColourId },
        { "combo-outline", ComboBox::outlineColourId },
        { "combo-button", ComboBox::buttonColourId },
        { "combo-arrow", ComboBox::arrowColourId },
        { "combo-focused-outline", ComboBox::focusedOutlineColourId },
        { "combo-menu-background", PopupMenu::backgroundColourId },
        { "combo-menu-background-highlight", PopupMenu::highlightedBackgroundColourId },
        { "combo-menu-text", PopupMenu::textColourId },
        { "combo-menu-text-highlight", PopupMenu::highlightedTextColourId }
    });

    addAndMakeVisible (comboBox);
}

void OversamplingMenu::update()
{
    auto& vts = dynamic_cast<ChowtapeModelAudioProcessor*> (getMagicState().getProcessor())->getVTS();

    int count = 0;
    for (auto paramTag : { &osParam, &osMode, &osOfflineParam, &osOfflineMode, &osOfflineSame })
    {
        attachments[count].reset();
        auto paramID = configNode.getProperty (*paramTag, String()).toString();
        if (paramID.isNotEmpty())
        {
            parameters[count] = vts.getParameter (paramID);
            attachments[count] = std::make_unique<ParameterAttachment> (*parameters[count],
                                                                        [=] (float) { generateComboBoxMenu(); },
                                                                        vts.undoManager);
        }

        count += 1;
    }

    generateComboBoxMenu();
}

void OversamplingMenu::generateComboBoxMenu()
{
    comboBox.clear();
    auto* menu = comboBox.getRootMenu();

    auto createParamItem = [=] (PopupMenu::Item& item, auto* parameter, auto& attachment,
                                int& menuIdx, int menuOffset, const String& choice,
                                bool forceOff = false, bool disableSame = false)
    {
        item.itemID = menuIdx++;
        int paramVal = item.itemID - menuOffset;
        bool isSelected = ((int) parameter->convertFrom0to1 (parameter->getValue()) == paramVal) && ! forceOff;
        item.text = choice;
        item.colour = isSelected ? Colour (0xFFEAA92C) : Colours::white;
        item.action = [&, paramVal, disableSame] {
            if (disableSame)
                attachments[4]->setValueAsCompleteGesture (0.0f);
            attachment->setValueAsCompleteGesture (float (paramVal));
        };
        return isSelected;
    };

    // set up main menu
    StringArray headers { "OS Factor", "Mode", "OS Factor", "Mode" };
    int menuIdx = 1;
    int menuOffset = menuIdx;

    // set up offline menu
    PopupMenu offlineMenu;
    int offlineMenuIdx = 1;
    int offlineMenuOffset = menuIdx;

    bool sameAsRT = false;
    { // same as real-time option
        PopupMenu::Item item;
        item.itemID = menuIdx++;
        auto* parameter = parameters[4];
        sameAsRT = (int) parameter->convertFrom0to1 (parameter->getValue()) == 1;
        item.text = "Same as real-time";
        item.colour = sameAsRT ? Colour (0xFFEAA92C) : Colours::white;
        item.action = [&] { attachments[4]->setValueAsCompleteGesture (1.0f); };
        offlineMenu.addItem (item);
    }

    // add parameter to menus
    for (int paramIdx = 0; paramIdx < 4; ++paramIdx)
    {
        bool isOfflineParam = paramIdx >= 2;
        auto* thisMenu = isOfflineParam ? &offlineMenu : menu;
        auto& thisMenuIdx = isOfflineParam ? offlineMenuIdx : menuIdx;
        auto& thisMenuOffset = isOfflineParam ? offlineMenuOffset : menuOffset;
        thisMenuOffset = thisMenuIdx;

        thisMenu->addSectionHeader (headers[paramIdx]);
        for (auto& choice : parameters[paramIdx]->getAllValueStrings())
        {
            PopupMenu::Item item;
            bool isSelected = createParamItem (item,
                                               parameters[paramIdx],
                                               attachments[paramIdx],
                                               thisMenuIdx,
                                               thisMenuOffset,
                                               choice,
                                               sameAsRT && isOfflineParam,
                                               isOfflineParam);
            thisMenu->addItem (item);

            if (isSelected && paramIdx == 0)
                comboBox.setText (item.text);
        }
    }
    
    menu->addSeparator();
    menu->addSubMenu ("Offline:", offlineMenu);

    auto osParam = parameters[0]->convertFrom0to1 (parameters[0]->getValue());
    auto osMode = parameters[1]->convertFrom0to1 (parameters[1]->getValue());
    auto osIndex = osManager.getOSIndex (osParam, osMode);
    auto curLatencyMs = osManager.getLatencyMilliseconds (osIndex);
    menu->addSectionHeader ("Current Latency: " + String (curLatencyMs, 3) + " ms");
}

std::vector<foleys::SettableProperty> OversamplingMenu::getSettableProperties() const
{
    std::vector<foleys::SettableProperty> properties;
    properties.push_back ({ configNode, osParam, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
    properties.push_back ({ configNode, osMode, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
    properties.push_back ({ configNode, osOfflineParam, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
    properties.push_back ({ configNode, osOfflineMode, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
    return properties;
}

const Identifier OversamplingMenu::osParam = { "os-param" };
const Identifier OversamplingMenu::osMode = { "os-mode" };
const Identifier OversamplingMenu::osOfflineParam = { "os-off-param" };
const Identifier OversamplingMenu::osOfflineMode = { "os-off-mode" };
const Identifier OversamplingMenu::osOfflineSame = { "os-off-same" };
