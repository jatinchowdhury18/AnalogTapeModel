#include "WowProcess.h"

void WowProcess::prepare (double sampleRate, int samplesPerBlock, int numChannels)
{
    fs = (float) sampleRate;

    depthSlew.resize ((size_t) numChannels);
    for (auto& dSlew : depthSlew)
    {
        dSlew.reset (sampleRate, 0.05);
        dSlew.setCurrentAndTargetValue (depthSlewMin);
    }

    phase.resize ((size_t) numChannels, 0.0f);

    amp = 1000.0f * 1000.0f / (float) sampleRate;
    wowBuffer.setSize (numChannels, samplesPerBlock);

    ohProc.prepare (sampleRate, samplesPerBlock, numChannels);
}

void WowProcess::prepareBlock (float curDepth, float wowFreq, float wowVar, float wowDrift, int numSamples, int numChannels)
{
    for (auto& dSlew : depthSlew)
        dSlew.setTargetValue (jmax (depthSlewMin, curDepth));

    auto freqAdjust = wowFreq * (1.0f + std::pow (driftRand.nextFloat(), 1.25f) * wowDrift);
    angleDelta = MathConstants<float>::twoPi * freqAdjust / fs;

    wowBuffer.setSize (numChannels, numSamples, false, false, true);
    wowBuffer.clear();
    wowPtrs = wowBuffer.getArrayOfWritePointers();

    ohProc.prepareBlock (wowVar, numSamples);
}

void WowProcess::plotBuffer (foleys::MagicPlotSource* plot)
{
    if (shouldTurnOff())
        wowBuffer.clear();

    wowBuffer.applyGain (0.83333f / amp);
    plot->pushSamples (wowBuffer);
}
