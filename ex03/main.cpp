#include <iostream>

#include "Vector.hpp"

int main() {
    {
        std::cout << "Dot product of [0, 0] and [1, 1]: ";
        Vector<float> u({0, 0});
        Vector<float> v({1, 1});
        std::cout << u.dotProduct(v) << std::endl;
    }
    {
        std::cout << "Dot product of [1, 1] and [1, 1]: ";
        Vector<float> u({1, 1});
        Vector<float> v({1, 1});
        std::cout << u.dotProduct(v) << std::endl;
    }
    {
        std::cout << "Dot product of [-1, 6] and [3, 2]: ";
        Vector<float> u({-1, 6});
        Vector<float> v({3, 2});
        std::cout << u.dotProduct(v) << std::endl;
    }
    return 0;
}
