#!/bin/bash

travis_run_before_install
travis_run_script

cd $TRAVIS_BUILD_DIR/Plugin/Bin/Mac
rm -Rf CHOWTapeModel.*

cp -Rf $TRAVIS_BUILD_DIR/Plugin/Builds/MacOSX/build/Release/CHOWTapeModel.app CHOWTapeModel.app
cp -Rf ~/Library/Audio/Plug-Ins/VST3/CHOWTapeModel.vst3 CHOWTapeModel.vst3
cp -Rf ~/Library/Audio/Plug-Ins/VST/CHOWTapeModel.vst CHOWTapeModel.vst
cp -Rf ~/Library/Audio/Plug-Ins/Components/CHOWTapeModel.component CHOWTapeModel.component

cd ../
zip -r MacBuilds.zip Mac
