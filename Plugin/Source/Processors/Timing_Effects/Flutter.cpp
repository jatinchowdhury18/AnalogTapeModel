#include "Flutter.h"

Flutter::Flutter (AudioProcessorValueTreeState& vts)
{
    rate = vts.getRawParameterValue ("rate");
    depth = vts.getRawParameterValue ("depth");

    depthSlew[0].setCurrentAndTargetValue (*depth);
    depthSlew[1].setCurrentAndTargetValue (*depth);
}

void Flutter::createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params)
{
    params.push_back (std::make_unique<AudioParameterFloat> ("rate",  "Rate",  0.0f, 1.0f, 0.3f));
    params.push_back (std::make_unique<AudioParameterFloat> ("depth", "Depth", 0.0f, 1.0f, 0.0f));
}

void Flutter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    fs = (float) sampleRate;

    delay[0].prepareToPlay (sampleRate, samplesPerBlock);
    delay[1].prepareToPlay (sampleRate, samplesPerBlock);

    delay[0].setLengthMs (0.f);
    delay[1].setLengthMs (0.f);

    depthSlew[0].reset (100);
    depthSlew[1].reset (100);

    phase1[0] = 0.0f;
    phase1[1] = 0.0f;
    phase2[0] = 0.0f;
    phase2[1] = 0.0f;
    phase3[0] = 0.0f;
    phase3[1] = 0.0f;

    amp1     = -230.0f * 1000.0f / (float) sampleRate;
    amp2     = -80.0f  * 1000.0f / (float) sampleRate;
    amp3     = -99.0f  * 1000.0f / (float) sampleRate;
    dcOffset =  350.0f * 1000.0f / (float) sampleRate;
}

void Flutter::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiMessages*/)
{
    ScopedNoDenormals noDenormals;

    auto curDepth = powf (*depth * 81.0f / 625.0f, 0.5f);
    depthSlew[0].setTargetValue (jmax ((float) 1.0e-12, curDepth));
    depthSlew[1].setTargetValue (jmax ((float) 1.0e-12, curDepth));

    auto freq = 0.1f * powf (1000.0f, *rate);
    auto angleDelta1 = MathConstants<float>::twoPi * 1.0f * freq / fs;
    auto angleDelta2 = MathConstants<float>::twoPi * 2.0f * freq / fs;
    auto angleDelta3 = MathConstants<float>::twoPi * 3.0f * freq / fs;

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* x = buffer.getWritePointer (ch);
        for (int n = 0; n < buffer.getNumSamples(); ++n)
        {
            phase1[ch] += angleDelta1;
            phase2[ch] += angleDelta2;
            phase3[ch] += angleDelta3;
            
            auto lfo = amp1 * cosf (phase1[ch] + phaseOff1)
                     + amp2 * cosf (phase2[ch] + phaseOff2)
                     + amp3 * cosf (phase3[ch] + phaseOff3)
                     + dcOffset;

            delay[ch].setLengthMs (depthSlew[ch].getNextValue() * lfo);
            x[n] = delay[ch].delay (x[n]);
        }

        while (phase1[ch] >= MathConstants<float>::twoPi)
            phase1[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
        while (phase2[ch] >= MathConstants<float>::twoPi)
            phase2[ch] -= MathConstants<float>::twoPi;
    }
}
