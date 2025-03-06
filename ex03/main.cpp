#include <iostream>

#include "Vector.hpp"

int main() {
    {
        const Vector<float> u({0, 0});
        const Vector<float> v({1, 1});
        std::cout << "Dot product of [0, 0] and [1, 1]: " << u.dotProduct(v)
                  << '\n';
    }
    {
        const Vector<float> u({1, 1});
        const Vector<float> v({1, 1});
        std::cout << "Dot product of [1, 1] and [1, 1]: " << u.dotProduct(v)
                  << '\n';
    }
    {
        const Vector<float> u({-1, 6});
        const Vector<float> v({3, 2});
        std::cout << "Dot product of [-1, 6] and [3, 2]: " << u.dotProduct(v)
                  << '\n';
    }
    return 0;
}
