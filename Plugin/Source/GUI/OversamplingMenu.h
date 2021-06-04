#pragma once

#include "../Processors/Hysteresis/OversamplingManager.h"

class OversamplingMenu : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (OversamplingMenu)

    static const Identifier osParam;
    static const Identifier osMode;
    static const Identifier osOfflineParam;
    static const Identifier osOfflineMode;
    static const Identifier osOfflineSame;

    OversamplingMenu (foleys::MagicGUIBuilder& builder, const ValueTree& node);

    void update() override;
    std::vector<foleys::SettableProperty> getSettableProperties() const override;

    Component* getWrappedComponent() override { return &comboBox; }

private:
    void generateComboBoxMenu();

    ComboBox comboBox;

    std::unique_ptr<ParameterAttachment> attachments[5];
    RangedAudioParameter* parameters[5];

    const OversamplingManager& osManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OversamplingMenu)
};
