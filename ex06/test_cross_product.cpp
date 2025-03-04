
#include <stdexcept>

#include "UnitTest.hpp"
#include "Vector.hpp"
#include "cross_product.hpp"

void testVectorCrossProductValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        const Vector<int> vec1({1, 0, 0});
        const Vector<int> vec2({0, 0, 1});
        const Vector<int> res = cross_product(vec1, vec2);
        const Vector<int> expected({0, -1, 0});

        ASSERT_EQUALS(test, expected, res);
    }
    {
        const Vector<int> vec1({1, 2, 3});
        const Vector<int> vec2({4, 5, 6});
        const Vector<int> res = cross_product(vec1, vec2);
        const Vector<int> expected({-3, 6, -3});

        ASSERT_EQUALS(test, expected, res);
    }
}

void testVectorCrossProductWrongSizes(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        const Vector<int> vec1({0, 0, 0});
        const Vector<int> vec2({1, 2, 3, 4});

        ASSERT_THROWS(test, std::invalid_argument, cross_product(vec1, vec2));
    }
        {
        const Vector<int> vec1({1, 2, 3});
        const Vector<int> vec2({1, 2});

        ASSERT_THROWS(test, std::invalid_argument, cross_product(vec1, vec2));
    }
}

int main() {
    UnitTest tests({
        testVectorCrossProductValid,
        testVectorCrossProductWrongSizes,
    });
    return tests.run();
}
