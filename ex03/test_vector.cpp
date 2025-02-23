#include <stdexcept>

#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorDotValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Vector<float> vec1({1, 2, 3});
        Vector<float> vec2({0, 10, -10});
        ASSERT_EQUALS(test, -10.f, vec1.dotProduct(vec2));
    }
    {
        Vector<int> u({0, 0});
        Vector<int> v({1, 1});
        ASSERT_EQUALS(test, 0, u.dotProduct(v));
    }
    {
        Vector<int> u({1, 1});
        Vector<int> v({1, 1});
        ASSERT_EQUALS(test, 2, u.dotProduct(v));
    }
    {
        Vector<int> u({-1, 6});
        Vector<int> v({3, 2});
        ASSERT_EQUALS(test, 9, u.dotProduct(v));
    }
}

void testVectorDotEmptyValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<float> vec1({});
    Vector<float> vec2({});

    const float expected = 0;
    ASSERT_EQUALS(test, expected, vec1.dotProduct(vec2));
}

void testVectorDotInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<float> vec1({1, 2, 3});
    Vector<float> vec2({0, 10});

    // vec1.size() != vec2.size()
    ASSERT_THROWS(test, std::invalid_argument, vec1.dotProduct(vec2));
}

int main() {
    UnitTest tests({
        testVectorDotValid,
        testVectorDotEmptyValid,
        testVectorDotInvalid,
    });
    return tests.run();
}
