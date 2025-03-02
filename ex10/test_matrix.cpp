

#include "Matrix.hpp"
#include "UnitTest.hpp"

void testMatrixREFValid(UnitTest &test) {
    SET_TEST_NAME(test);
    {
        Matrix<float> u({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        });
        Matrix<float> expected({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        });

        ASSERT_EQUALS(test, expected, u.row_echelon());
    }
    {
        Matrix<float> u({
            {1, 2},
            {3, 4},
        });
        Matrix<float> expected({
            {1, 0},
            {0, 1},
        });

        ASSERT_EQUALS(test, expected, u.row_echelon());
    }
    {
        Matrix<float> u({
            {1, 2},
            {2, 4},
        });
        Matrix<float> expected({
            {1, 2},
            {0, 0},
        });

        ASSERT_EQUALS(test, expected, u.row_echelon());
    }
    {
        Matrix<float> u({
            {8, 5, -2, 4, 28},
            {4, 2.5, 20, 4, -4},
            {8, 5, 1, 4, 17},
        });
        Matrix<float> expected({
            {1.0, 0.625, 0.0, 0.0, -12.1666667},
            {0.0, 0.0, 1.0, 0.0, -3.6666667},
            {0.0, 0.0, 0.0, 1.0, 29.5},
        });

        ASSERT_EQUALS(test, expected, u.row_echelon());
    }
    {
        Matrix<float> m1({
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        });
        Matrix<float> expected({
            {1, 0, -1},
            {0, 1, 2},
            {0, 0, 0},
        });

        ASSERT_EQUALS(test, Matrix<float>(3, 3, 0.f), m1.row_echelon() - expected);
    }
}

int main() {
    UnitTest tests({
        testMatrixREFValid,
    });
    return tests.run();
}
