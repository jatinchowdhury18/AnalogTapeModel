#include "PresetManager.h"
#include "../PluginProcessor.h"
#include "PresetComp.h"

namespace
{
    static String userPresetPath = "ChowdhuryDSP/ChowTape/UserPresets.txt";
}

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
    initialise (ValueTree::fromXml (xmlText));
    
}

Preset::Preset (const File& presetFile)
{
    String xmlText = presetFile.loadFileAsString();
    initialise (ValueTree::fromXml (xmlText));
}

void Preset::initialise (const ValueTree& parentTree)
{
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
    // load factory presets
    presets.add (std::make_unique<Preset> ("Default.preset"));
    presets.add (std::make_unique<Preset> ("TC260.preset"));
    presets.add (std::make_unique<Preset> ("LoFi.preset"));
    presets.add (std::make_unique<Preset> ("WoozyChorus.preset"));
    presets.add (std::make_unique<Preset> ("OldTape.preset"));
    presets.add (std::make_unique<Preset> ("Underbiased.preset"));
    presets.add (std::make_unique<Preset> ("SNK_CleanFat.preset"));
    presets.add (std::make_unique<Preset> ("SNK_Fat2.preset"));
    presets.add (std::make_unique<Preset> ("SNK_Gritty.preset"));
    presets.add (std::make_unique<Preset> ("SNK_Gritty2.preset"));
    presets.add (std::make_unique<Preset> ("SNK_lofi.preset"));
    presets.add (std::make_unique<Preset> ("SNK_SlightlyWobbly.preset"));

    for (auto* p : presets)
    {
        jassert (! presetMap.contains (p->index)); // no two presets can have the same index
        presetMap.set (p->index, p);
        maxIdx = jmax (maxIdx, p->index);
    }

    maxIdx++;

    // load user presets
    auto presetFile = getUserPresetFile();
    StringArray presetPaths;
    presetFile.readLines (presetPaths);
    
    for (const auto& path : presetPaths)
    {
        File pathFile { path };
        if (! pathFile.existsAsFile())
        {
            presetPaths.removeString (path);
            continue;
        }

        loadUserPreset (pathFile);
    }

    resaveUserPresetFile (presetPaths);
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

void PresetManager::saveUserPreset (const String& name, const AudioProcessorValueTreeState& vts)
{
    FileChooser fileChooser ("Save Preset", File(), "*.chowpreset");
    if (fileChooser.browseForFileToSave (true))
    {
        auto saveFile = fileChooser.getResult();
        saveFile.deleteFile();
        auto result = saveFile.create();

        if (result.failed()) // unable to create file;
            return;

        auto stateXml = vts.state.createXml();
        if (stateXml == nullptr) // invalid xml
            return;

        auto presetXml = std::make_unique<XmlElement> ("Preset");
        presetXml->setAttribute ("name", "User_" + name);
        
        auto xmlParameters = std::make_unique<XmlElement> ("Parameters");
        forEachXmlChildElementWithTagName (*stateXml, p, "PARAM")
        {
            if (p->getAttributeValue (0) == "preset")
                p->setAttribute ("value", maxIdx);

            xmlParameters->addChildElement (new XmlElement (*p));
        }
        presetXml->addChildElement (xmlParameters.release());

        saveFile.replaceWithText (presetXml->toString());
        loadUserPreset (saveFile);
    }
}

void PresetManager::loadUserPreset (const File& file)
{
    const auto& presetFile = getUserPresetFile();

    StringArray lines;
    presetFile.readLines (lines);
    lines.addIfNotAlreadyThere (file.getFullPathName());

    auto newPreset = presets.add (std::make_unique<Preset> (file));
    newPreset->index = jmax (maxIdx, newPreset->index);
    presetMap.set (newPreset->index, newPreset);
    maxIdx++;

    resaveUserPresetFile (lines);
}

File PresetManager::getUserPresetFile()
{
    File updatePresetFile = File::getSpecialLocation (File::userApplicationDataDirectory);
    updatePresetFile = updatePresetFile.getChildFile (userPresetPath);

    if (! updatePresetFile.existsAsFile())
        updatePresetFile.create();

    return updatePresetFile;
}

void PresetManager::resaveUserPresetFile (const StringArray& presetPaths)
{
    auto presetFile = getUserPresetFile();
    presetFile.deleteFile();
    presetFile.create();

    for (const auto& path : presetPaths)
        presetFile.appendText (path);
}
