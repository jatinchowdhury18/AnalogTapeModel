#include <iostream>
#include <fstream>
#include "model_loader.hpp"
#include "load_csv.hpp"

using T = double;

int main()
{
    std::cout << "TESTING DENSE IMPLEMENTATION..." << std::endl;

    std::ifstream jsonStream("models/dense.json", std::ifstream::binary);
    auto model = json_parser::parseJson<T>(jsonStream);

    std::ifstream pythonX("test_data/dense_x_python.csv");
    auto xData = load_csv::loadFile<T>(pythonX);

    std::ifstream pythonY("test_data/dense_y_python.csv");
    const auto yRefData = load_csv::loadFile<T>(pythonY);

    std::vector<T> yData (xData.size(), (T) 0);
    for(size_t n = 0; n < xData.size(); ++n)
        yData[n] = model->forward(xData[n].data());

    constexpr T THRESH = 1.0e-6; // 2.0e-8;
    for(size_t n = 0; n < xData.size(); ++n)
    {
        auto err = std::abs(yData[n] - yRefData[n][0]);
        if(err > THRESH)
        {
            std::cout << "ERR: " << err << ", idx: " << n << std::endl;
            break;
        }
    }

    return 0;
}
