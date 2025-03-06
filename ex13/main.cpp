
#include <iostream>

#include "Matrix.hpp"

int main() {
    {
        std::cout << "Matrix rank test 1\n";
        const Matrix<double> given({
            {1., 2., 0., 0.},
            {2., 4., 0., 0.},
            {-1., 2., 1., 1.},
        });
        std::cout << "Rank: " << given.rank() << '\n';
    }
    return 0;
}
