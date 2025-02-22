
#pragma once

#include "Matrix.hpp"

template <class T>
void Matrix<T>::add(const Matrix<T> &other) noexcept(false) {
    if (other.getRows() != this->getRows() ||
        other.getCols() != this->getCols()) {
        throw std::invalid_argument("Matrices must have the same size");
    }

    for (size_t i = 0; i < this->getRows(); i++) {
        (*this)[i].add(other[i]);
    }
}

template <class T>
void Matrix<T>::sub(const Matrix<T> &other) noexcept(false) {
    if (other.getRows() != this->getRows() ||
        other.getCols() != this->getCols()) {
        throw std::invalid_argument("Matrices must have the same size");
    }

    for (size_t i = 0; i < this->getRows(); i++) {
        (*this)[i].sub(other[i]);
    }
}

template <class T>
void Matrix<T>::scalar(const T &scalar) noexcept(false) {
    for (size_t i = 0; i < this->getRows(); i++) {
        (*this)[i].scalar(scalar);
    }
}
