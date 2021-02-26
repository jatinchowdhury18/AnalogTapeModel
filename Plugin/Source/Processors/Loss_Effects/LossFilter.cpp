#include "LossFilter.h"

LossFilter::LossFilter (AudioProcessorValueTreeState& vts, int order) : order (order)
{
    speed = vts.getRawParameterValue ("speed");
    spacing = vts.getRawParameterValue ("spacing");
    thickness = vts.getRawParameterValue ("thick");
    gap = vts.getRawParameterValue ("gap");
    onOff = vts.getRawParameterValue ("loss_onoff");

    for (int ch = 0; ch < 2; ++ch)
    {
        filters[ch].add (new FIRFilter (order));
        filters[ch].add (new FIRFilter (order));
    }

    currentCoefs.resize (order);
}

void LossFilter::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    constexpr float minDist = 0.1f;

    auto valueToString = [] (float value, int) { return String (value, 4); };
    auto stringToValue = [] (const String& text) { return text.getFloatValue(); };

    NormalisableRange<float> speedRange (1.0f, 50.0f); // meters per second
    speedRange.setSkewForCentre (15.0f);

    NormalisableRange<float> spaceRange (minDist, 20.0f);
    spaceRange.setSkewForCentre (10.0f);

    NormalisableRange<float> thickRange (minDist, 50.0f);
    thickRange.setSkewForCentre (15.0f);

    NormalisableRange<float> gapRange (1.0f, 50.0f);
    gapRange.setSkewForCentre (10.0f);

    params.push_back (std::make_unique<AudioParameterBool> ("loss_onoff", "Loss On/Off", true));

    params.push_back (std::make_unique<AudioParameterFloat> ("speed", "Tape Speed", speedRange, 30.0f, String(), AudioProcessorParameter::genericParameter, [] (float value, int) { return String (value, 2); }));

    params.push_back (std::make_unique<AudioParameterFloat> ("spacing", "Tape Spacing", spaceRange, minDist, String(), AudioProcessorParameter::genericParameter, valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("thick", "Tape Thickness", thickRange, minDist, String(), AudioProcessorParameter::genericParameter, valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("gap", "Playhead Gap", gapRange, 1.0f, String(), AudioProcessorParameter::genericParameter, valueToString, stringToValue));
}

float LossFilter::getLatencySamples() const noexcept
{
    return onOff->load() == 1.0f ? (float) curOrder / 2.0f // on
                                 : 0.0f; // off
}

void LossFilter::prepare (float sampleRate, int samplesPerBlock)
{
    fs = sampleRate;
    fadeBuffer.setSize (2, samplesPerBlock);

    fsFactor = (float) fs / 44100.0f;
    curOrder = int (order * fsFactor);
    currentCoefs.resize (curOrder);
    Hcoefs.resize (curOrder);

    bumpFilter[0].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, 2 });
    bumpFilter[1].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, 2 });
    calcCoefs (bumpFilter[activeFilter]);

    for (int ch = 0; ch < 2; ++ch)
    {
        filters[ch].clear();
        filters[ch].add (new FIRFilter (curOrder));
        filters[ch].add (new FIRFilter (curOrder));

        filters[ch][0]->reset();
        filters[ch][1]->reset();

        filters[ch][0]->setCoefs (currentCoefs.getRawDataPointer());
        filters[ch][1]->setCoefs (currentCoefs.getRawDataPointer());
    }

    prevSpeed = *speed;
    prevSpacing = *spacing;
    prevThickness = *thickness;
    prevGap = *gap;

    bypass.prepare (samplesPerBlock, bypass.toBool (onOff));
}

void LossFilter::calcHeadBumpFilter (float speedIps, float gapMeters, double fs, StereoIIR& filter)
{
    auto bumpFreq = speedIps * 0.0254f / (gapMeters * 500.0f);
    auto gain = jmax (1.5f * (1000.0f - std::abs (bumpFreq - 100.0f)) / 1000.0f, 1.0f);
    *filter.state = *dsp::IIR::Coefficients<float>::makePeakFilter (fs, bumpFreq, 2.0f, gain);
}

void LossFilter::calcCoefs (StereoIIR& filter)
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
        const size_t idx = curOrder / 2 + n;
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
        for (int ch = 0; ch < numChannels; ++ch)
            filters[ch][! activeFilter]->setCoefs (currentCoefs.getRawDataPointer());
        bumpFilter[! activeFilter].reset();

        fadeCount = fadeLength;
        prevSpeed = *speed;
        prevSpacing = *spacing;
        prevThickness = *thickness;
        prevGap = *gap;
    }

    if (fadeCount > 0)
    {
        fadeBuffer.makeCopyOf (buffer, true);
    }
    else
    {
        for (int ch = 0; ch < numChannels; ++ch)
            filters[ch][! activeFilter]->processBypassed (buffer.getReadPointer (ch), numSamples);
    }

    // normal processing here...
    {
        for (int ch = 0; ch < numChannels; ++ch)
            filters[ch][activeFilter]->process (buffer.getWritePointer (ch), numSamples);

        dsp::AudioBlock<float> block (buffer);
        dsp::ProcessContextReplacing<float> ctx (block);
        bumpFilter[activeFilter].process (ctx);
    }

    if (fadeCount > 0)
    {
        for (int ch = 0; ch < numChannels; ++ch)
            filters[ch][! activeFilter]->process (fadeBuffer.getWritePointer (ch), numSamples);

        dsp::AudioBlock<float> block (fadeBuffer);
        dsp::ProcessContextReplacing<float> ctx (block);
        bumpFilter[! activeFilter].process (ctx);

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

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}
