
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T> Vector<T>::add(const Vector<T> &other) noexcept(false) {
    if (other.getSize() != this->getSize()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    Vector<T> result(this->getSize(), 0);

    for (size_t i = 0; i < this->getSize(); i++) {
        result[i] = this->_data[i] + other[i];
    }

    return result;
}

template <class T>
Vector<T> Vector<T>::sub(const Vector<T> &other) noexcept(false) {
    if (other.getSize() != this->getSize()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    Vector<T> result(this->getSize(), 0);

    for (size_t i = 0; i < this->getSize(); i++) {
        result[i] = this->_data[i] - other[i];
    }

    return result;
}

template <class T>
Vector<T> Vector<T>::scalar(const T &scalar) noexcept(false) {
    Vector<T> result(this->getSize(), 0);

    for (size_t i = 0; i < this->getSize(); i++) {
        result[i] = this->_data[i] * scalar;
    }

    return result;
}
