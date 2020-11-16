#ifndef POWERBUTTON_H_INCLUDED
#define POWERBUTTON_H_INCLUDED

#include <JuceHeader.h>

class PowerButton : public Component
{
public:
    PowerButton();

    enum ColourIDs
    {
        buttonColourId,
        buttonOnColourId,
    };

    void resized();
    void updateColours();
    DrawableButton& getButton() { return button; }

private:
    DrawableButton button;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerButton)
};

//===============================================================
class PowerButtonItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (PowerButtonItem)

    static const Identifier pOnClick;

    PowerButtonItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node);

    void update() override;
    std::vector<foleys::SettableProperty> getSettableProperties() const override;

    juce::Component* getWrappedComponent() override
    {
        return &button;
    }

private:
    PowerButton button;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> attachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerButtonItem)
};

#endif // POWERBUTTON_H_INCLUDED
