# Changelog
All notable changes to this project will be documented in
this file.

## [UNRELEASED]
- Updated delay lines in wow/flutter processing to use 3-point
  Lagrange interpolation.
- Improved Newton-Raphson solver performance.
- Improved loss filter sliders.
- Fixed tooltip name sometimes not appearing.
- Fixed save/load bug for VST3 in Ableton.

## [2.4.0] - 2020-07-26
- New "Hysteresis Mode" parameter: choose between Runge-Kutta or
  Newton-Raphson modes, or revert to Version 1.0-style processing.
- New GUI design.
- Added support for LV2 builds on Linux.
- Fixed volume spike when loading plugin during playback.

## [2.3.4] - 2020-06-25
- Fixed slider controls.
- Fixed dry/wet phase cancellation issues.

## [2.3.3] - 2020-06-22
- Fixed save/load bug in some DAWs.
- More subtle flutter/wow controls.
- Fixed issues with phase cancellation and reported latency.
- Turned off JUCE app usage reporting.

## [2.3.0] - 2020-06-02
- New 1x oversampling option.
- New "Wow" processing.
- Added presets.
- Fixed Logic validation issues.
- General bug fixes.

## [2.2.0] - 2020-05-06
- Improved "chew" algorithm.
- Much improved overall efficiency.
- General bug fixes.

## [2.1.0] - 2020-04-20
- New processors for modelling tape degradation and "chew".
- New GUI (courtesy of [Foleys GUI Magic](https://github.com/ffAudio/foleys_gui_magic)).
- Improved efficiency for loss filters.
- General bug fixes. 

## [2.0.0] - 2019-12-11
- New hysteresis processor, with much lower CPU consumption.
- Updated playhead model.
- Updated flutter processor with independent rate and
  depth controls.
- New variable oversampling parameter (2x, 4x, 8x)
- Improved overall stability.

## [1.0.0] - 2019-03-10
- Initial release for CHOW Tape Model research and plugin. Available
  in VST, VST3, AU, and Standalone formats. Mac tested has been limited.
