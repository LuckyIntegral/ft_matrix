#include "Matrix.hpp"
#include "UnitTest.hpp"

void testIdentityMatrixRank(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.},
    });
    ASSERT_EQUALS(test, 3, given.rank());
}

void testZeroMatrixRank(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> given({
        {0., 0., 0.},
        {0., 0., 0.},
        {0., 0., 0.},
    });
    ASSERT_EQUALS(test, 0, given.rank());
}

void testDependentRowsMatrixRank(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 2., 3.},
        {2., 4., 6.},
        {3., 6., 9.},
    });
    ASSERT_EQUALS(test, 1, given.rank());
}

void testRectangularMatrixRank(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> given({
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.},
        {21., 18., 7.},
    });
    ASSERT_EQUALS(test, 3, given.rank());
}

void testEmptyMatrixRank(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> given;
    ASSERT_EQUALS(test, 0, given.rank());
}

int main() {
    UnitTest tests({
        testIdentityMatrixRank,
        testZeroMatrixRank,
        testDependentRowsMatrixRank,
        testRectangularMatrixRank,
        testEmptyMatrixRank,
    });
    return tests.run();
}
