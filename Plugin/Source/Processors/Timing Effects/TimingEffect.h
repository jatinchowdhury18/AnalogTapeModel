#ifndef TIMINGEFFECT_H_INCLUDED
#define TIMINGEFFECT_H_INCLUDED

#include "../ProcessorBase.h"

class TimingEffect : public ProcessorBase
{
public:
    TimingEffect();

    void prepareToPlay (double sampleRate, int maxExpectedBlockSize) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& /*midiBuffer*/) override;

    void setLength (int channel, int length);
    int getLength (int channel) const;

    void setDepth (float newDepth);
    void setTapeSpeed (String tapeSpeed);

    double getTailLengthSeconds() const override;

private:
    enum
    {
        maxDelaySamples = 600 * 10,
        polyOrder = 10,
        periodLen = 490,
    };

    struct DelayChannel
    {
        LinearSmoothedValue<float> length = 0.0f;
        int readPtr = 0;

        void resetPtrs() { readPtr = 0; }
        void setReadPtr (int maxLength);
    };

    DelayChannel dChannels[2];

    AudioBuffer<float> delayBuffer;

    float delay (int channel, float x);
    void updateDelay();
    void resetDelay();

    float coefs[polyOrder+1] = { 5.06485313f, 2.45320771f, (float) 5.90645745e-2,
                                 (float) -3.05750415e-4, (float) -1.16380361e-5, (float) 1.95163044e-7,
                                 (float) -1.36154581e-9, (float) 5.11840498e-12, (float) -1.08010214e-14,
                                 (float) 1.20503554e-17, (float) -5.53696539e-21 };
    int n = 0;
    int numSamplesFreq = 0;
    int countFreq = 0;

    float freq = 10.0f;
    float depth = 1.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimingEffect)
};

#endif //TIMINGEFFECT_H_INCLUDED
