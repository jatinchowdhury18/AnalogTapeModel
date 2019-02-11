#ifndef SPEEDFILTERPROCESSOR_H_INCLUDED
#define SPEEDFILTERPROCESSOR_H_INCLUDED

#include "../ProcessorBase.h"

class SpeedFilterProcessor : public ProcessorBase
{
public:
    enum
    {
        order = 2,
        maxFreq = 22000,
    };

    SpeedFilterProcessor() : ProcessorBase (String ("Filter Processor")) { initFilter(); }

    void prepareToPlay (double sampleRate, int maxExpectedBlockSize) override;
    void releaseResources() override;
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiBuffer) override;

    void setSpeed (String speed);

    void setFreq (float newFreq);
    float getFreq() const { return cutoffFreq; }

private:
    void initFilter();
    void clearIOs();
    void resetArrays();

    void calcCoefs();
    void setCoefs (float* as, float* bs);

    float filter (int channel, float x);

    float cutoffFreq = (float) maxFreq;
    const float Q = 0.707f;
    const float gain = 1.0f;

    std::unique_ptr<float[]> a;	// a0, a1, a2 (a0 is usually 1)
    std::unique_ptr<float[]> b; // b0, b1, b2
    std::unique_ptr<std::unique_ptr<float[]> []> filterIOs; //x1, x2, y1, y2

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpeedFilterProcessor)
};

#endif // !SPEEDFILTERPROCESSOR_H_INCLUDED
