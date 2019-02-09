#include "HysteresisProcessing.h"
#include <math.h>

HysteresisProcessor::HysteresisProcessor()
{

}

float HysteresisProcessor::langevin (float x)
{
    if (std::abs (x) > (float) (10e-4))
        return (1.0f / (float) tanh (x)) - (1.0f / x);
    else
        return (x / 3.0f);
}

float HysteresisProcessor::langevinD (float x)
{
    if (std::abs (x) > (float) (10e-4))
    {
        float tanhRecip = 1.0f / tanh (x);
        return (1.0f / (x * x)) - (tanhRecip * tanhRecip) + 1.0f;
    }
    else
        return (1.0f / 3.0f);
}

float HysteresisProcessor::deriv (float x_n, float x_n1, float x_d_n1)
{
    return ((2.0f * fs) * (x_n - x_n1)) - x_d_n1;
}

float HysteresisProcessor::hysteresisFunc (float M, float H, float H_d)
{
    const float Q = (H + alpha * M) / a;
    const float M_diff = M_s * langevin (Q) - M;

    const float delta = H_d > 0 ? 1.0f : -1.0f;
    const float delta_M = signbit (delta) == signbit (M_diff) ? 1.0f : 0.0f;

    const float L_prime = langevinD (Q);

    const float denominator = 1 - (c * alpha * (M_s / a) * L_prime);

    const float t1_num = (1 - c) * delta_M * M_diff;
    const float t1_den = ((1 - c) * delta * k) - (alpha * M_diff);
    const float t1 = (t1_num / t1_den) * H_d;

    const float t2 = c * (M_s / a) * H_d * L_prime;

    return (t1 + t2) / denominator;
}

float HysteresisProcessor::M_n (float prevM, float k1, float k2, float k3, float k4)
{
    return prevM + (k1 / 6.0f) + (k2 / 3.0f) + (k3 / 3.0f) + (k4 / 6.0f);
}

float HysteresisProcessor::process (float H)
{
    const float H_d = deriv (H, H_n1, H_d_n1);

    const float T = (1.0f / fs);
    const float k1 = T * hysteresisFunc (M_n1, H_n1, H_d_n1);
    const float k2 = T * hysteresisFunc (M_n1 + (k1 / 2.0f), (H + H_n1) / 2.0f, (H_d + H_d_n1) / 2.0f);
    const float k3 = T * hysteresisFunc (M_n1 + (k2 / 2.0f), (H + H_n1) / 2.0f, (H_d + H_d_n1) / 2.0f);
    const float k4 = T * hysteresisFunc (M_n1 + k3, H, H_d);

    const float M = M_n (M_n1, k1, k2, k3, k4);

    M_n1 = M;
    H_n1 = H;
    H_d_n1 = H_d;

    return M / M_s;
}
