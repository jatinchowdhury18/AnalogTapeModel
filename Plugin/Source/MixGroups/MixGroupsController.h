#ifndef MIXGROUPSCONTROLLER_H_INCLUDED
#define MIXGROUPSCONTROLLER_H_INCLUDED

#include "MixGroupsSharedData.h"

namespace MixGroupsConstants
{
    constexpr int numMixGroups = 4;
    const String mixGroupParamID = "mix_group";    
}

/** Class to control syncing parameters between multiple mix groups */
class MixGroupsController : private AudioProcessorValueTreeState::Listener,
                            private MixGroupsSharedData::Listener
{
public:
    MixGroupsController (AudioProcessorValueTreeState& vts, AudioProcessor* proc);
    ~MixGroupsController();

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void parameterChanged (const String& parameterID, float newValue) override;
    void mixGroupParamChanged (const String& paramID, int mixGroup, float value, String otherUuid) override;

private:
    void loadParameterList (Array<AudioProcessorParameter*>& params);

    AudioProcessorValueTreeState& vts;
    std::atomic<float>* mixGroupParam = nullptr;
    Array<String> paramList;
    Uuid uuid;

    String lastParameterChanged = "";

    SharedResourcePointer<MixGroupsSharedData> sharedData;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupsController)
};

#endif // MIXGROUPSCONTROLLER_H_INCLUDED
