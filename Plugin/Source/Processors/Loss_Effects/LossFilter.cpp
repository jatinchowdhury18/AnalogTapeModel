#include "LossFilter.h"

LossFilter::LossFilter (AudioProcessorValueTreeState& vts, int order) : order (order)
{
    using namespace chowdsp::ParamUtils;
    loadParameterPointer (speed, vts, "speed");
    loadParameterPointer (spacing, vts, "spacing");
    loadParameterPointer (thickness, vts, "thick");
    loadParameterPointer (gap, vts, "gap");
    loadParameterPointer (azimuth, vts, "azimuth");
    onOff = vts.getRawParameterValue ("loss_onoff");
}

void LossFilter::createParameterLayout (chowdsp::Parameters& params)
{
    using namespace chowdsp::ParamUtils;
    constexpr float minDist = 0.1f;
    emplace_param<chowdsp::BoolParameter> (params, "loss_onoff", "Loss On/Off", true);
    emplace_param<chowdsp::FloatParameter> (params, "speed", "Tape Speed", createNormalisableRange (1.0f, 50.0f, 15.0f), 30.0f, &floatValToString, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "spacing", "Tape Spacing", createNormalisableRange (minDist, 20.0f, 10.0f), minDist, &floatValToStringDecimal<4>, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "thick", "Tape Thickness", createNormalisableRange (minDist, 50.0f, 15.0f), minDist, &floatValToStringDecimal<4>, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "gap", "Playhead Gap", createNormalisableRange (1.0f, 50.0f, 10.0f), 1.0, &floatValToStringDecimal<4>, &stringToFloatVal);
    emplace_param<chowdsp::FloatParameter> (params, "azimuth", "Azimuth", NormalisableRange { -75.0f, 75.0f }, 0.0f, &floatValToString, &stringToFloatVal);
}

float LossFilter::getLatencySamples() const noexcept
{
    return onOff->load() == 1.0f ? (float) curOrder / 2.0f // on
                                 : 0.0f; // off
}

void LossFilter::prepare (float sampleRate, int samplesPerBlock, int numChannels)
{
    fs = sampleRate;
    fadeBuffer.setSize (numChannels, samplesPerBlock);
    fadeLength = jmax (1024, samplesPerBlock);

    fsFactor = (float) fs / 44100.0f;
    curOrder = int ((float) order * fsFactor);
    currentCoefs.resize (curOrder);
    Hcoefs.resize (curOrder);

    bumpFilter[0].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, (uint32) numChannels });
    bumpFilter[1].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, (uint32) numChannels });
    calcCoefs (bumpFilter[activeFilter]);

    for (auto& filter : filters)
    {
        filter.setOrder (curOrder);
        filter.prepare (numChannels);
        filter.setCoefficients (currentCoefs.getRawDataPointer());
    }

    prevSpeed = *speed;
    prevSpacing = *spacing;
    prevThickness = *thickness;
    prevGap = *gap;

    azimuthProc.prepare (sampleRate, samplesPerBlock);
    bypass.prepare (samplesPerBlock, numChannels, bypass.toBool (onOff));
}

void LossFilter::calcHeadBumpFilter (float speedIps, float gapMeters, double fs, MultiChannelIIR& filter)
{
    auto bumpFreq = speedIps * 0.0254f / (gapMeters * 500.0f);
    auto gain = jmax (1.5f * (1000.0f - std::abs (bumpFreq - 100.0f)) / 1000.0f, 1.0f);
    *filter.state = *dsp::IIR::Coefficients<float>::makePeakFilter (fs, bumpFreq, 2.0f, gain);
}

void LossFilter::calcCoefs (MultiChannelIIR& filter)
{
    // Set freq domain multipliers
    binWidth = fs / (float) curOrder;
    auto H = Hcoefs.getRawDataPointer();
    for (int k = 0; k < curOrder / 2; k++)
    {
        const auto freq = (float) k * binWidth;
        const auto waveNumber = MathConstants<float>::twoPi * jmax (freq, 20.0f) / (*speed * 0.0254f);
        const auto thickTimesK = waveNumber * (*thickness * (float) 1.0e-6);
        const auto kGapOverTwo = waveNumber * (*gap * (float) 1.0e-6) / 2.0f;

        H[k] = expf (-waveNumber * (*spacing * (float) 1.0e-6)); // Spacing loss
        H[k] *= (1.0f - expf (-thickTimesK)) / thickTimesK; // Thickness loss
        H[k] *= sinf (kGapOverTwo) / kGapOverTwo; // Gap loss
        H[curOrder - k - 1] = H[k];
    }

    // Create time domain filter signal
    auto h = currentCoefs.getRawDataPointer();
    for (int n = 0; n < curOrder / 2; n++)
    {
        const auto idx = (size_t) curOrder / 2 + (size_t) n;
        for (int k = 0; k < curOrder; k++)
            h[idx] += Hcoefs[k] * cosf (MathConstants<float>::twoPi * (float) k * (float) n / (float) curOrder);

        h[idx] /= (float) curOrder;
        h[curOrder / 2 - n] = h[idx];
    }

    // compute head bump filters
    calcHeadBumpFilter (*speed, *gap * (float) 1.0e-6, (double) fs, filter);
}

void LossFilter::processBlock (AudioBuffer<float>& buffer)
{
    const auto numChannels = buffer.getNumChannels();
    const auto numSamples = buffer.getNumSamples();

    if (! bypass.processBlockIn (buffer, bypass.toBool (onOff)))
        return;

    if ((*speed != prevSpeed || *spacing != prevSpacing || *thickness != prevThickness || *gap != prevGap) && fadeCount == 0)
    {
        calcCoefs (bumpFilter[! activeFilter]);
        filters[! activeFilter].setCoefficients (currentCoefs.getRawDataPointer());

        bumpFilter[! activeFilter].reset();

        fadeCount = fadeLength;
        prevSpeed = *speed;
        prevSpacing = *spacing;
        prevThickness = *thickness;
        prevGap = *gap;
    }

    if (fadeCount > 0)
        fadeBuffer.makeCopyOf (buffer, true);
    else
        filters[! activeFilter].processBlockBypassed (buffer);

    // normal processing here...
    {
        dsp::AudioBlock<float> block (buffer);
        filters[activeFilter].processBlock (buffer);

        bumpFilter[activeFilter].process (dsp::ProcessContextReplacing<float> { block });
    }

    if (fadeCount > 0)
    {
        dsp::AudioBlock<float> fadeBlock (fadeBuffer);
        filters[! activeFilter].processBlock (fadeBuffer);

        bumpFilter[! activeFilter].process (dsp::ProcessContextReplacing<float> { fadeBlock });

        // fade between buffers
        auto startGain = (float) fadeCount / (float) fadeLength;
        auto samplesToFade = jmin (fadeCount, numSamples);
        fadeCount -= samplesToFade;
        auto endGain = (float) fadeCount / (float) fadeLength;

        buffer.applyGainRamp (0, samplesToFade, startGain, endGain);
        buffer.applyGain (samplesToFade, numSamples - samplesToFade, endGain);

        for (int ch = 0; ch < numChannels; ++ch)
            buffer.addFromWithRamp (ch, 0, fadeBuffer.getReadPointer (ch), samplesToFade, 1.0f - startGain, 1.0f - endGain);

        if (fadeCount == 0)
            activeFilter = ! activeFilter;
    }

    azimuthProc.setAzimuthAngle (azimuth->getCurrentValue(), speed->getCurrentValue());
    azimuthProc.processBlock (buffer);

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}
