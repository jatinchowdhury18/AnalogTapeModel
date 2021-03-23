#pragma once

#include "MyLNF.h"
#include "../PluginProcessor.h"

class WowFlutterMenuLNF;
class WowFlutterMenu : public ComboBox
{
public:
    WowFlutterMenu (const ChowtapeModelAudioProcessor& proc, const String& type);
    ~WowFlutterMenu() override;

    void setupUI();
    void setupRateParam (bool isFlutter);
    void setRateValue (float value);

private:
    AudioParameterFloat* rateParam = nullptr;

    const ChowtapeModelAudioProcessor& proc;
    std::unique_ptr<WowFlutterMenuLNF> lnf;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowFlutterMenu)
};

class WowFlutterMenuItem : public foleys::GuiItem
{
public:
    WowFlutterMenuItem (foleys::MagicGUIBuilder& builder, const ValueTree& node, const String& type) :
        foleys::GuiItem (builder, node)
    {
        const auto* proc = dynamic_cast<ChowtapeModelAudioProcessor*> (builder.getMagicState().getProcessor());
        jassert (proc); // this should never be nullptr!

        menu = std::make_unique<WowFlutterMenu> (*proc, type);
        addAndMakeVisible (menu.get());
    }

    void update() override {}

    Component* getWrappedComponent() override { return menu.get(); }

private:
    std::unique_ptr<WowFlutterMenu> menu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowFlutterMenuItem)
};
