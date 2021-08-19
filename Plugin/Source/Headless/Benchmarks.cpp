#include "Benchmarks.h"
#include "../PluginProcessor.h"

namespace
{
constexpr double pluginSampleRate = 44100.0;
constexpr int samplesPerBlock = 256;
constexpr int nChs = 2;
} // namespace

Benchmarks::Benchmarks()
{
    this->commandOption = "--bench";
    this->argumentDescription = "--bench --file=FILE --mode=MODE";
    this->shortDescription = "Runs benchmarks for ChowTapeModel";
    this->longDescription = "";
    this->command = std::bind (&Benchmarks::runBenchmarks, this, std::placeholders::_1);
}

void getAudioFile (AudioBuffer<float>& buffer, const File& file)
{
    AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    std::unique_ptr<InputStream> inputStream = file.createInputStream();
    if (inputStream == nullptr)
        return;

    std::unique_ptr<AudioFormatReader> reader (formatManager.createReaderFor (std::move (inputStream)));
    if (reader == nullptr)
        return;

    buffer.setSize ((int) reader->numChannels, (int) reader->lengthInSamples);
    reader->read (buffer.getArrayOfWritePointers(), buffer.getNumChannels(), 0, buffer.getNumSamples());
}

void setParameters (AudioProcessor* plugin, int mode)
{
    auto params = plugin->getParameters();
    for (auto param : params)
    {
        if (param->getName (1024) == "Oversampling")
        {
            param->setValueNotifyingHost (3.0f / 4.0f); // 8x
            std::cout << "Setting parameter " << param->getName (1024)
                      << ": " << param->getText (param->getValue(), 1024) << std::endl;
        }

        if (param->getName (1024) == "Tape Mode")
        {
            param->setValueNotifyingHost ((float) mode / 5.0f);
            std::cout << "Setting parameter " << param->getName (1024)
                      << ": " << param->getText (param->getValue(), 1024) << std::endl;
        }
    }
}

double timeAudioProcess (AudioProcessor* plugin, AudioBuffer<float>& audio, const int blockSize)
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

        AudioBuffer<float> curBuff (audio.getArrayOfWritePointers(), nChs, samplePtr, curBlockSize);
        plugin->processBlock (curBuff, midi);

        samplePtr += curBlockSize;
    }

    return (time.getMillisecondCounterHiRes() - start) / 1000.0;
}

void Benchmarks::runBenchmarks (const ArgumentList& args)
{
    ignoreUnused (args);

    std::cout << "Loading plugin..." << std::endl;
    auto plugin = std::make_unique<ChowtapeModelAudioProcessor>();

    File audioFile;
    if (args.containsOption ("--file"))
    {
        audioFile = args.getExistingFileForOption ("--file");
    }
    else
    {
        auto rootFolder = File::getSpecialLocation (File::currentExecutableFile);
        while (rootFolder.getFileName() != "AnalogTapeModel")
            rootFolder = rootFolder.getParentDirectory();

        audioFile = rootFolder.getChildFile ("Testing/Canada_Dry.wav");
    }

    std::cout << "Loading audio file: " << audioFile.getFullPathName() << std::endl;
    AudioBuffer<float> audio;
    getAudioFile (audio, audioFile);
    const double audioLength = audio.getNumSamples() / pluginSampleRate; // seconds

    if (audioLength == 0.0)
    {
        std::cout << "No audio found in file!" << std::endl;
        return;
    }

    std::cout << "Setting parameters..." << std::endl;
    int mode = 4; // STN
    if (args.containsOption ("--mode"))
        mode = args.getValueForOption ("--mode").getIntValue();
    setParameters (plugin.get(), mode);

    std::cout << "Processing audio..." << std::endl;
    plugin->prepareToPlay (pluginSampleRate, samplesPerBlock);
    auto time = timeAudioProcess (plugin.get(), audio, samplesPerBlock);
    plugin->releaseResources();

    std::cout << "Results:" << std::endl;
    std::cout << audioLength / time << "x real-time" << std::endl;
    std::cout << time << " seconds" << std::endl;
}
