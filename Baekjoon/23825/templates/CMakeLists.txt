cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


SET(BINARY test_template)
SET(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(${BINARY} ${SRCS} combination.h)

ADD_COMPILE_OPTIONS(-DAJAVA_DEBUG)

add_test(NAME ${BINARY} COMMAND ${BINARY})

TARGET_LINK_LIBRARIES(${BINARY} gtest_main pthread)

include_directories(
        /usr/local/include
)
