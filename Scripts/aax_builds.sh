#!/bin/bash

# exit on failure
set -e

if [[ "$*" = *debug* ]]; then
    echo "Making DEBUG build"
    build_config="Debug"
else
    echo "Making RELEASE build"
    build_config="Release"
fi

cd Plugin

# clean up old builds
if [[ $* = *clean* ]]; then
    echo "Cleaning previous build..."
    rm -rf build-aax/
fi

sed_cmakelist()
{
    sed_args="$1"

    if [[ "$OSTYPE" == "darwin"* ]]; then
        sed -i '' "$sed_args" CMakeLists.txt
    else
        sed -i -e "$sed_args" CMakeLists.txt
    fi
}

# set up OS-dependent variables
if [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Building for MAC"

    AAX_PATH=~/Developer/AAX_SDK/
    ilok_pass=$(more ~/Developer/ilok_pass)
    aax_target_dir="/Library/Application Support/Avid/Audio/Plug-Ins"
    TEAM_ID=$(more ~/Developer/mac_id)

else # Windows
    echo "Building for WINDOWS"

    AAX_PATH=C:/SDKs/AAX_SDK/
    ilok_pass=$(cat /d/ilok_pass)
    aax_target_dir="/c/Program Files/Common Files/Avid/Audio/Plug-Ins"
fi

# set up build AAX
sed_cmakelist "s~# juce_set_aax_sdk_path.*~juce_set_aax_sdk_path(${AAX_PATH})~"

# cmake new builds
if [[ "$OSTYPE" == "darwin"* ]]; then
    cmake -Bbuild-aax -GXcode -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="Developer ID Application" \
        -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="$TEAM_ID" \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_STYLE="Manual" \
        -D"CMAKE_OSX_ARCHITECTURES=x86_64" \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_INJECT_BASE_ENTITLEMENTS=NO \
        -DCMAKE_XCODE_ATTRIBUTE_OTHER_CODE_SIGN_FLAGS="--timestamp" \
        -DMACOS_RELEASE=ON

    cmake --build build-aax --config $build_config -j12 --target CHOWTapeModel_AAX | xcpretty

else # Windows
    cmake -Bbuild-aax -G"Visual Studio 16 2019" -A x64
    cmake --build build-aax --config $build_config --parallel $(nproc) --target CHOWTapeModel_AAX
fi

# sign with PACE
aax_location=build-aax/CHOWTapeModel_artefacts/$build_config/AAX/CHOWTapeModel.aaxplugin
wcguid="D3FA57E0-3DA5-11EC-8891-005056920FF7"
if [[ "$OSTYPE" == "darwin"* ]]; then
    wraptool sign --verbose \
        --account chowdsp \
        --password "$ilok_pass" \
        --wcguid $wcguid \
        --dsig1-compat off \
        --signid "Developer ID Application: Jatin Chowdhury" \
        --in $aax_location \
        --out $aax_location

    wraptool verify --verbose --in $aax_location

else # Windows
    wraptool sign --verbose \
        --account chowdsp \
        --password "$ilok_pass" \
        --wcguid $wcguid \
        --keyfile /c/Users/jatin/Downloads/jatin_aax_cert.p12 \
        --keypassword "$ilok_pass" \
        --in $aax_location \
        --out $aax_location
        
    wraptool verify --verbose --in $aax_location/Contents/x64/CHOWTapeModel.aaxplugin
fi

# reset AAX SDK field...
sed_cmakelist "s~juce_set_aax_sdk_path.*~# juce_set_aax_sdk_path(NONE)~"

rm -rf "$aax_target_dir/CHOWTapeModel.aaxplugin"
cp -R "$aax_location" "$aax_target_dir/CHOWTapeModel.aaxplugin"
