cmake_minimum_required(VERSION 3.20)

project(boj)

MESSAGE ( ${CMAKE_PROJECT_NAME} test )

set(CMAKE_CXX_STANDARD 17)

ADD_COMPILE_OPTIONS(-DAJAVA_DEBUG)

add_executable(
        boj
        main.cpp
)

include_directories(
        /usr/local/include
)
