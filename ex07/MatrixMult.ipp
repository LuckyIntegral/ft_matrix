
#pragma once

#include <cmath>

#include "Matrix.hpp"

template <class T>
Vector<T> Matrix<T>::mult(const Vector<T> &other) const noexcept(false) {
    if (this->_cols != other.getSize()) {
        throw std::invalid_argument("Dimensions do not match");
    }

    Vector<T> result(this->_rows, 0);

    for (size_t row = 0; row < this->_rows; row++) {
        for (size_t col = 0; col < this->_cols; col++) {
            result[row] = std::fma((*this)[row][col], other[col], result[row]);
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::mult(const Matrix<T> &other) const noexcept(false) {
    if (this->_cols != other._rows) {
        throw std::invalid_argument("Dimensions do not match");
    }

    Matrix<T> result(this->_rows, other._cols, 0);

    for (size_t row = 0; row < this->_rows; row++) {
        for (size_t col = 0; col < other._cols; col++) {
            for (size_t i = 0; i < this->_cols; i++) {
                result[row][col] = std::fma((*this)[row][i], other[i][col], result[row][col]);
            }
        }
    }

    return result;
}

template <class T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vec) const noexcept(false) {
    return this->mult(vec);
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const noexcept(false) {
    return this->mult(other);
}
