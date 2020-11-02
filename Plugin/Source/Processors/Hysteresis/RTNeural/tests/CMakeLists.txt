include_directories(../src)
include_directories(../modules/Eigen)
include_directories(../modules/json)

add_executable(dense dense.cpp)
target_link_libraries(dense LINK_PUBLIC MLUtils)
