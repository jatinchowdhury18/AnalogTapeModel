#include "PresetManager.h"

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
    auto userPresetFolder = appDataDir.getChildFile (userPresetPath).getSiblingFile ("Presets");
    if (! userPresetFolder.isDirectory())
    {
        userPresetFolder.deleteFile();
        userPresetFolder.createDirectory();
    }

    setUserPresetPath (userPresetFolder);
#endif // JUCE_IOS
}

void PresetManager::loadFactoryPresets()
{
    setDefaultPreset (chowdsp::Preset { BinaryData::Default_chowpreset, BinaryData::Default_chowpresetSize });

    std::vector<chowdsp::Preset> factoryPresets;

    // CHOW
    factoryPresets.emplace_back (BinaryData::TC260_chowpreset, BinaryData::TC260_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::LoFi_chowpreset, BinaryData::LoFi_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::WoozyChorus_chowpreset, BinaryData::WoozyChorus_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::OldTape_chowpreset, BinaryData::OldTape_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Underbiased_chowpreset, BinaryData::Underbiased_chowpresetSize);

    // SINK
    factoryPresets.emplace_back (BinaryData::SNK_BassPusher_chowpreset, BinaryData::SNK_BassPusher_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Chorus2_chowpreset, BinaryData::SNK_Chorus2_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Chorus3_chowpreset, BinaryData::SNK_Chorus3_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Chorus4_chowpreset, BinaryData::SNK_Chorus4_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_CleanFat_chowpreset, BinaryData::SNK_CleanFat_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Fat2_chowpreset, BinaryData::SNK_Fat2_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Gritty_chowpreset, BinaryData::SNK_Gritty_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_Gritty2_chowpreset, BinaryData::SNK_Gritty2_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_lofi_chowpreset, BinaryData::SNK_lofi_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::SNK_SlightlyWobbly_chowpreset, BinaryData::SNK_SlightlyWobbly_chowpresetSize);

    // AEIOU
    factoryPresets.emplace_back (BinaryData::AEIOU_DisintegratedMemories_chowpreset, BinaryData::AEIOU_DisintegratedMemories_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::AEIOU_FunkThat1987_chowpreset, BinaryData::AEIOU_FunkThat1987_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::AEIOU_HelloHangover_chowpreset, BinaryData::AEIOU_HelloHangover_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::AEIOU_IHaveARadio_chowpreset, BinaryData::AEIOU_IHaveARadio_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::AEIOU_Warehouse1997_chowpreset, BinaryData::AEIOU_Warehouse1997_chowpresetSize);

    // Carter
    factoryPresets.emplace_back (BinaryData::Bad_Tape_Good_Player_chowpreset, BinaryData::Bad_Tape_Good_Player_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Cozy_Unstable_chowpreset, BinaryData::Cozy_Unstable_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Fast_Wobble_chowpreset, BinaryData::Fast_Wobble_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Found_Tape_Player_chowpreset, BinaryData::Found_Tape_Player_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Good_Tape_Bad_Player_chowpreset, BinaryData::Good_Tape_Bad_Player_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::INIT_chowpreset, BinaryData::INIT_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Just_Warmth_chowpreset, BinaryData::Just_Warmth_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Low_Cut_High_Cut_chowpreset, BinaryData::Low_Cut_High_Cut_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Old_Telephone_chowpreset, BinaryData::Old_Telephone_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Punchy_Lofi_Drums_chowpreset, BinaryData::Punchy_Lofi_Drums_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::That_Dirty_LoFi_chowpreset, BinaryData::That_Dirty_LoFi_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::ThatDirtyLofi_Less_Noise_chowpreset, BinaryData::ThatDirtyLofi_Less_Noise_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Underwater_chowpreset, BinaryData::Underwater_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Perc__Noise_After_Hit_chowpreset, BinaryData::Perc__Noise_After_Hit_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Bass__Sub_Beef_chowpreset, BinaryData::Bass__Sub_Beef_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Bass__Warm_Tape_chowpreset, BinaryData::Bass__Warm_Tape_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Bass__808_Comp_and_Tone_chowpreset, BinaryData::Bass__808_Comp_and_Tone_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Bass__808_Maker_chowpreset, BinaryData::Bass__808_Maker_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Guitar__Phaser_Like_chowpreset, BinaryData::Guitar__Phaser_Like_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Guitar__Short_Plucked_chowpreset, BinaryData::Guitar__Short_Plucked_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Guitar__Slower_Chorus_chowpreset, BinaryData::Guitar__Slower_Chorus_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Guitar__Vintage_Chorus_chowpreset, BinaryData::Guitar__Vintage_Chorus_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Guitar__Breaking_Up_chowpreset, BinaryData::Guitar__Breaking_Up_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::High_Hats__Hats_Shorter_chowpreset, BinaryData::High_Hats__Hats_Shorter_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::High_Hats__Lofi_Vibe_chowpreset, BinaryData::High_Hats__Lofi_Vibe_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::High_Hats__Old_MPC_chowpreset, BinaryData::High_Hats__Old_MPC_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Kick__A_Little_Punch_chowpreset, BinaryData::Kick__A_Little_Punch_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Kick__Broken_Kick_chowpreset, BinaryData::Kick__Broken_Kick_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Kick__In_the_Cut_chowpreset, BinaryData::Kick__In_the_Cut_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Kick__LoFi_Kick_chowpreset, BinaryData::Kick__LoFi_Kick_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Kick__LoFi_Kick_Short_chowpreset, BinaryData::Kick__LoFi_Kick_Short_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Kick__Punch_Hi_Cut_chowpreset, BinaryData::Kick__Punch_Hi_Cut_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Mix__Cassette_Like_chowpreset, BinaryData::Mix__Cassette_Like_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Mix__Super_LoFi_chowpreset, BinaryData::Mix__Super_LoFi_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Mix__30ips_Glue_chowpreset, BinaryData::Mix__30ips_Glue_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Just_Tape_Noise_chowpreset, BinaryData::Just_Tape_Noise_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Subtle_Tape_Noise_chowpreset, BinaryData::Subtle_Tape_Noise_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Tape_Noise_Hard_Rain_chowpreset, BinaryData::Tape_Noise_Hard_Rain_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Tape_Noise_Rain_chowpreset, BinaryData::Tape_Noise_Rain_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Almost_LoFi_Piano_chowpreset, BinaryData::Almost_LoFi_Piano_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Piano__Clean_Cassette_chowpreset, BinaryData::Piano__Clean_Cassette_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Piano__Dirtier_Cassette_chowpreset, BinaryData::Piano__Dirtier_Cassette_chowpresetSize);

    factoryPresets.emplace_back (BinaryData::Snare__Almost_Bitcrushed_chowpreset, BinaryData::Snare__Almost_Bitcrushed_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Snare__Cut_the_Lows_chowpreset, BinaryData::Snare__Cut_the_Lows_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Snare__LoFi_Vibe_chowpreset, BinaryData::Snare__LoFi_Vibe_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Snare__Shorter_LoFi_chowpreset, BinaryData::Snare__Shorter_LoFi_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::Snare__Shorter_Snare_chowpreset, BinaryData::Snare__Shorter_Snare_chowpresetSize);

    // Cool WAV
    factoryPresets.emplace_back (BinaryData::CoolWAV_ChewLoss_chowpreset, BinaryData::CoolWAV_ChewLoss_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_DriftwithMe_chowpreset, BinaryData::CoolWAV_DriftwithMe_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_GoodbyeHighs_chowpreset, BinaryData::CoolWAV_GoodbyeHighs_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_HeavyDrumloop_chowpreset, BinaryData::CoolWAV_HeavyDrumloop_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_StudioTime_chowpreset, BinaryData::CoolWAV_StudioTime_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_TapeWide_chowpreset, BinaryData::CoolWAV_TapeWide_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_ThatsCool_chowpreset, BinaryData::CoolWAV_ThatsCool_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_VibeDrive_chowpreset, BinaryData::CoolWAV_VibeDrive_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_Wack_chowpreset, BinaryData::CoolWAV_Wack_chowpresetSize);
    factoryPresets.emplace_back (BinaryData::CoolWAV_WowDude_chowpreset, BinaryData::CoolWAV_WowDude_chowpresetSize);

    addPresets (factoryPresets);
    loadDefaultPreset();
}

chowdsp::Preset PresetManager::loadUserPresetFromFile (const File& file)
{
    chowdsp::Preset compatiblePreset { file };
    if (compatiblePreset.isValid())
        return std::move (compatiblePreset);

    auto xml = XmlDocument::parse (file);
    if (xml == nullptr)
        return compatiblePreset;

    if (xml->getTagName() != chowdsp::Preset::presetTag.toString())
        return compatiblePreset;

    auto name = xml->getStringAttribute (chowdsp::Preset::nameTag);
    if (name.isEmpty())
        return compatiblePreset;

    auto vendor = xml->getStringAttribute (chowdsp::Preset::vendorTag);
    if (vendor.isEmpty())
    {
        vendor = name.upToFirstOccurrenceOf ("_", false, false);
        name = name.fromLastOccurrenceOf ("_", false, false);
    }

    auto category = xml->getStringAttribute (chowdsp::Preset::categoryTag);

    auto* xmlState = xml->getChildElement (0);
    if (xmlState == nullptr)
        return compatiblePreset;

    return { name, vendor, *xmlState, category, file };
}

void PresetManager::loadPresetState (const XmlElement* xml)
{
    StringArray presetAgnosticParams { "os_factor", "os_mode", "os_render_factor", "os_render_mode", "os_render_like_realtime" };

    auto newState = juce::ValueTree::fromXml (*xml);
    for (auto& param : presetAgnosticParams)
    {
        auto curParamTree = vts.state.getChildWithProperty ("id", param);
        jassert (curParamTree.isValid());

        auto presetParamTree = newState.getChildWithProperty ("id", param);
        if (presetParamTree.isValid())
            presetParamTree.copyPropertiesFrom (curParamTree, nullptr);
        else
            newState.appendChild (curParamTree.createCopy(), nullptr);
    }

    vts.replaceState (newState);
}
