cmake_minimum_required(VERSION 3.15)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment target")
set(CMAKE_CXX_STANDARD 17)
project(CHOWTapeModel VERSION 2.9.0)

add_subdirectory(modules)
include_directories(modules/RTNeural)

# set up plugin project
# juce_set_vst2_sdk_path(C:/SDKs/VST_SDK/VST2_SDK/)
# juce_set_aax_sdk_path(/Users/jatin/Developer/AAX_SDK/)
# include_directories(ASIO_SDK)

if(IOS)
    set(JUCE_FORMATS Standalone AUv3)
else()
    set(JUCE_FORMATS AU VST3 Standalone)
endif()

# Build LV2 only on Linux
if(UNIX AND NOT APPLE)
    message(STATUS "Building LV2 plugin format")
    list(APPEND JUCE_FORMATS LV2)
endif()

# Build VST2 if SDK target exists
if(TARGET juce_vst2_sdk)
    message(STATUS "Building VST2 plugin format")
    list(APPEND JUCE_FORMATS VST)
endif()

# Build AAX if SDK target exists
if(TARGET juce_aax_sdk)
    message(STATUS "Building AAX plugin format")
    list(APPEND JUCE_FORMATS AAX)
endif()

juce_add_plugin(CHOWTapeModel
    COMPANY_NAME chowdsp
    PLUGIN_MANUFACTURER_CODE Chow
    PLUGIN_CODE Jdox
    FORMATS ${JUCE_FORMATS}
    ProductName "CHOWTapeModel"
    LV2_URI https://github.com/jatinchowdhury18/AnalogTapeModel
    ICON_BIG Source/GUI/Assets/logo.png
    MICROPHONE_PERMISSION_ENABLED TRUE
    IPHONE_SCREEN_ORIENTATIONS UIInterfaceOrientationPortrait UIInterfaceOrientationPortraitUpsideDown UIInterfaceOrientationLandscapeLeft UIInterfaceOrientationLandscapeRight
    IPAD_SCREEN_ORIENTATIONS UIInterfaceOrientationPortrait UIInterfaceOrientationPortraitUpsideDown UIInterfaceOrientationLandscapeLeft UIInterfaceOrientationLandscapeRight
    NEEDS_STORE_KIT TRUE
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
    JUCE_JACK=1
    JUCE_ALSA=1
    CHOWDSP_AUTO_UPDATE=1
)

target_link_libraries(CHOWTapeModel PUBLIC
    juce_plugin_modules
)

# we need these flags for notarization on MacOS
option(MACOS_RELEASE "Set build flags for MacOS Release" OFF)
if(MACOS_RELEASE)
    message(STATUS "Setting MacOS release flags...")
    set_target_properties(CHOWTapeModel_Standalone PROPERTIES
        XCODE_ATTRIBUTE_ENABLE_HARDENED_RUNTIME YES)
endif()

if(IOS)
    message(STATUS "Setting iOS-specific properties...")

    foreach(target IN ITEMS BinaryData RTNeural juce_plugin_modules CHOWTapeModel CHOWTapeModel_Standalone CHOWTapeModel_AUv3)
        set_target_properties(${target}
            PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY "./"
                ARCHIVE_OUTPUT_DIRECTORY "./"
                LIBRARY_OUTPUT_DIRECTORY "./")
    endforeach()

    set_target_properties(CHOWTapeModel_Standalone PROPERTIES
            XCODE_ATTRIBUTE_INSTALL_PATH "$(LOCAL_APPS_DIR)"
            XCODE_ATTRIBUTE_SKIP_INSTALL "NO"
            XCODE_ATTRIBUTE_ENABLE_IN_APP_PURCHASE "YES")

    set_target_properties(CHOWTapeModel_AUv3 PROPERTIES
            XCODE_ATTRIBUTE_INSTALL_PATH "$(LOCAL_APPS_DIR)/CHOWTapeModel.app/PlugIns"
            XCODE_ATTRIBUTE_SKIP_INSTALL "NO"
            XCODE_ATTRIBUTE_ENABLE_IN_APP_PURCHASE "YES")
endif()
