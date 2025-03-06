
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T> linear_combination(Vector<Vector<T>> &vectors,
                             Vector<T> &coefficients);

#include "linear_combination.ipp"
