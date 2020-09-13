#ifndef MIXGROUPSPARAMRECEIVER
#define MIXGROUPSPARAMRECEIVER

#include <JuceHeader.h>

/** 
 * Class to receive parameter info from other instances of the plugin.
 * Create instances of this class with a SharedResourcePointer, otherwise
 * the messages won't sync correctly between instances of the plugin.
 */
class MixGroupsParamReceiver : public ChangeBroadcaster,
                               private OSCReceiver,
                               private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
    MixGroupsParamReceiver();

    void oscMessageReceived (const OSCMessage& message) override;
    void loadReceiverListeners (Array<String>& paramList);
    const OSCMessage& getOSCMessage() { return oscMessage; }

private:
    DatagramSocket socket;
    OSCMessage      oscMessage { "/noaddress" };
    bool            listenersInitialized = false;
};

#endif // MIXGROUPSPARAMRECEIVER

