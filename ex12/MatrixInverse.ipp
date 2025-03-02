#pragma once

#include "Matrix.hpp"

#define EPSILON 1e-5f

template <class T>
Matrix<T> Matrix<T>::inverse(void) const noexcept(false) {
    if (!this->isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    const size_t n = this->getRows();
    Matrix<T> augmented(*this);
    Matrix<T> inverse = Matrix<T>::identity(n);

    for (size_t row = 0, pivot = 0; row < n; row++) {
        if (pivot >= n) {
            break;
        }

        size_t i = row;
        T maxVal = std::abs(augmented[row][pivot]);
        for (size_t r = row + 1; r < n; r++) {
            if (std::abs(augmented[r][pivot]) > maxVal) {
                maxVal = std::abs(augmented[r][pivot]);
                i = r;
            }
        }

        if (maxVal < EPSILON) {
            throw std::runtime_error("Matrix cannot be inverted");
        }

        if (i != row) {
            std::swap(augmented[i], augmented[row]);
            std::swap(inverse[i], inverse[row]);
        }

        T norm = augmented[row][pivot];
        for (size_t col = 0; col < n; col++) {
            augmented[row][col] /= norm;
            inverse[row][col] /= norm;
        }

        for (size_t r = 0; r < n; r++) {
            if (r == row) {
                continue;
            }

            T factor = augmented[r][pivot];
            for (size_t col = 0; col < n; col++) {
                augmented[r][col] =
                    std::fma(-factor, augmented[row][col], augmented[r][col]);
                inverse[r][col] =
                    std::fma(-factor, inverse[row][col], inverse[r][col]);

                if (std::abs(augmented[r][col]) < EPSILON)
                    augmented[r][col] = 0;
                if (std::abs(inverse[r][col]) < EPSILON)
                    inverse[r][col] = 0;
            }
        }

        pivot++;
    }

    return inverse;
}

template <class T>
Matrix<T> Matrix<T>::identity(size_t n) noexcept(false) {
    Matrix<T> identity(n, n, 0);

    for (size_t i = 0; i < n; i++) {
        identity[i][i] = 1;
    }
    return identity;
}
