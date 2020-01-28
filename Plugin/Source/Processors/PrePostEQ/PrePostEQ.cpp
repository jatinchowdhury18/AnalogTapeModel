#include "PrePostEQ.h"

void PrePostEQ::prepare (double sampleRate, int samplesPerBlock)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        preEQ[ch].setCutoff (20.0f);
        preEQ[ch].reset ((float) sampleRate);

        postEQ[ch].setCutoff (20000.0f);
        postEQ[ch].reset ((float) sampleRate);

        for (int i = 0; i < 6; ++i)
        {
            postEQLow[ch][i].setCutoff (12000.0f);
            postEQLow[ch][i].reset ((float) sampleRate);
        }
    }

    preGain.setGain (Decibels::decibelsToGain (18.0f));
    preGain.prepareToPlay (sampleRate, samplesPerBlock);
    
    postGain.setGain (Decibels::decibelsToGain (54.0f));
    postGain.prepareToPlay (sampleRate, samplesPerBlock);
}

void PrePostEQ::processPreBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    preGain.processBlock (buffer, midiMessages);

    for (int ch = 0; ch < 2; ++ch)
        preEQ[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
}

void PrePostEQ::processPostBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    for (int ch = 0; ch < 2; ++ch)
    {
        for (int i = 0; i < 6; ++i)
            postEQLow[ch][i].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());

        postEQ[ch].processBlock (buffer.getWritePointer (ch), buffer.getNumSamples());
    }
    
    postGain.processBlock (buffer, midiMessages);
}
