juce_add_console_app(ChowTapeModel_Headless
    PRODUCT_NAME "ChowTapeModel"
    COMPANY_NAME chowdsp
)

juce_generate_juce_header(ChowTapeModel_Headless)
add_custom_command(TARGET ChowTapeModel_Headless
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "copying $<TARGET_FILE:ChowTapeModel_Headless> to ${PROJECT_BINARY_DIR}/ChowTapeModel"
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ChowTapeModel_Headless> ${PROJECT_BINARY_DIR}/ChowTapeModel)

target_sources(ChowTapeModel_Headless PRIVATE
    Main.cpp

    Benchmarks.cpp
    ScreenshotHelper.cpp

    UnitTests/UnitTests.cpp
    UnitTests/MixGroupsTest.cpp
)

target_include_directories(ChowTapeModel_Headless PRIVATE ../)

target_link_libraries(ChowTapeModel_Headless PUBLIC
    BinaryData
    CHOWTapeModel
)
