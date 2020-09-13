#include "MixGroupsController.h"

using namespace MixGroupsConstants;

MixGroupsController::MixGroupsController (AudioProcessorValueTreeState& vts,
                                          AudioProcessor* proc) :
    vts (vts)
{
    // connect sender
    sender.connect ("127.0.0.1", portNum);

    // load parameters
    auto params = proc->getParameters();
    loadParameterList (params);

    // set up receiver
    paramReceiver->loadReceiverListeners (paramList);
    paramReceiver->addChangeListener (this);

    mixGroupParam = vts.getRawParameterValue (mixGroupParamID);
}

void MixGroupsController::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterChoice> (mixGroupParamID, "Mix Group", StringArray ({"N/A", "1", "2", "3", "4"}), 0));
}

void MixGroupsController::loadParameterList (Array<AudioProcessorParameter*>& params)
{
    // iterate over parameters
    for (auto* param : params)
    {
        auto paramWithID = dynamic_cast<AudioProcessorParameterWithID*> (param);

        if (paramWithID == nullptr)
            continue;

        auto paramID = paramWithID->paramID;
        vts.addParameterListener (paramID, this);

        if (paramID != mixGroupParamID)
            paramList.addIfNotAlreadyThere (paramID);
    }
}

void MixGroupsController::parameterChanged (const String& parameterID, float newValue)
{
    int mixGroup = (int) mixGroupParam->load();
    if (mixGroup == 0) // no mix group, don't bother sending
        return;

    if (parameterID == mixGroupParamID) // mix group was changed
    {
        OSCMessage message (allParamsAddress);
        message.addArgument (uuid.toString());
        message.addArgument (mixGroup);

        for (const auto& paramID : paramList)
        {
            auto param = vts.getParameter (paramID);
            auto value = param->convertFrom0to1 (param->getValue());
            
            message.addArgument (paramID);
            message.addArgument (value);
        }

        sender.send (message);

        return;
    }

    if (! paramList.contains (parameterID)) // parameter is not in list
        return;

    sendParameter (parameterID, mixGroup, newValue);
}

void MixGroupsController::sendParameter (const String& paramID, int mixGroup, float value)
{
    String address = oscAddressPrefix + paramID;
    String pluginID = uuid.toString();

    sender.send (address, pluginID, mixGroup, value);
}

void MixGroupsController::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source != paramReceiver)
        return;

    // get message from receiver, we already know this will be a valid message!
    auto& message = paramReceiver->getOSCMessage();

    // get address
    auto address = message.getAddressPattern().toString();

    // special case: all parameters
    if (address == allParamsAddress)
    {
        parseAllParams (message);
        return;
    }

    // get paramID from address
    auto paramID = address.fromFirstOccurrenceOf (oscAddressPrefix, false, false);
    auto param = vts.getParameter (paramID);

    if (param == nullptr) // invalid parameter
        return;

    String pluginID = message[0].getString();
    if (uuid == pluginID) // this message came from me!
        return;

    int mixGroup = message[1].getInt32();
    if (mixGroup != (int) mixGroupParam->load()) // received message does not apply to this mix group
        return;

    auto value = message[2].getFloat32();
    param->setValueNotifyingHost (param->convertTo0to1 (value));
}

void MixGroupsController::parseAllParams (const OSCMessage& message)
{
    if (message.size() % 2 != 0) // must have even number of arguments!
        return;

    String pluginID = message[0].getString();
    if (uuid == pluginID) // this message came from me!
        return;

    int mixGroup = message[1].getInt32();
    if (mixGroup != (int) mixGroupParam->load()) // received message does not apply to this mix group
        return;

    for (int argIdx = 2; argIdx < message.size(); argIdx += 2)
    {
        auto temp1 = message[argIdx];
        auto temp2 = message[argIdx+1];
        if (! (message[argIdx].isString() && message[argIdx + 1].isFloat32())) // incorrect format...
            continue;

        String paramID = message[argIdx].getString();
        auto param = vts.getParameter (paramID);

        if (param == nullptr) // invalid parameter
            continue;

        auto value = message[argIdx + 1].getFloat32();
        param->setValueNotifyingHost (param->convertTo0to1 (value));
    }
}

bool MixGroupsController::isValidOSCMessage (const OSCMessage& message)
{
    // special case: all parameters
    if (message.getAddressPattern() == allParamsAddress && message.size() > 2)
        return true;

    // other valid messages will be of the form: string, int, float
    if (message.size() != 3)
        return false;

    bool isValid = true;

    isValid &= message[0].isString();
    isValid &= message[1].isInt32();
    isValid &= message[2].isFloat32();

    return isValid;
}
