#include <future>
#include "HysteresisSTN.h"
#include "RTNeural/src/Json2RnnParser.h"

namespace
{
    constexpr double trainingSampleRate = 96e3;
    
    constexpr float satIdxMult   = (float) HysteresisSTN::numSatModels   - 1.0f;
    constexpr float widthIdxMult = (float) HysteresisSTN::numWidthModels - 1.0f;

    static std::array<String, HysteresisSTN::numWidthModels> widthTags
        { "0", "10", "20", "30", "40", "50", "60", "70", "80", "90", "100"};

    static std::array<String, HysteresisSTN::numSatModels> satTags
        { "0",  "5", "10", "15", "20", "25", "30", "35", "40", "45",
         "50", "55", "60", "65", "70", "75", "80", "85", "90", "95", "100" };
}

constexpr size_t getSatIdx (float satParam)
{
    return std::clamp (static_cast<int> (satIdxMult * satParam), 0, HysteresisSTN::numSatModels - 1);
}

constexpr size_t getWidthIdx (float widthParam)
{
    return std::clamp (static_cast<int> (widthIdxMult * widthParam), 0, HysteresisSTN::numWidthModels - 1);
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
    // load models
    auto start = Time::getMillisecondCounterHiRes();
    size_t widthLoadIdx = 0;
    for (const auto& width : widthTags)
    {
        auto modelsStream = getModelFileStream ("hyst_width_" + width + ".json");
        jassert (modelsStream != nullptr);

        auto modelsJson = JSON::parse (*modelsStream.get());
        size_t satLoadIdx = 0;
        for (const auto& sat : satTags)
        {
            String modelTag = "drive_" + sat + "_" + width;
            auto modelJson = modelsJson[modelTag.toRawUTF8()];
            stnModels[widthLoadIdx][satLoadIdx] = Json2RnnParser::parseJson<double> (modelJson);

            jassert (stnModels[widthLoadIdx][satLoadIdx] != nullptr);
            jassert (stnModels[widthLoadIdx][satLoadIdx]->layers[0]->in_size == inputSize);
            satLoadIdx++;
        }
        widthLoadIdx++;
    }

    auto dur = Time::getMillisecondCounterHiRes() - start;
    Logger::writeToLog ("Loaded " + String (widthTags.size() * satTags.size())
        + " models in " + String (dur / 1000.0) + " seconds");
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
