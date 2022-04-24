add_subdirectory(GUI)
add_subdirectory(Processors)

target_sources(CHOWTapeModel PRIVATE
    PluginProcessor.cpp

    MixGroups/MixGroupsController.cpp
    MixGroups/MixGroupsSharedData.cpp

    Presets/PresetManager.cpp
)

file(GLOB UI_ASSET_FILES GUI/Assets/*)
file(GLOB_RECURSE PRESET_FILES Presets/PresetConfigs/*.chowpreset)
file(GLOB STN_MODEL_FILES Processors/Hysteresis/STN_Models/*.json)
list(APPEND binary_data_files ${UI_ASSET_FILES} ${PRESET_FILES} ${STN_MODEL_FILES})
juce_add_binary_data(BinaryData SOURCES ${binary_data_files})

# Need to build BinaryData with -fPIC flag on Linux
set_target_properties(BinaryData PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE)

if(${BUILD_HEADLESS})
    message(STATUS "Configuring ChowTape Headless")
    add_subdirectory(Headless)
endif()
