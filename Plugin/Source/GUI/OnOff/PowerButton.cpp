#include "PowerButton.h"

PowerButton::PowerButton() : DrawableButton ("", DrawableButton::ImageFitted)
{
    setColour (buttonColourId, Colours::blue);
    setColour (buttonOnColourId, Colours::red);
    setColour (DrawableButton::backgroundColourId, Colours::transparentBlack);
    setColour (DrawableButton::backgroundOnColourId, Colours::transparentBlack);

    updateColours();
    setClickingTogglesState (true);
}

void PowerButton::updateColours()
{
    std::unique_ptr<Drawable> onImage (Drawable::createFromImageData (BinaryData::powerswitch_svg, BinaryData::powerswitch_svgSize));
    auto offImage = onImage->createCopy();

    onImage->replaceColour (Colours::black, findColour (buttonOnColourId));
    offImage->replaceColour (Colours::black, findColour (buttonColourId));
    setImages (offImage.get(), offImage.get(), offImage.get(), nullptr, onImage.get(), onImage.get(), onImage.get());
}

void PowerButton::mouseDown (const MouseEvent& e)
{
    if (e.mods.isAnyModifierKeyDown())
        return;

    DrawableButton::mouseDown (e);
}

void PowerButton::mouseUp (const MouseEvent& e)
{
    if (e.mods.isAnyModifierKeyDown())
        return;

    DrawableButton::mouseUp (e);
}

//===============================================================
PowerButtonItem::PowerButtonItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node) : foleys::GuiItem (builder, node)
{
    setColourTranslation (
        { { "button-color", PowerButton::buttonColourId },
          { "button-on-color", PowerButton::buttonOnColourId } });

    addAndMakeVisible (button);
}

void PowerButtonItem::resized()
{
    auto indent = (int) ((float) jmin (getWidth(), getHeight()) * 0.2f);
    button.setEdgeIndent (indent);

    GuiItem::resized();
}

void PowerButtonItem::update()
{
    attachment.reset();

    auto parameter = getControlledParameterID ({});
    if (parameter.isNotEmpty())
    {
        button.setTitle (getMagicState().getParameter (parameter)->name);
        attachment = getMagicState().createAttachment (parameter, button);
    }

    auto triggerID = getProperty (pOnClick).toString();
    if (triggerID.isNotEmpty())
        button.onClick = getMagicState().getTrigger (triggerID);

    button.updateColours();

    button.setName (magicBuilder.getStyleProperty (foleys::IDs::name, configNode).toString());

    auto tooltip = magicBuilder.getStyleProperty (foleys::IDs::tooltip, configNode).toString();
    if (tooltip.isNotEmpty())
        button.setTooltip (tooltip);
}

std::vector<foleys::SettableProperty> PowerButtonItem::getSettableProperties() const
{
    std::vector<foleys::SettableProperty> itemProperties;

    itemProperties.push_back ({ configNode, foleys::IDs::parameter, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenuLambda() });
    itemProperties.push_back ({ configNode, pOnClick, foleys::SettableProperty::Choice, {}, magicBuilder.createTriggerMenuLambda() });

    return itemProperties;
}

String PowerButtonItem::getControlledParameterID (juce::Point<int>)
{
    return configNode.getProperty (foleys::IDs::parameter, String()).toString();
}

const juce::Identifier PowerButtonItem::pOnClick { "onClick" };
