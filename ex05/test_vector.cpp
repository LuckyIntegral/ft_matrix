
#include <stdexcept>

#include "UnitTest.hpp"
#include "Vector.hpp"
#include "angle_cos.hpp"

void testVectorCosValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Vector<float> vec1({1., 0.});
        Vector<float> vec2({0., 1.});

        ASSERT_EQUALS(test, 0.f, angle_cos(vec1, vec2));
    }
    {
        Vector<float> vec1({1, 2, 3});
        Vector<float> vec2({4, 5, 6});

        ASSERT_EQUALS(test, 0.974632f, angle_cos(vec1, vec2));
    }
    {
        Vector<float> vec1({-1., 1.});
        Vector<float> vec2({1., -1.});

        ASSERT_EQUALS(test, -1.f, angle_cos(vec1, vec2));
    }
    {
        Vector<float> vec1({-1., 1.});
        Vector<float> vec2({1., 1.});

        ASSERT_EQUALS(test, 0.f, angle_cos(vec1, vec2));
    }
}

void testVectorCosInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Vector<int> vec1({0, 0, 0});
        Vector<int> vec2({1, 2, 3});

        ASSERT_EQUALS(test, 0.f, vec1.normEuclidean());
        ASSERT_THROWS(test, std::runtime_error, angle_cos(vec1, vec2));
    }
}

int main() {
    UnitTest tests({
        testVectorCosValid,
        testVectorCosInvalid,
    });
    return tests.run();
}
