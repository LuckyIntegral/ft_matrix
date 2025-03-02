
#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixTransposeValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
        Matrix<int> expected({{1, 4}, {2, 5}, {3, 6}});

        ASSERT_EQUALS(test, expected, m1.transpose());
        ASSERT_EQUALS(test, m1, m1.transpose().transpose());
    }
    {
        Matrix<int> m1({{1, 2, 3, 4, 5}});
        Matrix<int> expected({{1}, {2}, {3}, {4}, {5}});

        ASSERT_FALSE(test, m1.transpose() == m1);
        ASSERT_EQUALS(test, expected, m1.transpose());
        ASSERT_EQUALS(test, m1, m1.transpose().transpose());
    }
}

int main() {
    UnitTest tests({
        testMatrixTransposeValid,
    });
    return tests.run();
}
