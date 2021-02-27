#include "WowProcess.h"

void WowProcess::prepare (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    for (int ch = 0; ch < 2; ++ch)
    {
        depthSlew[ch].reset (sampleRate, 0.05);
        depthSlew[ch].setCurrentAndTargetValue (depthSlewMin);
        phase[ch] = 0.0f;
    }

    amp = 1000.0f * 1000.0f / (float) sampleRate;
    wowBuffer.setSize (2, samplesPerBlock);

    ohProc.prepare (sampleRate, samplesPerBlock);
}

void WowProcess::prepareBlock (float curDepth, float wowFreq, float wowVar, float wowDrift, int numSamples)
{
    depthSlew[0].setTargetValue (jmax (depthSlewMin, curDepth));
    depthSlew[1].setTargetValue (jmax (depthSlewMin, curDepth));

    auto freqAdjust = wowFreq * (1.0f + std::pow (driftRand.nextFloat(), 1.25f) * wowDrift);
    angleDelta = MathConstants<float>::twoPi * freqAdjust / fs;

    wowBuffer.setSize (2, numSamples, false, false, true);
    wowBuffer.clear();
    wowPtrs = wowBuffer.getArrayOfWritePointers();

    ohProc.prepareBlock (wowVar, numSamples);
}

void WowProcess::plotBuffer (foleys::MagicPlotSource* plot)
{
    wowBuffer.applyGain (0.83333f / amp);
    plot->pushSamples (wowBuffer);
}
