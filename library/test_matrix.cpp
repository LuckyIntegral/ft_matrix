#include <stdexcept>
#include <vector>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixConstructorFromStdVector(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(stdMat);

    ASSERT_EQUALS(test, 3ul, mat.getRows());
    ASSERT_EQUALS(test, 3ul, mat.getCols());
    ASSERT_EQUALS(test, 1, mat[0][0]);
    ASSERT_EQUALS(test, 5, mat[1][1]);
    ASSERT_EQUALS(test, 9, mat[2][2]);
}

void testMatrixCopyConstructor(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat1(stdMat);
    Matrix<int> mat2(mat1);

    ASSERT_EQUALS(test, 2ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixAssignmentOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat1(stdMat);
    Matrix<int> mat2 = mat1;

    ASSERT_EQUALS(test, 2ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixFromNotSquareVector(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}, {7, 8}};
    ASSERT_THROWS(test, std::invalid_argument, Matrix<int> mat(stdMat));
}

void testAccessOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    const Matrix<int> mat(stdMat);

    ASSERT_EQUALS(test, 1, mat[0][0]);
    ASSERT_EQUALS(test, 5, mat[1][1]);
    ASSERT_THROWS(test, std::out_of_range, mat[1][10]);
}

void testMatrixIsSquareValid(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(stdMat);

    ASSERT_TRUE(test, mat.isSquare());
}

void testMatrixIsSquareInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat(stdMat);

    ASSERT_FALSE(test, mat.isSquare());
}

void testEqualsOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    std::vector<std::vector<int>> stdMat1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> stdMat2 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> stdMat3 = {{1, 2, 3}, {4, 5, 7}};
    std::vector<std::vector<int>> stdMat4 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Matrix<int> mat1(stdMat1);
    Matrix<int> mat2(stdMat2);
    Matrix<int> mat3(stdMat3);
    Matrix<int> mat4(stdMat4);

    ASSERT_TRUE(test, mat1 == mat2);
    ASSERT_FALSE(test, mat1 == mat3);
    ASSERT_FALSE(test, mat1 == mat4);
}

int main() {
    UnitTest tests({
        testMatrixConstructorFromStdVector,
        testMatrixCopyConstructor,
        testMatrixAssignmentOperator,
        testMatrixFromNotSquareVector,
        testAccessOperator,
        testMatrixIsSquareValid,
        testMatrixIsSquareInvalid,
        testEqualsOperator,
    });
    return tests.run();
}
