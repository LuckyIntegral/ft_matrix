#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix trace is the sum of the diagonal elements\n";
        std::cout << "Main rule: Matrix must be square\n";
        std::cout << "Also, tr(AB) = tr(BA)\n";
    }
    {
        const Matrix<int> m1({
            {1, 0},
            {0, 1},
        });

        std::cout << "Test 1 result: " << m1.trace() << '\n';
    }
    {
        const Matrix<int> m1({
            {2, -5, 0},
            {4, 3, 7},
            {-2, 3, 4},
        });

        std::cout << "Test 2 result: " << m1.trace() << '\n';
    }
    {
        const Matrix<int> m1({
            {-2, -8, 4},
            {1, -23, 4},
            {0, 6, 4},
        });

        std::cout << "Test 3 result: " << m1.trace() << '\n';
    }
    {
        const Matrix<int> m1({
            {8, 5},
            {3, 4},
        });
        const Matrix<int> m2({
            {1, 2},
            {9, 4},
        });

        std::cout << "Test 4 result: tr(AB) = " << (m1 * m2).trace()
                  << "; tr(BA) = " << (m2 * m1).trace() << '\n';
    }
    return 0;
}
