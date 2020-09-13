#ifndef MIXGROUPSCONTROLLER_H_INCLUDED
#define MIXGROUPSCONTROLLER_H_INCLUDED

#include <JuceHeader.h>

class MixGroupsController : private AudioProcessorValueTreeState::Listener,
                            private OSCReceiver,
                            private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
    MixGroupsController (AudioProcessorValueTreeState& vts,
                         AudioProcessor* proc);
    ~MixGroupsController();

    void parameterChanged (const String& parameterID, float newValue) override;
    void oscMessageReceived (const OSCMessage& message) override;

private:
    AudioProcessorValueTreeState& vts;
    Array<String> paramIDs;
    OSCSender sender;

    String sendingString = ""; // store last sent param, so we can ignore when it comes back

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupsController)
};

#endif // MIXGROUPSCONTROLLER_H_INCLUDED
