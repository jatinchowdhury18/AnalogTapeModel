cmake_minimum_required(VERSION 3.8)
project(MLUtils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")

add_definitions(-DUSE_EIGEN)

add_subdirectory(src)

option(BUILD_TESTS "Build MLUtils accuracy tests" OFF)
if(BUILD_TESTS)
    message("Building tests...")
    add_subdirectory(tests)
endif()

option(BUILD_BENCH "Build MLUtils benchmarks" OFF)
if(BUILD_BENCH)
    message("Building benchmarks...")
endif()
