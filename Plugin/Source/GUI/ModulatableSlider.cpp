#include "ModulatableSlider.h"
#include "../PluginProcessor.h"

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
    modulatedValue = modParameter->getCurrentValue();
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
    const auto newModulatedValue = modParameter->getCurrentValue();
    if (std::abs (modulatedValue - newModulatedValue) < 0.01)
        return;

    modulatedValue = newModulatedValue;
    repaint();
}

void ModulatableSlider::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float modSliderPos)
{
    int diameter = (width > height) ? height : width;
    if (diameter < 16)
        return;

    juce::Point<float> centre ((float) x + std::floor ((float) width * 0.5f + 0.5f), (float) y + std::floor ((float) height * 0.5f + 0.5f));
    diameter -= (diameter % 2 == 1) ? 9 : 8;
    float radius = (float) diameter * 0.5f;
    x = int (centre.x - radius);
    y = int (centre.y - radius);

    const auto bounds = juce::Rectangle<int> (x, y, diameter, diameter).toFloat();

    auto b = sharedAssets->pointer->getBounds().toFloat();
    sharedAssets->pointer->setTransform (AffineTransform::rotation (MathConstants<float>::twoPi * ((sliderPos - 0.5f) * 300.0f / 360.0f),
                                                                    b.getCentreX(),
                                                                    b.getCentreY()));

    const auto alpha = isEnabled() ? 1.0f : 0.4f;
    auto knobBounds = (bounds * 0.75f).withCentre (centre);
    sharedAssets->knob->drawWithin (g, knobBounds, RectanglePlacement::stretchToFit, alpha);
    sharedAssets->pointer->drawWithin (g, knobBounds, RectanglePlacement::stretchToFit, alpha);

    static constexpr auto rotaryStartAngle = MathConstants<float>::pi * 1.2f;
    static constexpr auto rotaryEndAngle = MathConstants<float>::pi * 2.8f;
    const auto toAngle = rotaryStartAngle + modSliderPos * (rotaryEndAngle - rotaryStartAngle);
    constexpr float arcFactor = 0.9f;

    juce::Path valueArc;
    valueArc.addPieSegment (bounds, rotaryStartAngle, rotaryEndAngle, arcFactor);
    g.setColour (Colour (0xff595c6b).withMultipliedAlpha (alpha));
    g.fillPath (valueArc);
    valueArc.clear();

    valueArc.addPieSegment (bounds, rotaryStartAngle, toAngle, arcFactor);
    g.setColour (Colour (0xff9cbcbd).withMultipliedAlpha (alpha));
    g.fillPath (valueArc);
}

void ModulatableSlider::drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float modSliderPos)
{
    const auto horizontal = isHorizontal();
    auto trackWidth = juce::jmin (6.0f, horizontal ? (float) height * 0.25f : (float) width * 0.25f);

    juce::Point startPoint (horizontal ? (float) x : (float) x + (float) width * 0.5f,
                            horizontal ? (float) y + (float) height * 0.5f : (float) (height + y));

    juce::Point endPoint (horizontal ? (float) (width + x) : startPoint.x,
                          horizontal ? startPoint.y : (float) y);

    juce::Path backgroundTrack;
    backgroundTrack.startNewSubPath (startPoint);
    backgroundTrack.lineTo (endPoint);

    const auto alphaMult = isEnabled() ? 1.0f : 0.4f;
    g.setColour (Colour (0xff595c6b).withAlpha (alphaMult));
    g.strokePath (backgroundTrack, { trackWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded });

    juce::Path valueTrack;
    const auto maxPoint = [&]
    {
        auto kx = horizontal ? sliderPos : ((float) x + (float) width * 0.5f);
        auto ky = horizontal ? ((float) y + (float) height * 0.5f) : sliderPos;
        return juce::Point { kx, ky };
    }();
    const auto modPoint = [&]
    {
        auto kmx = horizontal ? modSliderPos : ((float) x + (float) width * 0.5f);
        auto kmy = horizontal ? ((float) y + (float) height * 0.5f) : modSliderPos;
        return juce::Point { kmx, kmy };
    }();

    valueTrack.startNewSubPath (startPoint);
    valueTrack.lineTo (modPoint);
    g.setColour (Colour (0xff9cbcbd).withAlpha (alphaMult));
    g.strokePath (valueTrack, { trackWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded });

    auto thumbWidth = getLookAndFeel().getSliderThumbRadius (*this);
    auto thumbRect = juce::Rectangle<float> (static_cast<float> (thumbWidth),
                                             static_cast<float> (thumbWidth))
                         .withCentre (maxPoint);
    sharedAssets->knob->drawWithin (g, thumbRect, juce::RectanglePlacement::stretchToFit, alphaMult);
}

void ModulatableSlider::paint (Graphics& g)
{
    if (modParameter == nullptr)
        return;

    auto& lf = getLookAndFeel();
    auto layout = lf.getSliderLayout (*this);
    const auto sliderRect = layout.sliderBounds;

    modulatedValue = modParameter->getCurrentValue();
    if (isRotary())
    {
        const auto sliderPos = (float) valueToProportionOfLength (getValue());
        const auto modSliderPos = (float) jlimit (0.0, 1.0, valueToProportionOfLength (modulatedValue));
        drawRotarySlider (g,
                          sliderRect.getX(),
                          sliderRect.getY(),
                          sliderRect.getWidth(),
                          sliderRect.getHeight(),
                          sliderPos,
                          modSliderPos);
    }
    else
    {
        const auto normRange = NormalisableRange { getRange() };
        const auto sliderPos = getPositionOfValue (getValue());
        const auto modSliderPos = getPositionOfValue (modulatedValue);
        drawLinearSlider (g,
                          sliderRect.getX(),
                          sliderRect.getY(),
                          sliderRect.getWidth(),
                          sliderRect.getHeight(),
                          sliderPos,
                          modSliderPos);
    }
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
    if (const auto* plugin = dynamic_cast<const ChowtapeModelAudioProcessor*> (magicBuilder.getMagicState().getProcessor()))
    {
        if (plugin->supportsParameterModulation())
            slider.startTimerHz (24);
    }

    slider.setPluginEditorCallback ([this]
                                    { return magicBuilder.getMagicState().getProcessor()->getActiveEditor(); });

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
    const auto sliderTextHeightToUse = [this]
    {
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
