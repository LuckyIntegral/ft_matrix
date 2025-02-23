#include <iostream>

#include "Vector.hpp"

int main() {
    {
        std::cout << "Euclidean norm: ||v||2   = sqrt(v1^2 + v2^2 + v3^2)"
                  << std::endl;
        std::cout << "Cosine of the angle between two vectors: "
                  << "cos(v1, v2) = (v1 * v2) / (||v1||2 * ||v2||2)"
                  << std::endl;
    }
    {
        Vector<int> vec1({-1, -1});
        Vector<int> vec2({1, 1});
        std::cout << "\nVector 1: " << vec1 << std::endl;
        std::cout << "Vector 2: " << vec2 << std::endl;

        std::cout << "Cosine of the angle between the two vectors: "
                  << angle_cos(vec1, vec2) << std::endl;
        std::cout << "Step by step calculation: " << std::endl;

        const float numerator = vec1.dotProduct(vec2);
        std::cout << "Numerator: " << numerator << std::endl;

        const float norm1 = vec1.normEuclidean();
        const float norm2 = vec2.normEuclidean();
        std::cout << "Denominator: " << norm1 << " * " << norm2 << " = "
                  << norm1 * norm2 << std::endl;

        const float denominator = norm1 * norm2;
        std::cout << "Result: " << numerator << " / " << denominator << " = "
                  << numerator / denominator << std::endl;
    }
    return 0;
}
