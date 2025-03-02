
run () {
    CXXFLAGS="-Wall -Wextra -std=c++17 -pedantic"
    INCLUDES="-I library -I unittest_framework"
    NAME="test"
    UNIT_TESTS="./unittest_framework/UnitTest.cpp"

    if [ -n "$1" ]; then
        if [ $1 -lt 10 ]; then
            FOLDER="ex0$1"
        else
            FOLDER="ex$1"
        fi
    else
        FOLDER='.'
    fi

    TESTS=$(find "$FOLDER" -name "test_*.cpp")

    for test in $TESTS; do
        g++ $CXXFLAGS -o $NAME $test $UNIT_TESTS $INCLUDES
        ./$NAME
        rm $NAME
    done
}

run $@
