#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix by vector or matrix multiplications\n";
        std::cout << "A(m x n) * u(n) = v(m)\n";
        std::cout << "Main rule: A.cols == u.size\n";
    }
    std::cout << '\n';
    {
        const Matrix<int> m1({{1, 0}, {0, 1}});
        const Vector<int> v1({4, 2});

        std::cout << "Matrix * Vector or Au\n";
        std::cout << "Matrix:\n" << m1;
        std::cout << "Vector:\t" << v1 << "\n";

        std::cout << "Manual calculation: \n";
        std::cout << "Au[0] = 1 * 4 + 0 * 2 = 4\n";
        std::cout << "Au[1] = 0 * 4 + 1 * 2 = 2\n";
        std::cout << "Matrix * Vector:\n" << m1 * v1 << '\n';
    }
    std::cout << '\n';
    {
        const Matrix<int> m1({{2, 0}, {0, 2}});
        const Vector<int> v1({4, 2});

        std::cout << "Test 2 result:" << m1 * v1 << '\n';
    }
    std::cout << '\n';
    {
        const Matrix<int> m1({{2, -2}, {-2, 2}});
        const Vector<int> v1({4, 2});

        std::cout << "Test 3 result:" << m1 * v1 << '\n';
    }
    std::cout << '\n';
    {
        std::cout << "Matrix multiplications\n";
        std::cout << "A(m x n) * B(n x p) = C(m x p)\n";
        std::cout << "Main rule: A.cols == B.rows\n";
    }
    std::cout << '\n';
    {
        const Matrix<int> m1({{1, 3, 5}, {7, 9, 11}});     // 2x3
        const Matrix<int> m2({{2, 4}, {6, 8}, {10, 12}});  // 3x2

        std::cout << "Matrix 1:\n" << m1 << '\n';
        std::cout << "Matrix 2:\n" << m2 << '\n';
        std::cout << "Manual calculation: \n";
        std::cout << "A(2x3) * B(3x2) = C(2x2)\n";
        std::cout
            << "C[0][0] = 1 * 2 + 3 * 6 + 5 * 10 = 2 + 18 + 50 = 70\n"
            << "C[0][1] = 1 * 4 + 3 * 8 + 5 * 12 = 4 + 24 + 60 = 88\n"
            << "C[1][0] = 7 * 2 + 9 * 6 + 11 * 10 = 14 + 54 + 110 = 178\n"
            << "C[1][1] = 7 * 4 + 9 * 8 + 11 * 12 = 28 + 72 + 132 = 232\n";
        std::cout << "Matrix 1 * Matrix 2:\n" << m1 * m2 << '\n';
    }
    std::cout << '\n';
    {
        const Matrix<int> m1({{1, 0}, {0, 1}});
        const Matrix<int> m2({{1, 0}, {0, 1}});

        std::cout << "Test 5 result:\n" << m1 * m2 << '\n';
    }
    return 0;
}
