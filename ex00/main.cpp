#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix test" << std::endl;
        Matrix<float> mat1({{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}});
        const Matrix<float> mat2({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix 1:" << std::endl;
        std::cout << mat1 << std::endl;
        std::cout << "Matrix 2:" << std::endl;
        std::cout << mat2 << std::endl;

        mat1.add(mat2);
        std::cout << "Matrix 1 after mat1.add(mat2)" << std::endl;
        std::cout << mat1 << std::endl;

        mat1.sub(mat2);
        std::cout << "Matrix 1 after mat1.sub(mat2)" << std::endl;
        std::cout << mat1 << std::endl;

        mat1.scalar(10);
        std::cout << "Matrix 1 after mat1.scalar(10)" << std::endl;
        std::cout << mat1 << std::endl;
    }
    {
        std::cout << "\nVector test" << std::endl;
        Vector<long double> vec1({1.1, 2.2, 3.3});
        const Vector<long double> vec2({1, 2, 3});

        std::cout << "Vector 1: --- " << vec1 << std::endl;
        std::cout << "Vector 2: --- " << vec2 << std::endl;

        vec1.add(vec2);
        std::cout << "Vector 1 after vec1.add(vec2)  --- " << vec1 << std::endl;

        vec1.sub(vec2);
        std::cout << "Vector 1 after vec1.sub(vec2)  --- " << vec1 << std::endl;

        vec1.scalar(10);
        std::cout << "Vector 1 after vec1.scalar(10) --- " << vec1 << std::endl;
    }
    return 0;
}
