
#pragma once

#include <cmath>

#include "Matrix.hpp"
#include "Vector.hpp"

template <class T>
T lerp(const T &u, const T &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    return std::fma(t, (v - u), u);
}

template <class T>
Vector<T> lerp(const Vector<T> &u, const Vector<T> &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    Vector<T> acc(v - u);

    for (size_t i = 0; i < u.getSize(); i++) {
        acc[i] = std::fma(t, acc[i], u[i]);
    }

    return acc;
}

template <class T>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    Matrix<T> acc(v - u);

    for (size_t i = 0; i < acc.getRows(); i++) {
        for (size_t j = 0; j < acc.getCols(); j++) {
            acc[i][j] = std::fma(t, acc[i][j], u[i][j]);
        }
    }

    return acc;
}
