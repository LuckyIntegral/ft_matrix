#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix by vector or matrix multiplications" << std::endl;
        std::cout << "A(m x n) * u(n) = v(m)" << std::endl;
        std::cout << "Main rule: A.cols == u.size" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Matrix * Vector or Au" << std::endl;
        Matrix<int> m1({{1, 0}, {0, 1}});
        Vector<int> v1({4, 2});
        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Vector 1: {" << v1 << "}" << std::endl;
        std::cout << "Manual calculation: " << std::endl;
        std::cout << "Au[0] = 1 * 4 + 0 * 2 = 4" << std::endl;
        std::cout << "Au[1] = 0 * 4 + 1 * 2 = 2" << std::endl;
        std::cout << "Au 1: {" << v1 << "}\n" << std::endl;
    }
    {
        Matrix<int> m1({{2, 0}, {0, 2}});
        Vector<int> v1({4, 2});
        std::cout << "Test 2 result:" << m1 * v1 << std::endl;
    }
    {
        Matrix<int> m1({{2, -2}, {-2, 2}});
        Vector<int> v1({4, 2});
        std::cout << "Test 3 result:" << m1 * v1 << std::endl;
    }
    {
        std::cout << "\n\nMatrix multiplications" << std::endl;
        std::cout << "A(m x n) * B(n x p) = C(m x p)" << std::endl;
        std::cout << "Main rule: A.cols == B.rows" << std::endl;
        std::cout << std::endl;
    }
    {
        Matrix<int> m1({{1, 3, 5}, {7, 9, 11}});     // 2x3
        Matrix<int> m2({{2, 4}, {6, 8}, {10, 12}});  // 3x2
        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Matrix 2:\n" << m2;
        std::cout << "Manual calculation: " << std::endl;
        std::cout << "A(2x3) * B(3x2) = C(2x2)" << std::endl;
        std::cout
            << "C[0][0] = 1 * 2 + 3 * 6 + 5 * 10 = 2 + 18 + 50 = 70\n"
            << "C[0][1] = 1 * 4 + 3 * 8 + 5 * 12 = 4 + 24 + 60 = 88\n"
            << "C[1][0] = 7 * 2 + 9 * 6 + 11 * 10 = 14 + 54 + 110 = 178\n"
            << "C[1][1] = 7 * 4 + 9 * 8 + 11 * 12 = 28 + 72 + 132 = 232\n";
        std::cout << "Matrix 1 * Matrix 2:\n" << m1 * m2 << std::endl;
    }
    {
        Matrix<int> m1({{1, 0}, {0, 1}});
        Matrix<int> m2({{1, 0}, {0, 1}});
        std::cout << "Test 5 result:\n" << m1 * m2 << std::endl;
    }
    return 0;
}
