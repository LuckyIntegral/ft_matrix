
#pragma once

#include "Vector.hpp"

template <class T>
void Vector<T>::add(const Vector<T> &other) noexcept(false) {
    if (other.getSize() != this->getSize()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    for (size_t i = 0; i < this->getSize(); i++) {
        this->_data[i] += other[i];
    }
}

template <class T>
void Vector<T>::sub(const Vector<T> &other) noexcept(false) {
    if (other.getSize() != this->getSize()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    for (size_t i = 0; i < this->getSize(); i++) {
        this->_data[i] -= other[i];
    }
}

template <class T>
void Vector<T>::scalar(const T &scalar) noexcept(false) {
    for (size_t i = 0; i < this->getSize(); i++) {
        this->_data[i] *= scalar;
    }
}
