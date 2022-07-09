#include "ModulatableSlider.h"

void ModulatableSlider::attachToParameter (juce::RangedAudioParameter* param)
{
    if (param == nullptr)
    {
        attachment.reset();
        modParameter = nullptr;
        stopTimer();
        return;
    }

    attachment = std::make_unique<juce::SliderParameterAttachment> (*param, *this, nullptr);
    modParameter = dynamic_cast<chowdsp::FloatParameter*> (param);
    startTimerHz (24);
}

double ModulatableSlider::getModulatedPosition()
{
    if (modParameter == nullptr)
        return valueToProportionOfLength (getValue());

    return jlimit (0.0, 1.0, valueToProportionOfLength ((double) modParameter->getCurrentValue()));
}

void ModulatableSlider::mouseDown (const MouseEvent& e)
{
    if (e.mods.isPopupMenu())
    {
        auto popupMenu = getContextMenu();
        if (popupMenu.containsAnyActiveItems())
            popupMenu.showMenuAsync (juce::PopupMenu::Options());

        return;
    }

    foleys::AutoOrientationSlider::mouseDown (e);
}

void ModulatableSlider::setPluginEditorCallback (PluginEditorCallback&& newCallback)
{
    pluginEditorCallback = std::move (newCallback);
}

juce::PopupMenu ModulatableSlider::getContextMenu()
{
    if (pluginEditorCallback != nullptr)
    {
        if (auto* pluginEditor = pluginEditorCallback())
        {
            if (auto* hostContext = pluginEditor->getHostContext())
            {
                if (auto menu = hostContext->getContextMenuForParameter (modParameter))
                    return menu->getEquivalentPopupMenu();
            }
        }
    }

    return {};
}

void ModulatableSlider::timerCallback()
{
    repaint();
}

//====================================================================
ModSliderItem::ModSliderItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node) : GuiItem (builder, node)
{
    setColourTranslation (
        { { "slider-background", juce::Slider::backgroundColourId },
          { "slider-thumb", juce::Slider::thumbColourId },
          { "slider-track", juce::Slider::trackColourId },
          { "rotary-fill", juce::Slider::rotarySliderFillColourId },
          { "rotary-outline", juce::Slider::rotarySliderOutlineColourId },
          { "slider-text", juce::Slider::textBoxTextColourId },
          { "slider-text-background", juce::Slider::textBoxBackgroundColourId },
          { "slider-text-highlight", juce::Slider::textBoxHighlightColourId },
          { "slider-text-outline", juce::Slider::textBoxOutlineColourId } });

    addAndMakeVisible (slider);
}

void ModSliderItem::update()
{
    slider.setPluginEditorCallback ([this] { return magicBuilder.getMagicState().getProcessor()->getActiveEditor(); });

    slider.setTitle (magicBuilder.getStyleProperty (foleys::IDs::name, configNode));
    defaultHeight = magicBuilder.getStyleProperty (foleys::IDs::defaultHeight, configNode);

    auto type = getProperty (pSliderType).toString();
    slider.setAutoOrientation (type.isEmpty() || type == pSliderTypes[0]);

    if (type == pSliderTypes[1])
        slider.setSliderStyle (juce::Slider::LinearHorizontal);
    else if (type == pSliderTypes[2])
        slider.setSliderStyle (juce::Slider::LinearVertical);
    else if (type == pSliderTypes[3])
        slider.setSliderStyle (juce::Slider::Rotary);
    else if (type == pSliderTypes[4])
        slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    else if (type == pSliderTypes[5])
        slider.setSliderStyle (juce::Slider::IncDecButtons);

    auto textbox = getProperty (pSliderTextBox).toString();
    sliderTextBoxHeight = getProperty (pSliderTextBoxHeight);
    if (textbox == pTextBoxPositions[0])
        textBoxPosition = juce::Slider::NoTextBox;
    else if (textbox == pTextBoxPositions[1])
        textBoxPosition = juce::Slider::TextBoxAbove;
    else if (textbox == pTextBoxPositions[3])
        textBoxPosition = juce::Slider::TextBoxLeft;
    else if (textbox == pTextBoxPositions[4])
        textBoxPosition = juce::Slider::TextBoxRight;
    else
        textBoxPosition = juce::Slider::TextBoxBelow;

    double minValue = getProperty (pMinValue);
    double maxValue = getProperty (pMaxValue);
    if (maxValue > minValue)
        slider.setRange (minValue, maxValue);

    auto valueID = configNode.getProperty (pValue, juce::String()).toString();
    if (valueID.isNotEmpty())
        slider.getValueObject().referTo (getMagicState().getPropertyAsValue (valueID));

    auto paramID = getControlledParameterID ({});
    if (paramID.isNotEmpty())
        slider.attachToParameter (getMagicState().getParameter (paramID));
    else
        slider.attachToParameter (nullptr);

    resized();
}

void ModSliderItem::resized()
{
    const auto sliderTextHeightToUse = [this] {
        if (defaultHeight == 0)
            return sliderTextBoxHeight;

        return proportionOfHeight ((float) sliderTextBoxHeight / (float) defaultHeight);
    }();

    slider.setTextBoxStyle (textBoxPosition, false, proportionOfWidth (0.75f), sliderTextHeightToUse);

    foleys::GuiItem::resized();
}

std::vector<foleys::SettableProperty> ModSliderItem::getSettableProperties() const
{
    std::vector<foleys::SettableProperty> props;

    props.push_back ({ configNode, foleys::IDs::parameter, foleys::SettableProperty::Choice, {}, magicBuilder.createParameterMenuLambda() });
    props.push_back ({ configNode, pSliderType, foleys::SettableProperty::Choice, pSliderTypes[0], magicBuilder.createChoicesMenuLambda (pSliderTypes) });
    props.push_back ({ configNode, pSliderTextBox, foleys::SettableProperty::Choice, pTextBoxPositions[2], magicBuilder.createChoicesMenuLambda (pTextBoxPositions) });
    props.push_back ({ configNode, pValue, foleys::SettableProperty::Choice, 1.0f, magicBuilder.createPropertiesMenuLambda() });
    props.push_back ({ configNode, pMinValue, foleys::SettableProperty::Number, 0.0f, {} });
    props.push_back ({ configNode, pMaxValue, foleys::SettableProperty::Number, 2.0f, {} });
    props.push_back ({ configNode, pSliderTextBoxWidth, foleys::SettableProperty::Number, 85.0f, {} });
    props.push_back ({ configNode, pSliderTextBoxHeight, foleys::SettableProperty::Number, 17.0f, {} });

    return props;
}

juce::String ModSliderItem::getControlledParameterID (juce::Point<int>)
{
    return configNode.getProperty (foleys::IDs::parameter, juce::String()).toString();
}

juce::Component* ModSliderItem::getWrappedComponent()
{
    return &slider;
}

void ModSliderItem::mouseDrag (const juce::MouseEvent& e)
{
    auto numSources = juce::Desktop::getInstance().getNumDraggingMouseSources();
    if (numSources > 1)
        return;

    GuiItem::mouseDrag (e);
}

const juce::Identifier ModSliderItem::pSliderType { "slider-type" };
const juce::StringArray ModSliderItem::pSliderTypes { "auto", "linear-horizontal", "linear-vertical", "rotary", "rotary-horizontal-vertical", "inc-dec-buttons" };
const juce::Identifier ModSliderItem::pSliderTextBox { "slider-textbox" };
const juce::StringArray ModSliderItem::pTextBoxPositions { "no-textbox", "textbox-above", "textbox-below", "textbox-left", "textbox-right" };
const juce::Identifier ModSliderItem::pSliderTextBoxWidth { "slidertext-width" };
const juce::Identifier ModSliderItem::pSliderTextBoxHeight { "slidertext-height" };
const juce::Identifier ModSliderItem::pValue { "value" };
const juce::Identifier ModSliderItem::pMinValue { "min-value" };
const juce::Identifier ModSliderItem::pMaxValue { "max-value" };
