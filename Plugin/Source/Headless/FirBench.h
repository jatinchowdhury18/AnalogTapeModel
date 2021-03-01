#include "../Processors/Loss_Effects/FIRFilter.h"

namespace
{
constexpr double pluginSampleRate = 48000.0;
constexpr int samplesPerBlock = 256;
}

class FirBench : public ConsoleApplication::Command
{
public:
    FirBench()
    {
        this->commandOption = "--fir-bench";
        this->argumentDescription = "--fir-bench --size=FILTER_SIZE --length=AUDIO_LENGTH";
        this->shortDescription = "Runs benchmarks for ChowTapeModel FIR Filters";
        this->longDescription = "";
        this->command = std::bind (&FirBench::runBench, this, std::placeholders::_1);
    }

    void runBench (const ArgumentList& args)
    {
        int firSize = 128;
        if (args.containsOption ("--size"))
            firSize = args.getValueForOption ("--size").getIntValue();

        std::cout << "Creating FIR filter with size " << firSize << std::endl;
        FIRFilter filter { firSize };
        setFilterCoefs (filter, (size_t) firSize);

        float audioLength = 30.0f;
        if (args.containsOption ("--length"))
            audioLength = args.getValueForOption ("--length").getFloatValue();

        std::cout << "Creating audio buffer of length " << audioLength << " seconds" << std::endl;
        const int numSamples = int (audioLength * pluginSampleRate);
        auto buffer = createAudio (numSamples);

        std::cout << "Processing audio..." << std::endl;
        filter.reset();
        auto time = timeAudioProcess (filter, buffer, samplesPerBlock);

        std::cout << "Results:" << std::endl;
        std::cout << audioLength / time << "x real-time" << std::endl;
        std::cout << time << " seconds" << std::endl;
    }

private:
    void setFilterCoefs (FIRFilter& filter, const size_t size)
    {
        std::vector<float> coefs (size);
        Random r;
        for (size_t i = 0; i < size; ++i)
            coefs[i] = r.nextFloat() * 2.0f + 1.0f;

        filter.setCoefs (coefs.data());
    }

    AudioBuffer<float> createAudio (const int numSamples)
    {
        AudioBuffer<float> buffer (1, numSamples);
        Random r;
        for (int i = 0; i < numSamples; ++i)
            buffer.setSample (0, i, r.nextFloat() * 2.0f + 1.0f);

        return buffer;
    }

    double timeAudioProcess (FIRFilter& filter, AudioBuffer<float>& audio, const int blockSize)
    {
        auto totalNumSamples = audio.getNumSamples();
        int samplePtr = 0;

        Time time;
        auto start = time.getMillisecondCounterHiRes();
        while (totalNumSamples > 0)
        {
            auto curBlockSize = jmin (totalNumSamples, blockSize);
            totalNumSamples -= curBlockSize;

            filter.process (audio.getWritePointer (0) + samplePtr, curBlockSize);
            samplePtr += curBlockSize;
        }

        return (time.getMillisecondCounterHiRes() - start) / 1000.0;
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirBench)
};
