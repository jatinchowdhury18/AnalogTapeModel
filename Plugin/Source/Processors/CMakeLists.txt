target_sources(CHOWTapeModel PRIVATE
    Chew/ChewProcessor.cpp
    Degrade/DegradeProcessor.cpp

    Hysteresis/HysteresisProcessing.cpp
    Hysteresis/HysteresisProcessor.cpp
    Hysteresis/HysteresisSTN.cpp
    Hysteresis/ToneControl.cpp
    Hysteresis/RTNeural/src/Json2RnnParser.cpp

    Input_Filters/InputFilters.cpp
    Loss_Effects/LossFilter.cpp
    Timing_Effects/Flutter.cpp
)
