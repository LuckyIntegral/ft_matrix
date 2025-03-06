# ft_matrix

## Overview
`ft_matrix` is a C++ library for matrix and vector operations. It includes a variety of mathematical functions and algorithms for linear algebra, such as matrix multiplication, determinant calculation, vector dot product, and more. The library is designed to be modular and extensible, with each feature implemented in separate files for clarity and maintainability.

## Features
- [Matrix and vector basic operations](ex00)
- [Linear combination of vectors](ex01)
- [Linear interpolation (lerp)](ex02)
- [Dot product of vectors](ex03)
- [Norm calculations (Manhattan, Euclidean, Supremum)](ex04)
- [Angle cosine between vectors](ex05)
- [Cross product of vectors](ex06)
- [Matrix multiplication](ex07)
- [Matrix trace](ex08)
- [Matrix transpose](ex09)
- [Row echelon form (REF)](ex10)
- [Matrix determinant](ex11)
- [Matrix inverse](ex12)
- [Matrix rank](ex13)

## Getting Started

### Prerequisites
- C++17 or later
- A C++ compiler (e.g., g++)

### Running the Project
You can run the project using the provided `run.sh` script:
```sh
./run.sh <number>
```
Replace `<number>` with the exercise number you want to run.

### Running Tests
You can run the tests using the provided `test.sh` script:
```sh
./test.sh <number>
```
Replace `<number>` with the exercise number you want to test. If no number is provided, it will run all tests.

## Custom Unit Test Framework
This project includes a custom unit test framework located in the [unittest_framework](unittest_framework) directory. The framework provides basic functionality for writing and running unit tests.

### Example Test
Here is an example of how to write a test using the custom unit test framework:
```c++
#include "UnitTest.hpp"
#include "Vector.hpp"

void testVectorAddition(UnitTest &test) {
    SET_TEST_NAME(test);
    Vector<int> vec1({1, 2, 3});
    Vector<int> vec2({4, 5, 6});
    Vector<int> result = vec1 + vec2;

    ASSERT_EQUALS(test, 5, result[0]);
    ASSERT_EQUALS(test, 7, result[1]);
    ASSERT_EQUALS(test, 9, result[2]);
}

int main() {
    UnitTest tests({
        testVectorAddition,
        // Add more tests here
    });
    return tests.run();
}
```

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes. Make sure to follow the coding style and include tests for any new features or bug fixes.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Thanks to all the contributors who have helped improve this project.
- Special thanks to the open-source community for providing valuable resources and inspiration.
