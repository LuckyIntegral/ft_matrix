#include "Matrix.hpp"
#include "UnitTest.hpp"
#include "Vector.hpp"

void inline assertMatrixAlmostEquals(UnitTest &test,
                                     const Matrix<double> &expected,
                                     const Matrix<double> &actual) {
    for (size_t row = 0; row < expected.getRows(); row++) {
        for (size_t col = 0; col < expected.getCols(); col++) {
            ASSERT_TRUE(test, std::abs(expected[row][col] - actual[row][col]) <
                                  EPSILON_DOUBLE);
        }
    }
}

void testIdentityMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.},
    });
    Matrix<double> expected = given;
    assertMatrixAlmostEquals(test, expected, given.inverse());
}

void testScalarMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
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
    assertMatrixAlmostEquals(test, expected, given.inverse());
}

void testGeneralMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
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

void testNegativeDeterminantMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {4, 7},
        {2, 6},
    });
    Matrix<double> expected({
        {0.6, -0.7},
        {-0.2, 0.4},
    });
    assertMatrixAlmostEquals(test, expected, given.inverse());
}

void test4x4MatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {3, 0, 2, -1},
        {1, 2, 0, -2},
        {4, 0, 6, -3},
        {5, 0, 2, 0},
    });
    Matrix<double> expected({
        {0.6, 0, -0.2, 0},
        {-2.5, 0.5, 0.5, 1},
        {-1.5, 0, 0.5, 0.5},
        {-2.2, 0, 0.4, 1},
    });
    assertMatrixAlmostEquals(test, expected, given.inverse());
}

void testSingularMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 2., 3.},
        {4., 5., 6.},
        {7., 8., 9.},
    });
    ASSERT_EQUALS(test, 0, given.determinant());
    ASSERT_THROWS(test, std::runtime_error, given.inverse());
}

void testNonSquareMatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 2., 3.},
        {4., 5., 6.},
    });
    ASSERT_THROWS(test, std::invalid_argument, given.inverse());
}

void testSingular2x2MatrixInverse(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {1., 2.},
        {2., 4.},
    });
    ASSERT_EQUALS(test, 0, given.determinant());
    ASSERT_THROWS(test, std::runtime_error, given.inverse());
}

void testLargeInvertibleMatrix(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({{3, 2, 0, 1, 4},
                          {9, 8, 7, 6, 5},
                          {2, 7, 3, 4, 1},
                          {8, 1, 9, 2, 0},
                          {6, 4, 5, 3, 7}});
    Matrix<double> expected = given.inverse();
    assertMatrixAlmostEquals(test, expected.inverse(), given);
}

void testMatrixTimesInverseIsIdentity(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<double> given({
        {4, 3},
        {3, 2},
    });
    Matrix<double> inverse = given.inverse();
    Matrix<double> identity = given * inverse;
    Matrix<double> expected = Matrix<double>::identity(2);
    assertMatrixAlmostEquals(test, expected, identity);
}

int main() {
    UnitTest tests({
        testIdentityMatrixInverse,
        testScalarMatrixInverse,
        testGeneralMatrixInverse,
        testNegativeDeterminantMatrixInverse,
        test4x4MatrixInverse,
        testSingularMatrixInverse,
        testNonSquareMatrixInverse,
        testSingular2x2MatrixInverse,
        testLargeInvertibleMatrix,
        testMatrixTimesInverseIsIdentity,
    });
    return tests.run();
}
