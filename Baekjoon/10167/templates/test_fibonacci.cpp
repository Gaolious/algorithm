//#include <gtest/gtest.h>
//#include "fibonacci.hpp"
//
//
//namespace NS_FIBONACCI
//{
//    struct TestData {
//        long long n, expected ;
//    };
//    vector<TestData> data = {
//            {1, -1},
//            {2, -1},
//            {3, -1},
//            {4, 1},
//            {5, -1},
//            {6, 1},
//            {7, 2},
//            {8, -1},
//            {9, 1},
//            {16, 3},
//            {17, 1},
//            {18, 5},
//            {19, 1},
//            {20, 2},
//            {21, -1},
//            {28, 2},
//            {35, 1},
//            {42, 8},
//            {49, 2},
//            {56, 1},
//            {63, 8},
//            {70, 2},
//            {77, 1},
//            {84, 8},
//            {91, 2},
//            {98, 1}
//    };
//    TEST(Fibonacci, Zeckendorf) {
//        for ( auto in : data ) {
//            Zeckendorf<long long int> z;
//            z.generate_fibonacci(in.n);
//            EXPECT_EQ(z.answer(in.n), in.expected);
//
//        }
//    }
//}