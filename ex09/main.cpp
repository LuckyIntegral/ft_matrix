#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Transpose of a matrix\n";
        const Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix 1:\n" << m1 << '\n';
        std::cout << "Transpose of Matrix 1:\n" << m1.transpose() << '\n';
    }
    std::cout << '\n';
    {
        std::cout << "Properties of transpose" << '\n';
        std::cout << "1. Transpose(Transpose(A)) = A" << '\n';
        const Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix 1:\n" << m1 << '\n';
        std::cout << "Transpose of transpose of Matrix 1:\n"
                  << m1.transpose().transpose() << '\n';
    }
    {
        std::cout << "2. Transpose(A * B) = Transpose(B) * Transpose(A)\n";
        const Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
        const Matrix<int> m2({{7, 8}, {9, 10}, {11, 12}});

        std::cout << "Transpose(A * B):\n" << (m1 * m2).transpose() << '\n';
        std::cout << "Transpose(B) * Transpose(A):\n"
                  << m2.transpose() * m1.transpose() << '\n';
    }
    return 0;
}
