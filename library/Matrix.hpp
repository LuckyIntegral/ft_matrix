
#pragma once

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
    Matrix();
    Matrix(size_t rows, size_t cols, const T &value);
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

    Matrix<T> add(const Matrix<T> &other) noexcept(false);
    Matrix<T> sub(const Matrix<T> &other) noexcept(false);
    Matrix<T> scalar(const T &scalar) noexcept(false);
};

// template <class T>
// Matrix<T> lerp(const Matrix<T> &vec1, const Matrix<T> &vec2, float t);

#include "../ex00/MatrixBasics.ipp"
#include "../ex02/lerp.ipp"
#include "Matrix.ipp"
