#include <iostream>
#include <vector>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixConstructorFromStdVector(UnitTest &test) {
    test.setCurrentTestName("testMatrixConstructorFromStdVector");
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(stdMat);

    ASSERT_EQUALS(test, 3ul, mat.getRows());
    ASSERT_EQUALS(test, 3ul, mat.getCols());
    ASSERT_EQUALS(test, 1, mat[0][0]);
    ASSERT_EQUALS(test, 5, mat[1][1]);
    ASSERT_EQUALS(test, 9, mat[2][2]);
}

void testMatrixCopyConstructor(UnitTest &test) {
    test.setCurrentTestName("testMatrixCopyConstructor");
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat1(stdMat);
    Matrix<int> mat2(mat1);

    ASSERT_EQUALS(test, 22ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixAssignmentOperator(UnitTest &test) {
    test.setCurrentTestName("testMatrixAssignmentOperator");
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat1(stdMat);
    Matrix<int> mat2 = mat1;

    ASSERT_EQUALS(test, 2ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixFromNotSquareVector(UnitTest &test) {
    test.setCurrentTestName("testMatrixFromNotSquareMatrix");
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}, {7, 8}};
    try {
        Matrix<int> mat(stdMat);
        test.setCurrentTestResult(TestResult::KO);
    } catch (std::invalid_argument &e) {
        test.setCurrentTestResult(TestResult::OK);
    }
}

int main() {
    UnitTest tests({
        testMatrixConstructorFromStdVector,
        testMatrixCopyConstructor,
        testMatrixAssignmentOperator,
        testMatrixFromNotSquareVector,
    });
    return tests.run();
}
