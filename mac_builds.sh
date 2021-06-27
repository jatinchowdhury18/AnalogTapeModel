#!/bin/bash

# exit on failure
set -e

# clean up old builds
cd Plugin
rm -Rf build/
rm -Rf Bin/*Mac*

# set up build VST
VST_PATH=~/Developer/Plugin_SDKs/VST2_SDK/
sed -i '' "s~# juce_set_vst2_sdk_path.*~juce_set_vst2_sdk_path(${VST_PATH})~" CMakeLists.txt

# cmake new builds
TEAM_ID=$(more ~/Developer/mac_id)
cmake -Bbuild -GXcode -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="Developer ID Application" \
    -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="$TEAM_ID" \
    -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_STYLE="Manual" \
    -D"CMAKE_OSX_ARCHITECTURES=arm64;x86_64" \
    -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_INJECT_BASE_ENTITLEMENTS=NO \
    -DCMAKE_XCODE_ATTRIBUTE_OTHER_CODE_SIGN_FLAGS="--timestamp" \
    -DMACOS_RELEASE=ON
cmake --build build --config Release -j12 | xcpretty

# copy builds to Bin
mkdir -p Bin/Mac
plugin="CHOWTapeModel"
cp -R build/${plugin}_artefacts/Release/Standalone/${plugin}.app Bin/Mac/${plugin}.app
cp -R build/${plugin}_artefacts/Release/VST/${plugin}.vst Bin/Mac/${plugin}.vst
cp -R build/${plugin}_artefacts/Release/VST3/${plugin}.vst3 Bin/Mac/${plugin}.vst3
cp -R build/${plugin}_artefacts/Release/AU/${plugin}.component Bin/Mac/${plugin}.component

# reset CMakeLists.txt
git restore CMakeLists.txt

# run auval
echo "Running AU validation..."
rm -Rf ~/Library/Audio/Plug-Ins/Components/${plugin}.component
sudo rm -Rf /Library/Audio/Plug-Ins/Components/${plugin}.component
cp -R build/${plugin}_artefacts/Release/AU/${plugin}.component ~/Library/Audio/Plug-Ins/Components
manu=$(grep 'PLUGIN_MANUFACTURER_CODE' CMakeLists.txt | head -1 | awk '{print $NF}')
code=$(grep 'PLUGIN_CODE' CMakeLists.txt | head -1 | awk '{print $NF}')

set +e
auval_result=$(auval -v aufx "$code" "$manu")
auval_code="$?"
echo "AUVAL code: $auval_code"

if [ "$auval_code" != 0 ]; then
    echo "$auval_result"
    echo "auval FAIL!!!"
    exit 1
else
    echo "auval PASSED"
fi

# zip builds
VERSION=$(cut -f 2 -d '=' <<< "$(grep 'CMAKE_PROJECT_VERSION:STATIC' build/CMakeCache.txt)")
(
    cd bin
    rm -f "CHOWTapeModel-Mac-${VERSION}.zip"
    zip -r "CHOWTapeModel-Mac-${VERSION}.zip" Mac
)

# create installer
echo "Creating installer..."
(
    cd Installers/mac
    bash build_mac_installer.sh
)
