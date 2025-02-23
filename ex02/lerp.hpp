
#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"

template <class T>
T lerp(const T &u, const T &v, float t);

template <class T>
Vector<T> lerp(const Vector<T> &u, const Vector<T> &v, float t);

template <class T>
Matrix<T> lerp(const Matrix<T> &u, const Matrix<T> &v, float t);

#include "lerp.ipp"
