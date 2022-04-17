#include "FlutterProcess.h"

void FlutterProcess::prepare (double sampleRate, int samplesPerBlock, int numChannels)
{
    fs = (float) sampleRate;

    depthSlew.resize ((size_t) numChannels);
    for (auto& dSlew : depthSlew)
    {
        dSlew.reset (sampleRate, 0.05);
        dSlew.setCurrentAndTargetValue (depthSlewMin);
    }

    phase1.resize ((size_t) numChannels, 0.0f);
    phase2.resize ((size_t) numChannels, 0.0f);
    phase3.resize ((size_t) numChannels, 0.0f);

    amp1 = -230.0f * 1000.0f / fs;
    amp2 = -80.0f * 1000.0f / fs;
    amp3 = -99.0f * 1000.0f / fs;
    dcOffset = 350.0f * 1000.0f / fs;

    flutterBuffer.setSize (numChannels, samplesPerBlock);
}

void FlutterProcess::prepareBlock (float curDepth, float flutterFreq, int numSamples, int numChannels)
{
    for (auto& dSlew : depthSlew)
        dSlew.setTargetValue (jmax (depthSlewMin, curDepth));

    angleDelta1 = MathConstants<float>::twoPi * flutterFreq / fs;
    angleDelta2 = 2.0f * angleDelta1;
    angleDelta3 = 3.0f * angleDelta1;

    flutterBuffer.setSize (numChannels, numSamples, false, false, true);
    flutterBuffer.clear();
    flutterPtrs = flutterBuffer.getArrayOfWritePointers();
}

void FlutterProcess::plotBuffer (foleys::MagicPlotSource* plot)
{
    if (shouldTurnOff())
        flutterBuffer.clear();

    flutterBuffer.applyGain (1.3333f / amp1);
    plot->pushSamples (flutterBuffer);
}
