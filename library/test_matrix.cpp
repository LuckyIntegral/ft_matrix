#include <stdexcept>
#include <vector>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixConstructorFromStdVector(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    ASSERT_EQUALS(test, 3ul, mat.getRows());
    ASSERT_EQUALS(test, 3ul, mat.getCols());
    ASSERT_EQUALS(test, 1, mat[0][0]);
    ASSERT_EQUALS(test, 5, mat[1][1]);
    ASSERT_EQUALS(test, 9, mat[2][2]);
}

void testMatrixCopyConstructor(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> mat2(mat1);

    ASSERT_EQUALS(test, 2ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixAssignmentOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> mat2 = mat1;

    ASSERT_EQUALS(test, 2ul, mat2.getRows());
    ASSERT_EQUALS(test, 3ul, mat2.getCols());
    ASSERT_EQUALS(test, 1, mat2[0][0]);
    ASSERT_EQUALS(test, 5, mat2[1][1]);
}

void testMatrixFromNotSquareVector(UnitTest &test) {
    SET_TEST_NAME(test);
    ASSERT_THROWS(test, std::invalid_argument,
                  Matrix<int> mat({{1, 2, 3}, {4, 5, 6}, {7, 8}}));
}

void testAccessOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<int> mat({{1, 2, 3}, {4, 5, 6}});

    ASSERT_EQUALS(test, 1, mat[0][0]);
    ASSERT_EQUALS(test, 5, mat[1][1]);
    ASSERT_THROWS(test, std::out_of_range, mat[1][10]);
}

void testMatrixIsSquareValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    ASSERT_TRUE(test, mat.isSquare());
}

void testMatrixIsSquareInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat({{1, 2, 3}, {4, 5, 6}});

    ASSERT_FALSE(test, mat.isSquare());
}

void testEqualsOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> mat3({{1, 2, 3}, {4, 5, 7}});
    Matrix<int> mat4({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    ASSERT_TRUE(test, mat1 == mat2);
    ASSERT_FALSE(test, mat1 == mat3);
    ASSERT_FALSE(test, mat1 == mat4);
}

void testCopyAssignmentOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}});
    Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> mat3({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}});
    Matrix<int> mat4({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    mat1 = mat2;
    ASSERT_TRUE(test, mat1 == mat2);

    mat1 = mat3;
    ASSERT_TRUE(test, mat1 == mat3);

    mat1 = mat4;
    ASSERT_TRUE(test, mat1 == mat4);
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
        testCopyAssignmentOperator,
    });
    return tests.run();
}
