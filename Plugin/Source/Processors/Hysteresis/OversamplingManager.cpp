#include "OversamplingManager.h"

OversamplingManager::OversamplingManager (const AudioProcessorValueTreeState& vts, const AudioProcessor& p) : proc (p)
{
    osParam = vts.getRawParameterValue ("os");
    osModeParam = vts.getRawParameterValue ("os_mode");
    osOfflineParam = vts.getRawParameterValue ("os_render_factor");
    osOfflineModeParam = vts.getRawParameterValue ("os_render_mode");
    osOfflineSameParam = vts.getRawParameterValue ("os_render_like_realtime");

    for (int i = 0; i < numOSChoices; ++i)
    {
        overSample[i] = std::make_unique<dsp::Oversampling<double>> (2, i, dsp::Oversampling<double>::filterHalfBandPolyphaseIIR);
        overSample[i + numOSChoices] = std::make_unique<dsp::Oversampling<double>> (2, i, dsp::Oversampling<double>::filterHalfBandFIREquiripple);
    }
}

void OversamplingManager::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterChoice> ("os", "Oversampling", StringArray ({ "1x", "2x", "4x", "8x", "16x" }), 1));
    params.push_back (std::make_unique<AudioParameterChoice> ("os_mode", "Oversampling Mode", StringArray ({ "Min. Phase", "Linear Phase" }), 0));

    params.push_back (std::make_unique<AudioParameterChoice> ("os_render_factor", "Oversampling (render)", StringArray ({ "1x", "2x", "4x", "8x", "16x" }), 1));
    params.push_back (std::make_unique<AudioParameterChoice> ("os_render_mode", "Oversampling Mode (render)", StringArray ({ "Min. Phase", "Linear Phase" }), 0));
    params.push_back (std::make_unique<AudioParameterBool> ("os_render_like_realtime", "Oversampling (render like real-time)", true));
}

bool OversamplingManager::updateOSFactor()
{
    curOS = getOSIndex (*osParam, *osModeParam);
    if (proc.isNonRealtime() && *osOfflineSameParam == 0.0f)
    {
        curOS = getOSIndex (*osOfflineParam, *osOfflineModeParam);
    }
    if (curOS != prevOS)
    {
        overSamplingFactor = 1 << (curOS % numOSChoices);
        prevOS = curOS;
        return true;
    }

    return false;
}

void OversamplingManager::prepareToPlay (double sr, int samplesPerBlock)
{
    sampleRate = (float) sr;

    overSamplingFactor = 1 << curOS;

    for (int i = 0; i < numOSChoices; ++i)
    {
        overSample[i]->initProcessing ((size_t) samplesPerBlock);
        overSample[i + numOSChoices]->initProcessing ((size_t) samplesPerBlock);
    }
    prevOS = curOS;
}

void OversamplingManager::releaseResources()
{
    for (int i = 0; i < numOSChoices; ++i)
        overSample[i]->reset();
}
