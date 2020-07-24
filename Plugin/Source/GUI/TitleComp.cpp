#include "TitleComp.h"

TitleComp::TitleComp()
{
    setColour (text1ColourID, Colours::white);
    setColour (text2ColourID, Colours::grey);
}

void TitleComp::paint (Graphics& g)
{
    g.setFont (Font (font).boldened());
    auto font = g.getCurrentFont();
    auto b = getLocalBounds();

    auto drawText = [=, &g, &b] (const String& text)
    {
        auto width = font.getStringWidth (text);
        g.drawFittedText (text, b.removeFromLeft (width), Justification::left, 1);  
    };

    g.setColour (findColour (text1ColourID));
    drawText (title + " ");

    g.setColour (findColour (text2ColourID));
    drawText (subtitle);
}

void TitleComp::setStrings (String newTitle, String newSubtitle, float newFont)
{
    font = newFont == 0.0f ? (float) getHeight() : newFont;

    title = newTitle;
    subtitle = newSubtitle;
    repaint();
}

//======================================================================
TitleItem::TitleItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) :
    foleys::GuiItem (builder, node)
{
    setColourTranslation ({
        {"text1", TitleComp::text1ColourID},
        {"text2", TitleComp::text2ColourID},
    });

    addAndMakeVisible (comp);
}

void TitleItem::update()
{
    auto titleString    = magicBuilder.getStyleProperty (title,    configNode).toString();
    auto subtitleString = magicBuilder.getStyleProperty (subtitle, configNode).toString();
    auto fontVal = (float) magicBuilder.getStyleProperty (font, configNode);

    comp.setStrings (titleString, subtitleString, fontVal);
}

std::vector<foleys::SettableProperty> TitleItem::getSettableProperties() const
{
    std::vector<foleys::SettableProperty> properties;
    properties.push_back ({ configNode, title,    foleys::SettableProperty::Text, {}, {} });
    properties.push_back ({ configNode, subtitle, foleys::SettableProperty::Text, {}, {} });
    properties.push_back ({ configNode, font,     foleys::SettableProperty::Number, 0.0f, {} });
    return properties;
}

const Identifier TitleItem::title    { "title" };
const Identifier TitleItem::subtitle { "subtitle" };
const Identifier TitleItem::font     { "font" };
