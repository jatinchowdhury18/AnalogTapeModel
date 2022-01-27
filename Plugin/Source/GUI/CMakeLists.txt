target_sources(CHOWTapeModel PRIVATE
    AutoUpdating.cpp
    MyLNF.cpp
    OversamplingMenu.cpp
    SettingsButton.cpp
    TitleComp.cpp
    TooltipComp.cpp
    WowFlutterMenu.cpp
    
    OnOff/OnOffManager.cpp
    OnOff/PowerButton.cpp

    Visualizers/LightMeter.cpp
    Visualizers/MixGroupViz.cpp
    Visualizers/TapeScope.cpp
)

if(IOS)
    target_sources(CHOWTapeModel PRIVATE
        IOSOnly/DragToScrollListener.cpp
        IOSOnly/ScrollView.cpp
        IOSOnly/TipJar.cpp
    )
endif()
