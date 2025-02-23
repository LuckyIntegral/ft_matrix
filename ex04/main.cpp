#include <iostream>

#include "Vector.hpp"

int main() {
    {
        std::cout << "Manhattan norm: ||v||1   = |v1| + |v2| + |v3|" << std::endl;
        std::cout << "Euclidean norm: ||v||2   = sqrt(v1^2 + v2^2 + v3^2)" << std::endl;
        std::cout << "Supremum norm:  ||v||inf = max(|v1|, |v2|, |v3|)" << std::endl;
    }
    {
        Vector<int> vec({0, 0, 0});

        std::cout << "\nVector 1: " << vec << std::endl;
        std::cout << "Manhattan norm: " << vec.normManhattan() << std::endl;
        std::cout << "Euclidean norm: " << vec.normEuclidean() << std::endl;
        std::cout << "Supremum norm: " << vec.normSupremum() << std::endl;
    }
    {
        Vector<int> vec({1, 2, 3});

        std::cout << "\nVector 2: " << vec << std::endl;
        std::cout << "Manhattan norm: " << vec.normManhattan() << std::endl;
        std::cout << "Euclidean norm: " << vec.normEuclidean() << std::endl;
        std::cout << "Supremum norm: " << vec.normSupremum() << std::endl;
    }
    {
        Vector<int> vec({-1, -2, -3});

        std::cout << "\nVector 3: " << vec << std::endl;
        std::cout << "Manhattan norm: " << vec.normManhattan() << std::endl;
        std::cout << "Euclidean norm: " << vec.normEuclidean() << std::endl;
        std::cout << "Supremum norm: " << vec.normSupremum() << std::endl;
    }
    return 0;
}
