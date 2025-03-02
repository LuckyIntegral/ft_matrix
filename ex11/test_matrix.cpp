
#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixREFValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<double> u({
            {1., -1.},
            {-1., 1.},
        });
        ASSERT_EQUALS(test, 0., u.determinant());
    }
    {
        Matrix<double> u({
            {2., 0., 0.},
            {0., 2., 0.},
            {0., 0., 2.},
        });
        ASSERT_EQUALS(test, 8.0, u.determinant());
    }
    {
        Matrix<double> u({
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
        });
        ASSERT_EQUALS(test, -174.0, u.determinant());
    }
    {
        Matrix<double> u({
            {8., 5., -2., 4.},
            {4., 2.5, 20., 4.},
            {8., 5., 1., 4.},
            {28., -4., 17., 1.},
        });
        ASSERT_EQUALS(test, 1032.0, u.determinant());
    }
    {
        Matrix<float> u({
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {11, 12, 13, 14, 15, 16, 17, 18, 19},
            {21, 22, 23, 24, 25, 26, 27, 28, 29},
            {31, 32, 33, 34, 35, 36, 37, 38, 39},
            {41, 42, 43, 44, 45, 46, 47, 48, 49},
            {51, 52, 53, 54, 55, 56, 57, 58, 59},
            {61, 62, 63, 64, 65, 66, 67, 68, 69},
            {71, 72, 73, 74, 75, 76, 77, 78, 79},
            {81, 82, 83, 84, 85, 86, 87, 88, 89},
        });
        ASSERT_EQUALS(test, 0, u.determinant());
    }
}

int main() {
    UnitTest tests({
        testMatrixREFValid,
    });
    return tests.run();
}
