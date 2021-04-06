#pragma once

class ScrollView : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (ScrollView)

    ScrollView (foleys::MagicGUIBuilder& builder, ValueTree node)
        : foleys::GuiItem (builder, node),
          baseView (builder, node)
    {
        addAndMakeVisible (viewport);
        addAndMakeVisible (baseView);
        viewport.setViewedComponent (&baseView, false);

        viewport.setScrollBarsShown (true, false);
        viewport.getVerticalScrollBar().setColour (ScrollBar::thumbColourId, Colour (0xFFEAA92C).withAlpha (0.7f));
    }

    void resized() override
    {
        viewport.setBounds (getLocalBounds());
        baseView.setSize (getWidth(), jmax (420, getHeight()));
    }

    void update() override
    {
        baseView.getConfigNode() = configNode.createCopy();
        baseView.update();
    }

    bool isContainer() const override { return true; }

    void createSubComponents() override
    {
        baseView.getConfigNode() = configNode.createCopy();
        baseView.createSubComponents();
    }

    Component* getWrappedComponent() override { return &viewport; }

    foleys::GuiItem* findGuiItemWithId (const String& name) override { return baseView.findGuiItemWithId (name); }

private:
    Viewport viewport;
    foleys::Container baseView;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScrollView)
};
