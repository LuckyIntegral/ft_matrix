#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

static std::string equal(const bool b) {
    return b ? "true" : "false";
}

int main() {
    {
        std::cout << "Matrix test" << '\n';
        const Matrix<float> A({{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}});
        const Matrix<float> B({{1, 2, 3}, {4, 5, 6}});

        std::cout << "Matrix A:\n" << A << '\n';
        std::cout << "Matrix B:\n" << B << '\n';

        std::cout << "Result of A + B\n" << A + B << '\n';
        std::cout << "Result of A - B\n" << A - B << '\n';
        std::cout << "Result of A * 10\n" << A * 10 << '\n';

        std::cout << "Properties:\n";
        std::cout << "A + B == B + A: " << equal(A + B == B + A) << '\n';
        std::cout << "An + Bn == (A + B)n: "
                  << equal(A * 10 + B * 10 == (A + B) * 10) << '\n';
    }
    {
        std::cout << "\nVector test" << '\n';
        const Vector<long double> a({1.1, 2.2, 3.3});
        const Vector<long double> b({1, 2, 3});

        std::cout << "Vector a:\n" << a << '\n';
        std::cout << "Vector b:\n" << b << '\n';

        std::cout << "Result of a + b\n" << a + b << '\n';
        std::cout << "Result of a - b\n" << a - b << '\n';
        std::cout << "Result of a * 10\n" << a * 10 << '\n';

        std::cout << "Properties:\n";
        std::cout << "a + b == b + a: " << equal(a + b == b + a) << '\n';
        std::cout << "an + bn == (a + b)n: "
                  << equal(a * 10 + b * 10 == (a + b) * 10) << '\n';
    }
    return 0;
}
