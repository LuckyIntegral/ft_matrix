#pragma once

#include "Matrix.hpp"

#define EPSILON 1e-5f

template <class T>
T Matrix<T>::determinant(void) const noexcept(false) {
    if (!this->isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    if (this->getRows() == 1) {
        return (*this)[0][0];
    }

    if (this->getRows() == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    const size_t rows = this->getRows();
    Matrix<T> result(*this);
    T det = 1;
    int swaps = 0;

    for (size_t row = 0, pivot = 0; row < rows; row++) {
        if (pivot >= rows) {
            break;
        }

        size_t i = row;
        T maxVal = std::abs(result[row][pivot]);
        for (size_t r = row + 1; r < rows; r++) {
            if (std::abs(result[r][pivot]) > maxVal) {
                maxVal = std::abs(result[r][pivot]);
                i = r;
            }
        }

        if (maxVal < EPSILON) {
            return 0;
        }

        if (i != row) {
            std::swap(result[i], result[row]);
            swaps++;
        }

        det *= result[row][pivot];

        if (det == 0) {
            return 0;
        }

        for (size_t r = row + 1; r < rows; r++) {
            T factor = result[r][pivot] / result[row][pivot];

            for (size_t j = pivot; j < rows; j++) {
                result[r][j] = std::fma(-factor, result[row][j], result[r][j]);

                if (std::abs(result[r][j]) < EPSILON) {
                    result[r][j] = 0;
                }
            }
        }

        pivot++;
    }

    return (swaps % 2 == 0) ? det : -det;
}
