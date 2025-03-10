
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T> Matrix<T>::add(const Matrix<T> &other) const {
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
Matrix<T> Matrix<T>::sub(const Matrix<T> &other) const {
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
Matrix<T> Matrix<T>::scalar(const T &scalar) const noexcept {
    Matrix<T> result(*this);

    for (size_t i = 0; i < this->getRows(); i++) {
        result[i] = result[i].scalar(scalar);
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
    return this->add(other);
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {
    return this->sub(other);
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const noexcept {
    return this->scalar(scalar);
}
