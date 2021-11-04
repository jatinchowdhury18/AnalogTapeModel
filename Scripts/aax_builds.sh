#!/bin/bash

# exit on failure
set -e

# clean up old builds
cd Plugin
# rm -rf build-aax/

# set up build AAX
AAX_PATH=~/Developer/AAX_SDK/
sed -i '' "s~# juce_set_aax_sdk_path.*~juce_set_aax_sdk_path(${AAX_PATH})~" CMakeLists.txt

# cmake new builds
TEAM_ID=$(more ~/Developer/mac_id)
cmake -Bbuild-aax -GXcode -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="Developer ID Application" \
    -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="$TEAM_ID" \
    -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_STYLE="Manual" \
    -D"CMAKE_OSX_ARCHITECTURES=x86_64" \
    -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_INJECT_BASE_ENTITLEMENTS=NO \
    -DCMAKE_XCODE_ATTRIBUTE_OTHER_CODE_SIGN_FLAGS="--timestamp" \
    -DMACOS_RELEASE=ON
cmake --build build-aax --config Release -j12 --target CHOWTapeModel_AAX | xcpretty

# sign with PACE
aax_location=build-aax/CHOWTapeModel_artefacts/Release/AAX/CHOWTapeModel.aaxplugin
wcguid="D3FA57E0-3DA5-11EC-8891-005056920FF7"
ilok_pass=$(more ~/Developer/ilok_pass)
wraptool sign --verbose \
    --account chowdsp \
    --password "$ilok_pass" \
    --wcguid $wcguid \
    --dsig1-compat off \
    --signid "Developer ID Application: Jatin Chowdhury" \
    --in $aax_location \
    --out $aax_location

# reset AAX SDK field...
sed -i '' "s~juce_set_aax_sdk_path.*~# juce_set_aax_sdk_path(${AAX_PATH})~" CMakeLists.txt
