#include "HysteresisProcessor.h"

namespace
{
enum
{
    numSteps = 500,
};

constexpr double v1Norm = 1.414 / 10000.0;

template <typename T>
static void interleaveSamples (const T** source, T* dest, int numSamples, int numChannels)
{
    for (int chan = 0; chan < numChannels; ++chan)
    {
        auto i = chan;
        const auto* src = source[chan];

        for (int j = 0; j < numSamples; ++j)
        {
            dest[i] = src[j];
            i += numChannels;
        }
    }
}

template <typename T>
static void deinterleaveSamples (const T* source, T** dest, int numSamples, int numChannels)
{
    for (int chan = 0; chan < numChannels; ++chan)
    {
        auto i = chan;
        auto* dst = dest[chan];

        for (int j = 0; j < numSamples; ++j)
        {
            dst[j] = source[i];
            i += numChannels;
        }
    }
}
} // namespace

HysteresisProcessor::HysteresisProcessor (AudioProcessorValueTreeState& vts) : osManager (vts)
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
    }

    makeup.reset (numSteps);
}

void HysteresisProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterBool> ("hyst_onoff", "Tape On/Off", true));
    params.push_back (std::make_unique<AudioParameterFloat> ("drive", "Tape Drive", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("sat", "Tape Saturation", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("width", "Tape Bias", 0.0f, 1.0f, 0.5f));

    params.push_back (std::make_unique<AudioParameterChoice> ("mode", "Tape Mode", StringArray ({ "RK2", "RK4", "NR4", "NR8", "STN", "V1" }), 0));

    using OSManager = decltype (osManager);
    OSManager::createParameterLayout (params, OSManager::OSFactor::TwoX, OSManager::OSMode::MinPhase);
}

void HysteresisProcessor::setSolver (int newSolver)
{
    if (newSolver == SolverType::NUM_SOLVERS) // V1
        useV1 = true;
    else
        useV1 = false;

    solver = useV1 ? RK4 : static_cast<SolverType> (newSolver);

    // set clip level for solver
    switch (solver)
    {
        case RK2:
        case RK4:
            clipLevel = 10.0;
            return;

        case NR4:
        case NR8:
            clipLevel = 12.5;
            return;

        default:
            clipLevel = 20.0;
    };
}

double HysteresisProcessor::calcMakeup()
{
    return (1.0 + 0.6 * width[0].getTargetValue()) / (0.5 + 1.5 * (1.0 - sat[0].getTargetValue()));
}

void HysteresisProcessor::setDrive (float newDrive)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].setTargetValue ((double) newDrive);
    }
}

void HysteresisProcessor::setWidth (float newWidth)
{
    for (int ch = 0; ch < 2; ++ch)
        width[ch].setTargetValue ((double) newWidth);
}

void HysteresisProcessor::setSaturation (float newSaturation)
{
    for (int ch = 0; ch < 2; ++ch)
        sat[ch].setTargetValue ((double) newSaturation);
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
    biasFreq = fs * osManager.getOSFactor() / 2.0;
}

void HysteresisProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = sampleRate;
    wasV1 = useV1;
    calcBiasFreq();

    for (int ch = 0; ch < 2; ++ch)
    {
        drive[ch].skip (numSteps);
        width[ch].skip (numSteps);
        sat[ch].skip (numSteps);

        hProcs[ch].setSampleRate (sampleRate * osManager.getOSFactor());
        hProcs[ch].cook (drive[ch].getCurrentValue(), width[ch].getCurrentValue(), sat[ch].getCurrentValue(), wasV1);
        hProcs[ch].reset();

        biasAngle[ch] = 0.0;
    }

    makeup.skip (numSteps);

    osManager.prepareToPlay (sampleRate, samplesPerBlock);
    for (int ch = 0; ch < 2; ++ch)
        dcBlocker[ch].prepare (sampleRate, dcFreq);

    doubleBuffer.setSize (2, samplesPerBlock);
    bypass.prepare (samplesPerBlock, bypass.toBool (onOffParam));

#if HYSTERESIS_USE_SIMD
    const auto maxOSBlockSize = (uint32) samplesPerBlock * 16;
    interleaved = dsp::AudioBlock<Vec2> (interleavedBlockData, 1, maxOSBlockSize);
    zero = dsp::AudioBlock<double> (zeroData, Vec2::size(), maxOSBlockSize);
    zero.clear();
#endif
}

void HysteresisProcessor::releaseResources()
{
    osManager.reset();
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
    makeup.setTargetValue (calcMakeup());
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
    {
        auto* bufferPtr = buffer.getWritePointer (ch);
        FloatVectorOperations::clip (bufferPtr,
                                     bufferPtr,
                                     -clipLevel,
                                     clipLevel,
                                     buffer.getNumSamples());
    }

    doubleBuffer.makeCopyOf (buffer, true);

    dsp::AudioBlock<double> block (doubleBuffer);
    dsp::AudioBlock<double> osBlock = osManager.processSamplesUp (block);

#if HYSTERESIS_USE_SIMD
    const auto n = osBlock.getNumSamples();
    auto* inout = channelPointers.getData();
    for (size_t ch = 0; ch < Vec2::size(); ++ch)
        inout[ch] = (ch < osBlock.getNumChannels() ? const_cast<double*> (osBlock.getChannelPointer (ch)) : zero.getChannelPointer (ch));

    // interleave channels
    interleaveSamples (inout, reinterpret_cast<double*> (interleaved.getChannelPointer (0)), static_cast<int> (n), static_cast<int> (Vec2::size()));

    auto processBlock = interleaved.getSubBlock (0, n);
#else
    auto processBlock = osBlock;
#endif

    if (useV1)
    {
        if (needsSmoothing)
            processSmoothV1 (processBlock);
        else
            processV1 (processBlock);
    }
    else
    {
        switch (solver)
        {
            case RK2:
                if (needsSmoothing)
                    processSmooth<RK2> (processBlock);
                else
                    process<RK2> (processBlock);
                break;
            case RK4:
                if (needsSmoothing)
                    processSmooth<RK4> (processBlock);
                else
                    process<RK4> (processBlock);
                break;
            case NR4:
                if (needsSmoothing)
                    processSmooth<NR4> (processBlock);
                else
                    process<NR4> (processBlock);
                break;
            case NR8:
                if (needsSmoothing)
                    processSmooth<NR8> (processBlock);
                else
                    process<NR8> (processBlock);
                break;
            case STN:
                if (needsSmoothing)
                    processSmooth<STN> (processBlock);
                else
                    process<STN> (processBlock);
                break;
            default:
                jassertfalse; // unknown solver!
        };
    }

#if HYSTERESIS_USE_SIMD
    // de-interleave channels
    deinterleaveSamples (reinterpret_cast<double*> (interleaved.getChannelPointer (0)),
                         const_cast<double**> (inout),
                         static_cast<int> (n),
                         static_cast<int> (Vec2::size()));
#endif

    osManager.processSamplesDown (block);

    buffer.makeCopyOf (doubleBuffer, true);
    applyDCBlockers (buffer);

    bypass.processBlockOut (buffer, bypass.toBool (onOffParam));
}

template <typename T, typename SmoothType>
void applyMakeup (dsp::AudioBlock<T>& block, SmoothType& makeup)
{
#if 1 // HYSTERESIS_USE_SIMD
    const auto numSamples = block.getNumSamples();
    const auto numChannels = block.getNumChannels();

    if (makeup.isSmoothing())
    {
        for (size_t i = 0; i < numSamples; ++i)
        {
            const auto scaler = makeup.getNextValue();

            for (size_t ch = 0; ch < numChannels; ++ch)
                block.getChannelPointer (ch)[i] *= scaler;
        }
    }
    else
    {
        const auto scaler = makeup.getTargetValue();
        for (size_t ch = 0; ch < numChannels; ++ch)
        {
            auto* x = block.getChannelPointer (ch);
            for (size_t i = 0; i < numSamples; ++i)
                x[i] *= scaler;
        }
    }
#else
    block *= makeup;
#endif
}

template <SolverType solverType, typename T>
void HysteresisProcessor::process (dsp::AudioBlock<T>& block)
{
    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
            x[samp] = hProcs[channel].process<solverType> (x[samp]);
    }

    applyMakeup (block, makeup);
}

template <SolverType solverType, typename T>
void HysteresisProcessor::processSmooth (dsp::AudioBlock<T>& block)
{
    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), false);
            x[samp] = hProcs[channel].process<solverType> (x[samp]);
        }
    }

    applyMakeup (block, makeup);
}

template <typename T>
void HysteresisProcessor::processV1 (dsp::AudioBlock<T>& block)
{
    const auto angleDelta = MathConstants<double>::twoPi * biasFreq / (fs * osManager.getOSFactor());

    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            auto bias = biasGain * (1.0 - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            biasAngle[channel] += angleDelta;
            biasAngle[channel] -= MathConstants<double>::twoPi * (biasAngle[channel] >= MathConstants<double>::twoPi);

            x[samp] = hProcs[channel].process<RK4> ((x[samp] + bias) * 10000.0) * v1Norm;
        }
    }
}

template <typename T>
void HysteresisProcessor::processSmoothV1 (dsp::AudioBlock<T>& block)
{
    const auto angleDelta = MathConstants<double>::twoPi * biasFreq / (fs * osManager.getOSFactor());

    for (size_t channel = 0; channel < block.getNumChannels(); ++channel)
    {
        auto* x = block.getChannelPointer (channel);
        for (size_t samp = 0; samp < block.getNumSamples(); samp++)
        {
            hProcs[channel].cook (drive[channel].getNextValue(), width[channel].getNextValue(), sat[channel].getNextValue(), true);

            auto bias = biasGain * (1.0 - width[channel].getCurrentValue()) * std::sin (biasAngle[channel]);
            biasAngle[channel] += angleDelta;
            biasAngle[channel] -= MathConstants<double>::twoPi * (biasAngle[channel] >= MathConstants<double>::twoPi);

            x[samp] = hProcs[channel].process<RK4> ((x[samp] + bias) * 10000.0) * v1Norm;
        }
    }
}

void HysteresisProcessor::applyDCBlockers (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        dcBlocker[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
}
