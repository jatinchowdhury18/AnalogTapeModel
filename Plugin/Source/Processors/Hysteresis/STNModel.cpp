#include "STNModel.h"

namespace STNSpace
{
static bool printed = false;

STNModel::STNModel()
{
    // useful for debugging...
    if (! printed)
    {
#if USE_RTNEURAL_STATIC
        DBG ("Using RTNeural ModelT STN");
#elif USE_RTNEURAL_POLY
        DBG ("Using RTNeural polymorphic STN");
#endif
        printed = true;
    }
}

void STNModel::loadModel (const nlohmann::json& modelJ)
{
#if USE_RTNEURAL_STATIC
    model.parseJson (modelJ);
#elif USE_RTNEURAL_POLY
    model = RTNeural::json_parser::parseJson<double> (modelJ);
#endif
}

} // namespace STNSpace
