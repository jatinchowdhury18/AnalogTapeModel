#pragma once

#include "../PluginProcessor.h"

class SettingsButton : public DrawableButton,
                       public chowdsp::TrackedByBroadcasters
{
    using SettingID = chowdsp::GlobalPluginSettings::SettingID;

public:
    SettingsButton (const ChowtapeModelAudioProcessor& processor, chowdsp::OpenGLHelper* openGLHelper);

    void globalSettingChanged (SettingID settingID);

private:
    void showSettingsMenu();
    void openGLMenu (PopupMenu& menu, int itemID);
    void copyDiagnosticInfo();

    const ChowtapeModelAudioProcessor& proc;
    chowdsp::OpenGLHelper* openGLHelper;

    chowdsp::SharedPluginSettings pluginSettings;
    chowdsp::SharedLNFAllocator lnfAllocator;

    static constexpr SettingID openglID = "use_opengl";

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsButton)
};

class SettingsButtonItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (SettingsButtonItem)

    SettingsButtonItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node)
    {
        auto* plugin = dynamic_cast<ChowtapeModelAudioProcessor*> (builder.getMagicState().getProcessor());
        button = std::make_unique<SettingsButton> (*plugin, plugin->getOpenGLHelper());

        addAndMakeVisible (button.get());
    }

    void update() override {}

    Component* getWrappedComponent() override
    {
        return button.get();
    }

private:
    std::unique_ptr<SettingsButton> button;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsButtonItem)
};
