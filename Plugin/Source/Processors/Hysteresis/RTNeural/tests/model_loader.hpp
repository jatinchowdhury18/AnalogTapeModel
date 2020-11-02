#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "../src/Model.h"
#include "../modules/json/json.hpp"

namespace json_parser {

using json = nlohmann::json;

template<typename T>
std::unique_ptr<MLUtils::Dense<T>> createDense(size_t in_size, size_t out_size, const json& weights)
{
    auto dense = std::make_unique<MLUtils::Dense<T>>(in_size, out_size);

    // load weights
    std::vector<std::vector<T>> denseWeights (out_size);
    for(auto& w : denseWeights)
        w.resize(in_size, (T) 0);

    auto layerWeights = weights[0];
    for(size_t i = 0; i < layerWeights.size(); ++i)
    {
        auto lw = layerWeights[i];
        for(size_t j = 0; j < lw.size(); ++j)
            denseWeights[j][i] = lw[j].get<T>();
    }
    
    dense->setWeights(denseWeights);

    // load biases
    std::vector<T> denseBias = weights[1].get<std::vector<T>>();
    dense->setBias(denseBias.data());

    return std::move(dense);
}

template<typename T>
std::unique_ptr<MLUtils::Model<T>> parseJson (std::ifstream& jsonStream)
{
    json parent;
    jsonStream >> parent;
    auto shape = parent["in_shape"];
    auto layers = parent["layers"];

    if(! shape.is_array() || ! layers.is_array())
        return {};

    const auto nDims = shape.back().get<int>();
    std::cout << "# dimensions: " << nDims << std::endl;

    auto model = std::make_unique<MLUtils::Model<T>> (nDims);

    for(const auto& l : layers)
    {
        const auto type = l["type"].get<std::string>();
        std::cout << "Layer: " << type << std::endl;

        const auto layerShape = l["shape"];
        const auto layerDims = layerShape.back().get<int>();
        std::cout << "  Dims: " << layerDims << std::endl;

        const auto weights = l["weights"];

        if(type == "dense")
        {
            auto dense = createDense<T>(model->getNextInSize(), layerDims, weights);
            model->addLayer(dense.release());

            const auto activationType = l["activation"].get<std::string>();
            if(activationType == "tanh")
            {
                std::cout << "  activation: " << activationType << std::endl;
                auto activation = std::make_unique<MLUtils::TanhActivation<T>> (layerDims);
                model->addLayer(activation.release());
            }
        }
    }

    return std::move(model);
}

} // namespace json_parser
