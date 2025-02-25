#include <stdexcept>

#include "Matrix.hpp"
#include "UnitTest.hpp"
#include "Vector.hpp"
#include "lerp.hpp"

void testLerpNumber(UnitTest &test) {
    SET_TEST_NAME(test);
    ASSERT_EQUALS(test, 0., lerp(0., 2., 0.));
    ASSERT_EQUALS(test, 1., lerp(0., 2., 0.5));
    ASSERT_EQUALS(test, 2., lerp(0., 2., 1.));
    ASSERT_THROWS(test, std::invalid_argument, lerp(0., 2., 100.));
}

void testVectorLerpValid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Vector<float> mat1({1, 2, 3});
    const Vector<float> mat2({2, 4, 6});
    const Vector<float> expected({1.5, 3, 4.5});

    ASSERT_EQUALS(test, mat1, lerp(mat1, mat2, 0.));
    ASSERT_EQUALS(test, expected, lerp(mat1, mat2, 0.5));
    ASSERT_EQUALS(test, mat2, lerp(mat1, mat2, 1));
}

void testVectorLerpDifferentSizesInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Vector<float> mat1({1, 2, 3});
    const Vector<float> mat2({2, 4, 6, 5});

    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, 0.));
}

void testVectorLerpScalarOverflowsInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Vector<float> mat1({1, 2, 3});
    const Vector<float> mat2({2, 4, 6});

    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, -1.));
    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, 2.));
}

void testMatrixLerpValid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<float> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<float> mat2({{2, 4, 6}, {8, 10, 12}});
    const Matrix<float> expected({{1.5, 3, 4.5}, {6, 7.5, 9}});

    ASSERT_EQUALS(test, mat1, lerp(mat1, mat2, 0.));
    ASSERT_EQUALS(test, expected, lerp(mat1, mat2, 0.5));
    ASSERT_EQUALS(test, mat2, lerp(mat1, mat2, 1));
}

void testMatrixLerpDifferentSizesInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<float> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<float> mat2({{2, 4, 6}, {8, 10, 12}, {1, 2, 3}});

    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, 0.));
}

void testMatrixLerpScalarOverflowsInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    const Matrix<float> mat1({{1, 2, 3}, {4, 5, 6}});
    const Matrix<float> mat2({{2, 4, 6}, {8, 10, 12}});

    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, -1.));
    ASSERT_THROWS(test, std::invalid_argument, lerp(mat1, mat2, 2.));
}

int main() {
    UnitTest tests({
        testLerpNumber,
        testVectorLerpValid,
        testVectorLerpDifferentSizesInvalid,
        testVectorLerpScalarOverflowsInvalid,
        testMatrixLerpValid,
        testMatrixLerpDifferentSizesInvalid,
        testMatrixLerpScalarOverflowsInvalid,
    });
    return tests.run();
}
