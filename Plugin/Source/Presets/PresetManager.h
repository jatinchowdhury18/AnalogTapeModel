#ifndef PRESETMANAGER_H_INCLUDED
#define PRESETMANAGER_H_INCLUDED

#include "JuceHeader.h"

struct Preset
{
    Preset (String presetFile);

    String name;
    ValueTree state;
    int index;
};

//====================================================
class PresetManager
{
public:
    PresetManager();

    StringArray getPresetChoices();
    void loadPresets();
    
    int getNumPresets() const { return presets.size(); }
    String getPresetName (int idx);
    void setPreset (AudioProcessorValueTreeState& vts, int idx);

    void registerPresetsComponent (foleys::MagicGUIBuilder&, AudioProcessor* proc);
    void presetUpdated() { listeners.call (&Listener::presetUpdated); }

    struct Listener
    {
        virtual ~Listener() {}
        virtual void presetUpdated() {}
    };

    void addListener (Listener* l) { listeners.add (l); }
    void removeListener (Listener* l) { listeners.remove (l); }

private:
    HashMap<int, Preset*> presetMap;
    OwnedArray<Preset> presets;
    int maxIdx = 0;

    ListenerList<Listener> listeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetManager)
};

#endif // PRESETMANAGER_H_INCLUDED
