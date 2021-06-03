#include "OversamplingMenu.h"
#include "../PluginProcessor.h"

/*
class OSParamAttach : private ComboBox::Listener
{
    OSParamAttach()
    {
        // if (auto* parameter = stateToUse.getParameter (parameterID))
        //     return std::make_unique<Attachment> (*parameter, control, stateToUse.undoManager);
    }

    ComboBoxParameterAttachment (RangedAudioParameter& parameter, ComboBox& combo,
                                 UndoManager* undoManager = nullptr);

    ~ComboBoxParameterAttachment() override;

    void sendInitialUpdate();

private:
    void setValue (float newValue);
    void comboBoxChanged (ComboBox*) override;

    ComboBox& comboBox;
    RangedAudioParameter& storedParameter;
    ParameterAttachment attachment;
    bool ignoreCallbacks = false;
}; */

OversamplingMenu::OversamplingMenu (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node)
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
            attachments[count] = std::make_unique<ParameterAttachment> (*parameters[count], [=] (float) { generateComboBoxMenu(); }, vts.undoManager);
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
        item.action = [&, paramVal] {
            if (disableSame)
                attachments[4]->setValueAsCompleteGesture (0.0f);
            attachment->setValueAsCompleteGesture (float (paramVal));
        };
        return isSelected;
    };

    // oversampling parameter
    menu->addSectionHeader ("OS Factor");
    int menuIdx = 1;
    int menuOffset = menuIdx;
    for (auto& choice : parameters[0]->getAllValueStrings())
    {
        PopupMenu::Item item;
        bool isSelected = createParamItem (item, parameters[0], attachments[0], menuIdx, menuOffset, choice);
        menu->addItem (item);
        
        if (isSelected)
            comboBox.setText (item.text);
    }

    // oversampling mode
    menu->addSectionHeader ("Mode");
    menuOffset = menuIdx;
    for (auto& choice : parameters[1]->getAllValueStrings())
    {
        PopupMenu::Item item;
        createParamItem (item, parameters[1], attachments[1], menuIdx, menuOffset, choice);
        menu->addItem (item);
    }

    // offline params
    {
        menu->addSeparator();
        PopupMenu offlineMenu;
        int menuIdx = 1;

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

        offlineMenu.addSectionHeader ("OS Factor");
        int menuOffset = menuIdx;
        for (auto& choice : parameters[2]->getAllValueStrings())
        {
            PopupMenu::Item item;
            createParamItem (item, parameters[2], attachments[2], menuIdx, menuOffset, choice, sameAsRT, true);
            offlineMenu.addItem (item);
        }

        // oversampling mode
        offlineMenu.addSectionHeader ("Mode");
        menuOffset = menuIdx;
        for (auto& choice : parameters[3]->getAllValueStrings())
        {
            PopupMenu::Item item;
            createParamItem (item, parameters[3], attachments[3], menuIdx, menuOffset, choice, sameAsRT, true);
            offlineMenu.addItem (item);
        }

        menu->addSubMenu ("Offline:", offlineMenu);
    }
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
