
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T> Matrix<T>::add(const Matrix<T> &other) const noexcept(false) {
    if (other.getRows() != this->getRows() ||
        other.getCols() != this->getCols()) {
        throw std::invalid_argument("Matrices must have the same size");
    }

    Matrix<T> result(*this);

    for (size_t i = 0; i < this->getRows(); i++) {
        result[i] = result[i].add(other[i]);
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::sub(const Matrix<T> &other) const noexcept(false) {
    if (other.getRows() != this->getRows() ||
        other.getCols() != this->getCols()) {
        throw std::invalid_argument("Matrices must have the same size");
    }

    Matrix<T> result(*this);

    for (size_t i = 0; i < this->getRows(); i++) {
        result[i] = result[i].sub(other[i]);
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::scalar(const T &scalar) const noexcept(false) {
    Matrix<T> result(*this);

    for (size_t i = 0; i < this->getRows(); i++) {
        result[i] = result[i].scalar(scalar);
    }

    return result;
}
