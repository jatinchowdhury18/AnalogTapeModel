#include "MixGroupViz.h"

MixGroupViz::MixGroupViz (AudioProcessorParameter* mixGroupParam) : mixGroupParam (mixGroupParam)
{
    mixGroupParam->addListener (this);
    setMixGroupColour (int (mixGroupParam->getValue() * MixGroupsConstants::numMixGroups));
}

MixGroupViz::~MixGroupViz()
{
    mixGroupParam->removeListener (this);
}

void MixGroupViz::parameterValueChanged (int, float newValue)
{
    newMixGroupIndex = int (newValue * MixGroupsConstants::numMixGroups);

    if (MessageManager::existsAndIsCurrentThread())
        mixGroupChanged();
    else
        triggerAsyncUpdate();
}

void MixGroupViz::handleAsyncUpdate()
{
    mixGroupChanged();
}

void MixGroupViz::mixGroupChanged()
{
    setMixGroupColour (newMixGroupIndex);
}

void MixGroupViz::setMixGroupColour (int mixGroupIdx)
{
    switch (mixGroupIdx)
    {
        case 0:
            circleColour = Colour (0x00000000); // no circle
            break;

        case 1:
            circleColour = Colour (0xFF8B3232); // red
            break;

        case 2:
            circleColour = Colour (0xFFEAA92C); // orange
            break;

        case 3:
            circleColour = Colour (0xFF9CBCBD); // grey/blue
            break;

        case 4:
            circleColour = Colour (0xFFBDB09C); // beige
            break;

        default:
            circleColour = Colour (0x00000000);
    };

    MessageManagerLock mml;
    repaint();
}

void MixGroupViz::paint (Graphics& g)
{
    const auto height = float (getHeight() - getPosition().getY());
    const auto centre = juce::Point<int> (getWidth() / 2, getHeight() / 2).toFloat();
    auto bounds = Rectangle<float> (height, height)
                      .withCentre (centre);

    g.setColour (circleColour);
    g.fillEllipse (bounds);
}
