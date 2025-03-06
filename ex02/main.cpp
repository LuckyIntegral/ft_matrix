#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"
#include "lerp.hpp"

int main() {
    {
        std::cout << "Linear interpolation test" << '\n';
        std::cout << "lerp(x, y, n) = x * (1 - n) + y * n" << '\n';
    }
    {
        std::cout << "Scalar test:\n";
        std::cout << "lerp(0., 1., 0.):   " << lerp(0., 1., 0.) << "\n";
        std::cout << "lerp(0., 1., 1.):   " << lerp(0., 1., 1.) << "\n";
        std::cout << "lerp(0., 1., 0.5):  " << lerp(0., 1., 0.5) << "\n";
        std::cout << "lerp(21., 42., 0.3):" << lerp(21., 42., 0.3) << "\n";
    }
    std::cout << "\n";
    {
        std::cout << "Vector test:\n";
        const Vector<float> vec1 = Vector<float>({2., 1.});
        const Vector<float> vec2 = Vector<float>({4., 2.});
        std::cout << "Vector 1: " << vec1 << "\n";
        std::cout << "Vector 2: " << vec2 << "\n";

        std::cout << "lerp(vec1, vec2, 0.): " << lerp(vec1, vec2, 0.) << "\n";
        std::cout << "lerp(vec1, vec2, 0.5):" << lerp(vec1, vec2, 0.5) << "\n";
        std::cout << "lerp(vec1, vec2, 1.): " << lerp(vec1, vec2, 1.) << "\n";
    }
    std::cout << "\n";
    {
        std::cout << "Matrix test:\n";
        const Matrix<float> mat1 = Matrix<float>({{2., 1.}, {3., 4.}});
        const Matrix<float> mat2 = Matrix<float>({{20., 10.}, {30., 40.}});
        std::cout << "Matrix 1:\n" << mat1 << "\n";
        std::cout << "Matrix 2:\n" << mat2 << "\n";

        std::cout << "lerp(mat1, mat2, 0.):\n" << lerp(mat1, mat2, 0.) << "\n";
        std::cout << "lerp(mat1, mat2, 0.5):\n"
                  << lerp(mat1, mat2, 0.5) << "\n";
        std::cout << "lerp(mat1, mat2, 1.):\n" << lerp(mat1, mat2, 1.) << "\n";
    }
    return 0;
}
