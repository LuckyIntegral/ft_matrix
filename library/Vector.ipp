
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T>::Vector(const std::vector<T> &other)
    : size(other.size()), data(new T[size]) {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other[i];
    }
}

template <class T>
Vector<T>::Vector(const Vector &other)
    : size(other.size), data(new T[other.size]) {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] this->data;
}

template <class T>
size_t Vector<T>::getSize(void) const {
    return this->size;
}

template <class T>
T &Vector<T>::operator[](size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <class T>
const T &Vector<T>::operator[](size_t index) const {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->data[index];
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this == &other) {
        return *this;
    }
    delete[] this->data;

    this->size = other.size;
    this->data = new T[size];
    for (size_t i = 0; i < size; i++) {
        this->data[i] = other.data[i];
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
