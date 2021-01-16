#include "MixGroupsController.h"

using namespace MixGroupsConstants;

MixGroupsController::MixGroupsController (AudioProcessorValueTreeState& vts,
                                          AudioProcessor* proc) : vts (vts)
{
    // load parameters
    auto params = proc->getParameters();
    loadParameterList (params);

    // set up receiver
    sharedData->loadParameterList (paramList);
    sharedData->addListener (this);

    mixGroupParam = vts.getRawParameterValue (mixGroupParamID);
}

MixGroupsController::~MixGroupsController()
{
    sharedData->removeListener (this);
}

void MixGroupsController::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterChoice> (mixGroupParamID, "Mix Group", StringArray ({ "N/A", "1", "2", "3", "4" }), 0));
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
    if (parameterID == lastParameterChanged) // I just changed this param, don't want to get stuck in an endless loop...
    {
        lastParameterChanged = String();
        return;
    }

    int mixGroup = (int) mixGroupParam->load();

    if (parameterID == mixGroupParamID) // mix group was changed
    {
        sharedData->pluginGroupChanged (uuid.toString(), mixGroup);

        if (mixGroup == 0)
            return;

        int numPluginsInGroup = sharedData->getNumPluginsInGroup (mixGroup);
        if (numPluginsInGroup == 1) // I'm the only plugin in this group
        {
            sharedData->copyPluginState (mixGroup, vts);
        }
        else if (numPluginsInGroup > 1) // there are already plugins in this group
        {
            // copy shared state to me
            for (const auto& paramID : paramList)
            {
                auto param = vts.getParameter (paramID);
                auto value = sharedData->getParameter (paramID, mixGroup);

                lastParameterChanged = paramID;
                param->setValueNotifyingHost (param->convertTo0to1 (value));
            }
        }

        return;
    }

    if (mixGroup == 0) // no mix group, don't bother sending
        return;

    if (! paramList.contains (parameterID)) // parameter is not in list
        return;

    sharedData->setParameter (parameterID, mixGroup, newValue, uuid.toString());
}

void MixGroupsController::mixGroupParamChanged (const String& paramID, int mixGroup, float value, String otherUuid)
{
    if (uuid == otherUuid) // this message came from me!
        return;

    // load parameter
    auto param = vts.getParameter (paramID);
    if (param == nullptr) // invalid parameter
        return;

    if (mixGroup != (int) mixGroupParam->load()) // received message does not apply to this mix group
        return;

    // set parameter value
    lastParameterChanged = paramID;
    param->setValueNotifyingHost (param->convertTo0to1 (value));
}
