
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T> Matrix<T>::transpose(void) const noexcept(true) {
    Matrix<T> result(this->getCols(), this->getRows(), 0);

    for (size_t row = 0; row < this->getRows(); row++) {
        for (size_t col = 0; col < this->getCols(); col++) {
            result[col][row] = (*this)[row][col];
        }
    }

    return result;
}
