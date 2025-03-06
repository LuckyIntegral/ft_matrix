
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T> Matrix<T>::identity(size_t n) noexcept {
    Matrix<T> identity(n, n, 0);

    for (size_t i = 0; i < n; i++) {
        identity[i][i] = 1;
    }
    return identity;
}

template <class T>
Matrix<T> Matrix<T>::inverse(void) const {
    if (!this->isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    const size_t size = this->getRows();
    Matrix<T> copy(*this);
    Matrix<T> inv = Matrix<T>::identity(size);

    for (size_t row = 0, piv = 0; row < size && piv == row; row++, piv++) {
        size_t i = copy.findPivot(row, piv);

        if (copy[i][piv] == T()) {
            throw std::runtime_error("Matrix cannot be inverted");
        }

        if (i != row) {
            std::swap(copy[i], copy[row]);
            std::swap(inv[i], inv[row]);
        }

        T norm = copy[row][piv];

        copy[row] /= norm;
        copy[row].roundZeroes();
        inv[row] /= norm;
        inv[row].roundZeroes();

        for (size_t r = 0; r < size; r++) {
            if (r == row) {
                continue;
            }

            const T factor = copy[r][piv];
            for (size_t col = 0; col < size; col++) {
                copy[r][col] = std::fma(-factor, copy[row][col], copy[r][col]);
                inv[r][col] = std::fma(-factor, inv[row][col], inv[r][col]);
            }

            copy[r].roundZeroes();
            inv[r].roundZeroes();
        }
    }

    return inv;
}
