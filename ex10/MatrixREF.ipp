
#pragma once

#include "Matrix.hpp"

template <class T>
size_t Matrix<T>::findPivot(size_t row, size_t piv) const noexcept(true) {
    const size_t rows = (*this).getRows();
    size_t i = row;
    T maxVal = std::abs((*this)[row][piv]);

    for (size_t r = row + 1; r < rows; r++) {
        if (std::abs((*this)[r][piv]) > maxVal) {
            maxVal = std::abs((*this)[r][piv]);
            i = r;
        }
    }

    return i;
}

template <class T>
Matrix<T> Matrix<T>::rowEchelon(void) const noexcept(true) {
    const size_t rows = this->getRows(), cols = this->getCols();
    Matrix<T> result(*this);

    for (size_t row = 0, piv = 0; row < rows && piv < cols; row++, piv++) {
        size_t i = result.findPivot(row, piv);

        if (result[i][piv] == T()) {
            row--;
            continue;
        }

        if (i != row) {
            std::swap(result[i], result[row]);
        }

        const T norm = result[row][piv];
        result[row] /= norm;
        result[row].roundZeroes();

        for (size_t r = 0; r < rows; r++) {
            if (r == row) {
                continue;
            }

            const T factor = result[r][piv];
            for (size_t j = piv; j < cols; j++) {
                result[r][j] = std::fma(-factor, result[row][j], result[r][j]);
            }

            result[r].roundZeroes();
        }
    }

    return result;
}
