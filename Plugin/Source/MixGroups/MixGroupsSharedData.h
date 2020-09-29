#ifndef MIXGROUPSPARAMRECEIVER
#define MIXGROUPSPARAMRECEIVER

#include <JuceHeader.h>

class MixGroupsSharedData
{
public:
    MixGroupsSharedData();

    /** Create parameter maps from list of parameters */
    void loadParameterList (Array<String>& paramList);

    /** A plugin has changed mix group. */
    void pluginGroupChanged (const String& pluginID, int mixGroup);

    /** Get the number of plugins already in this mix group */
    int getNumPluginsInGroup (int mixGroup) const;

    /** Copy the plugin state into the parameter map for a given mix group */
    void copyPluginState (int mixGroup, AudioProcessorValueTreeState& vts);

    void setParameter (const String& paramID, int mixGroup, float value, String uuid);
    float getParameter (const String& paramID, int mixGroup) const;

    struct Listener
    {
        ~Listener() {}
        virtual void mixGroupParamChanged (const String& /*paramID*/, int /*mixGroup*/, float /*value*/, String /*uuid*/) {}
    };

    void addListener (Listener* l) { listeners.add (l); }
    void removeListener (Listener* l) { listeners.remove (l); }

private:
    using ParamMap = HashMap<String, float>;
    std::vector<std::unique_ptr<ParamMap>> paramMaps;

    OwnedArray<StringArray> pluginsInGroup; // list of plugin IDs of all the plugins in each mix group

    ListenerList<Listener> listeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixGroupsSharedData)
};

#endif // MIXGROUPSPARAMRECEIVER
