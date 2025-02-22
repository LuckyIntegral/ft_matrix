
#pragma once

#include "Vector.hpp"
#include <cmath>

template <class T>
Vector<T> linear_combination(Vector<Vector<T>> &vectors,
                             Vector<T> &coefficients) {
    if (vectors.getSize() != coefficients.getSize()) {
        throw std::invalid_argument(
            "Vectors and coefficients must have the same size");
    }

    for (size_t vec = 0; vec < vectors.getSize(); vec++) {
        if (vectors[vec].getSize() != vectors[0].getSize()) {
            throw std::invalid_argument("Vectors must have the same size");
        }
    }

    Vector<T> result(vectors[0].getSize(), 0);

    for (size_t vec = 0; vec < vectors.getSize(); vec++) {
        for (size_t iter = 0; iter < vectors[vec].getSize(); iter++) {
            result[iter] = std::fma(vectors[vec][iter], coefficients[vec], result[iter]);
        }
    }

    return result;
}
