#include "PresetManager.h"
#include "PresetComp.h"

namespace
{
const String userPresetPath = "ChowdhuryDSP/ChowTape/UserPresets.txt";
}

PresetManager::PresetManager (AudioProcessorValueTreeState& vts) : chowdsp::PresetManager (vts)
{

    loadFactoryPresets();
    setUserPresetConfigFile (userPresetPath);

#if JUCE_IOS
    File appDataDir = File::getSpecialLocation (File::userApplicationDataDirectory);
    userPresetFolder = appDataDir.getChildFile (userPresetPath).getSiblingFile ("Presets");
    if (! userPresetFolder.isDirectory())
    {
        userPresetFolder.deleteFile();
        userPresetFolder.createDirectory();
    }
#endif
}

void PresetManager::loadFactoryPresets()
{
    setDefaultPreset (chowdsp::Preset { BinaryData::Default_chowpreset, BinaryData::Default_chowpresetSize });

    std::vector<chowdsp::Preset> factoryPresets;

    // CHOW
    factoryPresets.emplace_back(BinaryData::TC260_chowpreset, BinaryData::TC260_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::LoFi_chowpreset, BinaryData::LoFi_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::WoozyChorus_chowpreset, BinaryData::WoozyChorus_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::OldTape_chowpreset, BinaryData::OldTape_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::Underbiased_chowpreset, BinaryData::Underbiased_chowpresetSize);

    // SINK
    factoryPresets.emplace_back(BinaryData::SNK_BassPusher_chowpreset, BinaryData::SNK_BassPusher_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Chorus2_chowpreset, BinaryData::SNK_Chorus2_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Chorus3_chowpreset, BinaryData::SNK_Chorus3_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Chorus4_chowpreset, BinaryData::SNK_Chorus4_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_CleanFat_chowpreset, BinaryData::SNK_CleanFat_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Fat2_chowpreset, BinaryData::SNK_Fat2_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Gritty_chowpreset, BinaryData::SNK_Gritty_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_Gritty2_chowpreset, BinaryData::SNK_Gritty2_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_lofi_chowpreset, BinaryData::SNK_lofi_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::SNK_SlightlyWobbly_chowpreset, BinaryData::SNK_SlightlyWobbly_chowpresetSize);

    // AEIOU
    factoryPresets.emplace_back(BinaryData::AEIOU_DisintegratedMemories_chowpreset, BinaryData::AEIOU_DisintegratedMemories_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::AEIOU_FunkThat1987_chowpreset, BinaryData::AEIOU_FunkThat1987_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::AEIOU_HelloHangover_chowpreset, BinaryData::AEIOU_HelloHangover_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::AEIOU_IHaveARadio_chowpreset, BinaryData::AEIOU_IHaveARadio_chowpresetSize);
    factoryPresets.emplace_back(BinaryData::AEIOU_Warehouse1997_chowpreset, BinaryData::AEIOU_Warehouse1997_chowpresetSize);

    addPresets (factoryPresets);
    loadDefaultPreset();
}
