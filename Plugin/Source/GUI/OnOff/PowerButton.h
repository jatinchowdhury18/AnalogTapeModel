#ifndef POWERBUTTON_H_INCLUDED
#define POWERBUTTON_H_INCLUDED

#include <JuceHeader.h>

class PowerButton : public DrawableButton
{
public:
    PowerButton();

    enum ColourIDs
    {
        buttonColourId,
        buttonOnColourId,
    };

    void mouseDown (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;

    void updateColours();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerButton)
};

//===============================================================
class PowerButtonItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (PowerButtonItem)

    static const Identifier pOnClick;

    PowerButtonItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node);

    void resized() override;
    void update() override;
    std::vector<foleys::SettableProperty> getSettableProperties() const override;
    String getControlledParameterID (juce::Point<int>) override;

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
