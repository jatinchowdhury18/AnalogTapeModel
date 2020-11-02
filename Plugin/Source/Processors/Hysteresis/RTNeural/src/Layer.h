#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include <stddef.h>

namespace MLUtils
{

/** Neural network layer */
template<typename T>
class Layer
{
public:
    Layer (size_t in_size, size_t out_size) :
        in_size (in_size),
        out_size (out_size)
    {}

    virtual ~Layer() {}

    virtual void forward (const T* input, T* out) = 0;

    const size_t in_size;
    const size_t out_size;
};

} // namespace MLUtils

#endif // LAYER_H_INCLUDED
