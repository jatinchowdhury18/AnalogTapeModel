X_display=":98"

mkdir -p JuceLibraryCode
cp -f AppConfig.h.in JuceLibraryCode/
# mkdir Juce
# ln -s /usr/share/juce/modules Juce/modules
sed -i -e 's/JUCEOPTIONS/JUCEOPTIONS JUCE_JACK="1"/'  CHOWTapeModel.jucer

lv2uri="https://github.com/jatinchowdhury18/AnalogTapeModel"
sed "s/_lv2uri_pattern_/${lv2uri//\//\\/}/g" JuceLibraryCode/AppConfig.h.in >JuceLibraryCode/AppConfig.h
sed "s/_juce_target_/CHOWTapeModel/g" LV2.mak.in >LV2.mak

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

cd Builds/LinuxMakefile
CONFIG=Release make
