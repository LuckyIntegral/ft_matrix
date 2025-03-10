#include <iostream>

#include "Vector.hpp"
#include "cross_product.hpp"

int main() {
    {
        std::cout << "Vector cross product" << std::endl;
        std::cout << "cx = aybz - azby\n"
                  << "cy = azbx - axbz\n"
                  << "cz = axby - aybx\n";
    }
    std::cout << '\n';
    {
        const Vector<int> vec1({2, 3, 4});
        const Vector<int> vec2({5, 6, 7});
        const Vector<int> res = cross_product(vec1, vec2);
        const Vector<int> expected({-3, 6, -3});

        std::cout << "Vector 1: " << vec1 << '\n';
        std::cout << "Vector 2: " << vec2 << '\n';
        std::cout << "Result:   " << res << '\n';
        std::cout << "Expected: " << expected << '\n';
    }
    return 0;
}
