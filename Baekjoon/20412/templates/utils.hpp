#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_UTILS_H
#define BOJ_UTILS_H

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

    template<typename T> pair<T, T> eGCD(T a, T b) {
        if (b == 0) return { 1, 0 };
        auto t = eGCD(b, a%b);
        return { t.second, t.first - t.second*(a / b) };
    }
    template <typename T> T eGCD(T a, T b, T &x, T &y) {
        if (b == 0) { x=1, y=0; return a; }
        auto t = eGCD(b, a % b, y, x);
        y -= a / b * x;
        return t;
    }

    template <typename T> T GCD( T a, T b ) {
        return b > 0 ? gcd(b, a % b) : a;
    }
    template <typename T> T mPOW( T a, T n, T m) {
        // a^n % m
        T ans = 1;
        for ( ans=1; n > 0 ; n/= 2, a = (a * a) % m )
            if ( n % 2 ) ans = ( ans * a ) % m;
        return ans;
    }
    template <typename T> T mMUL( T a, T n, T m) {
        //  (a*b) % m
        T ans = 0;
        for ( ans=0; n > 0 ; n/= 2, a = (a + a) % m )
            if ( n % 2 ) ans = ( ans + a ) % m;
        return ans;
    }

    template <typename T> T POW(T a, T n) {
        // a^n
        T ans = 1;
        for ( ans=1; n > 0 ; n/= 2, a *= a )
            if ( n % 2 ) ans *= a;
        return ans;
    }
#endif //BOJ_UTILS_H

