
#pragma once

#include <initializer_list>

#include "Matrix.hpp"

template <class T>
class Matrix;

template <class T>
class Vector {
private:
    size_t _size;
    T *_data;

public:
    Vector();
    Vector(const size_t size, const T &value);
    Vector(const std::initializer_list<T> &list);
    Vector(const Matrix<T> &other);
    Vector(const Vector &other);
    ~Vector();

    size_t getSize(void) const;

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    Vector &operator=(const Vector &other);

    Vector<T> add(const Vector<T> &other) const noexcept(false);
    Vector<T> sub(const Vector<T> &other) const noexcept(false);
    Vector<T> scalar(const T &scalar) const noexcept(false);

    Vector<T> operator+(const Vector<T> &other) const noexcept(false);
    Vector<T> operator-(const Vector<T> &other) const noexcept(false);
    Vector<T> operator*(const T &scalar) const noexcept(false);
};

template <class T>
Vector<T> linear_combination(Vector<Vector<T>> &vectors,
                             Vector<T> &coefficients) noexcept(false);

// template <class T>
// Vector<T> lerp(const Vector<T> &vec1, const Vector<T> &vec2, float t);

#include "../ex00/VectorBasics.ipp"
#include "../ex01/VectorLinearCombination.ipp"
#include "Vector.ipp"
