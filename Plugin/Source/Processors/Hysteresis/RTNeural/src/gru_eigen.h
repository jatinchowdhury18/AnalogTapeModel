#ifndef GRUEIGEN_H_INCLUDED
#define GRUEIGEN_H_INCLUDED

#include <Eigen/Dense>
#include "Layer.h"

namespace MLUtils
{

template<typename T>
class GRULayer : public Layer<T>
{
public:
    GRULayer (size_t in_size, size_t out_size);
    virtual ~GRULayer() {}

    void reset()
    {
        std::fill(ht1.data(), ht1.data() + Layer<T>::out_size, (T) 0);
    }

    inline void forward(const T* input, T* h) override
    {
        inVec = Eigen::Map<const Eigen::Matrix<T, Eigen::Dynamic, 1>> (input, Layer<T>::in_size, 1);

        zVec = wVec_z * inVec + uVec_z * ht1 + bVec_z.col (0) + bVec_z.col (1);
        rVec = wVec_r * inVec + uVec_r * ht1 + bVec_r.col (0) + bVec_r.col (1);
        sigmoid (zVec);
        sigmoid (rVec);
        
        cVec = wVec_c * inVec + rVec.cwiseProduct (uVec_c * ht1 + bVec_c.col (1)) + bVec_c.col (0);
        cVec = cVec.array().tanh();
        
        ht1 = (ones - zVec).cwiseProduct (cVec) + zVec.cwiseProduct (ht1);
        std::copy (ht1.data(), ht1.data() + Layer<T>::out_size, h);
    }

    inline void sigmoid (Eigen::Matrix<T, Eigen::Dynamic, 1>& vector)
    {
        vector = (T) 1 / (((T) -1 * vector.array()).array().exp() + (T) 1);
    }

    void setWVals(T** wVals);
    void setUVals(T** uVals);
    void setBVals(T** bVals);

    T getWVal(size_t i, size_t k) const noexcept;
    T getUVal(size_t i, size_t k) const noexcept;
    T getBVal(size_t i, size_t k) const noexcept;

private:
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> wVec_z;
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> wVec_r;
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> wVec_c;
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> uVec_z;
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> uVec_r;
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> uVec_c;
    Eigen::Matrix<T, Eigen::Dynamic, 2> bVec_z;
    Eigen::Matrix<T, Eigen::Dynamic, 2> bVec_r;
    Eigen::Matrix<T, Eigen::Dynamic, 2> bVec_c;

    Eigen::Matrix<T, Eigen::Dynamic, 1> ht1;
    Eigen::Matrix<T, Eigen::Dynamic, 1> zVec;
    Eigen::Matrix<T, Eigen::Dynamic, 1> rVec;
    Eigen::Matrix<T, Eigen::Dynamic, 1> cVec;

    Eigen::Matrix<T, Eigen::Dynamic, 1> inVec;
    Eigen::Matrix<T, Eigen::Dynamic, 1> ones;
};

} // namespace MLUtils

#endif // GRUEIGEN_H_INCLUDED
