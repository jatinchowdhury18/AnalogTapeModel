#pragma once

#include <JuceHeader.h>

class ModulatableSlider : public foleys::AutoOrientationSlider,
                          private Timer
{
public:
    ModulatableSlider() = default;

    void attachToParameter (juce::RangedAudioParameter* param)
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

    double getModulatedPosition()
    {
        if (modParameter == nullptr)
            return valueToProportionOfLength (getValue());

        return jlimit (0.0, 1.0, valueToProportionOfLength ((double) modParameter->getCurrentValue()));
    }

private:
    void timerCallback() override
    {
        repaint();
    }

    std::unique_ptr<juce::SliderParameterAttachment> attachment;
    chowdsp::FloatParameter* modParameter = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulatableSlider)
};


class ModSliderItem : public foleys::GuiItem
{

public:
    FOLEYS_DECLARE_GUI_FACTORY (ModSliderItem)

    static const juce::Identifier  pSliderType;
    static const juce::StringArray pSliderTypes;

    static const juce::Identifier  pSliderTextBox;
    static const juce::StringArray pTextBoxPositions;
    static const juce::Identifier  pSliderTextBoxWidth;
    static const juce::Identifier  pSliderTextBoxHeight;

    static const juce::Identifier  pValue;
    static const juce::Identifier  pMinValue;
    static const juce::Identifier  pMaxValue;

    ModSliderItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node);

    void update() override;

    std::vector<foleys::SettableProperty> getSettableProperties() const override;
    juce::String getControlledParameterID (juce::Point<int>) override;
    juce::Component* getWrappedComponent() override;

    void mouseDrag (const juce::MouseEvent& e) override;

private:
    ModulatableSlider slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModSliderItem)
};
