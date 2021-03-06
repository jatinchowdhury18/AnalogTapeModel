add_library(warning_flags INTERFACE)

if((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") OR (CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC"))
    target_compile_options(warning_flags INTERFACE "/W4 /wd4458 /wd4530 /wd4505")
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
    target_compile_options(warning_flags INTERFACE
        -Wall -Wshadow-all -Wshorten-64-to-32 -Wstrict-aliasing -Wuninitialized
        -Wunused-parameter -Wconversion -Wsign-compare -Wint-conversion
        -Wconditional-uninitialized -Woverloaded-virtual -Wreorder
        -Wconstant-conversion -Wsign-conversion -Wunused-private-field
        -Wbool-conversion -Wno-extra-semi -Wunreachable-code
        -Wzero-as-null-pointer-constant -Wcast-align
        -Wno-inconsistent-missing-destructor-override -Wshift-sign-overflow
        -Wnullable-to-nonnull-conversion -Wno-missing-field-initializers
        -Wno-ignored-qualifiers -Wno-switch-enum -Wpedantic -Wno-pessimizing-move
        # These lines suppress some warnings from Foley's GUI Magic and RTNeural.
        # Comment them out to be more strict.
        -Wno-shadow-field-in-constructor -Wno-shadow-field -Wno-sign-conversion
        -Wno-float-conversion -Wno-implicit-float-conversion
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(warning_flags INTERFACE
        -Wall -Wextra -Wstrict-aliasing -Wuninitialized -Wunused-parameter
        -Wsign-compare -Woverloaded-virtual -Wreorder -Wsign-conversion
        -Wunreachable-code -Wzero-as-null-pointer-constant -Wcast-align
        -Wno-implicit-fallthrough -Wno-maybe-uninitialized
        -Wno-missing-field-initializers -Wno-ignored-qualifiers -Wno-switch-enum
        -Wredundant-decls -Wpedantic)

    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "7.0.0")
        target_compile_options(warning_flags INTERFACE "-Wno-strict-overflow")
    endif()
endif()
