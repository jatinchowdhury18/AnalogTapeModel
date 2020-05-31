#include "Flutter.h"

Flutter::Flutter (AudioProcessorValueTreeState& vts)
{
    rate = vts.getRawParameterValue ("rate");
    depth = vts.getRawParameterValue ("depth");

    depthSlew[0].setCurrentAndTargetValue (*depth);
    depthSlew[1].setCurrentAndTargetValue (*depth);
}

void Flutter::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("rate",  "Rate",  0.0f, 1.0f, 0.3f));
    params.push_back (std::make_unique<AudioParameterFloat> ("depth", "Depth", 0.0f, 1.0f, 0.0f));

    params.push_back (std::make_unique<AudioParameterFloat> ("wow_rate", "Rate", 0.0f, 1.0f, 0.5f));
    params.push_back (std::make_unique<AudioParameterFloat> ("wow_depth", "Depth", 0.0f, 1.0f, 0.0f));
}

void Flutter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    for (int ch = 0; ch < 2; ++ch)
    {
        delay[ch].prepareToPlay (sampleRate, samplesPerBlock);
        delay[ch].setLengthMs (0.f);
        depthSlew[ch].reset (10000);
        depthSlew[ch].setCurrentAndTargetValue (0.001f);

        phase1[ch] = 0.0f;
        phase2[ch] = 0.0f;
        phase3[ch] = 0.0f;

        dcBlocker[ch].reset (sampleRate);
        dcBlocker[ch].calcCoefs (10.0f, 0.707f);
    }

    amp1     = -230.0f * 1000.0f / (float) sampleRate;
    amp2     = -80.0f  * 1000.0f / (float) sampleRate;
    amp3     = -99.0f  * 1000.0f / (float) sampleRate;
    dcOffset =  350.0f * 1000.0f / (float) sampleRate;

    isOff = depthSlew[0].getTargetValue() == 0.0f;
    dryBuffer.setSize (2, samplesPerBlock);
}

void Flutter::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/)
{
    ScopedNoDenormals noDenormals;

    auto curDepth = powf (*depth * 81.0f / 625.0f, 0.5f);
    depthSlew[0].setTargetValue (jmax (0.001f, curDepth));
    depthSlew[1].setTargetValue (jmax (0.001f, curDepth));

    auto freq = 0.1f * powf (1000.0f, *rate);
    angleDelta1 = MathConstants<float>::twoPi * 1.0f * freq / fs;
    angleDelta2 = MathConstants<float>::twoPi * 2.0f * freq / fs;
    angleDelta3 = MathConstants<float>::twoPi * 3.0f * freq / fs;

    bool shouldTurnOff = depthSlew[0].getTargetValue() == 0.001f;
    if (! isOff && ! shouldTurnOff) // process normally
    {
        processWetBuffer (buffer);
    }
    else if (! isOff && shouldTurnOff) // turn off
    {
        dryBuffer.makeCopyOf (buffer, true);
        processWetBuffer (buffer);

        buffer.applyGainRamp (0, buffer.getNumSamples(), 1.0f, 0.0f);
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            buffer.addFromWithRamp (ch, 0, dryBuffer.getWritePointer (ch), buffer.getNumSamples(), 0.0f, 1.0f);
    }
    else if (isOff && ! shouldTurnOff) // turn on
    {
        dryBuffer.makeCopyOf (buffer, true);
        processWetBuffer (buffer);

        buffer.applyGainRamp (0, buffer.getNumSamples(), 0.0f, 1.0f);
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            buffer.addFromWithRamp (ch, 0, dryBuffer.getWritePointer (ch), buffer.getNumSamples(), 1.0f, 0.0f);
    }
    else // off
    {
        processBypassed (buffer);
    }

    isOff = shouldTurnOff;

    // dc block
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
        dcBlocker[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
}

void Flutter::processWetBuffer (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            phase1[ch] += angleDelta1;
            phase2[ch] += angleDelta2;
            phase3[ch] += angleDelta3;

            auto lfo = amp1 * cosf (phase1[ch] + phaseOff1)
                + amp2 * cosf (phase2[ch] + phaseOff2)
                + amp3 * cosf (phase3[ch] + phaseOff3)
                + dcOffset;

            delay[ch].setLengthMs (depthSlew[ch].getNextValue() * lfo);
            x[n] = delay[ch].delay (x[n]);
        }

        while (phase1[ch] >= MathConstants<float>::twoPi)
            phase1[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
    }
}

void Flutter::processBypassed (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        delay[ch].setLengthMs (0.0f);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            phase1[ch] += angleDelta1;
            phase2[ch] += angleDelta2;
            phase3[ch] += angleDelta3;

            delay[ch].delay (0.0f);
        }

        while (phase1[ch] >= MathConstants<float>::twoPi)
            phase1[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
    }
}
