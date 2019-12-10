#include "HysteresisProcessing.h"
#include <math.h>

inline int sign (float x)
{
    return (x > 0.0f) - (x < 0.0f);
}

HysteresisProcessing::HysteresisProcessing()
{
}

void HysteresisProcessing::reset()
{
    M_n1 = 0.0f;
    H_n1 = 0.0f;
    H_d_n1 = 0.0f;

    coth = 0.0f;
    nearZero = false;
}

void HysteresisProcessing::cook (float drive,  float width, float sat)
{
    M_s = 0.5f + 1.5f * (1.0f - sat);
    a = M_s / (0.01f + 6.0f * drive);
    c = sqrtf (1.0f - width) - 0.01f;

    nc = 1.0f - c;
    M_s_oa = M_s / a;
    M_s_oa_tc = c * M_s_oa;
    M_s_oa_tc_talpha = alpha * M_s_oa_tc;
}

inline float HysteresisProcessing::cothApprox (float x)
{
    const auto exp_2x = expf (2.0f * x); // expf_approx (2.0f * x);

    return (exp_2x + 1.0f) / (exp_2x - 1.0f);

    // const auto xSquare = x * x;

    // return (1.0f + (xSquare / (3.0f + (xSquare / (5.0f + (xSquare / (7.0f))))))) / x;
    // return (1.0f + (xSquare / (3.0f + (xSquare / (5.0f))))) / x;
    // return (1.0f + (xSquare / 3.0f)) / x;
}

inline float HysteresisProcessing::langevin (float x)
{
    if (! nearZero)
        return (coth) - (1.0f / x);
    else
        return (x / 3.0f);
}

inline float HysteresisProcessing::langevinD (float x)
{
    if (! nearZero)
        return (1.0f / (x * x)) - (coth * coth) + 1.0f;
    else
        return (1.0f / 3.0f);
}

inline float HysteresisProcessing::deriv (float x_n, float x_n1, float x_d_n1)
{
    return (twoFs * (x_n - x_n1)) - x_d_n1;
}

inline float HysteresisProcessing::hysteresisFunc (float M, float H, float H_d)
{
    Q = (H + alpha * M) / a;
    coth = 1.0f /  dsp::FastMathApproximations::tanh (Q);
    nearZero = Q < 0.001f && Q > -0.001f;

    M_diff = M_s * langevin (Q) - M;

    delta = (float) ((H_d >= 0.0f) - (H_d < 0.0f));
    delta_M = (float) (sign (delta) == sign (M_diff));

    L_prime = langevinD (Q);

    // const float denominator = 1 - (c * alpha * (M_s / a) * L_prime);
    // 
    // const float t1_num = (1 - c) * delta_M * M_diff;
    // const float t1_den = ((1 - c) * delta * k) - (alpha * M_diff);
    // const float t1 = (t1_num / t1_den) * H_d;
    // 
    // const float t2 = c * (M_s / a) * H_d * L_prime;
    // 
    // return (t1 + t2) / denominator;
    return H_d * (((nc * delta_M * M_diff) / ((nc * delta * k) - (alpha * M_diff))) + (M_s_oa_tc * L_prime)) / (1.0f - (M_s_oa_tc_talpha * L_prime));
}

float HysteresisProcessing::M_n (float prevM, float k1, float k2, float k3, float k4)
{
    return prevM + (k1 / 6.0f) + (k2 / 3.0f) + (k3 / 3.0f) + (k4 / 6.0f);
}

float HysteresisProcessing::process (float H)
{
    float H_d = deriv (H, H_n1, H_d_n1);

    const float k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const float k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0f), (H + H_n1) / 2.0f, (H_d + H_d_n1) / 2.0f);

    float M = M_n1 + k2;

    if (std::isnan (M))
    {
        M = 0.0f;
        H = 0.0f;
        H_d = 0.0f;
    }

    M_n1 = M;
    H_n1 = H;
    H_d_n1 = H_d;

    return M;
}
