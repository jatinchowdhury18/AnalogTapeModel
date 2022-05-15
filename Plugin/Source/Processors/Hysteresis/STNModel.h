#pragma once

#include <JuceHeader.h>

JUCE_BEGIN_IGNORE_WARNINGS_GCC_LIKE("-Wshorten-64-to-32")
#include <RTNeural/RTNeural.h>
JUCE_END_IGNORE_WARNINGS_GCC_LIKE

#define USE_RTNEURAL_POLY 0
#define USE_RTNEURAL_STATIC 1

namespace STNSpace
{
class STNModel
{
public:
    STNModel();
    STNModel (STNModel&&) noexcept = default;

    inline double forward (const double* input) noexcept
    {
#if USE_RTNEURAL_STATIC
        return model.forward (input);
#elif USE_RTNEURAL_POLY
        return model->forward (input);
#endif
    }

    void loadModel (const nlohmann::json& modelJ);

private:
#if USE_RTNEURAL_STATIC
    RTNeural::ModelT<double, 5, 1, RTNeural::DenseT<double, 5, 4>, RTNeural::TanhActivationT<double, 4>, RTNeural::DenseT<double, 4, 4>, RTNeural::TanhActivationT<double, 4>, RTNeural::DenseT<double, 4, 1>> model;
#elif USE_RTNEURAL_POLY
    std::unique_ptr<RTNeural::Model<double>> model;
#endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (STNModel)
};

} // namespace STNSpace
