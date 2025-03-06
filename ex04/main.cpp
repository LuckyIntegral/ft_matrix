#include <iostream>

#include "Vector.hpp"

int main() {
    {
        std::cout << "Manhattan norm: ||v||1   = |v1| + |v2| + |v3|\n";
        std::cout << "Euclidean norm: ||v||2   = sqrt(v1^2 + v2^2 + v3^2)\n";
        std::cout << "Supremum norm:  ||v||inf = max(|v1|, |v2|, |v3|)\n";
    }
    std::cout << '\n';
    {
        const Vector<int> vec({0, 0, 0});

        std::cout << "Vector=\t" << vec << '\n';
        std::cout << "Manhattan norm: " << vec.normManhattan() << '\n';
        std::cout << "Euclidean norm: " << vec.normEuclidean() << '\n';
        std::cout << "Supremum norm: " << vec.normSupremum() << '\n';
    }
    std::cout << '\n';
    {
        const Vector<int> vec({1, 2, 3});

        std::cout << "Vector=\t" << vec << '\n';
        std::cout << "Manhattan norm: " << vec.normManhattan() << '\n';
        std::cout << "Euclidean norm: " << vec.normEuclidean() << '\n';
        std::cout << "Supremum norm: " << vec.normSupremum() << '\n';
    }
    std::cout << '\n';
    {
        const Vector<int> vec({-1, -2, -3});

        std::cout << "Vector=\t" << vec << '\n';
        std::cout << "Manhattan norm: " << vec.normManhattan() << '\n';
        std::cout << "Euclidean norm: " << vec.normEuclidean() << '\n';
        std::cout << "Supremum norm: " << vec.normSupremum() << '\n';
    }
    return 0;
}
