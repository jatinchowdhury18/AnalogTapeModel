set(JUCE_PATH JUCE)
if(CUSTOM_JUCE_PATH)
    set(JUCE_PATH "${CUSTOM_JUCE_PATH}")
endif()

add_subdirectory(${JUCE_PATH} juce)

juce_add_modules(foleys_gui_magic)
add_subdirectory(chowdsp_utils)

subproject_version(JUCE juce_version)
message(STATUS "VERSION for JUCE: ${juce_version}")
subproject_version(chowdsp_utils chowdsp_version)
message(STATUS "VERSION for chowdsp: ${chowdsp_version}")

# Using RTNeural with XSimd backend
set(RTNEURAL_XSIMD ON CACHE BOOL "Use RTNeural with XSimd backend" FORCE)
add_definitions(-DUSE_XSIMD=1)
add_subdirectory(RTNeural)

include(cmake/WarningFlags.cmake)
add_library(juce_plugin_modules STATIC)
target_link_libraries(juce_plugin_modules
    PRIVATE
        BinaryData
        juce::juce_audio_utils
        juce::juce_audio_plugin_client
        chowdsp::chowdsp_dsp_utils
        chowdsp::chowdsp_sources
        chowdsp::chowdsp_plugin_base
        chowdsp::chowdsp_plugin_utils
        chowdsp::chowdsp_presets
        chowdsp::chowdsp_foleys
        foleys_gui_magic
        RTNeural
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        warning_flags
)

if(CHOWTAPE_BUILD_CLAP)
    add_subdirectory(clap-juce-extensions EXCLUDE_FROM_ALL)
    target_link_libraries(juce_plugin_modules
        PRIVATE
            chowdsp::chowdsp_clap_extensions
            clap_juce_extensions
    )
endif()

add_diagnostic_info(juce_plugin_modules)

target_compile_definitions(juce_plugin_modules
    PUBLIC
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_REPORT_APP_USAGE=0
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_MODAL_LOOPS_PERMITTED=1
        JUCE_COREGRAPHICS_DRAW_ASYNC=1
        FOLEYS_SHOW_GUI_EDITOR_PALLETTE=0
        FOLEYS_ENABLE_BINARY_DATA=1
        FOLEYS_ENABLE_OPEN_GL_CONTEXT=0
        JucePlugin_Manufacturer="chowdsp"
        JucePlugin_VersionString="${CMAKE_PROJECT_VERSION}"
        JucePlugin_Name="${CMAKE_PROJECT_NAME}"
    INTERFACE
        $<TARGET_PROPERTY:juce_plugin_modules,COMPILE_DEFINITIONS>
)

target_include_directories(juce_plugin_modules
    PUBLIC
        RTNeural/modules/xsimd/include
    INTERFACE
        $<TARGET_PROPERTY:juce_plugin_modules,INCLUDE_DIRECTORIES>
)

set_target_properties(juce_plugin_modules PROPERTIES
    POSITION_INDEPENDENT_CODE TRUE
    VISIBILITY_INLINES_HIDDEN TRUE
    C_VISBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
)

if(IOS)
    target_link_libraries(juce_plugin_modules PRIVATE juce::juce_product_unlocking)
    target_compile_definitions(juce_plugin_modules PUBLIC JUCE_IN_APP_PURCHASES=1)
endif()

# Enable OpenGL on Windows by default.
if (WIN32)
    option(CHOWDSP_ENABLE_OPENGL "Enable OpenGL for this plugin" ON)
else()
    option(CHOWDSP_ENABLE_OPENGL "Enable OpenGL for this plugin" OFF)
endif()

if(CHOWDSP_ENABLE_OPENGL)
    message(STATUS "Linking with OpenGL")
    target_link_libraries(juce_plugin_modules PRIVATE juce::juce_opengl)
endif()
