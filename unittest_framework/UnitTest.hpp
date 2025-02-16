
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
#define ASSERT_TRUE(test, actual) \
    test.assertEquals(true, actual, __FILE__, __LINE__)
#define ASSERT_FALSE(test, actual) \
    test.assertEquals(false, actual, __FILE__, __LINE__)
#define ASSERT_THROWS(test, exception_type, expr) \
    test.assertThrows<exception_type>([&]() { expr; }, __FILE__, __LINE__)
#define SET_TEST_NAME(test) test.setCurrentTestName(__FUNCTION__)

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

    template <typename ExceptionType, typename Callable>
    void assertThrows(Callable &&callable, const std::string &file, int line) {
        try {
            callable();
            std::cerr << __FUNCTION__ << "(" << typeid(ExceptionType).name()
                      << ") --- no exception thrown at --- " << file << ":"
                      << line << ")" << std::endl;
            this->_currentTestResult = TestResult::KO;
        } catch (const ExceptionType &) {
            this->_currentTestResult = TestResult::OK;
        } catch (...) {
            std::cerr << __FUNCTION__ << " --- unexpected behavior at --- " << file
                      << ":" << line << std::endl;
            this->_currentTestResult = TestResult::KO;
        }
    }
};
