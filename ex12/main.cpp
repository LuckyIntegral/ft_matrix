
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix inverse\n";
        std::cout << "A * A^-1 = I\n";
        std::cout << "Main rule: A must be square\n";
        std::cout << '\n';
    }
    {
        const Matrix<double> m1({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.},
        });
        std::cout << "Test 1 result:\n" << m1.inverse() << '\n';
    }
    {
        const Matrix<double> m1({
            {3, 4},
            {1, 2},
        });
        std::cout << "Test 2 result:\n" << m1.inverse() << '\n';
        std::cout << "A * A^-1:\n" << m1 * m1.inverse() << '\n';
    }
    {
        /*
        2x + 3y= 8
        −7x + 4y= 2
        */
        const Matrix<double> A({
            {2., 3.},
            {-7., 4.},
        });
        const Vector<double> c({8., 2.});
        const Vector<double> b = A.inverse() * c;

        std::cout << "Ab = c,  b = (A^-1)c \n";
        std::cout << "Ab = " << A * b << '\n';
        std::cout << "c = " << c << '\n';
        std::cout << (A * b == c ? "Magic" : "No Magic") << '\n';
    }
    return 0;
}
