#include <gtest/gtest.h>
#include "utils.hpp"

namespace NS_PRIME
{
    TEST(Gcd, recursive ){
        EXPECT_EQ( 4, gcd(20, 4));
        EXPECT_EQ( 5, gcd(20, 5));
        EXPECT_EQ( 2, gcd(12, 14));
        EXPECT_EQ( 3, gcd(15, 9));
    }

    TEST(Multiply, simple ){
        EXPECT_EQ( 1024, mul(2, 10));
        EXPECT_EQ( 2048, mul(2, 11));
    }
    TEST(Multiply, with_mod ){
        EXPECT_EQ( 24, mul(2, 10, 100));
        EXPECT_EQ( 48, mul(2, 11, 100));
    }
}