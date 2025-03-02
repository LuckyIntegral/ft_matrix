
run () {
    if [ -z $1 ]; then
        echo "Usage: ./run.sh <number>"
        return
    fi

    CXXFLAGS="-Wall -Wextra -std=c++17 -pedantic"
    INCLUDES="-I library"
    if [ $1 -lt 10 ]; then
        NAME="exec0$1"
        FOLDER="ex0$1"
    else
        NAME="exec$1"
        FOLDER="ex$1"
    fi

    g++ $CXXFLAGS -o $NAME $FOLDER/main.cpp $INCLUDES
    ./$NAME
    rm $NAME
}

run $@
