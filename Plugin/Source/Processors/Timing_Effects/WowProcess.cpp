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
}

void WowProcess::prepareBlock (float curDepth, float wowFreq, int numSamples)
{
    depthSlew[0].setTargetValue (jmax (depthSlewMin, curDepth));
    depthSlew[1].setTargetValue (jmax (depthSlewMin, curDepth));
    angleDelta = MathConstants<float>::twoPi * wowFreq / fs;

    wowBuffer.setSize (2, numSamples, false, false, true);
    wowBuffer.clear();
    wowPtrs = wowBuffer.getArrayOfWritePointers();
}

void WowProcess::plotBuffer (foleys::MagicPlotSource* plot)
{
    wowBuffer.applyGain (0.83333f / amp);
    plot->pushSamples (wowBuffer);
}
