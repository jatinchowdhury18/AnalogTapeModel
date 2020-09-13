#ifndef MIXGROUPSCONTROLLER_H_INCLUDED
#define MIXGROUPSCONTROLLER_H_INCLUDED

#include "MixGroupsParamReceiver.h"

namespace MixGroupsConstants
{
    constexpr int portNum = 1818;
    const String oscAddressPrefix = "/chowdsp/tape/";
    const String allParamsAddress = oscAddressPrefix + "all";
    const String mixGroupParamID = "mix_group";
}

/** Class to control syncing parameters between multiple mix groups */
class MixGroupsController : private AudioProcessorValueTreeState::Listener,
                            private ChangeListener
{
public:
    MixGroupsController (AudioProcessorValueTreeState& vts, AudioProcessor* proc);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void parameterChanged (const String& parameterID, float newValue) override;
    void changeListenerCallback (ChangeBroadcaster* source) override;
    void sendParameter (const String& paramID, int mixGroup, float value);

    void parseAllParams (const OSCMessage& message);

    static bool isValidOSCMessage (const OSCMessage& message);

private:
    void loadParameterList (Array<AudioProcessorParameter*>& params);

    AudioProcessorValueTreeState& vts;
    std::atomic<float>* mixGroupParam = nullptr;
    Array<String> paramList;
    OSCSender sender;
    Uuid uuid;

    SharedResourcePointer<MixGroupsParamReceiver> paramReceiver;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupsController)
};

#endif // MIXGROUPSCONTROLLER_H_INCLUDED
