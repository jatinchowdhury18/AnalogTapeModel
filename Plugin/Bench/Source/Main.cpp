#include <JuceHeader.h>
#include <iostream>

namespace 
{
    constexpr double pluginSampleRate = 44100.0;
    constexpr int samplesPerBlock = 256;
    constexpr int numChannels = 2;
}

using namespace juce;

File getRootFolder();
void getAudioFile(AudioBuffer<float>& buffer);
File getPluginFile();
std::unique_ptr<AudioPluginInstance> getPlugin (String file);
void createRandomAudioInput (AudioBuffer<float>& buffer, double lengthSeconds);
double timeAudioProcess (AudioPluginInstance* plugin, AudioBuffer<float>& audio, const int blockSize);

int main (int argc, char* argv[])
{
    ignoreUnused (argc, argv);

    ScopedJuceInitialiser_GUI scopedJuce;

    std::cout << "Loading plugin..." << std::endl;
    auto pluginFile = getPluginFile();
    auto plugin = getPlugin (pluginFile.getFullPathName());

    if (plugin == nullptr)
        return 1;

    std::cout << "Loading audio file..." << std::endl;
    AudioBuffer<float> audio;
    getAudioFile (audio);
    const double audioLength = audio.getNumSamples() / pluginSampleRate; // seconds
    // std::cout << "Audio file is " << audioLength << " seconds" << std::endl;

    std::cout << "Setting parameters..." << std::endl;
    auto params = plugin->getParameters();
    for (auto param : params)
    {
        if (param->getName (10) == "Oversampling")
            param->setValue (3.0f / 4.0f); // 8x

        if (param->getName (10) == "Mode")
            param->setValue (3.0f / 5.0f); // NR4
    }

    // process audio
    std::cout << "Processing audio..." << std::endl;
    plugin->prepareToPlay (pluginSampleRate, samplesPerBlock);
    auto time = timeAudioProcess (plugin.get(), audio, samplesPerBlock);
    plugin->releaseResources();

    // print results
    std::cout << "Results:" << std::endl;
    std::cout << audioLength / time << "x real-time" << std::endl;
    std::cout << time << std::endl;

    return 0;
}

std::unique_ptr<AudioPluginInstance> getPlugin (String file)
{
    AudioPluginFormatManager pluginManager;
    pluginManager.addDefaultFormats();

    OwnedArray<PluginDescription> plugins;
    KnownPluginList pluginList;

    // attempt to load plugin from file
    File pluginFile;
    if (! File::isAbsolutePath (String(file)))
        pluginFile = File (File::getCurrentWorkingDirectory().getFullPathName() + "/" + file);
    else
        pluginFile = File (file);
    pluginList.scanAndAddDragAndDroppedFiles (pluginManager, StringArray (pluginFile.getFullPathName()), plugins);

    if (plugins.isEmpty()) // check if loaded
    {
        std::cout << "Error: unable to load plugin" << std::endl;
        return {};
    }

    // create plugin instance
    String error ("Unable to load plugin");
    auto plugin = pluginManager.createPluginInstance (*plugins.getFirst(), 44100.0, 256, error);

    return std::move (plugin);
}

void createRandomAudioInput (AudioBuffer<float>& buffer, double lengthSeconds)
{
    const int numSamples = int (lengthSeconds * pluginSampleRate);
    buffer.setSize (numChannels, numSamples);

    Random rand;
    for (int ch = 0; ch < numChannels; ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        for (int n = 0; n < numSamples; ++n)
        {
            x[n] = rand.nextFloat() * 2.0f - 1.0f;
        }
    }
}

double timeAudioProcess (AudioPluginInstance* plugin, AudioBuffer<float>& audio, const int blockSize)
{
    Time time;

    auto totalNumSamples = audio.getNumSamples();
    int samplePtr = 0;
    MidiBuffer midi;

    auto start = time.getMillisecondCounterHiRes();
    while (totalNumSamples > 0)
    {
        auto curBlockSize = jmin (totalNumSamples, blockSize);
        totalNumSamples -= curBlockSize;

        AudioBuffer<float> curBuff (audio.getArrayOfWritePointers(), numChannels, samplePtr, curBlockSize);
        plugin->processBlock (curBuff, midi);

        samplePtr += curBlockSize;
    }

    return (time.getMillisecondCounterHiRes() - start) / 1000.0;
}

File getPluginFile()
{
    File rootFolder = getRootFolder();

#ifdef JUCE_WINDOWS
    File pluginFile = rootFolder.getChildFile ("Builds/VisualStudio2017/x64/Release/VST3/CHOWTapeModel.vst3");
#endif

#ifdef JUCE_MAC
    File pluginFile = rootFolder.getChildFile ("Builds/MacOSX/build/Release/CHOWTapeModel.vst3");
#endif

#ifdef JUCE_LINUX
    File pluginFile = rootFolder.getChildFile ("Builds/LinuxMakefile/build/CHOWTapeModel.vst3");
#endif

    // std::cout << "Plugin File: " << pluginFile.getFullPathName() << std::endl;

    jassert (pluginFile.exists());

    return pluginFile;
}

File getRootFolder()
{
    File appFile = File::getSpecialLocation (File::currentApplicationFile);

#ifdef JUCE_WINDOWS
    int numParentsToRoot = 7;
#endif

#ifdef JUCE_MAC
    int numParentsToRoot = 6;
#endif

#ifdef JUCE_LINUX
    int numParentsToRoot = 5;
#endif

    File rootFolder = File (appFile);
    for (int i = 0; i < numParentsToRoot; ++i)
        rootFolder = File (rootFolder.getParentDirectory());

    // std::cout << "Root Folder: " << rootFolder.getFullPathName() << std::endl;

    return rootFolder;
}

void getAudioFile(AudioBuffer<float>& buffer)
{
    File rootFolder = getRootFolder();
    File audioFile = rootFolder.getParentDirectory().getChildFile ("Testing/Canada_Dry.wav");

    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    std::unique_ptr<InputStream> inputStream = audioFile.createInputStream();
    std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor (std::move (inputStream)));

    buffer.setSize (reader->numChannels, (int) reader->lengthInSamples);
    reader->read (buffer.getArrayOfWritePointers(), buffer.getNumChannels(), 0, buffer.getNumSamples());    
}
