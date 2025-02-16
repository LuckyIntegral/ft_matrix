
#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#define ASSERT_EQUALS(test, expected, actual) \
    test.assertEquals(expected, actual, __FILE__, __LINE__)

enum class TestResult : int { OK, KO };

inline std::ostream &operator<<(std::ostream &os, const TestResult &result) {
    os << (result == TestResult::OK ? GREEN "OK" RESET : RED "KO" RESET);
    return os;
}

class UnitTest;
using TestFunction = std::function<void(UnitTest &)>;

class UnitTest {
private:
    std::vector<TestFunction> _tests;
    std::string _currentTestName;
    TestResult _currentTestResult;
    int _totalTests;
    int _passedTests;

    void executeTest(const TestFunction &test);
    void printTestResult(const std::string &name, TestResult result);

public:
    UnitTest(const std::vector<TestFunction> &tests);
    ~UnitTest();

    int run();
    void setCurrentTestName(const std::string &name);
    void setCurrentTestResult(TestResult result);

    template <typename T>
    void assertEquals(const T &expected, const T &actual,
                      const std::string &file, int line) {
        if (expected != actual) {
            std::cerr << __FUNCTION__ << "(" << expected << ", " << actual
                      << ") --- failure at --- " << file << ":" << line
                      << std::endl;
            this->_currentTestResult = TestResult::KO;
        }
    }
};
