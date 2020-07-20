#include "TooltipComp.h"

TooltipComponent::TooltipComponent()
{
    setColour (backgroundColourID, Colours::transparentBlack);
    setColour (textColourID, Colours::lightgrey);
    setColour (nameColourID, Colours::white);

    showTip.store (false);
    startTimer (123);
}

void TooltipComponent::paint (Graphics& g)
{
    g.fillAll (findColour (backgroundColourID));

    if (showTip.load())
    {
        auto b = getLocalBounds();

        g.setFont (Font (17.0f).boldened());
        if (name.isNotEmpty())
        {
            g.setColour (findColour (nameColourID));
            g.drawFittedText (name + ":", b, Justification::topLeft, 1);
        }

        auto whitespace = String();
        auto font = g.getCurrentFont();
        while (font.getStringWidth(whitespace) < font.getStringWidth (name + ": "))
            whitespace += " ";

        g.setColour (findColour (textColourID));
        g.drawMultiLineText (whitespace + tip, b.getX(),
            b.getY() + (int) font.getHeight() - 3, b.getWidth(), Justification::topLeft);
    }
}

String TooltipComponent::getTipFor (Component& c)
{
    if (Process::isForegroundProcess()
         && ! ModifierKeys::currentModifiers.isAnyMouseButtonDown())
    {
        if (auto* ttc = dynamic_cast<TooltipClient*> (&c))
            if (! c.isCurrentlyBlockedByAnotherModalComponent())
                return ttc->getTooltip();
    }

    return {};
}

void TooltipComponent::timerCallback()
{
    auto& desktop = Desktop::getInstance();
    auto mouseSource = desktop.getMainMouseSource();

    auto* newComp = mouseSource.isTouch() ? nullptr : mouseSource.getComponentUnderMouse();

    bool needsRepaint = false;
    if (newComp != nullptr)
    {
        auto newTip = getTipFor (*newComp);
        needsRepaint = newTip != tip;

        tip = newTip;
        name = newComp->getName();   

        if (! showTip.load())
        {
            showTip.store (true);
            needsRepaint = true;
        }
    }
    else
    {
        if (showTip.load())
        {
            showTip.store (false);
            needsRepaint = true;
        }
    }

    if (needsRepaint)
        repaint();
}
