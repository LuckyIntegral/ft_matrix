
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
    std::unique_ptr<Vector<T>[]> _data;

public:
    Matrix() noexcept;
    Matrix(size_t rows, size_t cols, const T &value) noexcept;
    Matrix(const std::initializer_list<std::initializer_list<T>> &list);
    Matrix(const Matrix &other) noexcept;
    ~Matrix();

    bool isSquare() const noexcept;
    size_t getRows() const noexcept;
    size_t getCols() const noexcept;

    Vector<T> &operator[](size_t row);
    const Vector<T> &operator[](size_t row) const;
    bool operator==(const Matrix &other) const noexcept;
    bool operator!=(const Matrix &other) const noexcept;

    Matrix &operator=(const Matrix &other) noexcept;

    Matrix<T> add(const Matrix<T> &other) const;
    Matrix<T> sub(const Matrix<T> &other) const;
    Matrix<T> scalar(const T &scalar) const noexcept;

    Matrix<T> operator+(const Matrix<T> &other) const;
    Matrix<T> operator-(const Matrix<T> &other) const;
    Matrix<T> operator*(const T &scalar) const noexcept;

    Vector<T> mult(const Vector<T> &other) const;
    Matrix<T> mult(const Matrix<T> &other) const;
    Vector<T> operator*(const Vector<T> &vec) const;
    Matrix<T> operator*(const Matrix<T> &other) const;

    T trace(void) const;

    Matrix<T> transpose(void) const noexcept;

    size_t findPivot(size_t row, size_t pivot) const noexcept;
    Matrix<T> rowEchelon(void) const noexcept;
    T determinant(void) const;
    Matrix<T> inverse(void) const;
    size_t rank(void) const noexcept;

    static Matrix<T> identity(size_t n) noexcept;
};

#include "../ex00/MatrixBasics.ipp"
#include "../ex07/MatrixMult.ipp"
#include "../ex08/MatrixTrace.ipp"
#include "../ex09/MatrixTranspose.ipp"
#include "../ex10/MatrixREF.ipp"
#include "../ex11/MatrixDeterminant.ipp"
#include "../ex12/MatrixInverse.ipp"
#include "../ex13/MatrixRank.ipp"
#include "Matrix.ipp"
