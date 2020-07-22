#include "HysteresisProcessor.h"

enum
{
    numSteps = 500,
};

HysteresisProcessor::HysteresisProcessor (AudioProcessorValueTreeState& vts)
{
    driveParam = vts.getRawParameterValue ("drive");
    satParam = vts.getRawParameterValue ("sat");
    widthParam = vts.getRawParameterValue ("width");
    osParam = vts.getRawParameterValue ("os");
    modeParam = vts.getRawParameterValue ("mode");

    for (int i = 0; i < 5; ++i)
        overSample[i] = std::make_unique<dsp::Oversampling<float>>
            (2, i, dsp::Oversampling<float>::filterHalfBandPolyphaseIIR);

    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].reset  (numSteps);
        width[ch].reset  (numSteps);
        sat[ch].reset    (numSteps);
        makeup[ch].reset (numSteps);
    }
}

void HysteresisProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("drive", "Drive", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("sat", "Saturation", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("width", "Bias", 0.0f, 1.0f, 0.5f));

    params.push_back (std::make_unique<AudioParameterChoice> ("mode", "Mode", StringArray ({"RK2", "RK4", "NR5", "NR10", "V1"}), 0));
    params.push_back (std::make_unique<AudioParameterChoice> ("os", "Oversampling", StringArray ({"1x", "2x", "4x", "8x", "16x"}), 1));
}

void HysteresisProcessor::setSolver (int newSolver)
{
    if (newSolver == 4) // V1
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
    if ((int) *osParam != prevOS)
    {
        overSamplingFactor = (int) powf(2.0f, *osParam);
        prevOS = (int) *osParam;

        for (int ch = 0; ch < 2; ++ch)
        {
            hProcs[ch].setSampleRate (fs * overSamplingFactor);
            hProcs[ch].cook (drive[ch].getCurrentValue(), width[ch].getCurrentValue(), sat[ch].getCurrentValue(), wasV1);
            hProcs[ch].reset();
        }

        calcBiasFreq();
    }
}

void HysteresisProcessor::calcBiasFreq()
{
    biasFreq = fs * overSamplingFactor / 2.0f;
}

void HysteresisProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;
    overSamplingFactor = (int) powf(2.0f, *osParam);
    wasV1 = useV1;
    calcBiasFreq();

    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].skip (numSteps);
        width[ch].skip (numSteps);
        sat[ch].skip (numSteps);
        makeup[ch].skip (numSteps);

        hProcs[ch].setSampleRate (sampleRate * overSamplingFactor);
        hProcs[ch].cook (drive[ch].getCurrentValue(), width[ch].getCurrentValue(), sat[ch].getCurrentValue(), wasV1);
        hProcs[ch].reset();

        biasAngle[ch] = 0.0f;
    }

    for (int i = 0; i < 5; ++i)
        overSample[i]->initProcessing (samplesPerBlock);
    prevOS = (int) *osParam;

    dcBlocker[0].reset (sampleRate);
    dcBlocker[0].calcCoefs (dcFreq, 0.707f);
    dcBlocker[1].reset (sampleRate);
    dcBlocker[1].calcCoefs (dcFreq, 0.707f);
     
    // dcLower[0].reset (sampleRate);
    // dcLower[0].calcCoefs (dcShelfFreq, 0.707f, Decibels::decibelsToGain (-12.0f));
    // dcLower[1].reset (sampleRate);
    // dcLower[1].calcCoefs (dcShelfFreq, 0.707f, Decibels::decibelsToGain (-12.0f));
}

void HysteresisProcessor::releaseResources()
{
    for (int i = 0; i < 5; ++i)
        overSample[i]->reset();
}

float HysteresisProcessor::getLatencySamples() const noexcept
{
    // latency of oversampling + fudge factor for Runge-Kutta and hysteresis
    return overSample[(int) *osParam]->getLatencyInSamples() + 1.65f;
}

void HysteresisProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midi*/)
{
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

    // clip input to +9 dB
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        FloatVectorOperations::clip (buffer.getWritePointer (ch),
            buffer.getWritePointer (ch), -8.0f, 8.0f, buffer.getNumSamples());

    dsp::AudioBlock<float> block (buffer);
    dsp::AudioBlock<float> osBlock = overSample[(int) *osParam]->processSamplesUp (block);

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

    overSample[(int) *osParam]->processSamplesDown (block);

    applyDCBlockers (buffer);
}

void HysteresisProcessor::process (dsp::AudioBlock<float>& block)
{
    for (int channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (int samp = 0; samp < block.getNumSamples(); samp++)
        {
            x[samp] = (float) hProcs[channel].process ((double) x[samp]) * makeup[channel].getNextValue();
        }
    }
}

void HysteresisProcessor::processSmooth (dsp::AudioBlock<float>& block)
{
    for (int channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (int samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), false);

            x[samp] = (float) hProcs[channel].process ((double) x[samp]) * makeup[channel].getNextValue();
        }
    }
}

void HysteresisProcessor::processV1 (dsp::AudioBlock<float>& block)
{
    const auto angleDelta = MathConstants<float>::twoPi * biasFreq / (fs * overSamplingFactor);

    for (int channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (int samp = 0; samp < block.getNumSamples(); samp++)
        {
            float bias = biasGain * (1.0f - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            x[samp] = (float) hProcs[channel].process (5000.0 * (double) (x[samp] + bias));
            biasAngle[channel] += angleDelta;

            if (biasAngle[channel] >= MathConstants<float>::twoPi)
                biasAngle[channel] -= MathConstants<float>::twoPi;
        }

        FloatVectorOperations::multiply (x, 1.0f / 10000.0f, (int) block.getNumSamples());
    }
}

void HysteresisProcessor::processSmoothV1 (dsp::AudioBlock<float>& block)
{
    const auto angleDelta = MathConstants<float>::twoPi * biasFreq / (fs * overSamplingFactor);

    for (int channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (int samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), true);

            float bias = biasGain * (1.0f - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            x[samp] = (float) hProcs[channel].process (5000.0 * (double) (x[samp] + bias));
            biasAngle[channel] += angleDelta;

            if (biasAngle[channel] >= MathConstants<float>::twoPi)
                biasAngle[channel] -= MathConstants<float>::twoPi;
        }

        FloatVectorOperations::multiply (x, 1.0f / 10000.0f, (int) block.getNumSamples());
    }
}

void HysteresisProcessor::applyDCBlockers (AudioBuffer<float>& buffer)
{
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* x = buffer.getWritePointer (channel);
        for (int samp = 0; samp < buffer.getNumSamples(); samp++)
        {
            x[samp] = dcBlocker[channel].processSample (x[samp]);
            // x[samp] = dcLower[channel].processSample (x[samp]);
        }
    }
}
