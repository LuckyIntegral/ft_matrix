
#pragma once

#include <cmath>

#include "Matrix.hpp"
#include "Vector.hpp"

template <class T>
T lerp(const T &u, const T &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    return std::fma(t, v, std::fma(-t, u, u));
}

template <class T>
Vector<T> lerp(const Vector<T> &u, const Vector<T> &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    Vector<T> res(u.getSize(), 0);

    for (size_t i = 0; i < u.getSize(); i++) {
        res[i] = lerp(u[i], v[i], t);
    }

    return res;
}

template <class T>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, float t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be between 0 and 1");
    }

    if (u.getRows() != v.getRows() || u.getCols() != v.getCols()) {
        throw std::invalid_argument("Matrices must have the same size");
    }

    Matrix<T> res(u.getRows(), u.getCols(), 0);

    for (size_t i = 0; i < res.getRows(); i++) {
        for (size_t j = 0; j < res.getCols(); j++) {
            res[i][j] = lerp(u[i][j], v[i][j], t);
        }
    }

    return res;
}
