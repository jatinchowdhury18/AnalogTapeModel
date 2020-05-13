#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "HysteresisProcessing.h"

/* High-pass filter to compensate for low frequency noise of transformer */
class TransformerHPF
{
public:
    TransformerHPF() {}

    void reset (double sampleRate)
    {
        for (int n = 0; n < 3; ++n)
            z[n] = 0.0f;

        fs = (float) sampleRate;
    }

    void calcCoefs (float fc, float Q)
    {
        float wc = MathConstants<float>::twoPi * fc / fs;
        float c = 1.0f / dsp::FastMathApproximations::tan (wc / 2.0f);
        float phi = c * c;
        float K = c / Q;
        float a0 = phi + K + 1.0f;

        b[0] = phi / a0;
        b[1] = -2.0f * b[0];
        b[2] = b[0];
        a[1] = 2.0f * (1.0f - phi) / a0;
        a[2] = (phi - K + 1.0f) / a0;
    }

    inline float processSample (float x)
    {
        // direct form II transposed
        float y = z[1] + x * b[0];

        z[1] = z[2] + x*b[1] - y*a[1];
        z[2] = x*b[2] - y*a[2];

        return y;
    }

private:
    float a[3] = { 0.0f, 0.0f, 0.0f };
    float b[3] = { 1.0f, 0.0f, 0.0f };

    float z[3] = { 0.0f, 0.0f, 0.0f };

    float fs = 44100.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransformerHPF)
};

/* Low-shelf filter to compensate for low frequency noise of transformer 
class TransformerShelf
{
public:
    TransformerShelf() {}

    void reset (double sampleRate)
    {
        for (int n = 0; n < 3; ++n)
            z[n] = 0.0f;

        fs = (float) sampleRate;
    }

    void calcCoefs (float fc, float Q, float gain)
    {
        float A = sqrtf (gain);
        float wc = MathConstants<float>::twoPi * fc / fs;
        float wS = dsp::FastMathApproximations::sin (wc);
        float wC = dsp::FastMathApproximations::cos (wc);
        float beta = sqrtf (A) / Q;

        float a0 = ((A+1.0f) + ((A-1.0f) * wC) + (beta*wS));

        b[0] = A*((A+1.0f) - ((A-1.0f)*wC) + (beta*wS)) / a0;
        b[1] = 2.0f*A * ((A-1.0f) - ((A+1.0f)*wC)) / a0;
        b[2] = A*((A+1.0f) - ((A-1.0f)*wC) - (beta*wS)) / a0;

        a[1] = -2.0f * ((A-1.0f) + ((A+1.0f)*wC)) / a0;
        a[2] = ((A+1.0f) + ((A-1.0f)*wC)-(beta*wS)) / a0;
    }

    inline float processSample (float x)
    {
        // direct form II transposed
        float y = z[1] + x * b[0];

        z[1] = z[2] + x*b[1] - y*a[1];
        z[2] = x*b[2] - y*a[2];

        return y;
    }

private:
    float a[3] = { 0.0f, 0.0f, 0.0f };
    float b[3] = { 1.0f, 0.0f, 0.0f };

    float z[3] = { 0.0f, 0.0f, 0.0f };

    float fs = 44100.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransformerShelf)
};
*/

//=============================================================
/* Hysteresis Processor for transformer. */
class HysteresisProcessor
{
public:
    HysteresisProcessor (AudioProcessorValueTreeState& vts);

    /* Reset fade buffers, filters, and processors. Prepare oversampling */
    void prepareToPlay (double sampleRate, int samplesPerBlock);

    /* Reset oversampling */
    void releaseResources();

    /* Proceess a buffer. */
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer);

    void toggleOnOff (bool shouldBeOn);

    static void createParameterLayout (std::vector<std::unique_ptr<RangedAudioParameter>>& params);

    void setDrive (float newDrive);
    void setSaturation (float newSat);
    void setWidth (float newWidth);
    float calcMakeup();

private:
    std::atomic<float>* driveParam = nullptr;
    std::atomic<float>* satParam = nullptr;
    std::atomic<float>* widthParam = nullptr;
    std::atomic<float>* osParam = nullptr;

    SmoothedValue<float, ValueSmoothingTypes::Linear> drive[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> width[2];
    SmoothedValue<float, ValueSmoothingTypes::Linear> sat[2];
    SmoothedValue<float, ValueSmoothingTypes::Multiplicative> makeup[2];

    float fs = 44100.0f;
    int prevOS = 0;
    HysteresisProcessing hProcs[2];
    std::unique_ptr<dsp::Oversampling<float>> overSample[5]; // needs oversampling to avoid aliasing
    TransformerHPF dcBlocker[2];
    // TransformerShelf dcLower[2];

    AudioBuffer<float> fadeBuffer;
    bool isOn = false;
    bool isChanging = true;

    int overSamplingFactor = 2;
    const float dcFreq = 10.0f;
    const float dcShelfFreq = 60.0f;

    int resetCount = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif //HYSTERESISPROCESSOR_H_INCLUDED
