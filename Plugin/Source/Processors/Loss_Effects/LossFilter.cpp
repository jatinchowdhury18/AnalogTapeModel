#include "LossFilter.h"

LossFilter::LossFilter (AudioProcessorValueTreeState& vts, int order) :
    order (order)
{
    speed = vts.getRawParameterValue ("speed");
    spacing = vts.getRawParameterValue ("spacing");
    thickness = vts.getRawParameterValue ("thick");
    gap = vts.getRawParameterValue ("gap");

    filters.add (new FIRFilter (order));
    filters.add (new FIRFilter (order));

    currentCoefs.resize (order);
}

void LossFilter::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    constexpr float minDist = (float) 1.0e-6;
    constexpr float centreSkew = 5.0f;

    auto valueToString = [] (float value, int) { return String (10.0f * value, 5); };
    auto stringToValue = [] (const String& text) { return text.getFloatValue() / 10.0f; };

    NormalisableRange<float> speedRange (1.0f, 100.0f); // meters per second
    speedRange.setSkewForCentre (15.0f);

    NormalisableRange<float> spaceRange (minDist, 100.0f);
    spaceRange.setSkewForCentre (centreSkew);

    NormalisableRange<float> thickRange (minDist, 10.0f);
    thickRange.setSkewForCentre (centreSkew);

    NormalisableRange<float> gapRange (minDist, 100.0f);
    gapRange.setSkewForCentre (centreSkew);

    params.push_back (std::make_unique<AudioParameterFloat> ("speed", "Speed [ips]",
        speedRange, 15.0f, String(), AudioProcessorParameter::genericParameter,
        [] (float value, int) { return String (value, 4); }));

    params.push_back (std::make_unique<AudioParameterFloat> ("spacing", "Spacing [cm]",
        spaceRange, minDist, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("thick", "Thickness [cm]",
        thickRange, minDist, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));

    params.push_back (std::make_unique<AudioParameterFloat> ("gap", "Gap",
        gapRange, minDist, String(), AudioProcessorParameter::genericParameter,
        valueToString, stringToValue));
}

void LossFilter::prepare (float sampleRate, int samplesPerBlock)
{
    fs = sampleRate;
    fadeBuffer.setSize (1, samplesPerBlock);

    fsFactor = (float) fs / 44100.0f;
    const int curOrder = int (order * fsFactor);
    filters.clear();
    filters.add (new FIRFilter (curOrder));
    filters.add (new FIRFilter (curOrder));
    currentCoefs.resize (curOrder);

    filters[0]->reset();
    filters[1]->reset();

    calcCoefs();
    filters[0]->setCoefs (currentCoefs.getRawDataPointer());
    filters[1]->setCoefs (currentCoefs.getRawDataPointer());

    prevSpeed = *speed;
    prevSpacing = *spacing;
    prevThickness = *thickness;
    prevGap = *gap;

    starting = true;
}

void LossFilter::calcCoefs()
{
    // Set freq domain multipliers
    const int curOrder = int (order * fsFactor);
    binWidth = fs / (float) curOrder;
    std::unique_ptr<float[]> H (new float[curOrder]);
    for (int k = 0; k < curOrder / 2; k++)
    {
        const auto freq = ((float) k * binWidth); // + (binWidth / 2.0f);
        const auto waveNumber = MathConstants<float>::twoPi * jmax (freq, 20.0f) / (*speed * 0.0254f);
        const auto thickTimesK = waveNumber * (*thickness * (float) 1.0e-3);
        const auto kGapOverTwo = waveNumber * (*gap * (float) 1.0e-3) / 2.0f;

        H[k] = expf (-1.0f * waveNumber * (*spacing * (float) 1.0e-3)); // Spacing loss formula
        H[k] *= (1.0f - expf (-thickTimesK)) / thickTimesK;
        H[k] *= sinf (kGapOverTwo) / kGapOverTwo;
        H[curOrder - k - 1] = H[k];
    }

    // Create time domain filter signals
    auto h = currentCoefs.getRawDataPointer();
    for (int n = 0; n < curOrder; n++)
    {
        for (int k = 0; k < curOrder; k++)
            h[n] += H[k] * cosf (MathConstants<float>::twoPi * (float) k * (float) n / (float) curOrder);

        h[n] /= (float) curOrder;
    }
}

void LossFilter::processBlock (float* buffer, const int numSamples)
{
    if (*spacing == (float) 1.0e-6 && *thickness == (float) 1.0e-6 && *gap == (float) 1.0e-6
        && *spacing == prevSpacing && *thickness == prevThickness && *gap == prevGap)
    {
        filters[activeFilter]->processBypassed (buffer, numSamples);
        return;
    }

    if ((*speed != prevSpeed || *spacing != prevSpacing ||
        *thickness != prevThickness || *gap != prevGap) && fadeCount == 0)
    {
        calcCoefs();
        filters[! activeFilter]->setCoefs (currentCoefs.getRawDataPointer());

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

    if (! starting)
        filters[activeFilter]->process (buffer, numSamples);
    else
    {
        starting = false;
        filters[activeFilter]->processBypassed (buffer, numSamples);
    }

    if (fadeCount > 0)
    {
        auto* fadePtr = fadeBuffer.getWritePointer (0);
        filters[! activeFilter]->process (fadePtr, numSamples);

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
}
