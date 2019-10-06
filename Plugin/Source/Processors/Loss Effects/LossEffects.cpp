#include "LossEffects.h"

LossEffects::LossEffects()
{}

void LossEffects::init (float sampleRate, float speed, float spacing, float thickness, float gap)
{
    const auto numBins = sampleRate / (float) order;
    const auto binWidth = sampleRate / numBins;
    const auto speedMetric = speed * inchesToMeters;

    // Set freq domain multipliers
    float H[order];
    for (int k = 0; k < order / 2; k++)
    {
        const auto freq = ((float) k * binWidth) + (binWidth / 2.0f);
        const auto waveNumber = MathConstants<float>::twoPi * freq / speedMetric;

        const auto spacingLoss = expf (-1.0f * waveNumber * spacing);
        const auto gapLoss = sinf (waveNumber * gap / 2.0f) / (waveNumber * gap / 2.0f);
        const auto thicknessLoss = (1.0f - expf (-waveNumber * thickness)) / (waveNumber * thickness);

        H[k] = spacingLoss * gapLoss * thicknessLoss;
        H[order - k - 1] = H[k];
    }

    // Create time domain filter signals
    for (int n = 0; n < order; n++)
    {
        h[n] = 0;
        for (int k = 0; k < order; k++)
            h[n] += H[k] * cosf (MathConstants<float>::twoPi * (float) k * (float) n / (float) order);

        h[n] /= (float) order;
    }

    // Clear xs
    xPtr = 0;
    for (int n = 0; n < order; n++)
        x[n] = 0;
}

float LossEffects::process (float in)
{
    float y = 0.0f;
    x[xPtr]= in;
    for (int n = 0; n < order; n++)
        y += h[n] * x[negativeAwareModulo<int> (xPtr - n, order)];

    xPtr = (xPtr + 1) % order;

    return y;
}
