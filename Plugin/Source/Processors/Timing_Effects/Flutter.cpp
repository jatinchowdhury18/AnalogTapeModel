#include "Flutter.h"

namespace
{
    constexpr float depthSlewMin = 0.001f;
}

Flutter::Flutter (AudioProcessorValueTreeState& vts)
{
    flutterRate = vts.getRawParameterValue ("rate");
    flutterDepth = vts.getRawParameterValue ("depth");

    wowRate = vts.getRawParameterValue ("wow_rate");
    wowDepth = vts.getRawParameterValue ("wow_depth");

    depthSlewWow[0].setCurrentAndTargetValue (*wowDepth);
    depthSlewWow[1].setCurrentAndTargetValue (*wowDepth);

    depthSlewFlutter[0].setCurrentAndTargetValue (*flutterDepth);
    depthSlewFlutter[1].setCurrentAndTargetValue (*flutterDepth);
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

        depthSlewWow[ch].reset (10000);
        depthSlewWow[ch].setCurrentAndTargetValue (depthSlewMin);

        depthSlewFlutter[ch].reset (10000);
        depthSlewFlutter[ch].setCurrentAndTargetValue (depthSlewMin);

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

    isOff = true;
    dryBuffer.setSize (2, samplesPerBlock);
}

void Flutter::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/)
{
    ScopedNoDenormals noDenormals;

    auto curDepthWow = powf (*wowDepth * 81.0f / 625.0f, 0.5f);
    depthSlewWow[0].setTargetValue (jmax (depthSlewMin, curDepthWow));
    depthSlewWow[1].setTargetValue (jmax (depthSlewMin, curDepthWow));

    auto curDepthFlutter = powf (*flutterDepth * 81.0f / 625.0f, 0.5f);
    depthSlewFlutter[0].setTargetValue (jmax (depthSlewMin, curDepthFlutter));
    depthSlewFlutter[1].setTargetValue (jmax (depthSlewMin, curDepthFlutter));

    auto wowFreq = 0.1f * powf (1000.0f, *wowRate);
    auto flutterFreq = 0.1f * powf (1000.0f, *flutterRate);
    angleDelta1 = MathConstants<float>::twoPi * 1.0f * wowFreq / fs;
    angleDelta2 = MathConstants<float>::twoPi * 2.0f * flutterFreq / fs;
    angleDelta3 = MathConstants<float>::twoPi * 3.0f * flutterFreq / fs;

    bool shouldTurnOff = depthSlewWow[0].getTargetValue() == depthSlewMin
                      && depthSlewFlutter[0].getTargetValue() == depthSlewMin;
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

            auto wowLFO = depthSlewWow[ch].getNextValue() * amp1 * cosf (phase1[ch] + phaseOff1);
            auto flutterLFO = depthSlewFlutter[ch].getNextValue()
                * (amp2 * cosf (phase2[ch] + phaseOff2) + amp3 * cosf (phase3[ch] + phaseOff3));

            delay[ch].setLengthMs (wowLFO + flutterLFO + dcOffset);
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
