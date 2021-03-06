#include "FlutterProcess.h"

void FlutterProcess::prepare (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    for (int ch = 0; ch < 2; ++ch)
    {
        depthSlew[ch].reset (sampleRate, 0.05);
        depthSlew[ch].setCurrentAndTargetValue (depthSlewMin);

        phase1[ch] = 0.0f;
        phase2[ch] = 0.0f;
        phase3[ch] = 0.0f;
    }

    amp1 = -230.0f * 1000.0f / fs;
    amp2 = -80.0f * 1000.0f / fs;
    amp3 = -99.0f * 1000.0f / fs;
    dcOffset = 350.0f * 1000.0f / fs;

    flutterBuffer.setSize (2, samplesPerBlock);
}

void FlutterProcess::prepareBlock (float curDepth, float flutterFreq, int numSamples)
{
    depthSlew[0].setTargetValue (jmax (depthSlewMin, curDepth));
    depthSlew[1].setTargetValue (jmax (depthSlewMin, curDepth));

    angleDelta1 = MathConstants<float>::twoPi * 1.0f * flutterFreq / fs;
    angleDelta2 = MathConstants<float>::twoPi * 2.0f * flutterFreq / fs;
    angleDelta3 = MathConstants<float>::twoPi * 3.0f * flutterFreq / fs;

    flutterBuffer.setSize (2, numSamples, false, false, true);
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
