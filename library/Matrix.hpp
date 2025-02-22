
#pragma once

#include <iostream>
#include <vector>

#include "Vector.hpp"

template <class T>
class Vector;

template <class T>
class Matrix {
private:
    size_t _rows;
    size_t _cols;
    Vector<T> **_data;

public:
    Matrix(const std::vector<std::vector<T> > &other);
    Matrix(const Vector<T> &other);
    Matrix(const Matrix &other);
    ~Matrix();

    bool isSquare() const;
    size_t getRows() const;
    size_t getCols() const;

    Vector<T> &operator[](size_t row);
    const Vector<T> &operator[](size_t row) const;
    bool operator==(const Matrix &other) const;
    bool operator!=(const Matrix &other) const;

    Matrix &operator=(const Matrix &other);

    void add(const Matrix<T> &other) noexcept(false);
    void sub(const Matrix<T> &other) noexcept(false);
    void scalar(const T &scalar) noexcept(false);
};

#include "../ex00/MatrixBasics.ipp"
#include "Matrix.ipp"
