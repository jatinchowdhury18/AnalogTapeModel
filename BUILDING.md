# Instructions For Building
CHOW Tape is built using the [JUCE](https://github.com/juce-framework/JUCE) framework, with [PluginGUIMagic](https://github.com/ffAudio/PluginGUIMagic)
for the UI. To build from scratch, you must first clone the repository
and initialize the submodules using the following commands:

```bash
# Clone the repository
git clone --recursive https://github.com/jatinchowdhury18/AnalogTapeModel.git

# Enter the repository
cd AnalogTapeModel/Plugin

# Initialize submodules
git submodule update --init --recursive
```

## Building on MacOS/Windows
1. Navigate to `JUCE/extras/Projucer/Builds/`
2. Build the Projucer using XCode (Mac) or Visual Studio (Windows)
3. From the Projucer, open CHOWTapeModel.jucer
4. Select "Save and open in IDE"
5. Build CHOW Tape

## Building on Linux
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
- python3 (only if you plan to build LV2)

Then to build the plugin (Standalone, VST3, LV2), run
```
cd Plugin/ && bash build_linux.sh
```

If you would like to customise which plugin formats are
built, you may edit line 23 of `build_linux.sh`, to select
your desired plugin format targets (LV2, VST, VST3, Standalone).
```bash
CONFIG=Release make LV2 VST3 Standalone # replace this with a list of your preferred targets
```

Builds can be found in `Builds/LinuxMakefile/build/`.

## Building with the GUI Editor
If you need to make changes to the GUI, you can build the
plugin with Foley's Magic Editor attached. From the Projucer,
navigate to `modules -> foleys_gui_magic`, and enable
`FOLEYS_SHOW_GUI_EDITOR_PALLETTE`.
