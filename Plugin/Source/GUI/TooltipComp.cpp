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

    if (tip.isEmpty())
        return;

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

void TooltipComponent::getTipFor (Component& c, String& newTip, String& newName)
{
    if (Process::isForegroundProcess()
         && ! ModifierKeys::currentModifiers.isAnyMouseButtonDown())
    {
        if (auto* ttc = dynamic_cast<TooltipClient*> (&c))
        {
            if (! c.isCurrentlyBlockedByAnotherModalComponent())
            {
                newTip = ttc->getTooltip();
                newName = c.getName();
            }
        }
    }
}

void TooltipComponent::timerCallback()
{
    auto& desktop = Desktop::getInstance();
    auto mouseSource = desktop.getMainMouseSource();

    auto* newComp = mouseSource.isTouch() ? nullptr : mouseSource.getComponentUnderMouse();

    bool needsRepaint = false;
    if (newComp != nullptr)
    {
        String newTip, newName;
        getTipFor (*newComp, newTip, newName);
        needsRepaint = newTip != tip;

        if (newTip.isNotEmpty() && newName.isEmpty())
        {
            if (auto parent = newComp->getParentComponent())
                newName = parent->getName();
        }

        tip = newTip;
        name = newName;

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
