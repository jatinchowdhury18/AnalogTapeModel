#pragma once

#include <JuceHeader.h>
#include <RTNeural/RTNeural.h>

#define USE_RTNEURAL_POLY 0
#define USE_RTNEURAL_STATIC 1

namespace STNSpace
{
using v_type = dsp::SIMDRegister<double>;
constexpr auto v_size = v_type::SIMDNumElements;
static_assert (v_size == 2, "SIMD double size is required to be 2.");

class Dense54
{
public:
    Dense54();

    void setWeights (std::vector<std::vector<double>>& w);
    void setBias (std::vector<double>& b);

    inline void forward (const double* input) noexcept
    {
        ins[0] = v_type::fromRawArray (input);
        ins[1] = v_type::fromRawArray (input + v_size);
        ins[2] = v_type::fromRawArray (input + 2 * v_size);

        outs[0] = v_type (0.0);
        outs[1] = v_type (0.0);
        for (size_t k = 0; k < 3; ++k)
        {
            // output 0
            outs[0].set (0, outs[0].get (0) + (ins[k] * weights[0 * out_size + k]).sum());
            // output 1
            outs[0].set (1, outs[0].get (1) + (ins[k] * weights[1 * out_size + k]).sum());
            // output 2
            outs[1].set (0, outs[1].get (0) + (ins[k] * weights[2 * out_size + k]).sum());
            // output 3
            outs[1].set (1, outs[1].get (1) + (ins[k] * weights[3 * out_size + k]).sum());
        }

        outs[0] += bias[0];
        outs[1] += bias[1];
    }

    v_type outs[2];

private:
    static constexpr size_t in_size = 5;
    static constexpr size_t out_size = 4;

    v_type ins[3];
    v_type bias[2];
    v_type weights[16];
};

//===========================================================
class Dense44
{
public:
    Dense44();

    void setWeights (std::vector<std::vector<double>>& w);
    void setBias (std::vector<double>& b);

    inline void forward (const v_type* ins) noexcept
    {
        outs[0] = v_type (0.0);
        outs[1] = v_type (0.0);
        for (size_t k = 0; k < 2; ++k)
        {
            // output 0
            outs[0].set (0, outs[0].get (0) + (ins[k] * weights[0 * out_size + k]).sum());
            // output 1
            outs[0].set (1, outs[0].get (1) + (ins[k] * weights[1 * out_size + k]).sum());
            // output 2
            outs[1].set (0, outs[1].get (0) + (ins[k] * weights[2 * out_size + k]).sum());
            // output 3
            outs[1].set (1, outs[1].get (1) + (ins[k] * weights[3 * out_size + k]).sum());
        }

        outs[0] += bias[0];
        outs[1] += bias[1];
    }

    v_type outs[2];

private:
    static constexpr size_t in_size = 4;
    static constexpr size_t out_size = 4;

    v_type bias[2];
    v_type weights[16];
};

//===========================================================
class Dense41
{
public:
    Dense41();

    void setWeights (std::vector<std::vector<double>>& w);
    void setBias (std::vector<double>& b);

    inline double forward (const v_type* ins) const noexcept
    {
        double out = 0.0;
        for (size_t k = 0; k < 2; ++k)
            out += (ins[k] * weights[k]).sum();

        return out + bias;
    }

private:
    static constexpr size_t in_size = 4;
    static constexpr size_t out_size = 1;

    double bias;
    v_type weights[2];
};

//===========================================================
class Tanh
{
public:
    Tanh() = default;

    inline void forward (const v_type* input) noexcept
    {
#if USE_ACCELERATE
        alignas (16) double x[4];
        input[0].copyToRawArray (x);
        input[1].copyToRawArray (&x[2]);

        vvtanh (x, x, &size);

        outs[0] = v_type::fromRawArray (x);
        outs[1] = v_type::fromRawArray (x + 2);
#elif USE_XSIMD
        using x_type = xsimd::simd_type<double>;
        outs[0] = v_type (xsimd::tanh (static_cast<x_type> (input[0].value)));
        outs[1] = v_type (xsimd::tanh (static_cast<x_type> (input[1].value)));
#else
        // fallback
        outs[0].set (0, std::tanh (input[0].get (0)));
        outs[0].set (1, std::tanh (input[0].get (1)));
        outs[1].set (0, std::tanh (input[1].get (0)));
        outs[1].set (1, std::tanh (input[1].get (1)));
#endif
    }

    v_type outs[2];

private:
    static constexpr int size = 4;
};

static bool printed = false;

class STNModel
{
public:
    STNModel()
    {
        if (! printed)
        {
#if USE_RTNEURAL_STATIC
            std::cout << "Using RTNeural ModelT STN" << std::endl;
#elif USE_RTNEURAL_POLY
            std::cout << "Using RTNeural polymorphic STN" << std::endl;
#else
            std::cout << "Using hand-coded STN" << std::endl;
#endif
            printed = true;
        }
    }

    inline double forward (const double* input) noexcept
    {
#if USE_RTNEURAL_STATIC
        return model.forward (input);
#elif USE_RTNEURAL_POLY
        return model->forward (input);
#else
        dense54.forward (input);
        tanh1.forward (dense54.outs);
        dense44.forward (tanh1.outs);
        tanh2.forward (dense44.outs);
        return dense41.forward (tanh2.outs);
#endif
    }

    void loadModel (const nlohmann::json& modelJ);

private:
#if USE_RTNEURAL_STATIC
    RTNeural::ModelT<double, 5, 1, RTNeural::DenseT<double, 5, 4>, RTNeural::TanhActivationT<double, 4>, RTNeural::DenseT<double, 4, 4>, RTNeural::TanhActivationT<double, 4>, RTNeural::DenseT<double, 4, 1>> model;
#elif USE_RTNEURAL_POLY
    std::unique_ptr<RTNeural::Model<double>> model;
#else
    Dense54 dense54;
    Tanh tanh1;
    Dense44 dense44;
    Tanh tanh2;
    Dense41 dense41;
#endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (STNModel)
};

} // namespace STNSpace
