#include "PresetManager.h"
#include "../PluginProcessor.h"

Preset::Preset (String presetFile)
{
    // load xml text from BinaryData
    String xmlText;
    for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
    {
        if (String (BinaryData::originalFilenames[i]) == presetFile)
        {
            int dummy = 0;
            xmlText = String (BinaryData::getNamedResource (BinaryData::namedResourceList[i], dummy));
        }
    }

    jassert (xmlText.isNotEmpty()); // preset does not exist!!

    ValueTree parentTree = ValueTree::fromXml (xmlText);
    name = parentTree.getProperty ("name").toString();
    jassert (name.isNotEmpty()); // Preset name not found!!

    state = parentTree.getChildWithName ("Parameters");
    for (int i = 0; i < state.getNumChildren(); ++i)
    {
        auto child = state.getChild (i);
        if (child.getProperty ("id").toString() == "preset")
            index = (int) child.getProperty ("value");
    }
}

//====================================================
class PresetComp : public Component,
                   private PresetManager::Listener
{
public:
    PresetComp (ChowtapeModelAudioProcessor& proc, PresetManager& manager) :
        proc (proc)
    {
        manager.addListener (this);

        addAndMakeVisible (presetBox);
        presetBox.setJustificationType (Justification::centred);
        presetBox.setColour (ComboBox::ColourIds::backgroundColourId, Colours::transparentWhite);
        presetBox.addItemList (manager.getPresetChoices(), 1);
        presetBox.setColour (PopupMenu::ColourIds::backgroundColourId, Colour (0xFF434352));
        presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
        presetBox.onChange  = [=, &proc] {  proc.setCurrentProgram (presetBox.getSelectedItemIndex()); };
    }

    void paint (Graphics& g)
    {
        Colour background (0xFF434352);
        g.fillAll (background);

        g.setColour (Colours::white);
        g.setFont (getHeight() * 0.6f);
        auto presetBounds = presetBox.getBounds();
        presetBounds.setWidth (100);
        presetBounds.translate (-110, 0);
        g.drawFittedText ("Presets:", presetBounds, Justification::centredRight, 1);

        g.setFont (getHeight() * 0.4f);
        auto versionBounds = getLocalBounds().removeFromRight (50);
        g.drawFittedText ("v" + String (JucePlugin_VersionString), versionBounds, Justification::centred, 1);
    }

    void resized()
    {
        auto boxWidth = jmin (getWidth() / 3, 200);
        presetBox.setBounds ((getWidth() - boxWidth) / 2, 2, boxWidth, getHeight() - 4);
        repaint();
    }

    void presetUpdated() override
    {
        presetBox.setSelectedItemIndex (proc.getCurrentProgram(), dontSendNotification);
    }

private:
    ChowtapeModelAudioProcessor& proc;
    ComboBox presetBox;    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetComp)
};

//====================================================
PresetManager::PresetManager()
{
    loadPresets();
}

StringArray PresetManager::getPresetChoices()
{
    StringArray choices;
    for (int i = 0; i < maxIdx; ++i)
    {
        if (presetMap[i] != nullptr)
            choices.add (presetMap[i]->name);
    }

    return choices;
}

void PresetManager::loadPresets()
{
    presets.add (new Preset ("Default.xml"));
    presets.add (new Preset ("Quiet.xml"));

    for (auto* p : presets)
    {
        jassert (! presetMap.contains (p->index)); // no two presets can have the same index
        presetMap.set (p->index, p);
        maxIdx = jmax (maxIdx, p->index);
    }

    maxIdx++;
}

String PresetManager::getPresetName (int idx)
{
    jassert (isPositiveAndBelow (idx, presets.size()));
    return presetMap[idx]->name;
}

void PresetManager::setPreset (AudioProcessorValueTreeState& vts, int idx)
{
    jassert (isPositiveAndBelow (idx, presets.size()));
    auto newState = presetMap[idx]->state;
    vts.replaceState (newState);
}

void PresetManager::registerPresetsComponent (foleys::MagicGUIBuilder& builder, AudioProcessor* proc)
{
    auto procCast = dynamic_cast<ChowtapeModelAudioProcessor*> (proc);

    static Identifier presetsID { "presets" };
    builder.registerFactory (presetsID, [=] (const ValueTree&)
    {
        return std::make_unique<PresetComp> (*procCast, *this);
    });
}
