include_directories(../modules/Eigen)

add_library(MLUtils STATIC
    gru.h
    gru.cpp
    gru_eigen.h
    gru_eigen.cpp
    dense.h
    dense_eigen.h
    activation.h
    Model.h
    Layer.h
)
