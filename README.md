# Physical Modeling for Analog Tape Machines
[![Download Latest](https://img.shields.io/badge/download-latest-blue.svg)](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest)
[![Build Status](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel.svg?token=Ub9niJrqG1Br1qaaxp7E&branch=master)](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-brightgreen.svg)](https://www.gnu.org/licenses/gpl-3.0)

This repository contains an academic paper and corresponding
computer simulations and implementations for a signal processing
system that performs real-time physical modeling for an analog
tape machine.

This work is part of a class project for [Music 420](https://ccrma.stanford.edu/courses/420/) at Stanford
University (CCRMA).

## Definition
**magnetic tape** noun<br/>
mag·net·​ic tape | \ˈnedik 'tāp\
Definition of *magnetic tape*<br/>
1 : tape used in recording sound, pictures, or computer data.

## Description
![Pic](https://www.hifiengine.com/images/model/sony_tc-260.jpg)

CHOW Tape is an analog tape machine physical model, based on the
Sony TC-260. Useful for that vintage, top-of-the-line 1967 consumer
audio sound. Feel free to build and use for your own enjoyment.

CHOW Tape is currently available in the following formats:
  - VST
  - VST3
  - AU
  - Standalone plugin

## Instructions For Building
If you would like to build CHOW for yourself, use the following steps, otherwise you can download the [latest release &rarr;](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest).
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

For more information about the physical modelling process,
see the latest draft of the accompanying [paper](https://github.com/jatinchowdhury18/AnalogTapeModel/blob/master/Paper/420_paper.pdf).

## License
CHOW Tape is licensed under the GNU General Public License agreement. Enjoy!
