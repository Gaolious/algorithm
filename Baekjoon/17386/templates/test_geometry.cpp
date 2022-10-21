#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "geometry.h"
#include <math.h>

namespace NS_GEOMETRY {
    struct TestData {
        long long sx1, sy1, ex1, ey1;
        long long sx2, sy2, ex2, ey2;
        double cx, cy ;
    };
    TEST(intercept, cross) {
        std::vector<TestData> dataX {

                /*
                 *  |   |
                 *  |   |
                 *  |  -+------
                 *  +---------------
                 * */
//                {0, 0, 10, 0,  0, 0, 0, 10,   0, 0},
//                {0, 5, 10, 5,  0, 0, 0, 10,   0, 5},
//                {0, 10, 10, 10,0, 0, 0, 10,   0, 10},
//                {0, 0, 10, 0,  5, 0, 5, 10,   5, 0},
//                {0, 5, 10, 5,  5, 0, 5, 10,   5, 5},
//                {0, 10, 10, 10,5, 0, 5, 10,   5, 10},
//                {0, 0, 10, 0,  10, 0, 10, 10, 10, 0},
                {0, 5, 10, 5,  10, 0, 10, 10, 10, 5},
//                {0, 10, 10, 10,10, 0, 10, 10, 10, 10},
                /*
                 *  |
                 *  |
                 *  |  ----+----
                 *  +---------------
                 * */
        };
        for (auto input: dataX) {
            auto a = Line<long long>(input.sx1, input.sy1, input.ex1, input.ey1);
            auto b = Line<long long>(input.sx2, input.sy2, input.ex2, input.ey2);
            Vector2D<double> c;

            EXPECT_EQ(a.is_cross(b), true);
            EXPECT_EQ(a.getPoint(b, c), true );
            EXPECT_DOUBLE_EQ( c.x, input.cx);
            EXPECT_DOUBLE_EQ( c.y, input.cy);
        }
    }
}