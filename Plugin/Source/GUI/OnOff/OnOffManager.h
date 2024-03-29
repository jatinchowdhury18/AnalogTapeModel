#ifndef ONOFFMANAGER_H_INCLUDED
#define ONOFFMANAGER_H_INCLUDED

#include <JuceHeader.h>

/** Utility class to enable/disable components triggered by audio parameter changes */
class OnOffManager : private AudioProcessorValueTreeState::Listener,
                     private AsyncUpdater
{
public:
    OnOffManager (AudioProcessorValueTreeState& vts, const AudioProcessor* proc);
    ~OnOffManager() override;

    void setOnOffForNewEditor (AudioProcessorEditor* editor);
    void parameterChanged (const String& parameterID, float newValue) override;

private:
    void handleAsyncUpdate() override;
    void onOffButtonToggled();

    AudioProcessorValueTreeState& vts;
    const AudioProcessor* proc;

    const std::unordered_map<String, StringArray> triggerMap;
    const StringArray* componentsToToggle = nullptr;
    bool turningOn = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OnOffManager)
};

#endif // ONOFFMANAGER_H_INCLUDED
