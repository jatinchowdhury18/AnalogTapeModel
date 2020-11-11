#ifndef FIRFILTER_H_INCLUDED
#define FIRFILTER_H_INCLUDED

#include "JuceHeader.h"
#include <numeric>

/** FIR filter using a double-buffer and std::inner_product */
class FIRFilter
{
public:
    FIRFilter (int order) :
        order (order)
    {
        h = new float[order];
        z = new float[2 * order];
    }

    ~FIRFilter()
    {
        delete[] h;
        delete[] z;
    }

    void reset()
    {
        zPtr = 0;
        FloatVectorOperations::fill (z, 0.0f, 2 * order);
    }

    void setCoefs (float* coefs)
    {
        FloatVectorOperations::copy (h, coefs, order);
    }

    inline void process (float* buffer, int numSamples)
    {
        float y = 0.0f;
        for (int n = 0; n < numSamples; ++n)
        {
            // insert input into double-buffered state
            z[zPtr] = buffer[n];
            z[zPtr + order] = buffer[n];

#ifdef JUCE_USE_VDSP_FRAMEWORK
            y = 0.0f;
            vDSP_dotpr (z + zPtr, 1, h, 1, &y, order); // use Acclerate inner product (if available)
#else
            y = std::inner_product (z + zPtr, z + zPtr + order, h, 0.0f); // comput inner product
#endif

            zPtr = (zPtr == 0 ? order - 1 : zPtr - 1); // iterate state pointer in reverse
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
