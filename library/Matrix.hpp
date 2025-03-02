
#pragma once

#include <initializer_list>

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
    Matrix(const std::initializer_list<std::initializer_list<T>> &list);
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

    Matrix<T> add(const Matrix<T> &other) const noexcept(false);
    Matrix<T> sub(const Matrix<T> &other) const noexcept(false);
    Matrix<T> scalar(const T &scalar) const noexcept(false);

    Matrix<T> operator+(const Matrix<T> &other) const noexcept(false);
    Matrix<T> operator-(const Matrix<T> &other) const noexcept(false);
    Matrix<T> operator*(const T &scalar) const noexcept(false);

    Vector<T> mult(const Vector<T> &other) const noexcept(false);
    Matrix<T> mult(const Matrix<T> &other) const noexcept(false);
    Vector<T> operator*(const Vector<T> &vec) const noexcept(false);
    Matrix<T> operator*(const Matrix<T> &other) const noexcept(false);

    T trace(void) const noexcept(false);
    Matrix<T> transpose(void) const noexcept(true);
    Matrix<T> row_echelon(void) const noexcept(true);
    T determinant(void) const noexcept(false);
};

#include "../ex00/MatrixBasics.ipp"
#include "../ex07/MatrixMult.ipp"
#include "../ex08/MatrixTrace.ipp"
#include "../ex09/MatrixTranspose.ipp"
#include "../ex10/MatrixREF.ipp"
#include "../ex11/MatrixDeterminant.ipp"
#include "Matrix.ipp"
