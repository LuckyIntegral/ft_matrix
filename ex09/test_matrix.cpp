#include "Matrix.hpp"
#include "UnitTest.hpp"

void testSquareMatrixTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });
    Matrix<int> expected({
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
    });

    ASSERT_EQUALS(test, expected, m1.transpose());
    ASSERT_EQUALS(test, m1, m1.transpose().transpose());
}

void testRectangularMatrixTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1({
        {1, 2, 3},
        {4, 5, 6},
    });
    Matrix<int> expected({
        {1, 4},
        {2, 5},
        {3, 6},
    });

    ASSERT_EQUALS(test, expected, m1.transpose());
    ASSERT_EQUALS(test, m1, m1.transpose().transpose());
}

void testRowVectorTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1({{1, 2, 3, 4, 5}});
    Matrix<int> expected({{1}, {2}, {3}, {4}, {5}});

    ASSERT_FALSE(test, m1.transpose() == m1);
    ASSERT_EQUALS(test, expected, m1.transpose());
    ASSERT_EQUALS(test, m1, m1.transpose().transpose());
}

void testColumnVectorTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1({{1}, {2}, {3}, {4}, {5}});
    Matrix<int> expected({{1, 2, 3, 4, 5}});

    ASSERT_FALSE(test, m1.transpose() == m1);
    ASSERT_EQUALS(test, expected, m1.transpose());
    ASSERT_EQUALS(test, m1, m1.transpose().transpose());
}

void testEmptyMatrixTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1;
    Matrix<int> expected;

    ASSERT_EQUALS(test, expected, m1.transpose());
}

void testSingleElementMatrixTranspose(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1({{42}});
    Matrix<int> expected({{42}});

    ASSERT_EQUALS(test, expected, m1.transpose());
    ASSERT_EQUALS(test, m1, m1.transpose().transpose());
}

int main() {
    UnitTest tests({
        testSquareMatrixTranspose,
        testRectangularMatrixTranspose,
        testRowVectorTranspose,
        testColumnVectorTranspose,
        testEmptyMatrixTranspose,
        testSingleElementMatrixTranspose,
    });
    return tests.run();
}
