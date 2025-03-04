#include <stdexcept>

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixTraceValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m1({
            {1, 2},
            {3, 4},
        });
        ASSERT_EQUALS(test, 5, m1.trace());
    }
    {
        Matrix<int> m1({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        });
        Matrix<int> m2({
            {1, 42, 42},
            {42, 1, 42},
            {42, 42, 1},
        });
        ASSERT_EQUALS(test, m2.trace(), m1.trace());
    }
    {
        Matrix<int> m1({{1}});
        ASSERT_EQUALS(test, 1, m1.trace());
    }
    {
        Matrix<int> m1({
            {5, 1, 2},
            {3, 6, 4},
            {8, 7, 9},
        });
        ASSERT_EQUALS(test, 20, m1.trace());
    }
}

void testMatrixTraceEmpty(UnitTest &test) {
    SET_TEST_NAME(test);
    Matrix<int> m1;
    ASSERT_EQUALS(test, 0, m1.trace());
}

void testMatrixTraceNotSquare(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m1({{1, 2}});
        ASSERT_THROWS(test, std::invalid_argument, m1.trace());
    }
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
        ASSERT_THROWS(test, std::invalid_argument, m1.trace());
    }
    {
        Matrix<int> m1({{1}, {2}, {3}});
        ASSERT_THROWS(test, std::invalid_argument, m1.trace());
    }
}

int main() {
    UnitTest tests({
        testMatrixTraceValid,
        testMatrixTraceEmpty,
        testMatrixTraceNotSquare,
    });
    return tests.run();
}
