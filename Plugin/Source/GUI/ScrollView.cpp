#include "ScrollView.h"

ScrollView::ScrollView (foleys::MagicGUIBuilder& builder, ValueTree node)
    : foleys::GuiItem (builder, node),
      baseView (builder, node)
{
    addAndMakeVisible (viewport);
    addAndMakeVisible (baseView);
    viewport.setViewedComponent (&baseView, false);

    viewport.setScrollBarsShown (true, false);
    viewport.getVerticalScrollBar().setColour (ScrollBar::thumbColourId, Colour (0xFFEAA92C).withAlpha (0.7f));
    viewport.setScrollBarThickness (10);
    viewport.setScrollOnDragEnabled (false);

    dragToScrollListener = std::make_unique<DragToScrollListener> (viewport);
}

void ScrollView::resized()
{
    viewport.setBounds (getLocalBounds());
    baseView.setSize (getWidth() - viewport.getScrollBarThickness(), jmax (420, getHeight()));
}

void ScrollView::update()
{
    baseView.getConfigNode() = configNode.createCopy();
    baseView.update();
}

void ScrollView::createSubComponents()
{
    baseView.getConfigNode() = configNode.createCopy();
    baseView.createSubComponents();
}

foleys::GuiItem* ScrollView::findGuiItemWithId (const String& name)
{
    return baseView.findGuiItemWithId (name);
}
