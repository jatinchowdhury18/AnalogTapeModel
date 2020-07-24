#include "InfoComp.h"

InfoComp::InfoComp (const AudioProcessor::WrapperType wrapperType) :
    wrapperType (wrapperType)
{
    setColour (text1ColourID, Colours::grey);
    setColour (text2ColourID, Colours::white);

    addAndMakeVisible (linkButton);
    linkButton.setFont (Font (17.0f).boldened(), false, Justification::left);
}

void InfoComp::paint (Graphics& g)
{
    g.setFont (17.0f);
    auto font = g.getCurrentFont();
    auto b = getLocalBounds();

    auto drawText = [=, &g, &b] (const String& text)
    {
        auto width = font.getStringWidth (text);
        g.drawFittedText (text, b.removeFromLeft (width), Justification::left, 1);  
    };

    auto typeStr = String (AudioProcessor::getWrapperTypeDescription (wrapperType));
    g.setColour (findColour (text1ColourID));
    drawText (typeStr + ", ");

    g.setColour (findColour (text2ColourID));
    drawText ("v" + String (JucePlugin_VersionString) + " ");

    g.setColour (findColour (text1ColourID));
    drawText (String ("~ DSP by "));

    linkX =  b.getX() - 2;
    linkButton.setColour (HyperlinkButton::ColourIds::textColourId, findColour (text2ColourID));
    resized();
}

void InfoComp::resized()
{
    auto b = getLocalBounds();
    linkButton.setBounds (linkX, 0, 100, getHeight());
}
