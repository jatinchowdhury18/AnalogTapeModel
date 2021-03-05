#ifndef AZIMUTHPROC_H_INCLUDED
#define AZIMUTHPROC_H_INCLUDED

#include <JuceHeader.h>

class AzimuthProc
{
public:
    AzimuthProc() = default;

    void prepare (double sampleRate, int samplesPerBlock);
    void setAzimuthAngle (float angleDeg, float tapeSpeedIps);
    void processBlock (AudioBuffer<float>& buffer);

private:
    using ADelayLine = dsp::DelayLine<float, dsp::DelayLineInterpolationTypes::Lagrange3rd>;
    std::unique_ptr<ADelayLine> delays[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AzimuthProc)
};

#endif // AZIMUTHPROC_H_INCLUDED
