#include "OversamplingMenu.h"

namespace
{
const StringArray latencyChangeParameters { "loss_onoff", "hyst_onoff", "comp_onoff" };
}

OversamplingMenu::OversamplingMenu (OversamplerType& osManager,
                                    AudioProcessorValueTreeState& vtState) : BaseOSMenuType (osManager, vtState),
                                                                             vts (vtState),
                                                                             processor (vts.processor)
{
    generateComboBoxMenu();

    for (const auto& tag : latencyChangeParameters)
        vts.addParameterListener (tag, this);
}

OversamplingMenu::~OversamplingMenu()
{
    for (const auto& tag : latencyChangeParameters)
        vts.removeParameterListener (tag, this);
}

void OversamplingMenu::parameterChanged (const String&, float)
{
    generateComboBoxMenu();
}

void OversamplingMenu::generateComboBoxMenu()
{
    // update menu after parameter change has propagated
    Timer::callAfterDelay (
        50,
        [this, safeComp = Component::SafePointer<OversamplingMenu> (this)] {
            if (safeComp != nullptr)
            {
                BaseOSMenuType::generateComboBoxMenu();

                auto* menu = getRootMenu();
                if (! menu->containsAnyActiveItems())
                    return;

                auto totalLatencyMs = ((double) processor.getLatencySamples() / processor.getSampleRate()) * 1000.0;
                totalLatencyMs = totalLatencyMs < 0.025 ? 0.0 : totalLatencyMs;
                menu->addSectionHeader ("Total Latency: " + juce::String (totalLatencyMs, 3) + " ms");
            }
        });
}
