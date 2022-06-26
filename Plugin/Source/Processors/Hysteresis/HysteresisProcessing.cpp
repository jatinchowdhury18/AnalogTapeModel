#include "HysteresisProcessing.h"
#include <cmath>

HysteresisProcessing::HysteresisProcessing()
{
}

void HysteresisProcessing::reset()
{
    M_n1 = 0.0;
    H_n1 = 0.0;
    H_d_n1 = 0.0;

    hpState.coth = 0.0;
    hpState.nearZero = false;
}

void HysteresisProcessing::setSampleRate (double newSR)
{
    fs = newSR;
    T = 1.0 / fs;
    Talpha = T / 1.9;
    hysteresisSTN.prepare (newSR);
}

void HysteresisProcessing::cook (double drive, double width, double sat, bool v1)
{
    hysteresisSTN.setParams ((float) sat, (float) width);

    hpState.M_s = 0.5 + 1.5 * (1.0 - sat);
    hpState.a = hpState.M_s / (0.01 + 6.0 * drive);
    hpState.c = std::sqrt (1.0f - width) - 0.01;
    hpState.k = 0.47875;
    upperLim = 20.0;

    if (v1)
    {
        hpState.k = 27.0e3;
        hpState.c = 1.7e-1;
        hpState.M_s *= 50000.0;
        hpState.a = hpState.M_s / (0.01 + 40.0 * drive);
        upperLim = 100000.0;
    }

    hpState.nc = 1.0 - hpState.c;
    hpState.M_s_oa = hpState.M_s / hpState.a;
    hpState.M_s_oa_talpha = HysteresisOps::HysteresisState::alpha * hpState.M_s_oa;
    hpState.M_s_oa_tc = hpState.c * hpState.M_s_oa;
    hpState.M_s_oa_tc_talpha = HysteresisOps::HysteresisState::alpha * hpState.M_s_oa_tc;
    hpState.M_s_oaSq_tc_talpha = hpState.M_s_oa_tc_talpha / hpState.a;
    hpState.M_s_oaSq_tc_talphaSq = HysteresisOps::HysteresisState::alpha * hpState.M_s_oaSq_tc_talpha;
}
