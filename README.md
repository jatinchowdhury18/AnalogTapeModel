# Physical Modeling for Analog Tape Machines
[![Download Latest](https://img.shields.io/badge/download-latest-blue.svg)](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest)
[![Build Status](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel.svg?token=Ub9niJrqG1Br1qaaxp7E&branch=master)](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-brightgreen.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Downloads](https://img.shields.io/github/downloads/jatinchowdhury18/AnalogTapeModel/total)](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest)

CHOW Tape Model is a physical model of an analog tape machine,
implemented as an audio plugin. The physical model is described
in a [paper](http://dafx2019.bcu.ac.uk/papers/DAFx2019_paper_3.pdf)
presented at the 2019 DAFx conference. This work began part of a
class project for [Music 420](https://ccrma.stanford.edu/courses/420/)
at Stanford University (CCRMA). Download the latest release
[here](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest).

## Definition
**magnetic tape** noun<br/>
mag·net·​ic tape | \ˈnedik 'tāp\
Definition of *magnetic tape*<br/>
1 : tape used in recording sound, pictures, or computer data.

## Description
![Pic](https://www.hifiengine.com/images/model/sony_tc-260.jpg)

CHOW Tape is an analog tape machine physical model, originally
based on the Sony TC-260. The current version can be used to
emulate a wide variety of reel-to-reel tape machines.
Feel free to build and use for your own enjoyment.

CHOW Tape is currently available in the following formats:
  - VST
  - VST3
  - AU
  - Standalone plugin

## Instructions For Building
If you would like to try the most recent builds (potentially unstable),
see [here](https://github.com/jatinchowdhury18/AnalogTapeModel/tree/master/Plugin/Bin).
If you would like to build CHOW for yourself, use the following steps.

- Install [Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
- Run the following git commands:
  ```bash
  # Clone the repository
  git clone --recursive https://github.com/jatinchowdhury18/AnalogTapeModel.git
  
  # Enter the repository
  cd AnalogTapeModel/Plugin
  
  # Initialize JUCE submodule
  git submodule update --init --recursive
  ```
- Navigate to "JUCE/extras/Projucer/Builds/"
- Build the Projucer using XCode (Mac), Visual Studio (Windows), or Makefile (Linux)
- From the Projucer, open CHOWTapeModel.jucer
- From the "File" menu, open "Global Paths..."
  - Set "Path To JUCE" to "...\Plugin\JUCE"
  - Set "JUCE Modules" to "...\Plugin\JUCE\modules"
  - Set "VST (Legacy) SDK" to "...\Plugin\JUCE\VST2_SDK"
  - Close "Global Paths" window
- Select "Save and open in IDE"
- Build CHOW Tape

## License
CHOW Tape is licensed under the GNU General Public License agreement. Enjoy!
