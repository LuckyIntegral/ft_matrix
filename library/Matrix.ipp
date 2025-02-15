
#pragma once

#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(const std::vector<std::vector<T> > &other) {
    rows = other.size();
    cols = other[0].size();
    for (size_t i = 1; i < rows; i++) {
        if (other[i].size() != cols) {
            throw std::invalid_argument("Invalid matrix");
        }
    }
    data = new Vector<T> *[rows];
    for (size_t i = 0; i < rows; i++) {
        data[i] = new Vector<T>(other[i]);
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &other) : rows(other.rows), cols(other.cols) {
    data = new Vector<T> *[rows];
    for (size_t i = 0; i < rows; i++) {
        data[i] = new Vector<T>(*other.data[i]);
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for (size_t i = 0; i < rows; i++) {
        delete data[i];
    }
    delete[] data;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < rows; i++) {
        delete data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new Vector<T> *[rows];
    for (size_t i = 0; i < rows; i++) {
        data[i] = new Vector<T>(other.data[i]);
    }
    return *this;
}

template <class T>
Vector<T> &Matrix<T>::operator[](size_t row) {
    if (row >= rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *data[row];
}

template <class T>
const Vector<T> &Matrix<T>::operator[](size_t row) const {
    if (row >= rows) {
        throw std::out_of_range("Row index out of bounds");
    }
    return *data[row];
}

template <class T>
size_t Matrix<T>::getRows() const {
    return rows;
}

template <class T>
size_t Matrix<T>::getCols() const {
    return cols;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
    for (size_t i = 0; i < matrix.getRows(); i++) {
        os << matrix[i] << std::endl;
    }
    return os;
}
