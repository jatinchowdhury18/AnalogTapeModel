#include "HysteresisSTN.h"
#include <future>

namespace
{
constexpr double trainingSampleRate = 96e3;

constexpr float satIdxMult = (float) HysteresisSTN::numSatModels - 1.0f;
constexpr float widthIdxMult = (float) HysteresisSTN::numWidthModels - 1.0f;

const std::array<String, HysteresisSTN::numWidthModels> widthTags { "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100" };

const std::array<String, HysteresisSTN::numSatModels> satTags { "0", "5", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55", "60", "65", "70", "75", "80", "85", "90", "95", "100" };
} // namespace

constexpr size_t getSatIdx (float satParam)
{
    return (size_t) std::clamp (static_cast<int> (satIdxMult * satParam), 0, HysteresisSTN::numSatModels - 1);
}

constexpr size_t getWidthIdx (float widthParam)
{
    return (size_t) std::clamp (static_cast<int> (widthIdxMult * widthParam), 0, HysteresisSTN::numWidthModels - 1);
}

std::unique_ptr<MemoryInputStream> getModelFileStream (const String& modelFile)
{
    std::unique_ptr<MemoryInputStream> stream;
    for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
    {
        if (String (BinaryData::originalFilenames[i]) == modelFile)
        {
            int fileSize = 0;
            auto* fileData = BinaryData::getNamedResource (BinaryData::namedResourceList[i], fileSize);
            stream = std::make_unique<MemoryInputStream> (fileData, fileSize, false);
            return std::move (stream);
        }
    }

    return {};
}

HysteresisSTN::HysteresisSTN()
{
    // Since we have a lot of models to load
    // let's split them up and load them asychronously!
    // This cuts down the model loading time for both
    // channels from ~100 ms to ~30 ms
    size_t widthLoadIdx = 0;
    std::vector<std::future<void>> futures;
    for (const auto& width : widthTags)
    {
        auto loadModelSet = [=] (size_t widthModelIdx)
        {
            auto modelsStream = getModelFileStream ("hyst_width_" + width + ".json");
            jassert (modelsStream != nullptr);

            auto modelsJson = nlohmann::json::parse (modelsStream->readEntireStreamAsString().toStdString());
            size_t satLoadIdx = 0;
            for (const auto& sat : satTags)
            {
                String modelTag = "drive_" + sat + "_" + width;
                auto thisModelJson = modelsJson[modelTag.toStdString()];
                stnModels[widthModelIdx][satLoadIdx].loadModel (thisModelJson);
                satLoadIdx++;
            }
        };

        futures.push_back (std::async (std::launch::async,
                                       [=, &widthLoadIdx]
                                       { loadModelSet (widthLoadIdx++); }));
    }

    for (auto& f : futures)
        f.wait();
}

void HysteresisSTN::prepare (double sampleRate)
{
    sampleRateCorr = trainingSampleRate / sampleRate;
}

void HysteresisSTN::setParams (float saturation, float width)
{
    satIdx = getSatIdx (saturation);
    widthIdx = getWidthIdx (width);
}
