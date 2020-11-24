#ifndef GRU_H_INCLUDED
#define GRU_H_INCLUDED

#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>

#ifdef USE_EIGEN
#include "gru_eigen.h"
#include "gru_eigen.cpp"
#else
#include "Layer.h"

namespace MLUtils
{

template<typename T>
class GRULayer : public Layer<T>
{
public:
    GRULayer (size_t in_size, size_t out_size);
    virtual ~GRULayer();

    virtual void reset()
    {
        std::fill(ht1, ht1 + Layer<T>::out_size, (T) 0);
    }

    virtual inline void forward(const T* input, T* h) override
    {
        for(size_t i = 0; i < Layer<T>::out_size; ++i)
        {
            zVec[i] = sigmoid(vMult(zWeights.W[i], input, Layer<T>::in_size) + vMult(zWeights.U[i], ht1, Layer<T>::out_size) + zWeights.b[0][i] + zWeights.b[1][i]);
            rVec[i] = sigmoid(vMult(rWeights.W[i], input, Layer<T>::in_size) + vMult(rWeights.U[i], ht1, Layer<T>::out_size) + rWeights.b[0][i] + rWeights.b[1][i]);
            cVec[i] = std::tanh(vMult(cWeights.W[i], input, Layer<T>::in_size) + rVec[i] * (vMult(cWeights.U[i], ht1, Layer<T>::out_size) + cWeights.b[1][i]) + cWeights.b[0][i]);
            h[i] = ((T) 1 - zVec[i]) * cVec[i] + zVec[i] * ht1[i];
        }
    
        std::copy(h, h + Layer<T>::out_size, ht1);
    }

    inline T vMult(const T* arg1, const T* arg2, size_t dim)
    {
        return std::inner_product(arg1, arg1 + dim, arg2, (T) 0);
    }

    inline T sigmoid(T value)
    {
        return (T) 1 / ((T) 1 + std::exp(-value));
    }

    void setWVals(T** wVals);
    void setUVals(T** uVals);
    void setBVals(T** bVals);

    T getWVal(size_t i, size_t k) const noexcept;
    T getUVal(size_t i, size_t k) const noexcept;
    T getBVal(size_t i, size_t k) const noexcept;

protected:
    T* ht1;

    struct WeightSet
    {
        WeightSet (size_t in_size, size_t out_size);
        ~WeightSet();

        T** W;
        T** U;
        T* b[2];
        const size_t out_size;
    };

    WeightSet zWeights;
    WeightSet rWeights;
    WeightSet cWeights;

    T* zVec;
    T* rVec;
    T* cVec;
};

} // namespace MLUtils

#endif // USE_EIGEN

#endif // GRU_H_INCLUDED
