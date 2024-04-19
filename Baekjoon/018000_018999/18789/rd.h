//
// Created by ajava on 24. 3. 24.
//

#include "common.h"

#ifndef CLION_RD_H
#define CLION_RD_H

struct Random {
    mt19937 rd;

    Random() : rd((unsigned) chrono::steady_clock::now().time_since_epoch().count()) {}
    Random(int seed) : rd(seed) {}
    short GetInt(short l = 0, short r = 32767) {
        return uniform_int_distribution<short>(l, r)(rd);
    }
    ll GetLongInt(ll l = 0, ll r = 32767) {
        return uniform_int_distribution<ll>(l, r)(rd);
    }
    double GetDouble(double l = 0, double r = 1) {
        return uniform_real_distribution<double>(l, r)(rd);
    }
} R;

#endif //CLION_RD_H
