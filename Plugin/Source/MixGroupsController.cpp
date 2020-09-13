#include "MixGroupsController.h"

MixGroupsController::MixGroupsController (AudioProcessorValueTreeState& vts,
                                          AudioProcessor* proc) :
    vts (vts)
{
    // connect sender
    if (! sender.connect ("127.0.0.1", 1818))
    {
        jassertfalse;
    }

    // connect receiver
    if (! connect (1818))
    {
        jassertfalse;
    }

    auto params = proc->getParameters();
    for (auto* param : params)
    {
        auto paramWithID = dynamic_cast<AudioProcessorParameterWithID*> (param);

        if (paramWithID == nullptr)
            continue;

        auto paramID = paramWithID->paramID;
        paramIDs.addIfNotAlreadyThere (paramID);
        vts.addParameterListener (paramID, this);

        addListener (this, "/chowdsp/tape/" + paramID);
    }
}

MixGroupsController::~MixGroupsController()
{
    while (! paramIDs.isEmpty())
        vts.removeParameterListener (paramIDs.removeAndReturn (0), this);
}

void MixGroupsController::parameterChanged (const String& parameterID, float newValue)
{
    if (! paramIDs.contains (parameterID))
        return;

    sendingString = parameterID;
    sender.send ("/chowdsp/tape/" + parameterID, newValue);
}

void MixGroupsController::oscMessageReceived (const OSCMessage& message)
{
    if (message.size() == 1 && message[0].isFloat32())
    {
        auto address = message.getAddressPattern().toString();
        auto paramID = address.fromFirstOccurrenceOf ("/chowdsp/tape/", false, false);

        if (paramID == sendingString)
        {
            sendingString = "";
            return;
        }

        auto value = message[0].getFloat32();

        vts.getParameter (paramID)->setValueNotifyingHost (value);
    }
}
