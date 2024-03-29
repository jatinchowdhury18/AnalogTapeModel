#include "OnOffManager.h"
#include <unordered_map>

namespace
{
std::unordered_map<String, StringArray> createTriggerMap()
{
    return {
        { String ("ifilt_onoff"), StringArray ({ "Low Cut", "High Cut", "Makeup" }) },
        { String ("hyst_onoff"), StringArray ({ "Bias", "Saturation", "Drive" }) },
        { String ("tone_onoff"), StringArray ({ "Bass", "Treble", "Transition Frequency" }) },
        { String ("loss_onoff"), StringArray ({ "Gap", "Thickness", "Spacing", "Azimuth", "Speed", "3.75 ips", "7.5 ips", "15 ips", "30 ips" }) },
        { String ("chew_onoff"), StringArray ({ "Chew Depth", "Chew Frequency", "Chew Variance" }) },
        { String ("deg_onoff"), StringArray ({ "Depth", "Amount", "Variance", "Envelope", "0.1x" }) },
        { String ("flutter_onoff"), StringArray ({ "Flutter Depth", "Flutter Rate", "Wow Depth", "Wow Rate", "Wow Variance", "Wow Drift" }) },
        { String ("comp_onoff"), StringArray ({ "Compression Amount", "Compression Attack", "Compression Release" }) },
    };
}

void toggleEnableDisable (Component* root, StringArray& compNames, bool shouldBeEnabled)
{
    if (root == nullptr)
        return;

    if (compNames.isEmpty())
        return;

    for (auto child : root->getChildren())
    {
        auto compName = child->getName();
        if (compNames.contains (compName))
        {
            MessageManagerLock mml;
            compNames.removeString (compName);
            child->setEnabled (shouldBeEnabled);
            continue;
        }

        toggleEnableDisable (child, compNames, shouldBeEnabled);
    }
}
} // namespace

OnOffManager::OnOffManager (AudioProcessorValueTreeState& vts, const AudioProcessor* proc) : vts (vts),
                                                                                             proc (proc),
                                                                                             triggerMap (createTriggerMap())
{
    for (const auto& trigger : triggerMap)
        vts.addParameterListener (trigger.first, this);
}

OnOffManager::~OnOffManager()
{
    for (auto& trigger : triggerMap)
        vts.removeParameterListener (trigger.first, this);
}

void OnOffManager::setOnOffForNewEditor (AudioProcessorEditor* editor)
{
    for (const auto& trigger : triggerMap)
    {
        auto paramValue = vts.getRawParameterValue (trigger.first)->load();
        StringArray compNames { trigger.second };
        toggleEnableDisable (editor, compNames, (bool) paramValue);
    }
}

void OnOffManager::parameterChanged (const String& paramID, float newValue)
{
    if (const auto triggerMapIter = triggerMap.find (paramID); triggerMapIter != triggerMap.end())
    {
        componentsToToggle = &triggerMapIter->second;
        turningOn = (bool) newValue;

        if (MessageManager::existsAndIsCurrentThread())
            onOffButtonToggled();
        else
            triggerAsyncUpdate();
    }
}

void OnOffManager::handleAsyncUpdate()
{
    onOffButtonToggled();
}

void OnOffManager::onOffButtonToggled()
{
    if (componentsToToggle == nullptr)
        return;

    auto compNames = StringArray { *componentsToToggle };
    toggleEnableDisable (proc->getActiveEditor(), compNames, turningOn);
    componentsToToggle = nullptr;
}
