#include "WowFlutterProcessor.h"
#include "../../GUI/Visualizers/LightMeter.h"

WowFlutterProcessor::WowFlutterProcessor (AudioProcessorValueTreeState& vts)
{
    flutterRate = vts.getRawParameterValue ("rate");
    flutterDepth = vts.getRawParameterValue ("depth");

    wowRate = vts.getRawParameterValue ("wow_rate");
    wowDepth = vts.getRawParameterValue ("wow_depth");
    wowVariance = vts.getRawParameterValue ("wow_var");
    wowDrift = vts.getRawParameterValue ("wow_drift");

    flutterOnOff = vts.getRawParameterValue ("flutter_onoff");
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
    params.push_back (std::make_unique<AudioParameterFloat> ("wow_var", "Wow Variance", 0.0f, 1.0f, 0.0f));
    params.push_back (std::make_unique<AudioParameterFloat> ("wow_drift", "Wow Drift", 0.0f, 1.0f, 0.0f));
}

void WowFlutterProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    bypass.prepare (samplesPerBlock, bypass.toBool (flutterOnOff));
    wowProcessor.prepare (sampleRate, samplesPerBlock);
    flutterProcessor.prepare (sampleRate, samplesPerBlock);

    for (int ch = 0; ch < 2; ++ch)
    {
        delay.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
        delay.setDelay (0.0f);

        dcBlocker[ch].prepare (sampleRate, 15.0f);
    }

    wowPlot->prepareToPlay (sampleRate, samplesPerBlock);
    flutterPlot->prepareToPlay (sampleRate, samplesPerBlock);
}

void WowFlutterProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/)
{
    ScopedNoDenormals noDenormals;

    auto curDepthWow = powf (*wowDepth, 3.0f);
    auto wowFreq = powf (4.5, *wowRate) - 1.0f;
    wowProcessor.prepareBlock (curDepthWow, wowFreq, wowVariance->load(), wowDrift->load(), buffer.getNumSamples());

    auto curDepthFlutter = powf (powf (*flutterDepth, 3.0f) * 81.0f / 625.0f, 0.5f);
    auto flutterFreq = 0.1f * powf (1000.0f, *flutterRate);
    flutterProcessor.prepareBlock (curDepthFlutter, flutterFreq, buffer.getNumSamples());

    bool shouldTurnOff = ! bypass.toBool (flutterOnOff) || (wowProcessor.shouldTurnOff() && flutterProcessor.shouldTurnOff());
    if (bypass.processBlockIn (buffer, ! shouldTurnOff))
    {
        processWetBuffer (buffer);

        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            dcBlocker[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());

        bypass.processBlockOut (buffer, ! shouldTurnOff);
    }
    else
    {
        processBypassed (buffer);
    }

    wowProcessor.plotBuffer (wowPlot);
    flutterProcessor.plotBuffer (flutterPlot);
}

void WowFlutterProcessor::processWetBuffer (AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            auto [wowLFO, wowOffset] = wowProcessor.getLFO (n, ch);
            auto [flutterLFO, flutterOffset] = flutterProcessor.getLFO (n, ch);

            auto newLength = (wowLFO + flutterLFO + flutterOffset + wowOffset) * fs / 1000.0f;
            newLength = jlimit (0.0f, (float) HISTORY_SIZE, newLength);

            delay.setDelay (newLength);
            delay.pushSample (ch, x[n]);
            x[n] = delay.popSample (ch);
        }

        wowProcessor.boundPhase (ch);
        flutterProcessor.boundPhase (ch);
    }
}

void WowFlutterProcessor::processBypassed (const AudioBuffer<float>& buffer)
{
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        delay.setDelay (0.0f);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            wowProcessor.updatePhase (ch);
            flutterProcessor.updatePhase (ch);

            delay.pushSample (ch, 0.0f);
            delay.popSample (ch);
        }

        wowProcessor.boundPhase (ch);
        flutterProcessor.boundPhase (ch);
    }
}
