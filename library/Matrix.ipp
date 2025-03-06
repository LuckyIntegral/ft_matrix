
#pragma once

#include <iostream>

#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix() noexcept
    : _rows(0), _cols(0), _data(std::make_unique<Vector<T>[]>(0)) {
}

template <class T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T &value) noexcept
    : _rows(rows),
      _cols(cols),
      _data(std::make_unique<Vector<T>[]>(this->_rows)) {
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = Vector<T>(this->_cols, value);
    }
}

template <class T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &list)
    : _rows(list.size()) {
    if (this->_rows == 0) {
        this->_cols = 0;
        this->_data = std::make_unique<Vector<T>[]>(0);
        return;
    }

    this->_cols(list.begin()->size());
    this->_data = std::make_unique<Vector<T>[]>(list.size());

    for (const auto &row : list) {
        if (row.size() != _cols) {
            throw std::invalid_argument("Invalid matrix");
        }
    }

    size_t i = 0;
    for (const auto &row : list) {
        this->_data[i++] = Vector<T>(row);
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other) noexcept
    : _rows(other._rows),
      _cols(other._cols),
      _data(std::make_unique<Vector<T>[]>(other._rows)) {
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = Vector<T>(other._data[i]);
    }
}

template <class T>
Matrix<T>::~Matrix() {
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_data = std::make_unique<Vector<T>[]>(this->_rows);
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = other._data[i];
    }
    return *this;
}

template <class T>
Vector<T> &Matrix<T>::operator[](size_t row) {
    if (row >= this->_rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return _data[row];
}

template <class T>
const Vector<T> &Matrix<T>::operator[](size_t row) const {
    if (row >= this->_rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return _data[row];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &other) const noexcept {
    if (this->_rows != other._rows || this->_cols != other._cols) {
        return false;
    }

    for (size_t i = 0; i < this->_rows; i++) {
        if (this->_data[i] != other._data[i]) {
            return false;
        }
    }

    return true;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &other) const noexcept {
    return !(*this == other);
}

template <class T>
size_t Matrix<T>::getRows() const noexcept {
    return this->_rows;
}

template <class T>
size_t Matrix<T>::getCols() const noexcept {
    return this->_cols;
}

template <class T>
bool Matrix<T>::isSquare() const noexcept {
    return this->_rows == this->_cols;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.getRows(); i++) {
        os << matrix[i] << std::endl;
    }
    return os;
}
