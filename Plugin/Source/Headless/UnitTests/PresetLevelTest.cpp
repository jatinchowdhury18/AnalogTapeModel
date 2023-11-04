#include "PluginProcessor.h"

class PresetLevelTest : public UnitTest
{
public:
    PresetLevelTest() : UnitTest ("PresetLevelTest")
    {
    }

    void runTest() override
    {
        beginTest ("Preset Level Test");

        std::unique_ptr<ChowtapeModelAudioProcessor> proc {
            dynamic_cast<ChowtapeModelAudioProcessor*> (createPluginFilterOfType (
                AudioProcessor::WrapperType::wrapperType_Standalone))
        };

        static constexpr double sampleRate = 48000.0;
        static constexpr int blockSize = 512;
        const auto numChannels = proc->getMainBusNumInputChannels();

        auto rand = getRandom();

        juce::AudioBuffer<float> buffer { numChannels, blockSize };
        juce::MidiBuffer midi;

        for (int programIdx = 0; programIdx < proc->getNumPrograms(); ++programIdx)
        {
            proc->setCurrentProgram (programIdx);
            logMessage ("Loading preset: " + proc->getProgramName (programIdx));
            proc->prepareToPlay (sampleRate, blockSize);

            float maxMagnitudeDB = 0.0f;
            for (int i = 0; i < 10; ++i)
            {
                for (int ch = 0; ch < numChannels; ++ch)
                {
                    for (int n = 0; n < blockSize; ++n)
                        buffer.setSample (ch, n, rand.nextFloat() * 2.0f - 1.0f);
                }

                proc->processBlock (buffer, midi);

                const auto magnitudeDB = chowdsp::BufferMath::getMagnitude (buffer);
                expectGreaterThan (magnitudeDB, -60.0f);
                expectLessOrEqual (magnitudeDB, 3.5f);

                maxMagnitudeDB = juce::jmax (magnitudeDB, maxMagnitudeDB);
            }
            expectGreaterThan (maxMagnitudeDB, -3.0f);

            proc->releaseResources();
        }
    }
};

static PresetLevelTest presetLevelTest;

// Sink / Chorus4
// Carter / Bass - 808 Maker
// Carter / Guitar - Short Plucked
// COolWAV / Drift with me
