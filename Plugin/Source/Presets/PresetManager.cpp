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
    numFactoryPresets = presets.size();

    for (auto* p : presets)
    {
        jassert (! presetMap.contains (p->index)); // no two presets can have the same index
        presetMap.set (p->index, p);
        maxIdx = jmax (maxIdx, p->index);
    }

    maxIdx++;

    updateUserPresets();
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

bool PresetManager::saveUserPreset (const String& name, const AudioProcessorValueTreeState& vts)
{
    if (! userPresetFolder.isDirectory()) // if not set, choose preset folder
        chooseUserPresetFolder();

    if (! userPresetFolder.isDirectory()) // user doesn't want to choose preset folder, cancelling...
        return false;

    // create file to save preset
    File saveFile = userPresetFolder.getChildFile (name + ".preset");
    saveFile.deleteFile();
    auto result = saveFile.create();

    if (result.failed()) // unable to create file;
        return false;

    auto stateXml = vts.state.createXml();
    if (stateXml == nullptr) // invalid xml
        return false;

    // create preset XML
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
    updateUserPresets();
    return true;
}

File PresetManager::getUserPresetConfigFile() const
{
    File updatePresetFile = File::getSpecialLocation (File::userApplicationDataDirectory);
    return updatePresetFile.getChildFile (userPresetPath);
}

void PresetManager::chooseUserPresetFolder()
{
    FileChooser chooser ("Choose preset folder");
    if (chooser.browseForDirectory())
    {
        auto result = chooser.getResult();
        auto config = getUserPresetConfigFile();
        config.deleteFile();
        config.create();
        config.replaceWithText (result.getFullPathName());
        updateUserPresets();
    }
}

void PresetManager::loadPresetFolder (PopupMenu& menu, File& directory)
{
    Array<File> presetFiles;
    for (auto& userPreset : directory.findChildFiles (File::findFilesAndDirectories, false))
    {
        if (userPreset.isDirectory())
        {
            auto relativePath = userPreset.getRelativePathFrom (userPresetFolder);
            auto firstSubfolder = relativePath.fromLastOccurrenceOf (File::getSeparatorString(), false, false);

            PopupMenu subMenu;
            loadPresetFolder (subMenu, userPreset);
            menu.addSubMenu (firstSubfolder, subMenu);
        }

        if (userPreset.hasFileExtension (".preset"))
            presetFiles.add (userPreset);
    }

    for (auto& userPreset : presetFiles)
    {
        auto relativePath = userPreset.getRelativePathFrom (userPresetFolder);
        auto newPreset = presets.add (std::make_unique<Preset> (userPreset));
        newPreset->index = maxIdx;
        presetMap.set (newPreset->index, newPreset);
        menu.addItem (newPreset->index + 1, newPreset->name.fromFirstOccurrenceOf ("User_", false, false));
        maxIdx++;
    }
}

void PresetManager::updateUserPresets()
{
    // set preset folder
    auto config = getUserPresetConfigFile();
    if (config.existsAsFile())
        userPresetFolder = File (config.loadFileAsString());
    else
        userPresetFolder = File();

    // remove existing user presets
    presets.removeRange (numFactoryPresets, maxIdx - numFactoryPresets);
    for (; maxIdx > numFactoryPresets; maxIdx--)
        presetMap.remove (maxIdx - 1);
    userPresetMenu.clear();

    if (userPresetFolder.isDirectory())
        loadPresetFolder (userPresetMenu, userPresetFolder);
}
