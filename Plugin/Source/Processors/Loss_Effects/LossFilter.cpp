#include "LossFilter.h"

LossFilter::LossFilter (AudioProcessorValueTreeState& vts, int order) :
    order (order)
{
    speed = vts.getRawParameterValue ("speed");
    spacing = vts.getRawParameterValue ("spacing");
    thickness = vts.getRawParameterValue ("thick");
    gap = vts.getRawParameterValue ("gap");
    onOff = vts.getRawParameterValue ("loss_onoff");

    filters.add (new FIRFilter (order));
    filters.add (new FIRFilter (order));

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

    params.push_back (std::make_unique<AudioParameterFloat> ("speed", "Speed [ips]",
        speedRange, 30.0f, String(), AudioProcessorParameter::genericParameter,
        [] (float value, int) { return String (value, 2); }));

    params.push_back (std::make_unique<AudioParameterFloat> ("spacing", "Spacing [microns]",
        spaceRange, minDist, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("thick", "Thickness [microns]",
        thickRange, minDist, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("gap", "Gap [microns]",
        gapRange, 1.0f, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterBool> ("loss_onoff", "On/Off", true));
}

float LossFilter::getLatencySamples() const noexcept
{
    return onOff->load() == 1.0f ? (float) curOrder / 2.0f // on
                                 : 0.0f;                   // off
}

void LossFilter::prepare (float sampleRate, int samplesPerBlock)
{
    fs = sampleRate;
    fadeBuffer.setSize (1, samplesPerBlock);

    fsFactor = (float) fs / 44100.0f;
    curOrder = int (order * fsFactor);
    filters.clear();
    filters.add (new FIRFilter (curOrder));
    filters.add (new FIRFilter (curOrder));
    currentCoefs.resize (curOrder);
    Hcoefs.resize (curOrder);

    filters[0]->reset();
    filters[1]->reset();
    bumpFilter[0].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, 1 });
    bumpFilter[1].prepare ({ (double) sampleRate, (uint32) samplesPerBlock, 1 });

    calcCoefs();
    filters[0]->setCoefs (currentCoefs.getRawDataPointer());
    filters[1]->setCoefs (currentCoefs.getRawDataPointer());

    prevSpeed = *speed;
    prevSpacing = *spacing;
    prevThickness = *thickness;
    prevGap = *gap;

    bypass.prepare (samplesPerBlock, bypass.toBool (onOff));
}

static void calcHeadBumpFilter (float speedIps, float gapMeters, double fs, dsp::IIR::Filter<float>& filter)
{
    auto bumpFreq = speedIps * 0.0254f / (gapMeters * 500.0f);
    auto gain = jmax (1.5f * (1000.0f - std::abs (bumpFreq - 100.0f)) / 1000.0f, 1.0f);
    filter.coefficients = dsp::IIR::Coefficients<float>::makePeakFilter (fs, bumpFreq, 2.0f, gain);
}

void LossFilter::calcCoefs()
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
        H[k] *= (1.0f - expf (-thickTimesK)) / thickTimesK;      // Thickness loss
        H[k] *= sinf (kGapOverTwo) / kGapOverTwo;   // Gap loss
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
    calcHeadBumpFilter (*speed, *gap * (float) 1.0e-6, (double) fs, bumpFilter[! activeFilter]);
}

void LossFilter::processBlock (float* buffer, const int numSamples)
{
    AudioBuffer<float> bufferCast (&buffer, 1, numSamples);
    if (! bypass.processBlockIn (bufferCast, bypass.toBool (onOff)))
        return;

    if ((*speed != prevSpeed || *spacing != prevSpacing ||
        *thickness != prevThickness || *gap != prevGap) && fadeCount == 0)
    {
        calcCoefs();
        filters[! activeFilter]->setCoefs (currentCoefs.getRawDataPointer());
        bumpFilter[! activeFilter].reset();

        fadeCount = fadeLength;
        prevSpeed = *speed;
        prevSpacing = *spacing;
        prevThickness = *thickness;
        prevGap = *gap;
    }

    if (fadeCount > 0)
    {
        fadeBuffer.setSize (1, numSamples, false, false, true);
        fadeBuffer.copyFrom (0, 0, buffer, numSamples);
    }
    else
    {
        filters[! activeFilter]->processBypassed (buffer, numSamples);
    }

    {
        filters[activeFilter]->process (buffer, numSamples);
        dsp::AudioBlock<float> block (&buffer, 1, numSamples);
        dsp::ProcessContextReplacing<float> ctx (block);
        bumpFilter[activeFilter].process (ctx);
    }

    if (fadeCount > 0)
    {
        auto* fadePtr = fadeBuffer.getWritePointer (0);
        filters[! activeFilter]->process (fadePtr, numSamples);
        dsp::AudioBlock<float> block (&fadePtr, 1, numSamples);
        dsp::ProcessContextReplacing<float> ctx (block);
        bumpFilter[! activeFilter].process (ctx);

        for (int n = 0; n < numSamples; ++n)
        {
            float mult = (float) fadeCount / (float) fadeLength;
            buffer[n] = buffer[n] * mult + fadePtr[n] * (1.0f - mult);

            fadeCount--;
            if (fadeCount == 0)
                break;
        }

        if (fadeCount == 0)
            activeFilter = ! activeFilter;
    }

    bypass.processBlockOut (bufferCast, bypass.toBool (onOff));
}
