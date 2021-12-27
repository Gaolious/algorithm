cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(boj)

enable_testing()

ADD_COMPILE_OPTIONS(-DAJAVA_DEBUG)
add_executable(boj main.cpp templates/prime.hpp)
add_subdirectory(templates)

include_directories(
    /usr/local/include
)

TARGET_LINK_LIBRARIES(boj
        /usr/local/lib/libgtest.a
        /usr/local/lib/libgtest_main.a
        pthread
        )