#ifndef FIRFILTER_H_INCLUDED
#define FIRFILTER_H_INCLUDED

// include <Accelerate> on Apple devices so we can use vDSP_dotpr
#if JUCE_MAC || JUCE_IOS
#define Point CarbonDummyPointName
#define Component CarbonDummyCompName
#include <Accelerate/Accelerate.h>
#undef Point
#undef Component
#endif

#include <JuceHeader.h>
#include <numeric>

/** FIR filter using a double-buffer and std::inner_product */
class FIRFilter
{
public:
    FIRFilter (int filter_order) : order ((size_t) filter_order)
    {
        h.resize (order);
        z.resize (2 * order);
    }

    FIRFilter (FIRFilter&&) noexcept = default;

    void reset()
    {
        zPtr = 0;
        FloatVectorOperations::fill (z.data(), 0.0f, 2 * (int) order);
    }

    void setCoefs (float* coefs)
    {
        FloatVectorOperations::copy (h.data(), coefs, (int) order);
    }

    inline void process (float* buffer, int numSamples)
    {
        float y = 0.0f;
        for (int n = 0; n < numSamples; ++n)
        {
            // insert input into double-buffered state
            z[zPtr] = buffer[n];
            z[zPtr + order] = buffer[n];

#if JUCE_MAC || JUCE_IOS
            y = 0.0f;
            vDSP_dotpr (z.data() + zPtr, 1, h.data(), 1, &y, order); // use Acclerate inner product (if available)
#else
            y = std::inner_product (z.data() + zPtr, z.data() + zPtr + order, h.data(), 0.0f); // comput inner product
#endif

            zPtr = (zPtr == 0 ? order - 1 : zPtr - 1); // iterate state pointer in reverse
            buffer[n] = y;
        }
    }

    inline void processBypassed (const float* buffer, int numSamples)
    {
        for (int n = 0; n < numSamples; ++n)
        {
            z[zPtr] = buffer[n];
            z[zPtr + order] = buffer[n];
            zPtr = (zPtr == 0 ? order - 1 : zPtr - 1);
        }
    }

protected:
    std::vector<float> h;
    const size_t order;

private:
    std::vector<float> z;
    size_t zPtr = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FIRFilter)
};

#endif //FIRFILTER_H_INCLUDED
