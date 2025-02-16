
run () {
    CXXFLAGS="-Wall -Wextra -std=c++17 -pedantic"
    INCLUDES="-I library -I unittest_framework"
    NAME="test"
    UNIT_TESTS="./unittest_framework/UnitTest.cpp"
    TESTS=$(find . -name "test_*.cpp")

    for test in $TESTS; do
        g++ $CXXFLAGS -o $NAME $test $UNIT_TESTS $INCLUDES
        ./$NAME
        rm $NAME
    done
}

run $@
