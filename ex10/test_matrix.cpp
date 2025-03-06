#include "Matrix.hpp"
#include "UnitTest.hpp"

void inline assertMatrixAlmostEquals(UnitTest &test,
                                     const Matrix<float> &expected,
                                     const Matrix<float> &actual) {
    for (size_t row = 0; row < expected.getRows(); row++) {
        for (size_t col = 0; col < expected.getCols(); col++) {
            ASSERT_TRUE(test, std::abs(expected[row][col] - actual[row][col]) <
                                  EPSILON_FLOAT);
        }
    }
}

void testIdentityMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u = Matrix<float>::identity(10);
    Matrix<float> expected = u;
    ASSERT_EQUALS(test, expected, u.rowEchelon());
}

void testInvertibleMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {1, 2},
        {3, 4},
    });
    Matrix<float> expected = Matrix<float>::identity(2);
    ASSERT_EQUALS(test, expected, u.rowEchelon());
}

void testSingularMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {1, 2},
        {2, 4},
    });
    Matrix<float> expected({
        {1, 2},
        {0, 0},
    });
    ASSERT_EQUALS(test, expected, u.rowEchelon());
}

void testRankDeficientMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });
    Matrix<float> expected({
        {1, 0, -1},
        {0, 1, 2},
        {0, 0, 0},
    });
    assertMatrixAlmostEquals(test, expected, u.rowEchelon());
}

void testLargeMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {3, 2, 0, 1, 4},
        {9, 8, 7, 6, 5},
        {2, 7, 3, 4, 1},
        {8, 1, 9, 2, 0},
        {6, 4, 5, 3, 7},
    });
    Matrix<float> expected = u.rowEchelon();
    ASSERT_EQUALS(test, expected, u.rowEchelon());
}

void testFractionalMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {1.5, 3.0},
        {0.5, 1.0},
    });
    Matrix<float> expected({
        {1, 2},
        {0, 0},
    });
    ASSERT_EQUALS(test, expected, u.rowEchelon());
}

void testNearlySingularMatrixREF(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<float> u({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9.00001},
    });
    Matrix<float> expected({
        {1, 0, -1},
        {0, 1, 2},
        {0, 0, 0},
    });
    assertMatrixAlmostEquals(test, expected, u.rowEchelon());
}

int main() {
    UnitTest tests({
        testIdentityMatrixREF,
        testInvertibleMatrixREF,
        testSingularMatrixREF,
        testRankDeficientMatrixREF,
        testLargeMatrixREF,
        testFractionalMatrixREF,
        testNearlySingularMatrixREF,
    });
    return tests.run();
}
