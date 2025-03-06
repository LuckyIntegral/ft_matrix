
#pragma once

#include <iostream>

#include "Vector.hpp"

template <class T>
Vector<T>::Vector() noexcept : _size(0), _data(std::make_unique<T[]>(_size)) {
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> &list) noexcept
    : _size(list.size()), _data(std::make_unique<T[]>(list.size())) {
    size_t i = 0;

    for (const T &elem : list) {
        this->_data[i++] = elem;
    }
}

template <class T>
Vector<T>::Vector(const size_t size, const T &value) noexcept
    : _size(size), _data(std::make_unique<T[]>(size)) {
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = value;
    }
}

template <class T>
Vector<T>::Vector(const Vector &other) noexcept
    : _size(other.getSize()), _data(std::make_unique<T[]>(other.getSize())) {
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
}

template <class T>
size_t Vector<T>::getSize(void) const noexcept {
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
bool Vector<T>::operator==(const Vector &other) const noexcept {
    if (this->_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < this->_size; i++) {
        if (this->_data[i] != other._data[i]) {
            return false;
        }
    }
    return true;
}

// Specialization for floating-point types
template <>
bool Vector<float>::operator==(const Vector &other) const noexcept {
    if (this->_size != other._size) {
        return false;
    }
    const float epsilon = 1e-5;
    for (size_t i = 0; i < this->_size; i++) {
        if (std::fabs(this->_data[i] - other._data[i]) > epsilon) {
            return false;
        }
    }
    return true;
}

template <>
bool Vector<double>::operator==(const Vector &other) const noexcept {
    if (this->_size != other._size) {
        return false;
    }
    const double epsilon = 1e-9;
    for (size_t i = 0; i < this->_size; i++) {
        if (std::fabs(this->_data[i] - other._data[i]) > epsilon) {
            return false;
        }
    }
    return true;
}

template <class T>
bool Vector<T>::operator!=(const Vector &other) const noexcept {
    return !(*this == other);
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector &other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->_size = other._size;
    this->_data = std::make_unique<T[]>(this->_size);
    for (size_t i = 0; i < this->_size; i++) {
        this->_data[i] = other._data[i];
    }
    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vec) noexcept {
    for (size_t i = 0; i < vec.getSize(); i++) {
        os << vec[i] << "\t";
    }
    return os;
}
