
#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorNormValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Vector<int> vec({0, 0, 0});

        ASSERT_EQUALS(test, 0.f, vec.normManhattan());
        ASSERT_EQUALS(test, 0.f, vec.normEuclidean());
        ASSERT_EQUALS(test, 0.f, vec.normSupremum());
    }
    {
        Vector<int> vec({1, 2, 3});

        ASSERT_EQUALS(test, 6.f, vec.normManhattan());
        ASSERT_EQUALS(test, 3.74165738f, vec.normEuclidean());
        ASSERT_EQUALS(test, 3.f, vec.normSupremum());
    }
    {
        Vector<int> vec({-1, -2, -3});

        ASSERT_EQUALS(test, 6.f, vec.normManhattan());
        ASSERT_EQUALS(test, 3.74165738f, vec.normEuclidean());
        ASSERT_EQUALS(test, 3.f, vec.normSupremum());
    }
}

void testVectorNormInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Vector<int> vec({});

        ASSERT_EQUALS(test, 0.f, vec.normManhattan());
        ASSERT_EQUALS(test, 0.f, vec.normEuclidean());
        ASSERT_EQUALS(test, 0.f, vec.normSupremum());
    }
}

int main() {
    UnitTest tests({
        testVectorNormValid,
        testVectorNormInvalid,
    });
    return tests.run();
}
