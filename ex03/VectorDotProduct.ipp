
#pragma once

#include <cmath>

#include "Vector.hpp"

template <class T>
T Vector<T>::dotProduct(const Vector<T> &other) const noexcept(false) {
    if (this->_size != other._size) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    T acc = 0;

    for (size_t i = 0; i < this->_size; i++) {
        acc = std::fma(this->_data[i], other._data[i], acc);
    }

    return acc;
}
