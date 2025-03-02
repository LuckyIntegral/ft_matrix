
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix determinant" << std::endl;
        std::cout << "properties:" << std::endl;
        std::cout << "1. Matrix must be square" << std::endl;
        std::cout
            << "2. Matrix of size 1 has determinant equal to its only element"
            << std::endl;
        std::cout << "3. Matrix of size 2 has determinant equal to ad - bc"
                  << std::endl;
        std::cout << "4. Matrix of size 3 or more has determinant calculated "
                     "by sum of products of elements and their minors"
                  << std::endl;
    }
    {
        Matrix<float> m1({
            {2, 3},
            {1, 4},
        });
        std::cout << "Matrix 1:\n"
                  << m1 << "Determinant: " << m1.determinant() << std::endl;
    }
    {
        Matrix<float> m1({
            {7, 5, 2},
            {4, 1, 3},
            {8, 6, 9},
        });

        std::cout << "Matrix 2:\n"
                  << m1 << "Determinant: " << m1.determinant() << std::endl;
    }
    return 0;
}
