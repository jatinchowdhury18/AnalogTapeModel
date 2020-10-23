#ifndef PRESETCOMP_H_INCLUDED
#define PRESETCOMP_H_INCLUDED

#include "PresetManager.h"
#include "../PluginProcessor.h"

class PresetComp : public Component,
                   public SettableTooltipClient,
                   private PresetManager::Listener
{
public:
    enum ColourIDs
    {
        backgroundColourId,
        textColourId,
    };

    PresetComp (ChowtapeModelAudioProcessor& proc, PresetManager& manager);
    ~PresetComp();

    void paint (Graphics& g) override;
    void resized() override;
    void presetUpdated() override;
    void loadPresetChoices();

private:
    ChowtapeModelAudioProcessor& proc;
    PresetManager& manager;
    ComboBox presetBox;    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetComp)
};

class PresetComponentItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (PresetComponentItem)

    PresetComponentItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) :
        foleys::GuiItem (builder, node)
    {
        setColourTranslation ({
            {"presets-background", PresetComp::backgroundColourId},
            {"presets-text", PresetComp::textColourId}
        });

        if (auto* proc = dynamic_cast<ChowtapeModelAudioProcessor*> (builder.getMagicState().getProcessor()))
        {
            presetComp = std::make_unique<PresetComp> (*proc, proc->getPresetManager());
            addAndMakeVisible (presetComp.get());
        }
    }

    void update() override {}

    Component* getWrappedComponent() override
    {
        return presetComp.get();
    }

private:
    std::unique_ptr<PresetComp> presetComp;
};

#endif // PRESETCOMP_H_INCLUDED
