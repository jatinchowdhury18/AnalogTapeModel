#include "MixGroupsParamReceiver.h"
#include "MixGroupsController.h"

MixGroupsParamReceiver::MixGroupsParamReceiver()
{
    // connect datagram socket
    socket.bindToPort (MixGroupsConstants::portNum);
    socket.setEnablePortReuse (true);
    connectToSocket (socket);
}

void MixGroupsParamReceiver::loadReceiverListeners (Array<String>& paramList)
{
    if (listenersInitialized) // listeners are already set up!
        return;

    for (auto& paramID : paramList)
        addListener (this, MixGroupsConstants::oscAddressPrefix + paramID);

    addListener (this, MixGroupsConstants::oscAddressPrefix + "all");

    listenersInitialized = true;
}

void MixGroupsParamReceiver::oscMessageReceived (const OSCMessage& message)
{
    // clear existing OSC message
    oscMessage.clear();

    if (message.isEmpty()) // no message!
        return;

    if (! MixGroupsController::isValidOSCMessage (message))
        return;

    oscMessage = message;
    sendChangeMessage();
}
