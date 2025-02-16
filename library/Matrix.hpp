
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

    Matrix &operator=(const Matrix &other);

    Vector<T> &operator[](size_t row);
    const Vector<T> &operator[](size_t row) const;

    size_t getRows() const;
    size_t getCols() const;

    bool isSquare() const;
};

#include "Matrix.ipp"
