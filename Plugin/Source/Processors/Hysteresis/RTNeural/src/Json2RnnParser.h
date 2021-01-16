#ifndef JSON2RNNPARSER_H_INCLUDED
#define JSON2RNNPARSER_H_INCLUDED

#include "Model.h"
#include <JuceHeader.h>

class Json2RnnParser
{
public:
    Json2RnnParser() {}

    template <typename T>
    static std::unique_ptr<MLUtils::Model<T>> parseJson (InputStream& input);

    template <typename T>
    static std::unique_ptr<MLUtils::Model<T>> parseJson (const var& json);

    template <typename T>
    static std::unique_ptr<MLUtils::Dense<T>> createDense (size_t in_size, size_t out_size, var& weights);

    template <typename T>
    static std::unique_ptr<MLUtils::GRULayer<T>> createGRU (size_t in_size, size_t out_size, var& weights);
};

#endif // JSON2RNNPARSER_H_INCLUDED
