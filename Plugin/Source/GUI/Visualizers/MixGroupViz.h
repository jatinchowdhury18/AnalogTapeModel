#ifndef MIXGROUPVIZ_H_INCLUDED
#define MIXGROUPVIZ_H_INCLUDED

#include "../../MixGroups/MixGroupsController.h"
#include <JuceHeader.h>

class MixGroupViz : public Component,
                    private AudioProcessorParameter::Listener,
                    private AsyncUpdater
{
public:
    MixGroupViz (AudioProcessorParameter* mixGroupParam);
    ~MixGroupViz() override;

    void parameterValueChanged (int parameterIndex, float newValue) override;
    void parameterGestureChanged (int, bool) override {}
    void paint (Graphics& g) override;
    void setMixGroupColour (int mixGroupIdx);

private:
    void handleAsyncUpdate() override;
    void mixGroupChanged();

    Colour circleColour;
    AudioProcessorParameter* mixGroupParam;

    int newMixGroupIndex = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupViz)
};

class MixGroupVizItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (MixGroupVizItem)

    MixGroupVizItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node),
                                                                                viz (builder.getMagicState().getParameter (MixGroupsConstants::mixGroupParamID))
    {
        addAndMakeVisible (viz);
    }

    void update() override { viz.repaint(); }
    Component* getWrappedComponent() override { return &viz; }

private:
    MixGroupViz viz;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupVizItem)
};

#endif // !MIXGROUPVIZ_H_INCLUDED
