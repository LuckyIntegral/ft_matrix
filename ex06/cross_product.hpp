
#pragma once

#include "Vector.hpp"

template <class T>
Vector<T> cross_product(const Vector<T> &, const Vector<T> &) noexcept(false);

#include "cross_product.ipp"
