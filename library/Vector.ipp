
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T>::Vector(const std::vector<T> &other)
    : _size(other.size()), _data(new T[_size]) {
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = other[i];
    }
}

template <class T>
Vector<T>::Vector(const Matrix<T> &other) {
    this->_size = other.getCols() * other.getRows();
    this->_data = new T[this->_size];

    const auto &cols = other.getCols();
    for (size_t row = 0; row < other.getRows(); row++) {
        for (size_t col = 0; col < other.getCols(); col++) {
            this->_data[row * cols + col] = other[row][col];
        }
    }
}

template <class T>
Vector<T>::Vector(const Vector &other)
    : _size(other._size), _data(new T[other._size]) {
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] this->_data;
}

template <class T>
size_t Vector<T>::getSize(void) const {
    return this->_size;
}

template <class T>
T &Vector<T>::operator[](size_t index) {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->_data[index];
}

template <class T>
const T &Vector<T>::operator[](size_t index) const {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->_data[index];
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this == &other) {
        return *this;
    }
    delete[] this->_data;

    this->_size = other._size;
    this->_data = new T[this->_size];
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec) {
    for (size_t i = 0; i < vec.getSize(); i++) {
        os << vec[i] << " ";
    }
    return os;
}
