#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_UTILS_H
#define BOJ_UTILS_H
    template <typename T> T gcd( T a, T b ) {
        return b > 0 ? gcd(b, a % b) : a;
    }
    template <typename T> T mul( T a, T n) {
        // a^n
        T ans = 1;
        for ( ans=1; n > 0 ; n/= 2, a *= a )
            if ( n % 2 ) ans *= a;
        return ans;
    }
    template <typename T> T mul( T a, T n, T m) {
        // a^n % m
        T ans = 1;
        for ( ans=1; n > 0 ; n/= 2, a = (a * a) % m )
            if ( n % 2 ) ans = ( ans * a ) % m;
        return ans;
    }
#endif //BOJ_UTILS_H
