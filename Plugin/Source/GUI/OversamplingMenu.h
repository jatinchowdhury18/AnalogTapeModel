#pragma once

#include <JuceHeader.h>

using OversamplerType = chowdsp::VariableOversampling<double>;
using BaseOSMenuType = chowdsp::OversamplingMenu<OversamplerType>;

class OversamplingMenu : public BaseOSMenuType,
                         private AudioProcessorValueTreeState::Listener
{
public:
    OversamplingMenu (OversamplerType& osManager, AudioProcessorValueTreeState& vtState);
    ~OversamplingMenu() override;

    void parameterChanged (const String&, float) override;
    void generateComboBoxMenu() override;

private:
    AudioProcessorValueTreeState& vts;
    const AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OversamplingMenu)
};
