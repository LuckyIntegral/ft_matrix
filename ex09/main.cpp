#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    std::cout << "Transpose of a matrix" << std::endl;
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix 1:\n" << m1 << std::endl;
        std::cout << "Transpose of Matrix 1:\n" << m1.transpose() << std::endl;
    }
    std::cout << "Properties of transpose" << std::endl;
    {
        std::cout << "1. Transpose(Transpose(A)) = A" << std::endl;
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix 1:\n" << m1 << std::endl;
        std::cout << "Transpose of transpose of Matrix 1:\n"
                  << m1.transpose().transpose() << std::endl;
    }
    {
        std::cout << "2. Transpose(A * B) = Transpose(B) * Transpose(A)"
                  << std::endl;
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
        Matrix<int> m2({{7, 8}, {9, 10}, {11, 12}});

        std::cout << "Transpose(A * B):\n"
                  << (m1 * m2).transpose() << std::endl;
        std::cout << "Transpose(B) * Transpose(A):\n"
                  << m2.transpose() * m1.transpose() << std::endl;
    }
    {
        std::cout << "2. Transpose(A + B) = Transpose(A) + Transpose(B)"
                  << std::endl;
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        Matrix<int> m2({{7, 8, 9}, {10, 11, 12}, {13, 14, 15}});

        std::cout << "Transpose(A + B):\n"
                  << (m1 + m2).transpose() << std::endl;
        std::cout << "Transpose(A) + Transpose(B):\n"
                  <<  m1.transpose() + m2.transpose() << std::endl;
    }
    return 0;
}
