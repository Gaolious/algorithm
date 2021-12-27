#include <gtest/gtest.h>
#include "prime.hpp"

namespace NS_PRIME
{
    TEST(Sum, Positive){
        EXPECT_EQ(3, SUM(1,2) );
        EXPECT_EQ(4, SUM(1,3) );
    }
}