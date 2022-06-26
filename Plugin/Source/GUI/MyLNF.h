#ifndef MYLNF_H_INCLUDED
#define MYLNF_H_INCLUDED

#include <JuceHeader.h>

class MyLNF : public LookAndFeel_V4
{
public:
    MyLNF();

    Typeface::Ptr getTypefaceForFont (const Font&) override;

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override;

    void drawToggleButton (Graphics& g, ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void createTabTextLayout (const TabBarButton& button, float length, float depth, Colour colour, TextLayout& textLayout);
    void drawTabButton (TabBarButton& button, Graphics& g, bool isMouseOver, bool isMouseDown) override;
    Button* createTabBarExtrasButton() override;

    void drawLinearSlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;

    Slider::SliderLayout getSliderLayout (Slider& slider) override;
    Label* createSliderTextBox (Slider& slider) override;

    Component* getParentComponentForMenuOptions (const PopupMenu::Options& options) override;
    
    juce::PopupMenu::Options getOptionsForComboBoxPopupMenu (ComboBox& comboBox, Label& label) override;

private:
    std::unique_ptr<Drawable> knob = Drawable::createFromImageData (BinaryData::knob_svg, BinaryData::knob_svgSize);
    std::unique_ptr<Drawable> pointer = Drawable::createFromImageData (BinaryData::pointer_svg, BinaryData::pointer_svgSize);

    Typeface::Ptr roboto;
    Typeface::Ptr robotoBold;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyLNF)
};

class ComboBoxLNF : public MyLNF
{
public:
    ComboBoxLNF()
    {
        setColour (PopupMenu::backgroundColourId, Colour (0xFF31323A));
        setColour (PopupMenu::highlightedBackgroundColourId, Colour (0x7FEAA92C));
        setColour (PopupMenu::highlightedTextColourId, Colours::white);
    }

    void drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box) override;
    void positionComboBoxText (ComboBox& box, Label& label) override;

    void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, const bool isHighlighted, const bool /*isTicked*/, const bool hasSubMenu, const String& text, const String& shortcutKeyText, const Drawable* icon, const Colour* const textColourToUse) override
    {
        LookAndFeel_V4::drawPopupMenuItem (g, area, isSeparator, isActive, isHighlighted, false /*isTicked*/, hasSubMenu, text, shortcutKeyText, icon, textColourToUse);
    }

    void drawPopupMenuBackground (Graphics& g, int width, int height) override
    {
        g.fillAll (findColour (PopupMenu::backgroundColourId));
        ignoreUnused (width, height);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboBoxLNF)
};

class PresetsLNF : public ComboBoxLNF
{
public:
    PresetsLNF() = default;

    void drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box) override
    {
        auto cornerSize = 5.0f;
        Rectangle<int> boxBounds (0, 0, width, height);

        g.setColour (box.findColour (ComboBox::backgroundColourId));
        g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);
    }

    void positionComboBoxText (ComboBox& box, Label& label) override
    {
        label.setBounds (3, 1, box.getWidth(), box.getHeight() - 2);
        label.setFont (getComboBoxFont (box).boldened());
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetsLNF)
};

class SpeedButtonLNF : public MyLNF
{
public:
    SpeedButtonLNF() {}

    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        constexpr auto cornerSize = 8.0f;
        auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);

        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                              .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

        if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
            baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

        g.setColour (baseColour);
        g.fillRoundedRectangle (bounds, cornerSize);

        g.setColour (Colour (0xFF838590));
        g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpeedButtonLNF)
};

#endif // MYLNF_H_INCLUDED
