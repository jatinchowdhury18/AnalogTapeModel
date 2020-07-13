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
- webkit2gtk
- freeglut3
- libjack

These can be installed with the following command:
```
sudo apt-get install libasound2-dev libxcursor-dev libxinerama-dev libxrandr-dev webkit2gtk-4.0 freeglut3-dev libjack-jackd2-dev
```

Then to build the plugin (Standalone, VST/ LV2), simply run
```
cd Plugin/ && bash build_linux.sh
```

Builds can be found in `Builds/LinuxMakefile/build/`.

## Building with the GUI Editor
If you need to make changes to the GUI, you can build the
plugin with Foley's Magic Editor attached. From the Projucer,
navigate to `modules -> foleys_gui_magic`, and enable
`FOLEYS_SHOW_GUI_EDITOR_PALLETTE`.
