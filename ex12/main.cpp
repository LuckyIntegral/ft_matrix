
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    {
        std::cout << "Matrix inverse" << std::endl;
        std::cout << "A * A^-1 = I" << std::endl;
        std::cout << "Main rule: A must be square" << std::endl;
        std::cout << std::endl;
    }
    {
        Matrix<double> m1({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.},
        });
        std::cout << "Test 1 result:\n" << m1.inverse() << std::endl;
    }
    {
        Matrix<double> m1({
            {3, 4},
            {1, 2},
        });
        std::cout << "Test 2 result:\n" << m1.inverse() << std::endl;
        std::cout << "A * A^-1:\n" << m1 * m1.inverse() << std::endl;
    }
    {
        /*
        2x + 3y= 8
        −7x + 4y= 2
        */
        Matrix<double> A({
            {2., 3.},
            {-7., 4.},
        });
        Vector<double> c({8., 2.});
        Vector<double> b = A.inverse() * c;

        std::cout << "Ab = c,  b = (A^-1)c \n";
        std::cout << "Ab = " << A * b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << (A * b == c ? "Magic" : "No Magic") << std::endl;
    }
    return 0;
}
