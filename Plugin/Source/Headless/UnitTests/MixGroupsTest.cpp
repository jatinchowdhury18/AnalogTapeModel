#include "MixGroups/MixGroupsController.h"
#include "PluginProcessor.h"

class MixGroupsTest : public UnitTest
{
    using Proc = ChowtapeModelAudioProcessor;

public:
    MixGroupsTest() : UnitTest ("MixGroupsTest")
    {
    }

    void setMixGroup (Proc* plugin, float value)
    {
        for (auto* p : plugin->getParameters())
        {
            if (auto* pCast = dynamic_cast<RangedAudioParameter*> (p))
            {
                if (pCast->paramID == MixGroupsConstants::mixGroupParamID)
                    pCast->setValueNotifyingHost (value);
            }
        }
    }

    std::unique_ptr<Proc> createPlugin()
    {
        auto proc = createPluginFilterOfType (AudioProcessor::WrapperType::wrapperType_Standalone);
        std::unique_ptr<Proc> plugin (dynamic_cast<Proc*> (proc));
        return std::move (plugin);
    }

    void compareStates (Proc* plugin1, Proc* plugin2)
    {
        for (int i = 0; i < plugin1->getParameters().size(); ++i)
        {
            auto* param1 = dynamic_cast<RangedAudioParameter*> (plugin1->getParameters()[i]);
            auto* param2 = dynamic_cast<RangedAudioParameter*> (plugin2->getParameters()[i]);

            if (! param1 || ! param2)
                continue;

            if (auto* paramBool1 = dynamic_cast<AudioParameterBool*> (param1))
            {
                auto* paramBool2 = dynamic_cast<AudioParameterBool*> (param2);

                auto bool1 = paramBool1->get();
                auto bool2 = paramBool2->get();

                expect (bool1 == bool2, "Boolean Parameter " + param1->name + " is not linked correctly!");
            }
            else
            {
                expectWithinAbsoluteError (param1->getValue(), param2->getValue(), 0.001f, "Parameter " + param1->name + " is not linked correctly!");
            }
        }
    }

    void copyStateTest()
    {
        auto plugin1 = createPlugin();
        auto plugin2 = createPlugin();

        plugin1->setCurrentProgram (4);
        setMixGroup (plugin1.get(), 1.0f);
        setMixGroup (plugin2.get(), 1.0f);

        compareStates (plugin1.get(), plugin2.get());
    }

    void parameterLinkTest()
    {
        auto plugin1 = createPlugin();
        auto plugin2 = createPlugin();

        setMixGroup (plugin1.get(), 1.0f);
        setMixGroup (plugin2.get(), 1.0f);

        auto params1 = plugin1->getParameters();
        auto params2 = plugin2->getParameters();

        constexpr int numRuns = 100;
        for (int i = 0; i < numRuns; ++i)
        {
            auto paramIdxToChange = getRandom().nextInt (params1.size());
            params1[paramIdxToChange]->setValueNotifyingHost (getRandom().nextFloat());
            compareStates (plugin1.get(), plugin2.get());
        }
    }

    void runTest() override
    {
        beginTest ("Copy State Test");
        copyStateTest();

        beginTest ("Parameter Link Test");
        parameterLinkTest();
    }
};

static MixGroupsTest mixGroupsTest;
