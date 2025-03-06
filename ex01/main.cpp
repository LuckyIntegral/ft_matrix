#include <iostream>

#include "Vector.hpp"
#include "linear_combination.hpp"

int main() {
    {
        std::cout << "Linear combination test" << '\n';
        Vector<Vector<float>> vectors({
            Vector<float>({1, 0, 0, 2}),
            Vector<float>({0, 1, 0, 1}),
            Vector<float>({0, 0, 1, 5}),
            Vector<float>({0, 0, 0, -1}),
        });

        Vector<float> coefficients({10, -2, 0.5, 0});

        Vector<float> res = linear_combination(vectors, coefficients);

        std::cout << "Vectors:\n";
        for (size_t i = 0; i < vectors.getSize(); ++i) {
            std::cout << "Vector[" << i << "] = \t" << vectors[i] << '\n';
        }
        std::cout << "Coefficients:\t" << coefficients << '\n';
        std::cout << "Result: " << res << '\n';
    }
    return 0;
}
