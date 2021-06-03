#pragma once

#include <JuceHeader.h>

class OversamplingMenu : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (OversamplingMenu)

    OversamplingMenu (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node)
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

    void update() override
    {
        attachment.reset();

        auto paramID = configNode.getProperty (foleys::IDs::parameter, juce::String()).toString();
        if (paramID.isNotEmpty())
        {
            if (auto* parameter = getMagicState().getParameter (paramID))
            {
                comboBox.clear();
                comboBox.addItemList (parameter->getAllValueStrings(), 1);
                attachment = getMagicState().createAttachment (paramID, comboBox);
            }
        }
    }

    std::vector<foleys::SettableProperty> getSettableProperties() const override
    {
        std::vector<foleys::SettableProperty> properties;
        properties.push_back ({ configNode, foleys::IDs::parameter, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
        return properties;
    }

    Component* getWrappedComponent() override
    {
        return &comboBox;
    }

private:
    ComboBox comboBox;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> attachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OversamplingMenu)
};
