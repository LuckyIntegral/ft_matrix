#include <iostream>

#include "Vector.hpp"
#include "linear_combination.hpp"

int main() {
    {
        std::cout << "Linear combination test" << std::endl;
        Vector<Vector<float>> vectors({
            Vector<float>({1, 0, 0, 2}),
            Vector<float>({0, 1, 0, 1}),
            Vector<float>({0, 0, 1, 5}),
            Vector<float>({0, 0, 0, -1}),
        });

        Vector<float> coefficients({10, -2, 0.5, 0});

        Vector<float> res = linear_combination(vectors, coefficients);

        std::cout << "Vectors: " << vectors << std::endl;
        std::cout << "Coefficients: " << coefficients << std::endl;
        std::cout << "Result: " << res << std::endl;
    }
    return 0;
}
