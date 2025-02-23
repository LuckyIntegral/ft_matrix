
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T> Vector<T>::add(const Vector<T> &other) const noexcept(false) {
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
Vector<T> Vector<T>::sub(const Vector<T> &other) const noexcept(false) {
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
Vector<T> Vector<T>::scalar(const T &scalar) const noexcept(false) {
    Vector<T> result(this->getSize(), 0);

    for (size_t i = 0; i < this->getSize(); i++) {
        result[i] = this->_data[i] * scalar;
    }

    return result;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const noexcept(false) {
    return this->add(other);
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &other) const noexcept(false) {
    return this->sub(other);
}

template <class T>
Vector<T> Vector<T>::operator*(const T &scalar) const noexcept(false) {
    return this->scalar(scalar);
}

