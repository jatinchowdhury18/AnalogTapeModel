#include "DegradeProcessor.h"

DegradeProcessor::DegradeProcessor (AudioProcessorValueTreeState& vts)
{
    point1xParam = vts.getRawParameterValue ("deg_point1x");
    onOffParam = vts.getRawParameterValue ("deg_onoff");
    depthParam = vts.getRawParameterValue ("deg_depth");
    amtParam = vts.getRawParameterValue ("deg_amt");
    varParam = vts.getRawParameterValue ("deg_var");
    envParam = vts.getRawParameterValue ("deg_env");
}

void DegradeProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterBool> ("deg_point1x", "Degrade Point1x", false));
    params.push_back (std::make_unique<AudioParameterBool> ("deg_onoff", "Degrade On/Off", false));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_depth", "Degrade Depth", 0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_amt", "Degrade Amount", 0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_var", "Degrade Variance", 0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("deg_env", "Degrade Envelope", 0.0f, 1.0f, 0.0f));
}

void DegradeProcessor::cookParams()
{
    auto point1x = static_cast<bool> (point1xParam->load());
    auto depthValue = point1x ? depthParam->load() * 0.1f : depthParam->load();

    float freqHz = 200.0f * powf (20000.0f / 200.0f, 1.0f - *amtParam);
    float gainDB = -24.0f * depthValue;

    for (int ch = 0; ch < 2; ++ch)
    {
        noiseProc[ch].setGain (0.5f * depthValue * *amtParam);
        filterProc[ch].setFreq (jmin (freqHz + (*varParam * (freqHz / 0.6f) * (random.nextFloat() - 0.5f)), 0.49f * fs));
    }

    auto envSkew = 1.0f - std::pow (envParam->load(), 0.8f);
    levelDetector.setParameters (10.0f, 20.0f * std::pow (5000.0f / 20.0f, envSkew));
    gainProc.setGain (Decibels::decibelsToGain (jmin (gainDB + (*varParam * 36.0f * (random.nextFloat() - 0.5f)), 3.0f)));
}

void DegradeProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;
    cookParams();

    for (int ch = 0; ch < 2; ++ch)
    {
        noiseProc[ch].prepare();
        filterProc[ch].reset ((float) sampleRate, 20);
    }

    noiseBuffer.setSize (2, samplesPerBlock);
    levelBuffer.setSize (1, samplesPerBlock);

    levelDetector.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
    gainProc.prepareToPlay (sampleRate, samplesPerBlock);
    bypass.prepare (samplesPerBlock, 2, bypass.toBool (onOffParam)); // @multi-channel
}

void DegradeProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOffParam)))
        return;

    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();

    cookParams();
    noiseBuffer.clear();

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> levelBlock (levelBuffer.getArrayOfWritePointers(), 1, numSamples);
    dsp::ProcessContextNonReplacing<float> levelContext (block, levelBlock);
    levelDetector.process (levelContext);
    auto* levelPtr = levelBuffer.getReadPointer (0);

    for (int ch = 0; ch < numChannels; ++ch)
    {
        auto* noisePtr = noiseBuffer.getWritePointer (ch);
        noiseProc[ch].processBlock (noisePtr, numSamples);

        if (envParam->load() > 0.0f)
            FloatVectorOperations::multiply (noisePtr, levelPtr, numSamples);

        auto* xPtr = buffer.getWritePointer (ch);
        FloatVectorOperations::add (xPtr, noisePtr, numSamples);

        filterProc[ch].process (xPtr, numSamples);
    }

    gainProc.processBlock (buffer, midi);
    bypass.processBlockOut (buffer, bypass.toBool (onOffParam));
}
