#include "OversamplingManager.h"

OversamplingManager::OversamplingManager (const AudioProcessorValueTreeState& vts)
{
    osParam = vts.getRawParameterValue ("os_factor");

    for (int i = 0; i < 5; ++i)
        overSample[i] = std::make_unique<dsp::Oversampling<float>> (2, i, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR);
}

void OversamplingManager::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterChoice> ("os_factor", "Oversampling", StringArray ({ "1x", "2x", "4x", "8x", "16x" }), 1));
}

bool OversamplingManager::updateOSFactor()
{
    curOS = (int) *osParam;
    if (curOS != prevOS)
    {
        overSamplingFactor = 1 << curOS;
        prevOS = curOS;
        return true;
    }

    return false;
}

void OversamplingManager::prepareToPlay (double /*sampleRate*/, int samplesPerBlock)
{
    overSamplingFactor = 1 << curOS;

    for (int i = 0; i < 5; ++i)
        overSample[i]->initProcessing ((size_t) samplesPerBlock);
    prevOS = curOS;
}

void OversamplingManager::releaseResources()
{
    for (int i = 0; i < 5; ++i)
        overSample[i]->reset();
}
