#ifndef TONEFILTER_H_INCLUDED
#define TONEFILTER_H_INCLUDED

#include "../IIRFilter.h"
#include "../BilinearUtils.h"

/** A first order shelving filter, with a set gain at DC,
* a set gain at high frequencies, and a transition frequency.
*/
class ToneFilter : public chowdsp::IIRFilter<1>
{
public:
    ToneFilter() = default;

    /** Calculates the coefficients for the filter.
    * @param lowGain: the gain of the filter at low frequencies
    * @param highGain: the gain of the filter at high frequencies
    * @param fc: the transition frequency of the filter
    * @param fs: the sample rate for the filter
    */
    void calcCoefs (float lowGain, float highGain, float fc, float fs)
    {
        // reduce to simple gain element
        if (lowGain == highGain)
        {
            this->b[0] = lowGain; this->b[1] = 0.0f;
            this->a[0] = 1.0f; this->a[1] = 0.0f;
            return;
        }

        auto wc = MathConstants<float>::twoPi * fc;
        auto p = std::sqrt (wc*wc * (highGain*highGain - lowGain*highGain) / (lowGain*highGain - lowGain*lowGain));
        auto K = p / std::tan (p / (2.0f * fs));

        float bs[2] { highGain / p, lowGain };
        float as[2] { 1.0f / p, 1.0f };
        Bilinear::BilinearTransform<float, 2>::call (this->b, this->a, bs, as, K);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneFilter)
};

#endif // TONEFILTER_H_INCLUDED
