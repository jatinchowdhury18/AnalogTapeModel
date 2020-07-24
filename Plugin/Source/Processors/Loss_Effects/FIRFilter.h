#ifndef FIRFILTER_H_INCLUDED
#define FIRFILTER_H_INCLUDED

#include "JuceHeader.h"
#include <numeric>

class FIRFilter
{
public:
    FIRFilter (int order) :
        order (order)
    {
        h = new float[order];
        z = new float[order];
    }

    ~FIRFilter()
    {
        delete[] h;
        delete[] z;
    }

    void reset()
    {
        zPtr = 0;
        std::fill (z, &z[order], 0.0f);
    }

    void setCoefs (float* coefs)
    {
        std::copy (coefs, &coefs[order], h);
    }

    inline void process (float* buffer, int numSamples)
    {
        float y = 0.0f;
        for (int n = 0; n < numSamples; ++n)
        {
            z[zPtr] = buffer[n];

            y = std::inner_product (z + zPtr, z + order, h, 0.0f);
            y = std::inner_product (z, z + zPtr, h + (order - zPtr), y);

            zPtr = (zPtr == 0 ? order - 1 : zPtr - 1);
            buffer[n] = y;
        }
    }

    inline void processBypassed (float* buffer, int numSamples)
    {
        for (int n = 0; n < numSamples; ++n)
        {
            z[zPtr] = buffer[n];
            zPtr = (zPtr == 0 ? order - 1 : zPtr - 1);
        }
    }

protected:
    float* h;
    const int order;

private:
    float* z;
    int zPtr = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FIRFilter)
};

#endif //FIRFILTER_H_INCLUDED
