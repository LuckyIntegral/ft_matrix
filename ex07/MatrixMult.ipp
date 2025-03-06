
#pragma once

#include "Matrix.hpp"

template <class T>
Vector<T> Matrix<T>::mult(const Vector<T> &other) const {
    if (this->_cols != other.getSize()) {
        throw std::invalid_argument("Dimensions do not match");
    }

    Vector<T> result(this->_rows, 0);

    for (size_t row = 0; row < this->_rows; row++) {
        result[row] = (*this)[row].dotProduct(other);
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::mult(const Matrix<T> &other) const {
    if (this->_cols != other._rows) {
        throw std::invalid_argument("Dimensions do not match");
    }

    const Matrix<T> transposed = other.transpose();

    Matrix<T> result(this->_rows, other._cols, 0);

    for (size_t row = 0; row < result.getRows(); row++) {
        for (size_t col = 0; col < result.getCols(); col++) {
            result[row][col] = (*this)[row].dotProduct(transposed[col]);
        }
    }

    return result;
}

template <class T>
Vector<T> Matrix<T>::operator*(const Vector<T> &vec) const {
    return this->mult(vec);
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    return this->mult(other);
}
