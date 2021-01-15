cmake_minimum_required(VERSION 3.15)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.12" CACHE STRING "Minimum OS X deployment target")
set(CMAKE_CXX_STANDARD 17)
project(CHOWTapeModel VERSION 2.7.0)

# set up JUCE and modules
add_subdirectory(Juce)
juce_add_modules(foleys_gui_magic)

add_library(juce_plugin_modules STATIC)
target_link_libraries(juce_plugin_modules
    PRIVATE
        BinaryData
        juce::juce_audio_utils
        juce::juce_audio_plugin_client
        foleys_gui_magic
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(juce_plugin_modules
    PUBLIC
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_REPORT_APP_USAGE=0
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        FOLEYS_SHOW_GUI_EDITOR_PALLETTE=0
        FOLEYS_ENABLE_BINARY_DATA=1
        JucePlugin_Manufacturer="chowdsp"
        JucePlugin_VersionString="${CMAKE_PROJECT_VERSION}"
        JucePlugin_Name="${CMAKE_PROJECT_NAME}"
    INTERFACE
        $<TARGET_PROPERTY:juce_plugin_modules,COMPILE_DEFINITIONS>
)

if(MSVC)
    target_compile_options(juce_plugin_modules PRIVATE /wd4458) # supress "declaration hides class member" for Foley's
endif()

target_include_directories(juce_plugin_modules
    INTERFACE
        $<TARGET_PROPERTY:juce_plugin_modules,INCLUDE_DIRECTORIES>
)

set_target_properties(juce_plugin_modules PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE
    VISIBILITY_INLINES_HIDDEN TRUE
    C_VISBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
)

# set up plugin project
# juce_set_vst2_sdk_path(C:/SDKs/VST_SDK/VST2_SDK/)
# include_directories(C:/SDKs/asiosdk2.3/common)

juce_add_plugin(CHOWTapeModel
    COMPANY_NAME chowdsp
    PLUGIN_MANUFACTURER_CODE Chow
    PLUGIN_CODE Jdox
    FORMATS AU VST3 Standalone LV2 #VST
    ProductName "CHOWTapeModel"
    LV2_URI https://github.com/jatinchowdhury18/AnalogTapeModel
)

# create JUCE header
juce_generate_juce_header(CHOWTapeModel)

add_subdirectory(Source)

target_compile_definitions(CHOWTapeModel
    PUBLIC
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_REPORT_APP_USAGE=0
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(CHOWTapeModel PUBLIC
    juce_plugin_modules
)
