add_subdirectory(GUI)
add_subdirectory(Processors)

target_sources(CHOWTapeModel PRIVATE
    PluginProcessor.cpp

    MixGroups/MixGroupsController.cpp
    MixGroups/MixGroupsSharedData.cpp

    Presets/PresetComp.cpp
    Presets/PresetManager.cpp
)

juce_add_binary_data(BinaryData SOURCES
    GUI/Assets/Background.svg
    GUI/Assets/gui.xml
    GUI/Assets/knob.svg
    GUI/Assets/pointer.svg
    GUI/Assets/powerswitch.svg
    GUI/Assets/RobotoCondensed-Bold.ttf
    GUI/Assets/RobotoCondensed-Regular.ttf

    Presets/PresetConfigs/Default.chowpreset
    Presets/PresetConfigs/LoFi.chowpreset
    Presets/PresetConfigs/OldTape.chowpreset
    Presets/PresetConfigs/SNK_BassPusher.chowpreset
    Presets/PresetConfigs/SNK_Chorus2.chowpreset
    Presets/PresetConfigs/SNK_Chorus3.chowpreset
    Presets/PresetConfigs/SNK_Chorus4.chowpreset
    Presets/PresetConfigs/SNK_CleanFat.chowpreset
    Presets/PresetConfigs/SNK_Fat2.chowpreset
    Presets/PresetConfigs/SNK_Gritty.chowpreset
    Presets/PresetConfigs/SNK_Gritty2.chowpreset
    Presets/PresetConfigs/SNK_lofi.chowpreset
    Presets/PresetConfigs/SNK_SlightlyWobbly.chowpreset
    Presets/PresetConfigs/TC260.chowpreset
    Presets/PresetConfigs/Underbiased.chowpreset
    Presets/PresetConfigs/WoozyChorus.chowpreset

    Processors/Hysteresis/STN_Models/hyst_width_0.json
    Processors/Hysteresis/STN_Models/hyst_width_10.json
    Processors/Hysteresis/STN_Models/hyst_width_20.json
    Processors/Hysteresis/STN_Models/hyst_width_30.json
    Processors/Hysteresis/STN_Models/hyst_width_40.json
    Processors/Hysteresis/STN_Models/hyst_width_50.json
    Processors/Hysteresis/STN_Models/hyst_width_60.json
    Processors/Hysteresis/STN_Models/hyst_width_70.json
    Processors/Hysteresis/STN_Models/hyst_width_80.json
    Processors/Hysteresis/STN_Models/hyst_width_90.json
    Processors/Hysteresis/STN_Models/hyst_width_100.json
)

# Need to build BinaryData with -fPIC flag on Linux
set_target_properties(BinaryData PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE)

if(${BUILD_HEADLESS})
    add_subdirectory(Headless)
endif()
