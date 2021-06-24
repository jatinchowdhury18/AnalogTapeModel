#pragma once

#include "../Processors/Hysteresis/OversamplingManager.h"
#include "MyLNF.h"

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
    ~OversamplingMenu();

    void update() override;
    std::vector<foleys::SettableProperty> getSettableProperties() const override;

    Component* getWrappedComponent() override { return &comboBox; }

private:
    class OversamplingLNF : public ComboBoxLNF
    {
    public:
        OversamplingLNF() = default;

        void drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box) override
        {
            auto cornerSize = 5.0f;
            Rectangle<int> boxBounds (0, 0, width, height);

            g.setColour (box.findColour (ComboBox::backgroundColourId));
            g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

            auto name = box.getName();
            auto font = getComboBoxFont (box).boldened();
            g.setColour (Colours::white);
            g.setFont (font);
                
            auto nameBox = boxBounds.removeFromLeft (font.getStringWidth (name));
            g.drawFittedText (name + ": ", nameBox, Justification::left, 1);
        }

        void positionComboBoxText (ComboBox& box, Label& label) override
        {
            auto name = box.getName();
            auto font = getComboBoxFont (box).boldened();
            auto b = box.getBounds();
            b.removeFromLeft (font.getStringWidth (name));

            label.setBounds (b);
            label.setFont (getComboBoxFont (box).boldened());
            label.setJustificationType (Justification::centred);
        }
    } lnf;

    void generateComboBoxMenu();

    ComboBox comboBox;

    std::unique_ptr<ParameterAttachment> attachments[5];
    RangedAudioParameter* parameters[5];

    const OversamplingManager& osManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OversamplingMenu)
};
