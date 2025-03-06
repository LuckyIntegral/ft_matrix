#include <stdexcept>
#include <vector>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixMultiplicationWithIdentityMatrix(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<int> identityMatrix({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    });
    const Matrix<int> matrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });
    const Matrix<int> expectedResult({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });

    ASSERT_EQUALS(test, expectedResult, identityMatrix.mult(matrix));
}

void testMatrixMultiplicationWithNonSquareMatrices(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<int> matrix1({
        {1, 2, 3},
        {4, 5, 6},
    });
    const Matrix<int> matrix2({
        {1, 2},
        {3, 4},
        {5, 6},
    });
    const Matrix<int> expectedResult({
        {22, 28},
        {49, 64},
    });

    ASSERT_EQUALS(test, expectedResult, matrix1.mult(matrix2));
}

void testMatrixMultiplicationWithRowAndColumnVectors(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<int> rowVector({{1, 1, 1}});
    const Matrix<int> columnVector({
        {1},
        {1},
        {1},
    });
    const Matrix<int> expectedResult({3});

    ASSERT_EQUALS(test, expectedResult, rowVector.mult(columnVector));
}

void testMatrixMultiplicationWithInvalidDimensions(UnitTest &test) {
    SET_TEST_NAME(test);

    const Matrix<int> matrix1({
        {1, 2, 3},
        {4, 5, 6},
    });
    const Matrix<int> matrix2({
        {1, 2},
        {3, 4},
    });

    ASSERT_THROWS(test, std::invalid_argument, matrix1.mult(matrix2));
    ASSERT_THROWS(test, std::invalid_argument, matrix1 * matrix2);
}

void testMatrixVectorMultiplicationWithIdentityMatrix(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<int> identityMatrix({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    });

    const Vector<int> vector({1, 2, 3});
    const Vector<int> expectedResult({1, 2, 3});

    const auto result = identityMatrix.mult(vector);
    ASSERT_EQUALS(test, expectedResult, result);
    ASSERT_EQUALS(test, result, identityMatrix * vector);
}

void testMatrixVectorMultiplicationWithNonSquareMatrix(UnitTest &test) {
    SET_TEST_NAME(test);

    const Matrix<int> matrix({
        {1, 2, 3},
        {4, 5, 6},
    });

    const Vector<int> vector({1, 2, 3});
    const Vector<int> expectedResult({14, 32});

    const auto result = matrix.mult(vector);
    ASSERT_EQUALS(test, expectedResult, result);
    ASSERT_EQUALS(test, result, matrix * vector);
}

void testMatrixVectorMultiplicationWithInvalidDimensions(UnitTest &test) {
    SET_TEST_NAME(test);

    const Matrix<int> matrix({{1, 2, 3}, {4, 5, 6}});
    const Vector<int> vector({1, 2});

    ASSERT_THROWS(test, std::invalid_argument, matrix.mult(vector));
    ASSERT_THROWS(test, std::invalid_argument, matrix * vector);
}

int main() {
    UnitTest tests({
        testMatrixMultiplicationWithIdentityMatrix,
        testMatrixMultiplicationWithNonSquareMatrices,
        testMatrixMultiplicationWithRowAndColumnVectors,
        testMatrixMultiplicationWithInvalidDimensions,
        testMatrixVectorMultiplicationWithIdentityMatrix,
        testMatrixVectorMultiplicationWithNonSquareMatrix,
        testMatrixVectorMultiplicationWithInvalidDimensions,
    });

    return tests.run();
}
