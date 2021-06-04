#include "HysteresisProcessor.h"

enum
{
    numSteps = 500,
};

HysteresisProcessor::HysteresisProcessor (AudioProcessorValueTreeState& vts, const AudioProcessor& p) : osManager (vts, p)
{
    driveParam = vts.getRawParameterValue ("drive");
    satParam = vts.getRawParameterValue ("sat");
    widthParam = vts.getRawParameterValue ("width");
    modeParam = vts.getRawParameterValue ("mode");
    onOffParam = vts.getRawParameterValue ("hyst_onoff");

    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].reset (numSteps);
        width[ch].reset (numSteps);
        sat[ch].reset (numSteps);
        makeup[ch].reset (numSteps);
    }
}

void HysteresisProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterBool> ("hyst_onoff", "Tape On/Off", true));
    params.push_back (std::make_unique<AudioParameterFloat> ("drive", "Tape Drive", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("sat", "Tape Saturation", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("width", "Tape Bias", 0.0f, 1.0f, 0.5f));

    params.push_back (std::make_unique<AudioParameterChoice> ("mode", "Tape Mode", StringArray ({ "RK2", "RK4", "NR4", "NR8", "STN", "V1" }), 0));
    OversamplingManager::createParameterLayout (params);
}

void HysteresisProcessor::setSolver (int newSolver)
{
    if (newSolver == SolverType::NUM_SOLVERS) // V1
    {
        useV1 = true;
        newSolver = 1; // RK4
    }
    else
    {
        useV1 = false;
    }

    for (int ch = 0; ch < 2; ++ch)
        hProcs[ch].setSolver (static_cast<SolverType> (newSolver));

    // set clip level for solver
    switch (newSolver)
    {
        case 0: // RK2
        case 1: // RK4
            clipLevel = 10.0f;
            return;

        case 2: // NR4
        case 3: // NR8
            clipLevel = 12.5f;
            return;

        default:
            clipLevel = 20.0f;
    };
}

float HysteresisProcessor::calcMakeup()
{
    return (1.0f + 0.6f * width[0].getTargetValue()) / (0.5f + 1.5f * (1.0f - sat[0].getTargetValue()));
}

void HysteresisProcessor::setDrive (float newDrive)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].setTargetValue (newDrive);
    }
}

void HysteresisProcessor::setWidth (float newWidth)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        width[ch].setTargetValue (newWidth);
        makeup[ch].setTargetValue (calcMakeup());
    }
}

void HysteresisProcessor::setSaturation (float newSaturation)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        sat[ch].setTargetValue (newSaturation);
        makeup[ch].setTargetValue (calcMakeup());
    }
}

void HysteresisProcessor::setOversampling()
{
    if (osManager.updateOSFactor())
    {
        for (int ch = 0; ch < 2; ++ch)
        {
            hProcs[ch].setSampleRate (fs * osManager.getOSFactor());
            hProcs[ch].cook (drive[ch].getCurrentValue(), width[ch].getCurrentValue(), sat[ch].getCurrentValue(), wasV1);
            hProcs[ch].reset();
        }

        calcBiasFreq();
    }
}

void HysteresisProcessor::calcBiasFreq()
{
    biasFreq = fs * osManager.getOSFactor() / 2.0f;
}

void HysteresisProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;
    wasV1 = useV1;
    calcBiasFreq();

    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].skip (numSteps);
        width[ch].skip (numSteps);
        sat[ch].skip (numSteps);
        makeup[ch].skip (numSteps);

        hProcs[ch].setSampleRate (sampleRate * osManager.getOSFactor());
        hProcs[ch].cook (drive[ch].getCurrentValue(), width[ch].getCurrentValue(), sat[ch].getCurrentValue(), wasV1);
        hProcs[ch].reset();

        biasAngle[ch] = 0.0f;
    }

    osManager.prepareToPlay (sampleRate, samplesPerBlock);
    for (int ch = 0; ch < 2; ++ch)
        dcBlocker[ch].prepare (sampleRate, dcFreq);

    bypass.prepare (samplesPerBlock, bypass.toBool (onOffParam));
}

void HysteresisProcessor::releaseResources()
{
    osManager.releaseResources();
}

float HysteresisProcessor::getLatencySamples() const noexcept
{
    // latency of oversampling + fudge factor for hysteresis
    return onOffParam->load() == 1.0f ? osManager.getLatencySamples() + 1.4f // on
                                      : 0.0f; // off
}

void HysteresisProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midi*/)
{
    if (! bypass.processBlockIn (buffer, bypass.toBool (onOffParam)))
        return;

    setSolver ((int) *modeParam);
    setDrive (*driveParam);
    setSaturation (*satParam);
    setWidth (1.0f - *widthParam);
    setOversampling();

    bool needsSmoothing = drive[0].isSmoothing() || width[0].isSmoothing() || sat[0].isSmoothing() || wasV1 != useV1;

    if (useV1 != wasV1)
    {
        for (int ch = 0; ch < 2; ++ch)
            hProcs[ch].reset();
    }

    wasV1 = useV1;

    // clip input to avoid unstable hysteresis
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        FloatVectorOperations::clip (buffer.getWritePointer (ch),
                                     buffer.getWritePointer (ch),
                                     -clipLevel,
                                     clipLevel,
                                     buffer.getNumSamples());

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> osBlock = osManager.getOversampler()->processSamplesUp (block);

    if (needsSmoothing)
    {
        if (useV1)
            processSmoothV1 (osBlock);
        else
            processSmooth (osBlock);
    }
    else
    {
        if (useV1)
            processV1 (osBlock);
        else
            process (osBlock);
    }

    osManager.getOversampler()->processSamplesDown (block);

    applyDCBlockers (buffer);

    bypass.processBlockOut (buffer, bypass.toBool (onOffParam));
}

void HysteresisProcessor::process (dsp::AudioBlock<float>& block)
{
    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            x[samp] = (float) hProcs[channel].process ((double) x[samp]) * makeup[channel].getNextValue();
        }
    }
}

void HysteresisProcessor::processSmooth (dsp::AudioBlock<float>& block)
{
    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), false);

            x[samp] = (float) hProcs[channel].process ((double) x[samp]) * makeup[channel].getNextValue();
        }
    }
}

void HysteresisProcessor::processV1 (dsp::AudioBlock<float>& block)
{
    const auto angleDelta = MathConstants<float>::twoPi * biasFreq / (fs * osManager.getOSFactor());

    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            float bias = biasGain * (1.0f - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            biasAngle[channel] += angleDelta;
            biasAngle[channel] -= MathConstants<float>::twoPi * (biasAngle[channel] >= MathConstants<float>::twoPi);

            x[samp] = (float) hProcs[channel].process (10000.0 * (double) (x[samp] + bias));
        }

        FloatVectorOperations::multiply (x, 1.414f / 10000.0f, (int) block.getNumSamples());
    }
}

void HysteresisProcessor::processSmoothV1 (dsp::AudioBlock<float>& block)
{
    const auto angleDelta = MathConstants<float>::twoPi * biasFreq / (fs * osManager.getOSFactor());

    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), true);

            float bias = biasGain * (1.0f - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            biasAngle[channel] += angleDelta;
            biasAngle[channel] -= MathConstants<float>::twoPi * (biasAngle[channel] >= MathConstants<float>::twoPi);

            x[samp] = (float) hProcs[channel].process (10000.0 * (double) (x[samp] + bias));
        }

        FloatVectorOperations::multiply (x, 1.414f / 10000.0f, (int) block.getNumSamples());
    }
}

void HysteresisProcessor::applyDCBlockers (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        dcBlocker[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
}
