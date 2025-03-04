
#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixRankValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<double> given({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.},
        });
        ASSERT_EQUALS(test, 3, given.rank());
    }
    {
        Matrix<double> given({
            {1., 0., 0., 0.},
            {0., 1., 0., 0.},
            {0., 0., 1., 0.},
            {0., 0., 1., 0.},
        });
        ASSERT_EQUALS(test, 3, given.rank());
    }
    {
        Matrix<double> given({
            {7., 0., 0.},
            {0., 7., 0.},
            {0., 0., 7.},
        });
        ASSERT_EQUALS(test, 3, given.rank());
    }
    {
        Matrix<double> given({
            {1., 0., 0.},
            {0., 0., 0.},
            {0., 0., 0.},
        });
        ASSERT_EQUALS(test, 1, given.rank());
    }
    {
        Matrix<float> given({
            {0., 0., 0.},
            {0., 0., 0.},
            {0., 0., 0.},
        });
        ASSERT_EQUALS(test, 0, given.rank());
    }
    {
        Matrix<double> given({
            {1., 2., 0., 0.},
            {2., 4., 0., 0.},
            {-1., 2., 1., 1.},
        });
        ASSERT_EQUALS(test, 2, given.rank());
    }
    {
        Matrix<float> given({
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
            {21., 18., 7.},
        });
        ASSERT_EQUALS(test, 3, given.rank());
    }
}

int main() {
    UnitTest tests({
        testMatrixRankValid,
    });
    return tests.run();
}
