#include <iostream>
#include <vector>

#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorConstructorFromStdVector(UnitTest &test) {
    test.setCurrentTestName("testVectorConstructorFromStdVector");
    std::vector<int> stdVec = {1, 2, 3};
    Vector<int> vec(stdVec);

    ASSERT_EQUALS(test, 3ul, vec.getSize());
    ASSERT_EQUALS(test, 1, vec[0]);
    ASSERT_EQUALS(test, 2, vec[1]);
    ASSERT_EQUALS(test, 3, vec[2]);
}

void testVectorCopyConstructor(UnitTest &test) {
    test.setCurrentTestName("testVectorCopyConstructor");
    std::vector<int> stdVec = {1, 2, 3};
    Vector<int> vec1(stdVec);
    Vector<int> vec2(vec1);

    ASSERT_EQUALS(test, 3ul, vec2.getSize());
    ASSERT_EQUALS(test, 1, vec2[0]);
    ASSERT_EQUALS(test, 2, vec2[1]);
    ASSERT_EQUALS(test, 3, vec2[2]);
}

void testVectorAssignmentOperator(UnitTest &test) {
    test.setCurrentTestName("testVectorAssignmentOperator");
    std::vector<int> stdVec = {1, 2, 3};
    Vector<int> vec1(stdVec);
    Vector<int> vec2 = vec1;

    ASSERT_EQUALS(test, 3ul, vec2.getSize());
    ASSERT_EQUALS(test, 1, vec2[0]);
    ASSERT_EQUALS(test, 2, vec2[1]);
    ASSERT_EQUALS(test, 3, vec2[2]);
}

int main() {
    UnitTest tests({
        testVectorConstructorFromStdVector,
        testVectorCopyConstructor,
        testVectorAssignmentOperator,
    });
    return tests.run();
}
