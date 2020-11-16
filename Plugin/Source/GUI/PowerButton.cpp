#include "PowerButton.h"

PowerButton::PowerButton() :
    button ("", DrawableButton::ImageStretched)
{
    setColour (buttonColourId, Colours::blue);
    setColour (buttonOnColourId, Colours::red);
    button.setColour (DrawableButton::backgroundColourId, Colours::transparentBlack);
    button.setColour (DrawableButton::backgroundOnColourId, Colours::transparentBlack);

    addAndMakeVisible (button);
    updateColours();
    button.setClickingTogglesState (true);
}

void PowerButton::resized()
{
    auto dim = (int) ((float) jmin (getWidth(), getHeight()) * 0.6f);
    auto centre = getLocalBounds().getCentre();
    auto topLeft = centre.translated (-dim / 2, -dim / 2);
    
    button.setBounds (topLeft.x, topLeft.y, dim, dim);
}

void PowerButton::updateColours()
{
    std::unique_ptr<Drawable> onImage (Drawable::createFromImageData
        (BinaryData::powerswitch_svg, BinaryData::powerswitch_svgSize));
    auto offImage = onImage->createCopy();

    onImage->replaceColour (Colours::black, findColour (buttonOnColourId));
    offImage->replaceColour (Colours::black, findColour (buttonColourId));
    button.setImages (offImage.get(), offImage.get(), onImage.get(),
        offImage.get(), onImage.get(), onImage.get(), offImage.get());
}

//===============================================================
PowerButtonItem::PowerButtonItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node) :
    foleys::GuiItem (builder, node)
{
    setColourTranslation (
        {
            { "button-color",    PowerButton::buttonColourId },
            { "button-on-color", PowerButton::buttonOnColourId }
        }
    );

    addAndMakeVisible (button);
}

void PowerButtonItem::update()
{
    attachment.reset();
    auto& actualButton = button.getButton();

    auto parameter = configNode.getProperty (foleys::IDs::parameter, juce::String()).toString();
    if (parameter.isNotEmpty())
        attachment = getMagicState().createAttachment (parameter, actualButton);

    auto triggerID = getProperty (pOnClick).toString();
    if (triggerID.isNotEmpty())
        actualButton.onClick = getMagicState().getTrigger (triggerID);

    button.updateColours();

    actualButton.setName (magicBuilder.getStyleProperty (foleys::IDs::name, configNode).toString());

    auto tooltip = magicBuilder.getStyleProperty (foleys::IDs::tooltip, configNode).toString();
    if (tooltip.isNotEmpty())
        actualButton.setTooltip (tooltip);
}

std::vector<foleys::SettableProperty> PowerButtonItem::getSettableProperties() const
{
    std::vector<foleys::SettableProperty> itemProperties;

    itemProperties.push_back ({ configNode, foleys::IDs::parameter, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenu() });
    itemProperties.push_back ({ configNode, pOnClick, foleys::SettableProperty::Choice, {}, magicBuilder.createTriggerMenu() });

    return itemProperties;
}

const juce::Identifier PowerButtonItem::pOnClick { "onClick" };
