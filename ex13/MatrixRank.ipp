
#pragma once

#include <cstddef>

#include "Matrix.hpp"

template <class T>
size_t Matrix<T>::rank(void) const noexcept(false) {
    Matrix<T> copy(*this);
    const size_t rows = this->_rows, cols = this->_cols;
    size_t rank = 0;

    for (size_t row = 0, piv = 0; row < rows && piv < cols; row++, piv++) {
        size_t i = copy.findPivot(row, piv);

        if (copy[i][piv] == T()) {
            continue;
        }

        if (i != row) {
            std::swap(copy[i], copy[row]);
        }

        rank++;

        T norm = copy[row][piv];
        copy[row] /= norm;
        copy[row].roundZeroes();

        for (size_t r = 0; r < rows; r++) {
            if (r == row) {
                continue;
            }

            const T factor = copy[r][piv];
            for (size_t col = 0; col < cols; col++) {
                copy[r][col] = std::fma(-factor, copy[row][col], copy[r][col]);
            }

            copy[r].roundZeroes();
        }
    }

    return rank;
}
