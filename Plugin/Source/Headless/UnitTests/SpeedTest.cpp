#include "PluginProcessor.h"

class SpeedTest : public UnitTest
{
public:
    SpeedTest() : UnitTest ("SpeedTest")
    {
    }

    void createNoiseBuffer (AudioBuffer<float>& buffer)
    {
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        {
            auto* x = buffer.getWritePointer (ch);
            for (int n = 0; n < buffer.getNumSamples(); ++n)
                x[n] = getRandom().nextFloat() * 2.0f - 1.0f;
        }
    }

    void runTest() override
    {
        beginTest ("Speed Test");
        std::unique_ptr<AudioProcessor> plugin (createPluginFilterOfType (AudioProcessor::WrapperType::wrapperType_Standalone));

        AudioBuffer<float> buffer (plugin->getMainBusNumInputChannels(), 512);
        createNoiseBuffer (buffer);
        MidiBuffer mb;

        constexpr int numIters = 500;
        plugin->prepareToPlay (48000.0, 512);

        Time time;
        auto start = time.getMillisecondCounterHiRes();
        for (int i = 0; i < numIters; ++i)
            plugin->processBlock (buffer, mb);
        auto end = time.getMillisecondCounterHiRes();

        plugin->releaseResources();

        auto duration = (end - start) / 1000.0f;
        logMessage ("Plugin processing time: " + String (duration) + " seconds");
        
      #if JUCE_WINDOWS
        expectLessThan (duration, 1.0, "Plugin is not fast enough!");
      #else
        expectLessThan (duration, 5.0, "Plugin is not fast enough!");
      #endif
    }
};

static SpeedTest speedTest;
