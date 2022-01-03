#include <gtest/gtest.h>
#include "utils.hpp"

namespace NS_PRIME
{
    TEST(Gcd, recursive ){
        EXPECT_EQ( 4, GCD(20, 4));
        EXPECT_EQ( 5, GCD(20, 5));
        EXPECT_EQ( 2, GCD(12, 14));
        EXPECT_EQ( 3, GCD(15, 9));
    }

    TEST(Multiply, simple ){
        EXPECT_EQ(1024, POW(2, 10));
        EXPECT_EQ(2048, POW(2, 11));
    }
    TEST(Multiply, with_mod ){
        EXPECT_EQ( 24, mMUL(2, 10, 100));
        EXPECT_EQ( 48, mMUL(2, 11, 100));
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

        for (auto in: input ) {
            auto ret = eGCD(in.a, in.b);
            EXPECT_EQ( in.a * ret.first + in.b * ret.second, in.expected);
        }
    }
}
