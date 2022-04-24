#ifndef PRESETMANAGER_H_INCLUDED
#define PRESETMANAGER_H_INCLUDED

#include "JuceHeader.h"

class PresetManager : public chowdsp::PresetManager
{
public:
    PresetManager (AudioProcessorValueTreeState& vts);

    chowdsp::Preset loadUserPresetFromFile (const File& file) override;
    void loadPresetState (const XmlElement* xml) override;

private:
    void loadFactoryPresets();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetManager)
};

#endif // PRESETMANAGER_H_INCLUDED
