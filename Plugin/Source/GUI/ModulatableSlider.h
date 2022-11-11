#pragma once

#include <JuceHeader.h>

class ModulatableSlider : public foleys::AutoOrientationSlider,
                          private Timer
{
public:
    ModulatableSlider() = default;

    void attachToParameter (juce::RangedAudioParameter* param);
    double getModulatedPosition();

    void mouseDown (const MouseEvent& e) override;
    virtual juce::PopupMenu getContextMenu();

    using PluginEditorCallback = std::function<juce::AudioProcessorEditor*()>;
    void setPluginEditorCallback (PluginEditorCallback&& newCallback);

private:
    void timerCallback() override;

    std::unique_ptr<juce::SliderParameterAttachment> attachment;
    chowdsp::FloatParameter* modParameter = nullptr;
    PluginEditorCallback pluginEditorCallback = nullptr;
    
    double modulatedValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulatableSlider)
};

//====================================================================
class ModSliderItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (ModSliderItem)

    static const juce::Identifier pSliderType;
    static const juce::StringArray pSliderTypes;

    static const juce::Identifier pSliderTextBox;
    static const juce::StringArray pTextBoxPositions;
    static const juce::Identifier pSliderTextBoxWidth;
    static const juce::Identifier pSliderTextBoxHeight;

    static const juce::Identifier pValue;
    static const juce::Identifier pMinValue;
    static const juce::Identifier pMaxValue;

    ModSliderItem (foleys::MagicGUIBuilder& builder, const juce::ValueTree& node);

    void update() override;
    void resized() override;

    std::vector<foleys::SettableProperty> getSettableProperties() const override;
    juce::String getControlledParameterID (juce::Point<int>) override;
    juce::Component* getWrappedComponent() override;

    void mouseDrag (const juce::MouseEvent& e) override;

private:
    ModulatableSlider slider;

    int defaultHeight = 0;
    int sliderTextBoxHeight = 0;
    juce::Slider::TextEntryBoxPosition textBoxPosition;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModSliderItem)
};
