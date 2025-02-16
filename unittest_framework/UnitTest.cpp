
#include "UnitTest.hpp"

UnitTest::UnitTest(const std::vector<TestFunction> &tests)
    : _tests(tests), _totalTests(0), _passedTests(0) {
}

UnitTest::~UnitTest() {
    std::cout << "Tests passed " << this->_passedTests << " / "
              << this->_totalTests << std::endl;
}

void UnitTest::executeTest(const TestFunction &test) {
    try {
        test(*this);
    } catch (const std::exception &e) {
        std::cerr << "Test failed with exception " << e.what() << std::endl;
        this->_currentTestResult = TestResult::KO;
    } catch (...) {
        std::cerr << "Test failed with unknown exception" << std::endl;
        this->_currentTestResult = TestResult::KO;
    }
}

int UnitTest::run() {
    for (const auto &test : this->_tests) {
        this->_currentTestResult = TestResult::OK;
        executeTest(test);
        this->printTestResult(this->_currentTestName, this->_currentTestResult);
        if (this->_currentTestResult == TestResult::OK) {
            this->_passedTests++;
        }
        this->_totalTests++;
    }

    return this->_totalTests - this->_passedTests;
}

void UnitTest::setCurrentTestName(const std::string &name) {
    this->_currentTestName = name;
}

void UnitTest::setCurrentTestResult(TestResult result) {
    this->_currentTestResult = result;
}

void UnitTest::printTestResult(const std::string &name, TestResult result) {
    std::cout << result << " : " << name << std::endl;
}
