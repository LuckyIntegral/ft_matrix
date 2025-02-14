
run () {
    if [ -z $1 ]; then
        echo "Usage: ./run.sh <number>"
        return
    fi

    CXXFLAGS="-Wall -Wextra -std=c++17 -pedantic"
    INCLUDES="-I library"
    NAME="exec0$1"

    g++ $CXXFLAGS -o $NAME ex0$1/main.cpp $INCLUDES
    ./$NAME
}

run $@
