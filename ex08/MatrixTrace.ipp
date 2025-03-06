
#pragma once

#include "Matrix.hpp"

template <class T>
T Matrix<T>::trace(void) const noexcept(false) {
    if (!this->isSquare()) {
        throw std::invalid_argument("Matrix must be square");
    }

    T result = 0;

    for (size_t i = 0; i < this->_rows; i++) {
        result += (*this)[i][i];
    }

    return result;
}
