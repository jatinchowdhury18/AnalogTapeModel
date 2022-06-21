#include "DegradeProcessor.h"

DegradeProcessor::DegradeProcessor (AudioProcessorValueTreeState& vts)
{
    using namespace chowdsp::ParamUtils;
    point1xParam = vts.getRawParameterValue ("deg_point1x");
    onOffParam = vts.getRawParameterValue ("deg_onoff");
    loadParameterPointer (depthParam, vts, "deg_depth");
    loadParameterPointer (amtParam, vts, "deg_amt");
    loadParameterPointer (varParam, vts, "deg_var");
    loadParameterPointer (envParam, vts, "deg_env");
}

void DegradeProcessor::createParameterLayout (chowdsp::Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    emplace_param<chowdsp::BoolParameter> (params, "deg_point1x", "Degrade Point1x", false);
    emplace_param<chowdsp::BoolParameter> (params, "deg_onoff", "Degrade On/Off", false);
    emplace_param<chowdsp::FloatParameter> (params, "deg_depth", "Degrade Depth", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "deg_amt", "Degrade Amount", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "deg_var", "Degrade Variance", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "deg_env", "Degrade Envelope", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
}

void DegradeProcessor::cookParams()
{
    auto point1x = static_cast<bool> (point1xParam->load());
    auto depthValue = point1x ? depthParam->getCurrentValue() * 0.1f : depthParam->getCurrentValue();

    float freqHz = 200.0f * powf (20000.0f / 200.0f, 1.0f - *amtParam);
    float gainDB = -24.0f * depthValue;

    for (auto& noise : noiseProc)
        noise.setGain (0.5f * depthValue * *amtParam);

    for (auto& filter : filterProc)
        filter.setFreq (jmin (freqHz + (*varParam * (freqHz / 0.6f) * (random.nextFloat() - 0.5f)), 0.49f * fs));

    auto envSkew = 1.0f - std::pow (envParam->getCurrentValue(), 0.8f);
    levelDetector.setParameters (10.0f, 20.0f * std::pow (5000.0f / 20.0f, envSkew));
    gainProc.setGain (Decibels::decibelsToGain (jmin (gainDB + (*varParam * 36.0f * (random.nextFloat() - 0.5f)), 3.0f)));
}

void DegradeProcessor::prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels)
{
    fs = (float) sampleRate;
    cookParams();

    noiseProc.resize ((size_t) numChannels);
    for (auto& noise : noiseProc)
        noise.prepare();

    filterProc.resize ((size_t) numChannels);
    for (auto& filter : filterProc)
        filter.reset ((float) sampleRate, 20);

    noiseBuffer.setSize (numChannels, samplesPerBlock);
    levelBuffer.setSize (1, samplesPerBlock);

    levelDetector.prepare ({ sampleRate, (uint32) samplesPerBlock, (uint32) numChannels });
    gainProc.prepareToPlay (sampleRate, samplesPerBlock);
    bypass.prepare (samplesPerBlock, numChannels, bypass.toBool (onOffParam));

    sampleCounter = 0;
}

void DegradeProcessor::processBlock (AudioBuffer<float>& buffer)
{
    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();
    for (int i = 0; i < numSamples;)
    {
        int samplesToProcess = jmin (smallBlockSize, numSamples - i);

        auto&& smallBuffer = AudioBuffer<float> { buffer.getArrayOfWritePointers(), numChannels, i, samplesToProcess };
        processShortBlock (smallBuffer);

        i += samplesToProcess;
    }
}

void DegradeProcessor::processShortBlock (AudioBuffer<float>& buffer)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOffParam)))
        return;

    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();

    sampleCounter += numSamples;
    if (sampleCounter >= smallBlockSize)
    {
        cookParams();
        sampleCounter = 0;
    }

    noiseBuffer.setSize (numChannels, numSamples, false, false, true);
    noiseBuffer.clear();

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> levelBlock (levelBuffer.getArrayOfWritePointers(), 1, numSamples);
    dsp::ProcessContextNonReplacing<float> levelContext (block, levelBlock);
    levelDetector.process (levelContext);
    const auto* levelPtr = levelBuffer.getReadPointer (0);

    const auto applyEnvelope = envParam->getCurrentValue() > 0.0f;
    for (int ch = 0; ch < numChannels; ++ch)
    {
        auto* noisePtr = noiseBuffer.getWritePointer (ch);
        noiseProc[(size_t) ch].processBlock (noisePtr, numSamples);

        if (applyEnvelope)
            FloatVectorOperations::multiply (noisePtr, levelPtr, numSamples);

        auto* xPtr = buffer.getWritePointer (ch);
        FloatVectorOperations::add (xPtr, noisePtr, numSamples);

        filterProc[(size_t) ch].process (xPtr, numSamples);
    }

    gainProc.processBlock (buffer);
    bypass.processBlockOut (buffer, bypass.toBool (onOffParam));
}
