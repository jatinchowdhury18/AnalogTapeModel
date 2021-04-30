#!/bin/sh

cd Plugin

build64(){
    cmake -Bbuild -G"Visual Studio 15 2017 Win64"
    cmake --build build --config Release -j4
}

build32(){
    cmake -Bbuild32 -G"Visual Studio 15 2017"
    cmake --build build32 --config Release -j4
}

# exit on failure
set -e

# clean up old builds
rm -Rf build/
rm -Rf build32/
rm -Rf Bin/*Win64*
rm -Rf Bin/*Win32*

# set up VST and ASIO paths
sed -i -e "s~# juce_set_vst2_sdk_path.*~juce_set_vst2_sdk_path(C:/SDKs/VST_SDK/VST2_SDK/)~" CMakeLists.txt
# sed -i -e "s~.*ASIO_SDK.*~include_directories(C:/SDKs/ASIO_SDK/common)~" CMakeLists.txt
# sed -i -e 's/# JUCE_ASIO.*/JUCE_ASIO=1/' modules/CMakeLists.txt

# cmake new builds
build64 &
build32 &
wait

# copy builds to bin
mkdir -p Bin/Win64
mkdir -p Bin/Win32
plugin="CHOWTapeModel"

cp -R build/${plugin}_artefacts/Release/Standalone/${plugin}.exe Bin/Win64/${plugin}.exe
cp -R build/${plugin}_artefacts/Release/VST/${plugin}.dll Bin/Win64/${plugin}.dll
cp -R build/${plugin}_artefacts/Release/VST3/${plugin}.vst3 Bin/Win64/${plugin}.vst3

cp -R build32/${plugin}_artefacts/Release/Standalone/${plugin}.exe Bin/Win32/${plugin}.exe
cp -R build32/${plugin}_artefacts/Release/VST/${plugin}.dll Bin/Win32/${plugin}.dll
cp -R build32/${plugin}_artefacts/Release/VST3/${plugin}.vst3 Bin/Win32/${plugin}.vst3

# reset CMakeLists.txt
git restore CMakeLists.txt
git restore modules/CMakeLists.txt

# zip builds
VERSION=$(cut -f 2 -d '=' <<< "$(grep 'CMAKE_PROJECT_VERSION:STATIC' build/CMakeCache.txt)")
(
    cd bin
    rm -f "CHOWTapeModel-Win64-${VERSION}.zip"
    rm -f "CHOWTapeModel-Win32-${VERSION}.zip"
    zip -r "CHOWTapeModel-Win64-${VERSION}.zip" Win64
    zip -r "CHOWTapeModel-Win32-${VERSION}.zip" Win32
)

# create installer
echo "Creating installer..."
(
    cd Installers/windows
    bash build_win_installer.sh
)
