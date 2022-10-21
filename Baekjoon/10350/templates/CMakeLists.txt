cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


SET(BINARY test_template)
SET(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(${BINARY} ${SRCS})

ADD_COMPILE_OPTIONS(-DAJAVA_DEBUG)

add_test(NAME ${BINARY} COMMAND ${BINARY})

TARGET_LINK_LIBRARIES(${BINARY} gtest_main pthread)

include_directories(
        /usr/local/include
)
