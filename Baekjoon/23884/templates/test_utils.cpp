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
    TEST(ExtendGCD, simple) {
        struct data {
            int a, b, expected;
        };
        vector<data> input = {
                {3,5, 1},
                {4,2, 2},
                {12,9, 3},
        };
        auto ret = exGCD(3, 4);
        ret = exGCD(3*17, 4*17);

        for (auto in: input ) {
            auto ret = exGCD(in.a, in.b);
            EXPECT_EQ( in.a * ret.first + in.b * ret.second, in.expected);
        }
    }
}