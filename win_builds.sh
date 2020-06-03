#!/bin/sh

export PATH="/c/Program Files (x86)/Microsoft Visual Studio/2017/Community/MSBuild/15.0/Bin/":$PATH

echo "Building 64-bit..."
cd Plugin/Builds/VisualStudio2017/
MSBuild.exe -v:quiet -t:rebuild -p:Configuration=Release -p:Platform=x64 CHOWTapeModel.sln

echo "Building 32-bit..."
MSBuild.exe -v:quiet -t:rebuild -p:Configuration=Release32 -p:Platform=Win32 CHOWTapeModel.sln

echo "Copying Files..."
cd ../../
cp Builds/VisualStudio2017/x64/Release/VST/CHOWTapeModel.dll Bin/Win64/
cp Builds/VisualStudio2017/x64/Release/VST3/CHOWTapeModel.vst3 Bin/Win64/
cp Builds/VisualStudio2017/x64/Release/Standalone\ Plugin/CHOWTapeModel.exe Bin/Win64/

cp Builds/VisualStudio2017/Win32/Release32/VST/CHOWTapeModel.dll Bin/Win32/
cp Builds/VisualStudio2017/Win32/Release32/VST3/CHOWTapeModel.vst3 Bin/Win32/
cp Builds/VisualStudio2017/Win32/Release32/Standalone\ Plugin/CHOWTapeModel.exe Bin/Win32/
