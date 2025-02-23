#include <stdexcept>

#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorAddValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1(std::vector<int>{1, 2, 3});
    const Vector<int> vec2(std::vector<int>{1, 2, 3});
    const Vector<int> expected(std::vector<int>{2, 4, 6});

    ASSERT_FALSE(test, vec1 == expected);
    const Vector<int> res = vec1.add(vec2);
    ASSERT_TRUE(test, res == expected);
}

void testVectorAddInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1(std::vector<int>{1, 2, 3});
    const Vector<int> vec2(std::vector<int>{1, 2, 3, 4});

    ASSERT_THROWS(test, std::invalid_argument, vec1.add(vec2));
}

void testVectorSubstractValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1(std::vector<int>{1, 2, 3});
    const Vector<int> vec2(std::vector<int>{1, 2, 3});
    const Vector<int> expected(std::vector<int>{0, 0, 0});

    ASSERT_FALSE(test, vec1 == expected);
    const Vector<int> res = vec1.sub(vec2);
    ASSERT_TRUE(test, res == expected);
}

void testVectorSubstractInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1(std::vector<int>{1, 2, 3});
    const Vector<int> vec2(std::vector<int>{1, 2, 3, 4});

    ASSERT_THROWS(test, std::invalid_argument, vec1.sub(vec2));
}

void testVectorScalar(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1(std::vector<int>{1, 2, 3});
    const Vector<int> expected(std::vector<int>{3, 6, 9});

    ASSERT_FALSE(test, vec1 == expected);
    const Vector<int> res = vec1.scalar(3);
    ASSERT_TRUE(test, res == expected);
}

int main() {
    UnitTest tests({
        testVectorAddValid,
        testVectorAddInvalid,
        testVectorSubstractValid,
        testVectorSubstractInvalid,
        testVectorScalar,
    });
    return tests.run();
}
