#include "OnOffManager.h"

namespace
{
    static const std::unordered_map<String, StringArray> triggerMap {
        { String ("ifilt_onoff"),   StringArray ({ "Low Cut", "High Cut", "Makeup" }) },
        { String ("hyst_onoff"),    StringArray ({ "Bias", "Saturation", "Drive" }) },
        { String ("tone_onoff"),    StringArray ({ "Bass", "Treble", "Transition Frequency" }) },
        { String ("loss_onoff"),    StringArray ({ "Gap", "Thickness", "Spacing", "Speed", "Speed_375", "Speed_75", "Speed_15", "Speed_30" }) },
        { String ("chew_onoff"),    StringArray ({ "Chew Depth", "Chew Frequency", "Chew Variance" }) },
        { String ("deg_onoff"),     StringArray ({ "Depth", "Amount", "Variance" }) },
        { String ("flutter_onoff"), StringArray ({ "Flutter Depth", "Flutter Rate", "Wow Depth", "Wow Rate" }) },
    };

    void toggleEnableDisable (Component* root, StringArray& compNames, bool shouldBeEnabled)
    {
        if (root == nullptr || compNames.isEmpty())
            return;

        for (auto child : root->getChildren())
        {
            auto compName = child->getName();
            if (compNames.contains (compName))
            {
                compNames.removeString (compName);
                child->setEnabled (shouldBeEnabled);
                continue;
            }

            toggleEnableDisable (child, compNames, shouldBeEnabled);
        }
    }
}

OnOffManager::OnOffManager (AudioProcessorValueTreeState& vts, const AudioProcessor* proc) :
    vts (vts),
    proc (proc)
{
    for (auto& trigger : triggerMap)
        vts.addParameterListener (trigger.first, this);
}

OnOffManager::~OnOffManager()
{
    for (auto& trigger : triggerMap)
        vts.removeParameterListener (trigger.first, this);
}

void OnOffManager::setOnOffForNewEditor (AudioProcessorEditor* editor)
{
    for (auto& trigger : triggerMap)
    {
        auto paramValue = vts.getRawParameterValue (trigger.first)->load();
        StringArray compNames (trigger.second);
        toggleEnableDisable (editor, compNames, (bool) paramValue);
    }
}

void OnOffManager::parameterChanged (const String &paramID, float newValue)
{
    if (triggerMap.find (paramID) == triggerMap.end()) // unknown trigger key
        return;

    StringArray compNames (triggerMap.at (paramID));
    toggleEnableDisable (proc->getActiveEditor(), compNames, (bool) newValue);
}
