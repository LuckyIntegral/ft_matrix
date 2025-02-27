

#include <cassert>
#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixMulMatrixValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m1({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        Matrix<int> m2({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        Matrix<int> expected({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        Matrix<int> result = m1.mult(m2);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m1 * m2);
    }
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}});
        Matrix<int> m2({{1, 2}, {3, 4}, {5, 6}});
        Matrix<int> expected({{22, 28}, {49, 64}});
        Matrix<int> result = m1.mult(m2);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m1 * m2);
    }
    {
        Matrix<int> m1({{1, 1, 1}});
        Matrix<int> m2({{1}, {1}, {1}});
        Matrix<int> expected({3});
        Matrix<int> result = m1.mult(m2);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m1 * m2);
    }
}

void testMatrixMulMatrixInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}}); // 2x3
        Matrix<int> m2({{1, 2}, {3, 4}}); // 2x2
        ASSERT_THROWS(test, std::invalid_argument, m1.mult(m2));
        ASSERT_THROWS(test, std::invalid_argument, m1 * m2);
    }
    {
        Matrix<int> m1({{1, 2, 3}, {4, 5, 6}}); // 2x3
        Matrix<int> m2({{1, 2, 3}, {4, 5, 6}}); // 2x3
        ASSERT_THROWS(test, std::invalid_argument, m1.mult(m2));
        ASSERT_THROWS(test, std::invalid_argument, m1 * m2);
    }
}

void testMatrixMulVectorValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
        Vector<int> v({1, 2, 3});
        Vector<int> expected({1, 2, 3});
        Vector<int> result = m.mult(v);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m * v);
    }
    {
        Matrix<int> m({{1, 2, 3}, {4, 5, 6}});
        Vector<int> v({1, 2, 3});
        Vector<int> expected({14, 32});
        Vector<int> result = m.mult(v);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m * v);
    }
    {
        Matrix<int> m({{1, 1, 1}, {1, 1, 1}});
        Vector<int> v({1, 2, 3});
        Vector<int> expected({6, 6});
        Vector<int> result = m.mult(v);
        ASSERT_EQUALS(test, expected, result);
        ASSERT_EQUALS(test, result, m * v);
    }
}

void testMatrixMulVectorInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<int> m({{1, 2, 3}, {4, 5, 6}}); // 2x3
        Vector<int> v({1, 2}); // 2
        ASSERT_THROWS(test, std::invalid_argument, m.mult(v));
        ASSERT_THROWS(test, std::invalid_argument, m * v);
    }
}

int main() {
    UnitTest tests({
        testMatrixMulMatrixValid,
        testMatrixMulMatrixInvalid,
        testMatrixMulVectorValid,
        testMatrixMulVectorInvalid,
    });
    return tests.run();
}
