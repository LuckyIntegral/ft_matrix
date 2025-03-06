#include <iostream>

#include "Vector.hpp"
#include "angle_cos.hpp"

int main() {
    {
        std::cout << "Euclidean norm: ||v||2   = sqrt(v1^2 + v2^2 + v3^2)\n";
        std::cout << "Cosine of the angle between two vectors:\n"
                  << "cos(v1, v2) = (v1 * v2) / (||v1||2 * ||v2||2)\n";
    }
    std::cout << '\n';
    {
        const Vector<int> vec1({-1, -1});
        const Vector<int> vec2({1, 1});
        std::cout << "Vector 1:\n" << vec1 << '\n';
        std::cout << "Vector 2:\n" << vec2 << '\n';

        std::cout << "Cosine of the angle between the two vectors: "
                  << angle_cos(vec1, vec2) << '\n';
        std::cout << "Step by step calculation: " << '\n';

        const float numerator = vec1.dotProduct(vec2);
        std::cout << "Numerator: v1 * v2 = " << numerator << '\n';

        const float norm1 = vec1.normEuclidean();
        const float norm2 = vec2.normEuclidean();
        std::cout << "Denominator: " << norm1 << " * " << norm2 << " = "
                  << norm1 * norm2 << '\n';

        const float denominator = norm1 * norm2;
        std::cout << "Result: " << numerator << " / " << denominator << " = "
                  << numerator / denominator << '\n';
    }
    return 0;
}
