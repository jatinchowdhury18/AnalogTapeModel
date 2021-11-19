# Instructions For Building
ChowTape is built using [CMake](https://cmake.org),
along with the [JUCE](https://github.com/juce-framework/JUCE) 
framework, and [PluginGUIMagic](https://github.com/ffAudio/PluginGUIMagic)
for the UI. JUCE and PluginGUIMagic are included in
the repository, but CMake must be installed before
attempting to build. To build from scratch, you must
first clone the repository and initialize the submodules 
using the following commands:

```bash
# Clone the repository
git clone --recursive https://github.com/jatinchowdhury18/AnalogTapeModel.git

# Enter the repository
cd AnalogTapeModel

# Initialize submodules
git submodule update --init --recursive
```

Next you can generate the builds with CMake:

```bash
cd Plugin

cmake -Bbuild
cmake --build build/ --config Release
```

## Building for iOS

To build for iOS, you can use the following CMake configuration command:
```bash
cmake -Bbuild-ios -GXcode -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_DEPLOYMENT_TARGET=11.4 \
    -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="$YOUR_TEAM_ID" \
    -DCMAKE_XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY="1,2" \
    -DCMAKE_XCODE_ATTRIBUTE_ENABLE_BITCODE="NO"
```
Then, go to the `build-ios/` directory, open the Xcode 
project, and build. Note that you may not need to pass
the  `XCODE_ATTRIBUTE_DEVELOPMENT_TEAM` argument if
you're  building for your own local device, or using
the Xcode simulator. Alternatively, you could set the 
development team manually from within Xcode.

## Linux Dependencies
The Linux build utilises the following dependencies:
- libasound
- libxcursor
- libxinerama
- libxrandr
- freeglut3
- libjack

These can be installed with the following command:
```
sudo apt-get install libasound2-dev libxcursor-dev libxinerama-dev libxrandr-dev freeglut3-dev libjack-jackd2-dev
```
Depending on your Linux distribution, you may also need to install:
- freetype
- libGL
- libXext
- libcurl

## Building with the GUI Editor
If you need to make changes to the GUI, you can build
the plugin with Foley's Magic Editor attached. In
`Plugin/modules/CMakeLists.txt`, set 
`FOLEYS_SHOW_GUI_EDITOR_PALLETTE` equal to 1.
