
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(const std::vector<std::vector<T> > &other)
    : _rows(other.size()), _cols(other[0].size()) {
    for (size_t i = 1; i < _rows; i++) {
        if (other[i].size() != _cols) {
            throw std::invalid_argument("Invalid matrix");
        }
    }
    this->_data = new Vector<T> *[this->_rows];
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = new Vector<T>(other[i]);
    }
}

template <class T>
Matrix<T>::Matrix(const Vector<T> &other) : _rows(1), _cols(other.getSize()) {
    this->_data = new Vector<T> *[1];
    this->_data[0] = new Vector<T>(other);
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other)
    : _rows(other._rows), _cols(other._cols) {
    this->_data = new Vector<T> *[this->_rows];
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = new Vector<T>(*other._data[i]);
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for (size_t i = 0; i < this->_rows; i++) {
        delete this->_data[i];
    }
    delete[] this->_data;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < this->_rows; i++) {
        delete this->_data[i];
    }
    delete[] this->_data;

    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_data = new Vector<T> *[_rows];
    for (size_t i = 0; i < this->_rows; i++) {
        this->_data[i] = new Vector<T>(other._data[i]);
    }
    return *this;
}

template <class T>
Vector<T> &Matrix<T>::operator[](size_t row) {
    if (row >= this->_rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *_data[row];
}

template <class T>
const Vector<T> &Matrix<T>::operator[](size_t row) const {
    if (row >= this->_rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *_data[row];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &other) const {
    if (this->_rows != other._rows || this->_cols != other._cols) {
        return false;
    }

    for (size_t i = 0; i < this->_rows; i++) {
        if (*this->_data[i] != *other._data[i]) {
            return false;
        }
    }

    return true;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &other) const {
    return !(*this == other);
}

template <class T>
size_t Matrix<T>::getRows() const {
    return this->_rows;
}

template <class T>
size_t Matrix<T>::getCols() const {
    return this->_cols;
}

template <class T>
bool Matrix<T>::isSquare() const {
    return this->_rows == this->_cols;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.getRows(); i++) {
        os << matrix[i] << std::endl;
    }
    return os;
}
