#include "SpeedFilterProcessor.h"

void SpeedFilterProcessor::initFilter()
{
    resetArrays();
    calcCoefs();
    clearIOs();
}

void SpeedFilterProcessor::resetArrays()
{
    a.reset (new float[order + 1]);
    b.reset (new float[order + 1]);

    const int numChannels = 2; //getTotalNumOutputChannels();
    filterIOs.reset (new std::unique_ptr<float[]> [numChannels]);
    for (int ch = 0; ch < numChannels; ch++)
        filterIOs[ch].reset (new float[order * numChannels]);
}

void SpeedFilterProcessor::clearIOs()
{
    for (int ch = 0; ch < 2 /*getTotalNumOutputChannels()*/; ch++)
        for (int samp = 0; samp < 4; samp++)
            filterIOs[ch][samp] = 0.0f;
}

void SpeedFilterProcessor::calcCoefs()
{
    float alpha = tanf (MathConstants<float>::pi * cutoffFreq / (float) getSampleRate());
    float alphaSquared = alpha * alpha;
    float K = alphaSquared + alpha / Q + 1.0f;
    
    // b0, b1, b2 for setCoefs()
    float coef0 = alphaSquared * gain / K;
    float bs[] = { coef0,        // *x0 
                   2.0f * coef0, // *x1 
                   coef0,        // *x2
                 };

    // a0, a1, a2 for setCoefs()
    float coef1 = (2.0f * (alphaSquared - 1.0f)) / K;
    float coef2 = (alphaSquared - alpha/Q + 1.0f) / K;
    float as[] = { 1.0f,    // *y0 (usually 1) 
                   coef1,   // *y1 
                   coef2    // *y2
                 };

    setCoefs(as, bs);
}

void SpeedFilterProcessor::setCoefs (float* as, float* bs)
{
    for (int i = 0; i < order + 1; i++)
    {
        a[i] = as[i];
        b[i] = bs[i];
    }
}

void SpeedFilterProcessor::prepareToPlay (double sampleRate, int maxExpectedBlockSize)
{
    setRateAndBufferSizeDetails (sampleRate, maxExpectedBlockSize);
    initFilter();
}

void SpeedFilterProcessor::releaseResources()
{
    clearIOs();
}

void SpeedFilterProcessor::setSpeed (String speed)
{
    if (speed == "3.75 ips")
        setFreq (12000);
    else if (speed == "7.5 ips")
        setFreq (15000);
    else if (speed == "15 ips")
        setFreq (18000);
}

void SpeedFilterProcessor::setFreq (float newFreq)
{
    cutoffFreq = newFreq;
    calcCoefs();
}

void SpeedFilterProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/)
{
    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        float* x = buffer.getWritePointer(channel);
        for (int n = 0; n < buffer.getNumSamples(); n++)
            x[n] = filter (channel, x[n]);  
    }
}

float SpeedFilterProcessor::filter (int ch, float x)
{
    float y = b[0] * x + b[1] * filterIOs[ch][0] + b[2] * filterIOs[ch][1]
            - a[1] * filterIOs[ch][2] - a[2] * filterIOs[ch][3];

    //update I/O's
    filterIOs[ch][3] = filterIOs[ch][2]; //y2 = y1
    filterIOs[ch][1] = filterIOs[ch][0]; //x2 = x1
    filterIOs[ch][2] = y;	             //y1 = y
    filterIOs[ch][0] = x;	             //x1 = x

    jassert (abs(y) < 1.0f);

    return y;
}
