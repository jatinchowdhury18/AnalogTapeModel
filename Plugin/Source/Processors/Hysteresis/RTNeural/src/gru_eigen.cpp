#ifdef USE_EIGEN

#include "gru_eigen.h"

namespace MLUtils
{

template<typename T>
GRULayer<T>::GRULayer (size_t in_size, size_t out_size) :
    Layer<T> (in_size, out_size)
{
    wVec_z.resize (out_size, in_size);
    wVec_r.resize (out_size, in_size);
    wVec_c.resize (out_size, in_size);
    uVec_z.resize (out_size, out_size);
    uVec_r.resize (out_size, out_size);
    uVec_c.resize (out_size, out_size);
    bVec_z.resize (out_size, 2);
    bVec_r.resize (out_size, 2);
    bVec_c.resize (out_size, 2);

    ht1.resize (out_size, 1);
    zVec.resize (out_size, 1);
    rVec.resize (out_size, 1);
    cVec.resize (out_size, 1);

    inVec.resize (in_size, 1);
    ones = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>::Ones (out_size, 1);
}

template<typename T>
void GRULayer<T>::setWVals(T** wVals)
{
    for (size_t i = 0; i < Layer<T>::in_size; ++i)
    {
        for (size_t k = 0; k < Layer<T>::out_size; ++k)
        {
            wVec_z (k, i) = wVals[i][k];
            wVec_r (k, i) = wVals[i][k+Layer<T>::out_size];
            wVec_c (k, i) = wVals[i][k+Layer<T>::out_size*2];
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
            uVec_z (k, i) = uVals[i][k];
            uVec_r (k, i) = uVals[i][k+Layer<T>::out_size];
            uVec_c (k, i) = uVals[i][k+Layer<T>::out_size*2];
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
            bVec_z (k, i) = bVals[i][k];
            bVec_r (k, i) = bVals[i][k+Layer<T>::out_size];
            bVec_c (k, i) = bVals[i][k+Layer<T>::out_size*2];
        }
    }
}

template<typename T>
T GRULayer<T>::getWVal(size_t i, size_t k) const noexcept
{
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> set = wVec_z;
    if(k > 2 * Layer<T>::out_size)
        set = wVec_c;
    else if (k > Layer<T>::out_size)
        set = wVec_r;

    return set (k % Layer<T>::out_size, i);
}

template<typename T>
T GRULayer<T>::getUVal(size_t i, size_t k) const noexcept
{
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> set = uVec_z;
    if(k > 2 * Layer<T>::out_size)
        set = uVec_c;
    else if (k > Layer<T>::out_size)
        set = uVec_r;

    return set (k % Layer<T>::out_size, i);
}

template<typename T>
T GRULayer<T>::getBVal(size_t i, size_t k) const noexcept
{
    Eigen::Matrix<T, Eigen::Dynamic, 2> set = bVec_z;
    if(k > 2 * Layer<T>::out_size)
        set = bVec_c;
    else if (k > Layer<T>::out_size)
        set = bVec_r;

    return set (k % Layer<T>::out_size, i);
}

} // namespace MLUtils

#endif // USE_EIGEN
