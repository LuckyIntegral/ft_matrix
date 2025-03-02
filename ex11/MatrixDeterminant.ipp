
#pragma once

#include "Matrix.hpp"

#define EPSILON 1e-5f

template <class T>
T Matrix<T>::determinant(void) const noexcept(false) {
    if (!isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    if (this->_rows == 1) {
        return (*this)[0][0];
    }

    if (this->_rows == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    T det = 0;

    for (size_t i = 0; i < this->_rows; i++) {
        Matrix<T> m = minor(*this, 0, i);
        if (i % 2 == 0) {
            det += (*this)[0][i] * m.determinant();
        } else {
            det -= (*this)[0][i] * m.determinant();
        }
    }

    return det;
}

template <class T>
static Matrix<T> minor(const Matrix<T> &matrix, size_t row,
                       size_t col) noexcept(true) {
    Matrix<T> result(matrix.getRows() - 1, matrix.getCols() - 1, 0);

    for (size_t i = 0, r = 0; i < matrix.getRows(); i++, r++) {
        if (i == row) {
            r--;
            continue;
        }

        for (size_t j = 0, c = 0; j < matrix.getCols(); j++, c++) {
            if (j == col) {
                c--;
                continue;
            }

            result[r][c] = matrix[i][j];
        }
    }

    return result;
}
