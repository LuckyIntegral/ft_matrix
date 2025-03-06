
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Row-echelon form of a matrix\n";
        const Matrix<float> m1({
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        });
        const Matrix<float> expected({
            {1, 0, -1},
            {0, 1, 2},
            {0, 0, 0},
        });

        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Expected:\n" << expected;
        std::cout << "Result:\n" << m1.rowEchelon();
    }
    return 0;
}
