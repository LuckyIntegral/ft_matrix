#include <stdexcept>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixAddValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> expected({{2, 4, 6}, {8, 10, 12}});

    ASSERT_FALSE(test, mat1 == expected);
    mat1.add(mat2);
    ASSERT_TRUE(test, mat1 == expected);
}

void testMatrixAddInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    ASSERT_THROWS(test, std::invalid_argument, mat1.add(mat2));
}

void testMatrixSubstractValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> expected({{0, 0, 0}, {0, 0, 0}});

    ASSERT_FALSE(test, mat1 == expected);
    mat1.sub(mat2);
    ASSERT_TRUE(test, mat1 == expected);
}

void testMatrixSubstractInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> mat2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    ASSERT_THROWS(test, std::invalid_argument, mat1.sub(mat2));
}

void testMatrixScalar(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<int> expected({{2, 4, 6}, {8, 10, 12}});

    ASSERT_FALSE(test, mat1 == expected);
    mat1.scalar(2);
    ASSERT_TRUE(test, mat1 == expected);
}

int main() {
    UnitTest tests({
        testMatrixAddValid,
        testMatrixAddInvalid,
        testMatrixSubstractValid,
        testMatrixSubstractInvalid,
        testMatrixScalar,
    });
    return tests.run();
}
