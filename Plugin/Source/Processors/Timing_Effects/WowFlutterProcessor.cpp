#include "WowFlutterProcessor.h"
#include "../../GUI/Visualizers/LightMeter.h"

WowFlutterProcessor::WowFlutterProcessor (AudioProcessorValueTreeState& vts)
{
    using namespace chowdsp::ParamUtils;
    loadParameterPointer (flutterRate, vts, "rate");
    loadParameterPointer (flutterDepth, vts, "depth");
    loadParameterPointer (wowRate, vts, "wow_rate");
    loadParameterPointer (wowDepth, vts, "wow_depth");
    loadParameterPointer (wowVariance, vts, "wow_var");
    loadParameterPointer (wowDrift, vts, "wow_drift");
    flutterOnOff = vts.getRawParameterValue ("flutter_onoff");
}

void WowFlutterProcessor::initialisePlots (foleys::MagicGUIState& magicState)
{
    wowPlot = magicState.createAndAddObject<LightMeter> ("wow");
    magicState.addBackgroundProcessing (wowPlot);

    flutterPlot = magicState.createAndAddObject<LightMeter> ("flutter");
    magicState.addBackgroundProcessing (flutterPlot);
}

void WowFlutterProcessor::createParameterLayout (chowdsp::Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    emplace_param<chowdsp::BoolParameter> (params, "flutter_onoff", "Wow/Flutter On/Off", true);
    emplace_param<chowdsp::FloatParameter> (params, "rate", "Flutter Rate", NormalisableRange { 0.0f, 1.0f }, 0.3f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "depth", "Flutter Depth", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "wow_rate", "Wow Rate", NormalisableRange { 0.0f, 1.0f }, 0.25f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "wow_depth", "Wow Depth", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "wow_var", "Wow Variance", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "wow_drift", "Wow Drift", NormalisableRange { 0.0f, 1.0f }, 0.0f, &floatValToString, &stringToFloatVal);
}

void WowFlutterProcessor::prepareToPlay (double sampleRate, int samplesPerBlock, int numChannels)
{
    fs = (float) sampleRate;

    bypass.prepare (samplesPerBlock, numChannels, bypass.toBool (flutterOnOff));
    wowProcessor.prepare (sampleRate, samplesPerBlock, numChannels);
    flutterProcessor.prepare (sampleRate, samplesPerBlock, numChannels);

    delay.prepare ({ sampleRate, (uint32) samplesPerBlock, (uint32) numChannels });
    delay.setDelay (0.0f);

    dcBlocker.resize ((size_t) numChannels);
    for (auto& filt : dcBlocker)
        filt.prepare (sampleRate, 15.0f);

    wowPlot->prepareToPlay (sampleRate, samplesPerBlock);
    flutterPlot->prepareToPlay (sampleRate, samplesPerBlock);
}

void WowFlutterProcessor::processBlock (AudioBuffer<float>& buffer)
{
    ScopedNoDenormals noDenormals;

    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();

    auto curDepthWow = powf (*wowDepth, 3.0f);
    auto wowFreq = powf (4.5, *wowRate) - 1.0f;
    wowProcessor.prepareBlock (curDepthWow, wowFreq, wowVariance->getCurrentValue(), wowDrift->getCurrentValue(), numSamples, numChannels);

    auto curDepthFlutter = powf (powf (*flutterDepth, 3.0f) * 81.0f / 625.0f, 0.5f);
    auto flutterFreq = 0.1f * powf (1000.0f, *flutterRate);
    flutterProcessor.prepareBlock (curDepthFlutter, flutterFreq, numSamples, numChannels);

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
