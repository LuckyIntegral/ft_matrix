#include <stdexcept>

#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorLinearCombinationValid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<float> vec1({1, 2, 3});
    Vector<float> vec2({0, 10, -100});

    Vector<Vector<float>> vectors({vec1, vec2});
    Vector<float> coefficients(std::vector<float>({10, -2}));

    Vector<float> expected({10, 0, 230});

    ASSERT_FALSE(test, vec1 == expected);
    Vector<float> res = linear_combination(vectors, coefficients);
    ASSERT_TRUE(test, res == expected);
}

void testVectorLinearCombinationInvalid(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<float> vec1({1, 2, 3});
    Vector<float> vec2({0, 10, -100});

    Vector<Vector<float>> vectors({vec1, vec2});
    Vector<float> coefficients(std::vector<float>({10, -2, 5}));

    // vectors.size() != coefficients.size()
    ASSERT_THROWS(test, std::invalid_argument, linear_combination(vectors, coefficients));

    Vector<float> vec3({0, 10, -100, 4});
    vectors = Vector<Vector<float>>({vec1, vec2, vec3});

    // vectors[2] has a different size
    ASSERT_THROWS(test, std::invalid_argument, linear_combination(vectors, coefficients));
}

int main() {
    UnitTest tests({
        testVectorLinearCombinationValid,
        testVectorLinearCombinationInvalid,
    });
    return tests.run();
}
