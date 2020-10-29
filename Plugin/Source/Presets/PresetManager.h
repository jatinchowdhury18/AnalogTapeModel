#ifndef PRESETMANAGER_H_INCLUDED
#define PRESETMANAGER_H_INCLUDED

#include "JuceHeader.h"

struct Preset
{
    Preset (String presetFile);
    Preset (const File& presetFile);
    void initialise (const ValueTree& parentTree);

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
    bool setPreset (AudioProcessorValueTreeState& vts, int idx);

    void registerPresetsComponent (foleys::MagicGUIBuilder&);
    void presetUpdated() { listeners.call (&Listener::presetUpdated); }

    void loadUserPreset (const File& file);
    void saveUserPreset (const String& name, const AudioProcessorValueTreeState& vts);

    struct Listener
    {
        virtual ~Listener() {}
        virtual void presetUpdated() {}
    };

    void addListener (Listener* l) { listeners.add (l); }
    void removeListener (Listener* l) { listeners.remove (l); }

private:
    File getUserPresetFile();
    void resaveUserPresetFile (const StringArray& presetPaths);

    HashMap<int, Preset*> presetMap;
    OwnedArray<Preset> presets;
    int maxIdx = 0;

    ListenerList<Listener> listeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetManager)
};

#endif // PRESETMANAGER_H_INCLUDED
