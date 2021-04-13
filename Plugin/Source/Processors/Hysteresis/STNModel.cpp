#include "STNModel.h"

namespace STNSpace
{

Dense54::Dense54()
{
    for (size_t i = 0; i < 3; ++i)
        ins[i] = v_type (0.0);

    for (size_t i = 0; i < 16; ++i)
        weights[i] = v_type (0.0);

    for (size_t i = 0; i < 2; ++i)
        bias[i] = v_type (0.0);
}

void Dense54::setWeights (std::vector<std::vector<double>>& w)
{
    for (size_t i = 0; i < out_size; ++i)
        for (size_t j = 0; j < in_size; ++j)
            weights[i * out_size + j / 2].set (j % 2, w[i][j]);
}

void Dense54::setBias (std::vector<double>& b)
{
    for (size_t i = 0; i < out_size; ++i)
        bias[i/2].set (i % 2, b[i]);
}

//===========================================================
Dense44::Dense44()
{
    for (size_t i = 0; i < 16; ++i)
        weights[i] = v_type (0.0);

    for (size_t i = 0; i < 2; ++i)
        bias[i] = v_type (0.0);
}

void Dense44::setWeights (std::vector<std::vector<double>>& w)
{
    for (size_t i = 0; i < out_size; ++i)
        for (size_t j = 0; j < in_size; ++j)
            weights[i * out_size + j / 2].set (j % 2, w[i][j]);
}

void Dense44::setBias (std::vector<double>& b)
{
    for (size_t i = 0; i < out_size; ++i)
        bias[i/2].set (i % 2, b[i]);
}

//===========================================================
Dense41::Dense41()
{
    for (size_t i = 0; i < 2; ++i)
        weights[i] = v_type (0.0);
    
    bias = 0.0;
}

void Dense41::setWeights (std::vector<std::vector<double>>& w)
{
    for (size_t i = 0; i < out_size; ++i)
        for (size_t j = 0; j < in_size; ++j)
            weights[j / 2].set (j % 2, w[i][j]);
}

void Dense41::setBias (std::vector<double>& b)
{
    bias = b[0];
}

//===========================================================
void STNModel::loadModel (const nlohmann::json& modelJ)
{
    auto layers = modelJ["layers"];

    const auto weights_l0 = layers.at (0)["weights"];
    {
        // load weights
        std::vector<std::vector<double>> denseWeights(4);
        for(auto& w : denseWeights)
            w.resize(5, 0.0);
    
        auto layerWeights = weights_l0[0];
        for(size_t i = 0; i < layerWeights.size(); ++i)
        {
            auto lw = layerWeights[i];
            for(size_t j = 0; j < lw.size(); ++j)
                denseWeights[j][i] = lw[j].get<double>();
        }
        dense54.setWeights(denseWeights);
    
        // load biases
        std::vector<double> denseBias = weights_l0[1].get<std::vector<double>>();
        dense54.setBias(denseBias);
    }

    const auto weights_l1 = layers.at (1)["weights"];
    {
        // load weights
        std::vector<std::vector<double>> denseWeights(4);
        for(auto& w : denseWeights)
            w.resize(4, 0.0);
    
        auto layerWeights = weights_l1[0];
        for(size_t i = 0; i < layerWeights.size(); ++i)
        {
            auto lw = layerWeights[i];
            for(size_t j = 0; j < lw.size(); ++j)
                denseWeights[j][i] = lw[j].get<double>();
        }
        dense44.setWeights(denseWeights);
    
        // load biases
        std::vector<double> denseBias = weights_l1[1].get<std::vector<double>>();
        dense44.setBias(denseBias);
    }

    const auto weights_l2 = layers.at (2)["weights"];
    {
        // load weights
        std::vector<std::vector<double>> denseWeights(1);
        for(auto& w : denseWeights)
            w.resize(4, 0.0);
    
        auto layerWeights = weights_l2[0];
        for(size_t i = 0; i < layerWeights.size(); ++i)
        {
            auto lw = layerWeights[i];
            for(size_t j = 0; j < lw.size(); ++j)
                denseWeights[j][i] = lw[j].get<double>();
        }
        dense41.setWeights(denseWeights);
    
        // load biases
        std::vector<double> denseBias = weights_l2[1].get<std::vector<double>>();
        dense41.setBias(denseBias);
    }
}

} // namespace STNSpace
