cmake_minimum_required(VERSION 3.20)

find_package(Threads REQUIRED)
find_package(GTest)

SET(BINARY test_template)
SET(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(${BINARY} ${SRCS} combination.h test_combination.cpp utils.hpp fibonacci.hpp test_fibonacci.cpp)

ADD_COMPILE_OPTIONS(-DAJAVA_DEBUG)

add_test(NAME ${BINARY} COMMAND ${BINARY})

TARGET_LINK_LIBRARIES(${BINARY}
        /usr/local/lib/libgtest.a
        /usr/local/lib/libgtest_main.a
        pthread
        )

include_directories(
        /usr/local/include
)
