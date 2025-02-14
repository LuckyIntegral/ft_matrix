#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        Vector<int> vec1({5, 1});
        Vector<int> vec2({5, 2});
        Vector<int> vec3({5, 3});

        std::cout << vec1[0] << std::endl;

        std::cout << vec1 << std::endl;
        std::cout << vec2 << std::endl;
        std::cout << vec3 << std::endl;

        vec1 = vec2;
        std::cout << vec1 << std::endl;

        vec1 = vec3;
        std::cout << vec1 << std::endl;
    }
    {
        Matrix<int> mat({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        std::cout << "Initial Matrix:" << std::endl;
        std::cout << mat << std::endl;

        mat[0][0] = 4;
        mat[1][1] = 9;
        mat[2][2] = 5;

        std::cout << "Modified Matrix:" << std::endl;
        std::cout << mat << std::endl;

        return 0;
    }

    return 0;
}
