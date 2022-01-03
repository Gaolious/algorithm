#include <gtest/gtest.h>
#include "combination.h"

namespace NS_COMBINATION
{
    struct TestData {
        long long n, r, m, expected ;
    };
    vector<TestData> SmallPrime = {
            {3, 2, 7, 3},
            {5, 3, 7, 3},
    };
    vector<TestData> BigPrime = {
            {17, 7, 1000000007, 19448},
            {19, 11, 1000000007, 75582},
            {18972, 1233, 1000000007, 691680323},
    };
    vector<TestData> NormalData = {
            {17, 7, 30, 8},
            {19, 11, 30, 11},
            {18972, 1233, 10240, 8640},
    };

    TEST(nCr, factorial){
        for( auto input : SmallPrime ) {
            EXPECT_EQ(input.expected, NCR::FACTORIAL::nCr(input.n, input.r, input.m) );
        }
    }

    TEST(nCr, Inverse){
        for( auto input : SmallPrime ) {
            NCR::INVERSE::NCR ncr(input.n, input.m);
            EXPECT_EQ(input.expected, ncr.nCr(input.n, input.r) );
        }
        for( auto input : BigPrime ) {
            NCR::INVERSE::NCR ncr(input.n, input.m);
            EXPECT_EQ(input.expected, ncr.nCr(input.n, input.r) );
        }
//        for( auto input : NormalData ) {
//            NCR::INVERSE::NCR ncr(input.n, input.m);
//            EXPECT_EQ(input.expected, ncr.nCr(input.n, input.r) );
//        }
    }

    TEST(nCr, Ferma){
        for( auto input : SmallPrime ) {
            EXPECT_EQ(input.expected, NCR::FERMAT::nCr(input.n, input.r, input.m) );
        }
        for( auto input : BigPrime ) {
            EXPECT_EQ(input.expected, NCR::FERMAT::nCr(input.n, input.r, input.m) );
        }
    }

    TEST(nCr, Lucas){
        for( auto input : SmallPrime ) {
            EXPECT_EQ(input.expected, NCR::LUCAS::nCr(input.n, input.r, input.m) );
        }
//        for( auto input : BigPrime ) {
//            EXPECT_EQ(input.expected, NCR::LUCAS::nCr(input.n, input.r, input.m) );
//        }
    }
}