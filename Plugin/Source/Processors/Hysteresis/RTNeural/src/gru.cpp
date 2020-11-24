#include "gru.h"

namespace MLUtils
{

#ifndef USE_EIGEN
template<typename T>
GRULayer<T>::GRULayer (size_t in_size, size_t out_size) :
    Layer<T> (in_size, out_size),
    zWeights (in_size, out_size),
    rWeights (in_size, out_size),
    cWeights (in_size, out_size)
{
    ht1 = new T[out_size];
    zVec = new T[out_size];
    rVec = new T[out_size];
    cVec = new T[out_size];
}

template<typename T>
GRULayer<T>::~GRULayer()
{
    delete[] ht1;
    delete[] zVec;
    delete[] rVec;
    delete[] cVec;
}

template<typename T>
GRULayer<T>::WeightSet::WeightSet (size_t in_size, size_t out_size) :
    out_size (out_size)
{
    W = new T*[out_size];
    U = new T*[out_size];
    b[0] = new T[out_size];
    b[1] = new T[out_size];

    for (size_t i = 0; i < out_size; ++i)
    {
        W[i] = new T[in_size];
        U[i] = new T[out_size];
    }
}

template<typename T>
GRULayer<T>::WeightSet::~WeightSet()
{
    delete[] b[0];
    delete[] b[1];

    for (size_t i = 0; i < out_size; ++i)
    {
        delete[] W[i];
        delete[] U[i];
    }

    delete[] W;
    delete[] U;
}

template<typename T>
void GRULayer<T>::setWVals(T** wVals)
{
    for (size_t i = 0; i < Layer<T>::in_size; ++i)
    {
        for (size_t k = 0; k < Layer<T>::out_size; ++k)
        {
            zWeights.W[k][i] = wVals[i][k];
            rWeights.W[k][i] = wVals[i][k+Layer<T>::out_size];
            cWeights.W[k][i] = wVals[i][k+Layer<T>::out_size*2];
        }
    }
}

template<typename T>
void GRULayer<T>::setUVals(T** uVals)
{
    for (size_t i = 0; i < Layer<T>::out_size; ++i)
    {
        for (size_t k = 0; k < Layer<T>::out_size; ++k)
        {
            zWeights.U[k][i] = uVals[i][k];
            rWeights.U[k][i] = uVals[i][k+Layer<T>::out_size];
            cWeights.U[k][i] = uVals[i][k+Layer<T>::out_size*2];
        }
    }
}

template<typename T>
void GRULayer<T>::setBVals(T** bVals)
{
    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t k = 0; k < Layer<T>::out_size; ++k)
        {
            zWeights.b[i][k] = bVals[i][k];
            rWeights.b[i][k] = bVals[i][k+Layer<T>::out_size];
            cWeights.b[i][k] = bVals[i][k+Layer<T>::out_size*2];
        }
    }
}

template<typename T>
T GRULayer<T>::getWVal(size_t i, size_t k) const noexcept
{
    T** set = zWeights.W;
    if(k > 2 * Layer<T>::out_size)
    {
        k -= 2 * Layer<T>::out_size;
        set = cWeights.W;
    }
    else if (k > Layer<T>::out_size)
    {
        k -= Layer<T>::out_size;
        set = rWeights.W;
    }

    return set[i][k];
}

template<typename T>
T GRULayer<T>::getUVal(size_t i, size_t k) const noexcept
{
    T** set = zWeights.U;
    if(k > 2 * Layer<T>::out_size)
    {
        k -= 2 * Layer<T>::out_size;
        set = cWeights.U;
    }
    else if (k > Layer<T>::out_size)
    {
        k -= Layer<T>::out_size;
        set = rWeights.U;
    }

    return set[i][k];
}

template<typename T>
T GRULayer<T>::getBVal(size_t i, size_t k) const noexcept
{
    T** set = zWeights.b;
    if(k > 2 * Layer<T>::out_size)
    {
        k -= 2 * Layer<T>::out_size;
        set = cWeights.b;
    }
    else if (k > Layer<T>::out_size)
    {
        k -= Layer<T>::out_size;
        set = rWeights.b;
    }

    return set[i][k];
}
#endif // USE_EIGEN

} // namespace MLUtils
