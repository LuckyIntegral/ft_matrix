
#pragma once

#include "Matrix.hpp"

template <class T>
T Matrix<T>::determinant(void) const {
    if (!this->isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    if (this->getRows() == 1) {
        return (*this)[0][0];
    }

    if (this->getRows() == 2) {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    const size_t size = this->getRows();
    Matrix<T> result(*this);
    int swaps = 0;
    T det = 1;

    for (size_t row = 0, piv = 0; row < size && piv == row; row++, piv++) {
        size_t i = result.findPivot(row, piv);

        if (result[i][piv] == T()) {
            return 0;
        }

        if (i != row) {
            std::swap(result[i], result[row]);
            swaps++;
        }

        det *= result[row][piv];

        for (size_t r = row + 1; r < size; r++) {
            const T factor = result[r][piv] / result[row][piv];

            for (size_t j = piv; j < size; j++) {
                result[r][j] = std::fma(-factor, result[row][j], result[r][j]);
            }

            result[r].roundZeroes();
        }
    }

    return (swaps % 2 == 0) ? det : -det;
}
