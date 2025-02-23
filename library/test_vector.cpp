#include <stdexcept>
#include <vector>

#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorConstructorWithSize(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec(10ul, 42);
    Vector<int> vec2({42, 42, 42, 42, 42, 42, 42, 42, 42, 42});

    ASSERT_EQUALS(test, 10ul, vec.getSize());
    ASSERT_EQUALS(test, vec, vec2);
}

void testVectorConstructorFromStdVector(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec({1, 2, 3});

    ASSERT_EQUALS(test, 3ul, vec.getSize());
    ASSERT_EQUALS(test, 1, vec[0]);
    ASSERT_EQUALS(test, 2, vec[1]);
    ASSERT_EQUALS(test, 3, vec[2]);
}

void testVectorCopyConstructor(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1({1, 2, 3});
    Vector<int> vec2(vec1);

    ASSERT_EQUALS(test, 3ul, vec2.getSize());
    ASSERT_EQUALS(test, 1, vec2[0]);
    ASSERT_EQUALS(test, 2, vec2[1]);
    ASSERT_EQUALS(test, 3, vec2[2]);
}

void testVectorAssignmentOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1({1, 2, 3});
    Vector<int> vec2 = vec1;

    ASSERT_EQUALS(test, 3ul, vec2.getSize());
    ASSERT_EQUALS(test, 1, vec2[0]);
    ASSERT_EQUALS(test, 2, vec2[1]);
    ASSERT_EQUALS(test, 3, vec2[2]);
}

void testVectorFromEmptyStdVector(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec({});

    ASSERT_EQUALS(test, 0ul, vec.getSize());
    ASSERT_THROWS(test, std::out_of_range, vec[1]);
}

void testVectorAccessOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    const Vector<int> vec({1, 2, 3});

    ASSERT_EQUALS(test, 1, vec[0]);
    ASSERT_EQUALS(test, 2, vec[1]);
    ASSERT_THROWS(test, std::out_of_range, vec[10]);
}

void testVectorEqualsOperator(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1({1, 2, 3});
    Vector<int> vec2({1, 2, 3});
    Vector<int> vec3({1, 2, 3, 4});
    Vector<int> vec4({1, 2, 4});

    ASSERT_TRUE(test, vec1 == vec2);
    ASSERT_FALSE(test, vec1 != vec2);
    ASSERT_TRUE(test, vec1 != vec3);
    ASSERT_FALSE(test, vec1 == vec3);
    ASSERT_TRUE(test, vec1 != vec4);
    ASSERT_FALSE(test, vec1 == vec4);
}

int main() {
    UnitTest tests({
        testVectorConstructorWithSize,
        testVectorConstructorFromStdVector,
        testVectorCopyConstructor,
        testVectorAssignmentOperator,
        testVectorFromEmptyStdVector,
        testVectorAccessOperator,
        testVectorEqualsOperator,
    });
    return tests.run();
}
