
#pragma once

#include "Matrix.hpp"

#define EPSILON 1e-5f

template <class T>
Matrix<T> Matrix<T>::row_echelon(void) const noexcept(true) {
    const size_t rows = this->getRows(), cols = this->getCols();
    Matrix<T> result(*this);

    for (size_t row = 0, pivot = 0; row < rows; row++) {
        if (pivot >= cols) {
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
            pivot++;
            row--;
            continue;
        }

        if (i != row) {
            std::swap(result[i], result[row]);
        }

        T norm = result[row][pivot];
        for (size_t col = pivot; col < cols; col++) {
            result[row][col] /= norm;

            if (std::abs(result[row][col]) < EPSILON) {
                result[row][col] = 0;
            }
        }

        for (size_t r = 0; r < rows; r++) {
            if (r == row) {
                continue;
            }

            T factor = result[r][pivot];
            for (size_t j = pivot; j < cols; j++) {
                result[r][j] -= factor * result[row][j];

                if (std::abs(result[r][j]) < EPSILON) {
                    result[r][j] = 0;
                }
            }
        }

        pivot++;
    }

    return result;
}
