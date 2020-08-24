#include "PresetManager.h"
#include "../PluginProcessor.h"
#include "PresetComp.h"

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
    presets.add (new Preset ("TC260.xml"));
    presets.add (new Preset ("LoFi.xml"));
    presets.add (new Preset ("WoozyChorus.xml"));
    presets.add (new Preset ("OldTape.xml"));
    presets.add (new Preset ("Underbiased.xml"));

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
    if (! isPositiveAndBelow (idx, presets.size())) // invalid index
    {
        jassertfalse;
        return {};
    }

    return presetMap[idx]->name;
}

bool PresetManager::setPreset (AudioProcessorValueTreeState& vts, int idx)
{
    if (! isPositiveAndBelow (idx, presets.size())) // invalid index
    {
        jassertfalse;
        return false;
    }

    auto newState = presetMap[idx]->state.createCopy();
    vts.replaceState (newState);
    return true;
}

void PresetManager::registerPresetsComponent (foleys::MagicGUIBuilder& builder)
{
    static Identifier presetsID { "presets" };
    builder.registerFactory (presetsID, &PresetComponentItem::factory);
}
