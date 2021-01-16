#include "MixGroupsSharedData.h"
#include "MixGroupsController.h"

MixGroupsSharedData::MixGroupsSharedData()
{
    for (int i = 0; i < MixGroupsConstants::numMixGroups; ++i)
        pluginsInGroup.add (std::make_unique<StringArray>());
}

void MixGroupsSharedData::loadParameterList (Array<String>& paramList)
{
    if (! paramMaps.empty()) // already loaded
        return;

    for (int i = 0; i < MixGroupsConstants::numMixGroups; ++i)
    {
        auto paramMap = std::make_unique<ParamMap>();

        for (const auto& paramID : paramList)
            paramMap->set (paramID, 0.0f);

        paramMaps.push_back (std::move (paramMap));
    }
}

void MixGroupsSharedData::pluginGroupChanged (const String& pluginID, int mixGroup)
{
    // remove plugin from any group it's currently in
    for (auto& group : pluginsInGroup)
        group->removeString (pluginID);

    if (mixGroup == 0)
        return;

    // add plugin to new group
    pluginsInGroup[mixGroup - 1]->addIfNotAlreadyThere (pluginID);
}

int MixGroupsSharedData::getNumPluginsInGroup (int mixGroup) const
{
    return pluginsInGroup[mixGroup - 1]->size();
}

void MixGroupsSharedData::copyPluginState (int mixGroup, AudioProcessorValueTreeState& vts)
{
    auto paramMap = paramMaps[mixGroup - 1].get();
    auto mapIter = paramMap->begin();
    while (mapIter.next())
    {
        const auto param = vts.getRawParameterValue (mapIter.getKey());
        paramMap->set (mapIter.getKey(), param->load());
    }
}

void MixGroupsSharedData::setParameter (const String& paramID, int mixGroup, float value, String uuid)
{
    paramMaps[mixGroup - 1]->set (paramID, value);
    listeners.call (&Listener::mixGroupParamChanged, paramID, mixGroup, value, uuid);
}

float MixGroupsSharedData::getParameter (const String& paramID, int mixGroup) const
{
    return paramMaps[mixGroup - 1]->operator[] (paramID);
}
