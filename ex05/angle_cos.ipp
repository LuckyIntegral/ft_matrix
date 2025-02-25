
#pragma once

#include "Vector.hpp"

template <class T>
float angle_cos(const Vector<T> &vec1, const Vector<T> &vec2) noexcept(false) {
    const float numerator = vec1.dotProduct(vec2);
    const float denominator = vec1.normEuclidean() * vec2.normEuclidean();

    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }

    return numerator / denominator;
}
