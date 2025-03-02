
#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixInverseValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<double> given({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.},
        });
        Matrix<double> expected({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.},
        });
        ASSERT_EQUALS(test, expected, given.inverse());
    }
    {
        Matrix<double> given({
            {2., 0., 0.},
            {0., 2., 0.},
            {0., 0., 2.},
        });
        Matrix<double> expected({
            {0.5, 0., 0.},
            {0., 0.5, 0.},
            {0., 0., 0.5},
        });
        ASSERT_EQUALS(test, expected, given.inverse());
    }
    {
        Matrix<double> given({
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
        });
        Matrix<double> expected({
            {0.649425287, 0.097701149, -0.655172414},
            {-0.781609195, -0.126436782, 0.965517241},
            {0.143678161, 0.074712644, -0.206896552},
        });
        ASSERT_EQUALS(test, expected, given.inverse());
    }
}

void testMatrixInverseInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<double> given({
            {1., 2., 3.},
            {4., 5., 6.},
            {7., 8., 9.},
        });
        ASSERT_EQUALS(test, 0, given.determinant());
        ASSERT_THROWS(test, std::runtime_error, given.inverse());
    }
    {
        Matrix<double> given({
            {1., 2., 3.},
            {4., 5., 6.},
        });
        ASSERT_THROWS(test, std::invalid_argument, given.inverse());
    }
    {
        Matrix<double> given({
            {1., 2.},
            {2., 4.},
        });
        ASSERT_EQUALS(test, 0, given.determinant());
        ASSERT_THROWS(test, std::runtime_error, given.inverse());
    }
}

int main() {
    UnitTest tests({
        testMatrixInverseValid,
        testMatrixInverseInvalid,
    });
    return tests.run();
}
