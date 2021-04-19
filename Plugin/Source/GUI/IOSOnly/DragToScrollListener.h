#pragma once

#include <JuceHeader.h>

using ViewportDragPosition = AnimatedPosition<AnimatedPositionBehaviours::ContinuousWithMomentum>;

class DragToScrollListener : private MouseListener,
                             private ViewportDragPosition::Listener
{
public:
    DragToScrollListener (Viewport& v);
    ~DragToScrollListener() override;

    void positionChanged (ViewportDragPosition&, double) override;

    void mouseDown (const MouseEvent&) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent&) override;

    void endDragAndClearGlobalMouseListener();
    bool doesMouseEventComponentBlockViewportDrag (const Component* eventComp);

private:
    Viewport& viewport;
    ViewportDragPosition offsetX, offsetY;
    Point<int> originalViewPos;
    bool isDragging = false;
    bool isGlobalMouseListener = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DragToScrollListener)
};
