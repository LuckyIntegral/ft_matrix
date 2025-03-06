
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix determinant\n";
        std::cout << "properties:\n"
                  << "1. Matrix must be square\n"
                  << "2. Matrix of size 1 has determinant equal to its only "
                     "element\n";
    }
    {
        const Matrix<float> m1({
            {2, 3},
            {1, 4},
        });
        std::cout << "Matrix 1:\n"
                  << m1 << "Determinant: " << m1.determinant() << '\n';
    }
    {
        const Matrix<float> m1({
            {7, 5, 2},
            {4, 1, 3},
            {8, 6, 9},
        });

        std::cout << "Matrix 2:\n"
                  << m1 << "Determinant: " << m1.determinant() << '\n';
    }
    return 0;
}
