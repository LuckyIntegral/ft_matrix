
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

    size_t getSize(void) const;

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    Vector &operator=(const Vector &other);

    void add(const Vector<T> &other) noexcept(false);
    void sub(const Vector<T> &other) noexcept(false);
    void scalar(const T &scalar) noexcept(false);
};

#include "../ex00/VectorBasics.ipp"
#include "Vector.ipp"
