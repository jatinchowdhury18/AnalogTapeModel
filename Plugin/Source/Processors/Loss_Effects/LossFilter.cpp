#include "LossFilter.h"

LossFilter::LossFilter (AudioProcessorValueTreeState& vts, int order) : order (order)
{
    speed = vts.getRawParameterValue ("speed");
    spacing = vts.getRawParameterValue ("spacing");
    thickness = vts.getRawParameterValue ("thick");
    gap = vts.getRawParameterValue ("gap");
    onOff = vts.getRawParameterValue ("loss_onoff");
    azimuth = vts.getRawParameterValue ("azimuth");
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

    params.push_back (std::make_unique<AudioParameterFloat> ("azimuth", "Azimuth", -75.0f, 75.0f, 0.0f));
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
    curOrder = int (order * fsFactor);
    currentCoefs.resize (curOrder);
    Hcoefs.resize (curOrder);

    for (auto& filter : bumpFilter)
    {
        filter.resize ((size_t) numChannels);
        for (auto& filt : filter)
            filt.prepare ({ (double) sampleRate, (uint32) samplesPerBlock, 1 });
    }
    calcCoefs (bumpFilter[activeFilter]);

    for (auto& filter : filters)
    {
        filter.clear();
        for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
        {
            filter.emplace_back (curOrder);
            filter[ch].reset();
            filter[ch].setCoefs (currentCoefs.getRawDataPointer());
        }
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

    for (auto& filt : filter)
        filt.coefficients = *dsp::IIR::Coefficients<float>::makePeakFilter (fs, bumpFreq, 2.0f, gain);
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
        for (auto& filt : filters[! activeFilter])
            filt.setCoefs (currentCoefs.getRawDataPointer());

        for (auto& filt : bumpFilter[! activeFilter])
            filt.reset();

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
        for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
            filters[! activeFilter][ch].processBypassed (buffer.getReadPointer ((int) ch), numSamples);
    }

    // normal processing here...
    {
        dsp::AudioBlock<float> block (buffer);
        for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
        {
            filters[activeFilter][ch].process (buffer.getWritePointer ((int) ch), numSamples);

            auto&& channelBlock = block.getSingleChannelBlock (ch);
            dsp::ProcessContextReplacing<float> ctx (channelBlock);
            bumpFilter[activeFilter][ch].process (ctx);
        }
    }

    if (fadeCount > 0)
    {
        dsp::AudioBlock<float> block (buffer);
        for (size_t ch = 0; ch < (size_t) numChannels; ++ch)
        {
            filters[! activeFilter][ch].process (fadeBuffer.getWritePointer ((int) ch), numSamples);

            auto&& channelBlock = block.getSingleChannelBlock (ch);
            dsp::ProcessContextReplacing<float> ctx (channelBlock);
            bumpFilter[! activeFilter][ch].process (ctx);
        }

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

    azimuthProc.setAzimuthAngle (azimuth->load(), speed->load());
    azimuthProc.processBlock (buffer);

    bypass.processBlockOut (buffer, bypass.toBool (onOff));
}
