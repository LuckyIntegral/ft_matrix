
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T> cross_product(const Vector<T> &vec1, const Vector<T> &vec2) {
    if (vec1.getSize() != 3 || vec2.getSize() != 3) {
        throw std::invalid_argument("Vectors must have size 3");
    }

    return Vector<T>({
        vec1[1] * vec2[2] - vec1[2] * vec2[1],
        vec1[2] * vec2[0] - vec1[0] * vec2[2],
        vec1[0] * vec2[1] - vec1[1] * vec2[0],
    });
}
