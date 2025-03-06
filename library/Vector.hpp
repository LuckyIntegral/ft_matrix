
#pragma once

#include <initializer_list>
#include <memory>

#include "Matrix.hpp"

#define EPSILON_FLOAT 1e-5f
#define EPSILON_DOUBLE 1e-12
#define EPSILON_LONG_DOUBLE 1e-15

template <class T>
class Matrix;

template <class T>
class Vector {
private:
    size_t _size;
    std::unique_ptr<T[]> _data;

public:
    Vector() noexcept;
    Vector(const size_t size, const T &value) noexcept;
    Vector(const std::initializer_list<T> &list) noexcept;
    Vector(const Vector &other) noexcept;
    ~Vector() = default;

    size_t getSize(void) const noexcept;

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    bool operator==(const Vector &other) const noexcept;
    bool operator!=(const Vector &other) const noexcept;

    Vector &operator=(const Vector &other) noexcept;

    Vector<T> add(const Vector<T> &other) const;
    Vector<T> sub(const Vector<T> &other) const;
    Vector<T> scalar(const T &scalar) const noexcept;

    Vector<T> operator+(const Vector<T> &other) const;
    Vector<T> operator-(const Vector<T> &other) const;
    Vector<T> operator*(const T &scalar) const noexcept;

    T dotProduct(const Vector<T> &other) const;

    float normManhattan(void) const noexcept;
    float normEuclidean(void) const noexcept;
    float normSupremum(void) const noexcept;

    void operator/=(const T &value) noexcept;
    void roundZeroes(void) noexcept;
};

#include "../ex00/VectorBasics.ipp"
#include "../ex03/VectorDotProduct.ipp"
#include "../ex04/VectorNorm.ipp"
#include "Vector.ipp"
