#ifndef FT_MATRIX_VECTOR_HPP
#define FT_MATRIX_VECTOR_HPP

#include <iostream>
#include <vector>

template <class T>
class Vector {
private:
    size_t size;
    T *data;

public:
    Vector(const std::vector<T> &other);
    Vector(const Vector &other);
    ~Vector();

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    Vector &operator=(const Vector &other);

    size_t getSize(void) const;
};

#include "Vector.ipp"

#endif  // FT_MATRIX_VECTOR_HPP
