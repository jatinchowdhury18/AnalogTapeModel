#ifndef ONOFFMANAGER_H_INCLUDED
#define ONOFFMANAGER_H_INCLUDED

#include <JuceHeader.h>

/** Utility class to enable/disable components triggered by audio parameter changes */
class OnOffManager : private AudioProcessorValueTreeState::Listener
{
public:
    OnOffManager (AudioProcessorValueTreeState& vts, const AudioProcessor* proc);
    ~OnOffManager();

    void parameterChanged (const String &parameterID, float newValue) override;

private:
    AudioProcessorValueTreeState& vts;
    const AudioProcessor* proc;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OnOffManager)
};

#endif // ONOFFMANAGER_H_INCLUDED
