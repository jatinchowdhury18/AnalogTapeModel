#include "PluginProcessor.h"

class MultiChannelTest : public UnitTest
{
    using Proc = ChowtapeModelAudioProcessor;

public:
    MultiChannelTest() : UnitTest ("MultiChannelTest") {}

    using Layout = AudioProcessor::BusesLayout;
    Layout getLayout (AudioChannelSet channelSet)
    {
        Layout layout;
        layout.inputBuses.add (channelSet);
        layout.outputBuses.add (channelSet);
        return layout;
    }

    std::unique_ptr<Proc> createPlugin()
    {
        auto proc = createPluginFilterOfType (AudioProcessor::WrapperType::wrapperType_Standalone);
        std::unique_ptr<Proc> plugin (dynamic_cast<Proc*> (proc));
        return std::move (plugin);
    }

    void multiChannelTest (const Layout& layout)
    {
        auto&& plugin = createPlugin();
        const auto ableToSetBusesLayout = plugin->setBusesLayout (layout);
        expect (ableToSetBusesLayout, "Unable to set buses layout: " + layout.getMainInputChannelSet().getDescription());

        const auto& params = plugin->getParameters();
        for (auto* param : params)
        {
            if (auto* rangedParam = dynamic_cast<RangedAudioParameter*> (param))
            {
                if (rangedParam->getParameterID().contains ("onoff"))
                {
                    std::cout << "Turning on parameter: " << rangedParam->getName (1024) << std::endl;
                    rangedParam->setValueNotifyingHost (1.0f);
                }
            }
        }

        MessageManager::getInstance()->runDispatchLoopUntil (250);

        constexpr double sampleRate = 48000.0;
        constexpr int blockSize = 512;
        const auto numChannels = layout.getMainInputChannels();
        std::cout << "Running plugin processing with channel count: " << numChannels << std::endl;

        AudioBuffer<float> buffer (numChannels, blockSize);
        MidiBuffer midi;

        plugin->prepareToPlay (sampleRate, blockSize);
        plugin->processBlock (buffer, midi);
    }

    void runTest() override
    {
        beginTest ("Mono Test");
        multiChannelTest (getLayout (AudioChannelSet::mono()));

        beginTest ("Stereo Test");
        multiChannelTest (getLayout (AudioChannelSet::stereo()));

        beginTest ("Quad Test");
        multiChannelTest (getLayout (AudioChannelSet::quadraphonic()));

        beginTest ("5.0 Test");
        multiChannelTest (getLayout (AudioChannelSet::create5point0()));

        beginTest ("5.1 Test");
        multiChannelTest (getLayout (AudioChannelSet::create5point1()));

        beginTest ("7.0 Test");
        multiChannelTest (getLayout (AudioChannelSet::create7point0()));

        beginTest ("7.1 Test");
        multiChannelTest (getLayout (AudioChannelSet::create7point1()));
    }
};

MultiChannelTest multiChannelTest;
