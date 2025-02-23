
#pragma once

#include <cmath>

#include "Vector.hpp"

template <class T>
float Vector<T>::normManhattan(void) const noexcept {
    float norm = 0;

    for (size_t i = 0; i < this->_size; i++) {
        norm += std::abs(this->_data[i]);
    }

    return norm;
}

template <class T>
float Vector<T>::normEuclidean(void) const noexcept {
    float norm = 0;

    for (size_t i = 0; i < this->_size; i++) {
        norm = std::fma(this->_data[i], this->_data[i], norm);
    }

    return std::sqrt(norm);
}

template <class T>
float Vector<T>::normSupremum(void) const noexcept {
    float norm = 0;

    for (size_t i = 0; i < this->_size; i++) {
        norm = std::fmax(norm, std::abs(this->_data[i]));
    }

    return norm;
}
