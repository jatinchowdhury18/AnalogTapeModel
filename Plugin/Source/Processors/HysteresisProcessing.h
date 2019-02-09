#ifndef HYSTERESISPROCESSOR_H_INCLUDED
#define HYSTERESISPROCESSOR_H_INCLUDED

#include "JuceHeader.h"

class HysteresisProcessor
{
public:
    HysteresisProcessor();

    float process (float H);

    void setSampleRate (float newSR) { fs = newSR; }

private:

    float langevin (float x);
    float langevinD (float x);
    float deriv (float x_n, float x_n1, float x_d_n1);

    float hysteresisFunc (float M, float H, float H_d);
    float M_n (float M_n1, float k1, float k2, float k3, float k4);

    float fs = 48000.0f;
    const float M_s = 350000.0f;
    const float a = (float) 2.2e4;
    const float alpha = (float) 1.6e-3;
    const float k = (float) 27.0e3;
    const float c = (float) 1.7e-1;

    float M_n1 = 0.0f;
    float H_n1 = 0.0f;
    float H_d_n1 = 0.0f;

    //JUCE_DECLARE_NONCOPYABLE_WITH_LEAK_DETECTOR (HysteresisProcessor)
};

#endif
