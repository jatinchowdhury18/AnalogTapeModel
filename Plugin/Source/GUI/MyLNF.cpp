#include "MyLNF.h"

MyLNF::MyLNF()
{
    roboto = Typeface::createSystemTypefaceFor (BinaryData::RobotoCondensedRegular_ttf,
                                                BinaryData::RobotoCondensedRegular_ttfSize);

    robotoBold = Typeface::createSystemTypefaceFor (BinaryData::RobotoCondensedBold_ttf,
                                                    BinaryData::RobotoCondensedBold_ttfSize);

    setColour (TabbedButtonBar::tabOutlineColourId, Colour (0xFF595C6B));
}

Typeface::Ptr MyLNF::getTypefaceForFont (const Font& font)
{
    return font.isBold() ? robotoBold : roboto;
}

void MyLNF::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height,
                              float sliderPos, float rotaryStartAngle,
                              float rotaryEndAngle, juce::Slider& slider)
{
    int diameter = (width > height)? height : width;
    if (diameter < 16) return;

    juce::Point<float> centre (x + std::floor (width * 0.5f + 0.5f), y + std::floor (height * 0.5f + 0.5f));
    diameter -= (diameter % 2)? 9 : 8;
    float radius = diameter * 0.5f;
    x = int (centre.x - radius);
    y = int (centre.y - radius);

    const auto bounds = juce::Rectangle<int> (x, y, diameter, diameter).toFloat();   

    auto b = pointer->getBounds().toFloat();
    auto b2 = knob->getBounds().toFloat();
    pointer->setTransform (AffineTransform::rotation (MathConstants<float>::twoPi * ((sliderPos - 0.5f) * 300.0f / 360.0f),
        b.getCentreX(), b.getCentreY()));

    auto knobBounds = (bounds * 0.75f).withCentre (centre);
    knob->drawWithin (g, knobBounds, RectanglePlacement::stretchToFit, 1.0f);
    pointer->drawWithin (g, knobBounds, RectanglePlacement::stretchToFit, 1.0f);

    const auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const juce::Colour fill = slider.findColour (juce::Slider::rotarySliderFillColourId);
    constexpr float arcFactor = 0.9f;

    Path valueArc;
    valueArc.addPieSegment (bounds, rotaryStartAngle, rotaryEndAngle, arcFactor);
    g.setColour (Colour (0xff596b6c));
    g.fillPath (valueArc);
    valueArc.clear();

    valueArc.addPieSegment (bounds, rotaryStartAngle, toAngle, arcFactor);
    ColourGradient gr (Colour (0xffce5757), { centre.x - radius, centre.y },
                       Colour (0xffce5757), { centre.x + radius, centre.y }, false);
    g.setGradientFill (gr);
    g.fillPath (valueArc);
}

void MyLNF::drawToggleButton (Graphics& g, ToggleButton& button,
                              bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    auto fontSize = jmin (15.0f, (float) button.getHeight() * 0.75f);
    auto tickWidth = fontSize * 1.1f;

    drawTickBox (g, button, 4.0f, ((float) button.getHeight() - tickWidth) * 0.5f,
                 tickWidth, tickWidth,
                 button.getToggleState(),
                 button.isEnabled(),
                 shouldDrawButtonAsHighlighted,
                 shouldDrawButtonAsDown);

    g.setColour (button.findColour (ToggleButton::textColourId));
    g.setFont (Font (fontSize).boldened());

    if (! button.isEnabled())
        g.setOpacity (0.5f);

    g.drawFittedText (button.getButtonText(),
                      button.getLocalBounds().withTrimmedLeft (roundToInt (tickWidth) + 10)
                                             .withTrimmedRight (2),
                      Justification::centredLeft, 10);
}

void MyLNF::createTabTextLayout (const TabBarButton& button, float length, float depth,
                                 Colour colour, TextLayout& textLayout)
{
    Font font (depth * 0.45f, Font::bold);
    font.setUnderline (button.hasKeyboardFocus (false));

    AttributedString s;
    s.setJustification (Justification::centred);
    s.append (button.getButtonText().trim(), font, colour);

    textLayout.createLayout (s, length);
}

void MyLNF::drawTabButton (TabBarButton& button, Graphics& g, bool /*isMouseOver*/, bool /*isMouseDown*/)
{
    const Rectangle<int> activeArea (button.getActiveArea());

    const TabbedButtonBar::Orientation o = button.getTabbedButtonBar().getOrientation();

    const Colour bkg (button.getTabBackgroundColour());

    if (button.getToggleState())
    {
        g.setColour (bkg);
    }
    else
    {
        Point<int> p1, p2;

        switch (o)
        {
        case TabbedButtonBar::TabsAtBottom:   p1 = activeArea.getBottomLeft(); p2 = activeArea.getTopLeft();    break;
        case TabbedButtonBar::TabsAtTop:      p1 = activeArea.getTopLeft();    p2 = activeArea.getBottomLeft(); break;
        case TabbedButtonBar::TabsAtRight:    p1 = activeArea.getTopRight();   p2 = activeArea.getTopLeft();    break;
        case TabbedButtonBar::TabsAtLeft:     p1 = activeArea.getTopLeft();    p2 = activeArea.getTopRight();   break;
        default:                              jassertfalse; break;
        }

        g.setGradientFill (ColourGradient (bkg.brighter (0.2f), p1.toFloat(),
            bkg.darker (0.1f),   p2.toFloat(), false));
    }

    g.fillRect (activeArea);

    g.setColour (button.findColour (TabbedButtonBar::tabOutlineColourId));

    Rectangle<int> r (activeArea);
    g.fillRect (r.removeFromBottom (1));

    const float alpha = 0.6f;
    Colour col (bkg.contrasting().withMultipliedAlpha (alpha));

    if (button.isFrontTab())
        col = Colours::white;

    const Rectangle<float> area (button.getTextArea().toFloat());

    float length = area.getWidth();
    float depth  = area.getHeight();

    if (button.getTabbedButtonBar().isVertical())
        std::swap (length, depth);

    TextLayout textLayout;
    createTabTextLayout (button, length, depth, col, textLayout);

    AffineTransform t;

    switch (o)
    {
    case TabbedButtonBar::TabsAtLeft:   t = t.rotated (MathConstants<float>::pi * -0.5f).translated (area.getX(), area.getBottom()); break;
    case TabbedButtonBar::TabsAtRight:  t = t.rotated (MathConstants<float>::pi *  0.5f).translated (area.getRight(), area.getY()); break;
    case TabbedButtonBar::TabsAtTop:
    case TabbedButtonBar::TabsAtBottom: t = t.translated (area.getX(), area.getY()); break;
    default:                            jassertfalse; break;
    }

    g.addTransform (t);
    textLayout.draw (g, Rectangle<float> (length, depth));
}

void MyLNF::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                              float sliderPos, float /*minSliderPos*/, float /*maxSliderPos*/,
                              const Slider::SliderStyle, Slider& slider)
{
    auto trackWidth = jmin (6.0f, slider.isHorizontal() ? (float) height * 0.25f : (float) width * 0.25f);

    Point<float> startPoint (slider.isHorizontal() ? (float) x : (float) x + (float) width * 0.5f,
        slider.isHorizontal() ? (float) y + (float) height * 0.5f : (float) (height + y));

    Point<float> endPoint (slider.isHorizontal() ? (float) (width + x) : startPoint.x,
        slider.isHorizontal() ? startPoint.y : (float) y);

    Path backgroundTrack;
    backgroundTrack.startNewSubPath (startPoint);
    backgroundTrack.lineTo (endPoint);
    g.setColour (slider.findColour (Slider::backgroundColourId));
    g.strokePath (backgroundTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

    Path valueTrack;
    Point<float> minPoint, maxPoint, thumbPoint;

    {
        auto kx = slider.isHorizontal() ? sliderPos : ((float) x + (float) width * 0.5f);
        auto ky = slider.isHorizontal() ? ((float) y + (float) height * 0.5f) : sliderPos;

        minPoint = startPoint;
        maxPoint = { kx, ky };
    }

    auto thumbWidth = getSliderThumbRadius (slider);

    valueTrack.startNewSubPath (minPoint);
    valueTrack.lineTo (maxPoint);
    g.setColour (slider.findColour (Slider::trackColourId));
    g.strokePath (valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

    auto thumbRect = Rectangle<float> (static_cast<float> (thumbWidth),
                                       static_cast<float> (thumbWidth)).withCentre (maxPoint);
    knob->drawWithin (g, thumbRect, RectanglePlacement::stretchToFit, 1.0f);
}

void ComboBoxLNF::drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box)
{
    auto cornerSize = 5.0f;
    Rectangle<int> boxBounds (0, 0, width, height);

    g.setColour (box.findColour (ComboBox::backgroundColourId));
    g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

    g.setColour (Colours::white);
    g.setFont (getComboBoxFont (box).boldened());
    auto nameBox = boxBounds.withWidth (boxBounds.proportionOfWidth (0.7f));
    g.drawFittedText (box.getName() + ": ", nameBox, Justification::centred, 1);
}

void ComboBoxLNF::positionComboBoxText (ComboBox& box, Label& label)
{
    auto b = box.getBounds();
    auto width = b.proportionOfWidth (0.3f);
    auto x = b.proportionOfWidth (0.7f);
    label.setBounds (b.withX (x).withWidth (width));

    label.setFont (getComboBoxFont (box).boldened());
}
