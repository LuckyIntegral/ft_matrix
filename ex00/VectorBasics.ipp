
#pragma once

#include <stdexcept>

#include "Vector.hpp"

template <class T>
Vector<T> Vector<T>::add(const Vector<T> &other) const {
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
Vector<T> Vector<T>::sub(const Vector<T> &other) const {
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
Vector<T> Vector<T>::scalar(const T &scalar) const noexcept {
    Vector<T> result(this->getSize(), 0);

    for (size_t i = 0; i < this->getSize(); i++) {
        result[i] = this->_data[i] * scalar;
    }

    return result;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const {
    return this->add(other);
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &other) const {
    return this->sub(other);
}

template <class T>
Vector<T> Vector<T>::operator*(const T &scalar) const noexcept {
    return this->scalar(scalar);
}

template <class T>
void Vector<T>::operator/=(const T &value) noexcept {
    for (size_t i = 0; i < this->getSize(); i++) {
        this->_data[i] /= value;
    }
}

template <>
void Vector<float>::roundZeroes(void) noexcept {
    for (size_t i = 0; i < this->getSize(); i++) {
        if (std::abs(this->_data[i]) < EPSILON_FLOAT) {
            this->_data[i] = 0;
        }
    }
}

template <>
void Vector<double>::roundZeroes(void) noexcept {
    for (size_t i = 0; i < this->getSize(); i++) {
        if (std::abs(this->_data[i]) < EPSILON_DOUBLE) {
            this->_data[i] = 0;
        }
    }
}

template <>
void Vector<long double>::roundZeroes(void) noexcept {
    for (size_t i = 0; i < this->getSize(); i++) {
        if (std::abs(this->_data[i]) < EPSILON_LONG_DOUBLE) {
            this->_data[i] = 0;
        }
    }
}

template <class T>
void Vector<T>::roundZeroes(void) noexcept {
    for (size_t i = 0; i < this->getSize(); i++) {
        if (std::abs(this->_data[i]) < EPSILON_DOUBLE) {
            this->_data[i] = 0;
        }
    }
}
