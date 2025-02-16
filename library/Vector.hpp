
#pragma once

#include <iostream>
#include <vector>

#include "Matrix.hpp"

template <class T>
class Matrix;

template <class T>
class Vector {
private:
    size_t _size;
    T *_data;

public:
    Vector(const std::vector<T> &other);
    Vector(const Matrix<T> &other);
    Vector(const Vector &other);
    ~Vector();

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    Vector &operator=(const Vector &other);

    size_t getSize(void) const;
};

#include "Vector.ipp"
