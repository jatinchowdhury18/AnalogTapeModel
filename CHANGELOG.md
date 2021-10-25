# Changelog
All notable changes to this project will be documented in
this file.

## UNRELEASED
- Fixed linear phase oversampling affecting frequency response in STN mode.

## [2.9.0] - 2021-09-09
- Added tape compression processor.
- Improved hysteresis engine performance by ~1.5x.
- Improved oversampling menu with choices for linear vs. minimum phase and real-time vs. offline rendering.
- Made oversampling choices preset-agnostic.
- Further improved performance for Hysteresis "STN" mode.

## [2.8.0] - 2021-04-20
- Added support for iOS (AUv3) and Apple Silicon.
- Added Azimuth parameter for playhead loss controls.
- Added Variance and Drift parameters for Wow control.
- Fixed stability issue in tone filters.
- Fixed glitches when adjusting loss parameters at large buffer sizes.
- Improved performance for Hysteresis "STN" mode.
- Added sync options for Wow/Flutter rate.
- Added Envelope parameter for Degrade section.
- Added 0.1x control for Degrade "Depth" parameter.
- Improved parameter names for automation menus.
- Added arrows for preset menu.
- Added support for OSX versions 10.9 and up.
- Fixed an audio blowup when toggling the Input Filter makeup.
- Fixed GUI freezing bug in Cakewalk.
- Fixed gain staging bug in Renoise.
- Migrated build pipeline to CMake.
- Created installer packages for Windows/Mac.

## [2.7.0] - 2020-11-25
- Added new hysteresis mode: State Transition Network (STN)
- Updated Loss Filters to improve frequency response and phase response.
- Added high/low-cut filters for the input section.
- Updated presets menu: now supports saving presets, and managing user preset folder.
- Tone section: added transition frequency control, and made bass/treble controls more extreme.
- Added bypass switches for plugin sections.
- Fixed loss filter issues at higher sample rates.
- Added visualizations for Wow and Flutter.
- Added buttons to snap tape speed to conventional values.
- Added coloured circle on bottom bar to visualize mix group.
- Added a new official user manual.

## [2.6.0] - 2020-09-29
- Added Pre/post emphasis filters for the hysteresis stage.
- Added "mix groups" to allow instances of the plugin to be synced across a mix.
- Added Chew variance parameter to control the randomness of the chew dropouts.
- Improved behavior for thickness slider.
- Improved internal clipping characteristic (to preserve stability).
- Improved DC blocker for hysteresis processor.

## [2.5.0] - 2020-08-23
- Updated delay lines in wow/flutter processing to use 3-point
  Lagrange interpolation.
- Change Newton-Raphson solver to use 4 or 8 iterations, in unrolled loop.
- Adjust signal flow so that input/output gains apply only to the wet signal.
- Added simple behavior to automatically check for updates.
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
