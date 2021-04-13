#pragma once

#include "DragToScrollListener.h"

class ScrollView : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (ScrollView)

    ScrollView (foleys::MagicGUIBuilder& builder, ValueTree node);

    void resized() override;

    void update() override;
    Component* getWrappedComponent() override { return &viewport; }
    bool isContainer() const override { return true; }
    void createSubComponents() override;
    foleys::GuiItem* findGuiItemWithId (const String& name) override;

private:
    Viewport viewport;
    foleys::Container baseView;

    std::unique_ptr<DragToScrollListener> dragToScrollListener;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScrollView)
};
