#include "WowFlutterProcessor.h"
#include "../../GUI/LightMeter.h"

namespace
{
constexpr float depthSlewMin = 0.001f;
}

WowFlutterProcessor::WowFlutterProcessor (AudioProcessorValueTreeState& vts)
{
    flutterRate = vts.getRawParameterValue ("rate");
    flutterDepth = vts.getRawParameterValue ("depth");

    wowRate = vts.getRawParameterValue ("wow_rate");
    wowDepth = vts.getRawParameterValue ("wow_depth");

    flutterOnOff = vts.getRawParameterValue ("flutter_onoff");

    depthSlewFlutter[0].setCurrentAndTargetValue (*flutterDepth);
    depthSlewFlutter[1].setCurrentAndTargetValue (*flutterDepth);
}

void WowFlutterProcessor::initialisePlots (foleys::MagicGUIState& magicState)
{
    wowPlot = magicState.createAndAddObject<LightMeter> ("wow");
    magicState.addBackgroundProcessing (wowPlot);

    flutterPlot = magicState.createAndAddObject<LightMeter> ("flutter");
    magicState.addBackgroundProcessing (flutterPlot);
}

void WowFlutterProcessor::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterBool> ("flutter_onoff", "Wow/Flutter On/Off", true));

    params.push_back (std::make_unique<AudioParameterFloat> ("rate", "Flutter Rate", 0.0f, 1.0f, 0.3f));
    params.push_back (std::make_unique<AudioParameterFloat> ("depth", "Flutter Depth", 0.0f, 1.0f, 0.0f));

    params.push_back (std::make_unique<AudioParameterFloat> ("wow_rate", "Wow Rate", 0.0f, 1.0f, 0.25f));
    params.push_back (std::make_unique<AudioParameterFloat> ("wow_depth", "Wow Depth", 0.0f, 1.0f, 0.0f));
}

void WowFlutterProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    wowProcessor.prepare (sampleRate, samplesPerBlock);

    for (int ch = 0; ch < 2; ++ch)
    {
        delay.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
        delay.setDelay (0.0f);

        depthSlewFlutter[ch].reset (sampleRate, 0.05);
        depthSlewFlutter[ch].setCurrentAndTargetValue (depthSlewMin);

        phase1[ch] = 0.0f;
        phase2[ch] = 0.0f;
        phase3[ch] = 0.0f;

        dcBlocker[ch].prepare (sampleRate, 15.0f);
    }

    amp1 = -230.0f * 1000.0f / (float) sampleRate;
    amp2 = -80.0f * 1000.0f / (float) sampleRate;
    amp3 = -99.0f * 1000.0f / (float) sampleRate;
    dcOffset = 350.0f * 1000.0f / (float) sampleRate;

    isOff = true;
    dryBuffer.setSize (2, samplesPerBlock);
    flutterBuffer.setSize (2, samplesPerBlock);

    wowPlot->prepareToPlay (sampleRate, samplesPerBlock);
    flutterPlot->prepareToPlay (sampleRate, samplesPerBlock);
}

void WowFlutterProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/)
{
    ScopedNoDenormals noDenormals;

    auto curDepthWow = powf (*wowDepth, 3.0f);
    auto wowFreq = powf (4.5, *wowRate) - 1.0f;
    wowProcessor.prepareBlock (curDepthWow, wowFreq, buffer.getNumSamples());

    auto curDepthFlutter = powf (powf (*flutterDepth, 3.0f) * 81.0f / 625.0f, 0.5f);
    depthSlewFlutter[0].setTargetValue (jmax (depthSlewMin, curDepthFlutter));
    depthSlewFlutter[1].setTargetValue (jmax (depthSlewMin, curDepthFlutter));

    auto flutterFreq = 0.1f * powf (1000.0f, *flutterRate);
    angleDelta1 = MathConstants<float>::twoPi * 1.0f * flutterFreq / fs;
    angleDelta2 = MathConstants<float>::twoPi * 2.0f * flutterFreq / fs;
    angleDelta3 = MathConstants<float>::twoPi * 3.0f * flutterFreq / fs;

    flutterBuffer.setSize (2, buffer.getNumSamples(), false, false, true);
    flutterBuffer.clear();

    bool shouldTurnOff = ! static_cast<bool> (flutterOnOff->load()) || (wowProcessor.shouldTurnOff() && depthSlewFlutter[0].getTargetValue() == depthSlewMin);
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

    wowProcessor.plotBuffer (wowPlot);

    flutterBuffer.applyGain (1.3333f / amp1);
    flutterPlot->pushSamples (flutterBuffer);
}

void WowFlutterProcessor::processWetBuffer (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        auto* flutterPtr = flutterBuffer.getWritePointer (ch);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            auto [wowLFO, wowOffset] = wowProcessor.getLFO (n, ch);

            phase1[ch] += angleDelta1;
            phase2[ch] += angleDelta2;
            phase3[ch] += angleDelta3;

            auto flutterLFO = depthSlewFlutter[ch].getNextValue()
                              * (amp1 * cosf (phase1[ch] + phaseOff1)
                                 + amp2 * cosf (phase2[ch] + phaseOff2)
                                 + amp3 * cosf (phase3[ch] + phaseOff3));

            auto newLength = (wowLFO + flutterLFO + dcOffset + wowOffset) * (float) fs / 1000.0f;
            newLength = jlimit (0.0f, (float) HISTORY_SIZE, newLength);

            delay.setDelay (newLength);
            delay.pushSample (ch, x[n]);
            x[n] = delay.popSample (ch);

            flutterPtr[n] = flutterLFO;
        }

        wowProcessor.boundPhase (ch);
        while (phase1[ch] >= MathConstants<float>::twoPi)
            phase1[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
    }
}

void WowFlutterProcessor::processBypassed (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        delay.setDelay (0.0f);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            wowProcessor.updatePhase (ch);
            phase1[ch] += angleDelta1;
            phase2[ch] += angleDelta2;
            phase3[ch] += angleDelta3;

            delay.pushSample (ch, 0.0f);
            delay.popSample (ch);
        }

        wowProcessor.updatePhase (ch);
        while (phase1[ch] >= MathConstants<float>::twoPi)
            phase1[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
    }
}
