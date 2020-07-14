mkdir -p JuceLibraryCode
cp -f linux_utils/AppConfig.h.in JuceLibraryCode/

lv2uri="https://github.com/jatinchowdhury18/AnalogTapeModel"
sed "s/_lv2uri_pattern_/${lv2uri//\//\\/}/g" JuceLibraryCode/AppConfig.h.in >JuceLibraryCode/AppConfig.h
sed "s/_juce_target_/CHOWTapeModel/g" linux_utils/LV2.mak.in >LV2.mak

# build Projucer
(
    cd Juce/extras/Projucer/Builds/LinuxMakefile
    make
)

PJ=./Juce/extras/Projucer/Builds/LinuxMakefile/build/Projucer

$PJ --set-global-search-path linux defaultJuceModulePath Juce/modules
$PJ --set-global-search-path linux vstLegacyPath Juce/VST2_SDK
$PJ --resave CHOWTapeModel.jucer
echo "include ../../LV2.mak" >> Builds/LinuxMakefile/Makefile

(
    cd Builds/LinuxMakefile
    CONFIG=Release make
)

rm LV2.mak
