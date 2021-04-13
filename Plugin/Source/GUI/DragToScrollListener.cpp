#include "DragToScrollListener.h"

DragToScrollListener::DragToScrollListener (Viewport& v) : viewport (v)
{
    viewport.getViewedComponent()->addMouseListener (this, true);
    offsetX.addListener (this);
    offsetY.addListener (this);
    offsetX.behaviour.setMinimumVelocity (100);
    offsetY.behaviour.setMinimumVelocity (100);
}

DragToScrollListener::~DragToScrollListener()
{
    viewport.getViewedComponent()->removeMouseListener (this);
    Desktop::getInstance().removeGlobalMouseListener (this);
}

void DragToScrollListener::positionChanged (ViewportDragPosition&, double)
{
    if (! isDragging)
        return;

    viewport.setViewPosition (originalViewPos - Point<int> ((int) offsetX.getPosition(), (int) offsetY.getPosition()));
}

static int getNumSources()
{
    return Desktop::getInstance().getNumDraggingMouseSources();
}

void DragToScrollListener::mouseDown (const MouseEvent&)
{
    if (! isGlobalMouseListener && getNumSources() >= 2)
    {
        offsetX.setPosition (offsetX.getPosition());
        offsetY.setPosition (offsetY.getPosition());

        // switch to a global mouse listener so we still receive mouseUp events
        // if the original event component is deleted
        viewport.getViewedComponent()->removeMouseListener (this);
        Desktop::getInstance().addGlobalMouseListener (this);

        isGlobalMouseListener = true;
    }
}

void DragToScrollListener::mouseDrag (const MouseEvent& e)
{
    if (getNumSources() >= 2 && ! doesMouseEventComponentBlockViewportDrag (e.eventComponent))
    {
        auto totalOffset = e.getOffsetFromDragStart().toFloat();

        if (! isDragging && totalOffset.getDistanceFromOrigin() > 8.0f)
        {
            isDragging = true;

            originalViewPos = viewport.getViewPosition();
            offsetX.setPosition (0.0);
            offsetX.beginDrag();
            offsetY.setPosition (0.0);
            offsetY.beginDrag();
        }

        if (isDragging)
        {
            offsetX.drag (totalOffset.x);
            offsetY.drag (totalOffset.y);
        }
    }
}

void DragToScrollListener::mouseUp (const MouseEvent&)
{
    if (isGlobalMouseListener && getNumSources() < 2)
        endDragAndClearGlobalMouseListener();
}

void DragToScrollListener::endDragAndClearGlobalMouseListener()
{
    offsetX.endDrag();
    offsetY.endDrag();
    isDragging = false;

    viewport.getViewedComponent()->addMouseListener (this, true);
    Desktop::getInstance().removeGlobalMouseListener (this);

    isGlobalMouseListener = false;
}

bool DragToScrollListener::doesMouseEventComponentBlockViewportDrag (const Component* eventComp)
{
    for (auto c = eventComp; c != nullptr && c != &viewport; c = c->getParentComponent())
        if (c->getViewportIgnoreDragFlag())
            return true;

    return false;
}
