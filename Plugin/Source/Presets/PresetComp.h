#ifndef PRESETCOMP_H_INCLUDED
#define PRESETCOMP_H_INCLUDED

#include "PresetManager.h"
#include "../PluginProcessor.h"

class PresetComp : public Component,
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

private:
    class CustomComboBox : public ComboBox
    {
    public:
        CustomComboBox (const String& name = {}) :
            ComboBox (name)
        {
            setLookAndFeel (&comboLNF);
        }

        ~CustomComboBox()
        {
            setLookAndFeel (nullptr);
        }

    private:
        class ComboLNF : public LookAndFeel_V4
        {
            void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area,
                const bool isSeparator, const bool isActive,
                const bool isHighlighted, const bool /*isTicked*/,
                const bool hasSubMenu, const String& text,
                const String& shortcutKeyText,
                const Drawable* icon, const Colour* const textColourToUse) override
            {
                LookAndFeel_V4::drawPopupMenuItem (g, area, isSeparator, isActive,
                    isHighlighted, false /*isTicked*/, hasSubMenu, text,
                    shortcutKeyText, icon, textColourToUse);
            }
        };

        ComboLNF comboLNF;
    };

    ChowtapeModelAudioProcessor& proc;
    PresetManager& manager;
    CustomComboBox presetBox;    

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
