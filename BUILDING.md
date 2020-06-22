# Instructions For Building

CHOW Tape is built using the [JUCE](https://github.com/juce-framework/JUCE) framework, with [PluginGUIMagic](https://github.com/ffAudio/PluginGUIMagic)
for the UI. To build from scratch, use the following steps:

1. Run the following commands:
  ```bash
  # Clone the repository
  git clone --recursive https://github.com/jatinchowdhury18/AnalogTapeModel.git
  
  # Enter the repository
  cd AnalogTapeModel/Plugin
  
  # Initialize JUCE submodule
  git submodule update --init --recursive
  ```
2. Navigate to `JUCE/extras/Projucer/Builds/`
3. Build the Projucer using XCode (Mac), Visual Studio (Windows), or Makefile (Linux)
4. From the Projucer, open CHOWTapeModel.jucer
5. Select "Save and open in IDE"
6. Build CHOW Tape

### Building with the GUI Editor

If you need to make changes to the GUI, you can build the
plugin with Foley's Magic Editor attached. From the Projucer,
navigate to `modules -> foleys_gui_magic`, and enable
`FOLEYS_SHOW_GUI_EDITOR_PALLETTE`.
