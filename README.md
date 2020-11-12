# Physical Modeling for Analog Tape Machines
[![Download Latest](https://img.shields.io/badge/download-latest-blue.svg)](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest)
[![Build Status](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel.svg?token=Ub9niJrqG1Br1qaaxp7E&branch=master)](https://travis-ci.com/jatinchowdhury18/AnalogTapeModel)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-brightgreen.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Downloads](https://img.shields.io/github/downloads/jatinchowdhury18/AnalogTapeModel/total)](https://somsubhra.com/github-release-stats/?username=jatinchowdhury18&repository=AnalogTapeModel)

CHOW Tape Model is a physical model of an analog tape machine,
implemented as an audio plugin. The physical model is described
in a [paper](http://dafx2019.bcu.ac.uk/papers/DAFx2019_paper_3.pdf)
presented at the 2019 DAFx conference. This work began part of a
class project for [Music 420](https://ccrma.stanford.edu/courses/420/)
at Stanford University (CCRMA).

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
  - LV2
  - Standalone plugin

## Installation

Download the latest release
[here](https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest).
If you would like to try the most recent builds (potentially unstable),
see [here](https://github.com/jatinchowdhury18/AnalogTapeModel/tree/develop/Plugin/Bin).
If you need Linux builds, or if you prefer to build the plugin for yourself,
please see the [building instructions](https://github.com/jatinchowdhury18/AnalogTapeModel/blob/master/BUILDING.md).
Alternatively, Linux users may download builds from the
[Open Build Service](https://build.opensuse.org/package/show/home:kill_it:JUCE/CHOWTapeModel).

Note for FL Studio users: If you're experiencing pops and click while using
the plugin, try enabling the "used fixed size buffers" setting. For more
information, see this [issue](https://github.com/jatinchowdhury18/AnalogTapeModel/issues/17#issuecomment-640199581).

## Contributing

Contributions are most welcome! There are many ways to contribute to this 
project, for both programmers and non-programmers. For more information,
see the
[contributing guidelines](https://github.com/jatinchowdhury18/AnalogTapeModel/blob/master/CONTRIBUTING.md).

## Credits

- GUI Design - [Margus Mets](mailto:hello@mmcreative.eu)
- GUI Framework - [Plugin GUI Magic](https://github.com/ffAudio/PluginGUIMagic)
- Open Build Service Builds - [Konstantin Voinov](https://github.com/lv2-porting-project)
- User Manual - Yann

## License
CHOW Tape is licensed under the GNU General Public License agreement. Enjoy!
