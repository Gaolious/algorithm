#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_UTILS_H
#define BOJ_UTILS_H

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

    template<typename T> pair<T, T> exGCD(T a, T b) {
        // a * ret.first + b * ret.second = gcd(a,b)
        if (b == 0) return { 1, 0 };
        auto t = exGCD(b, a%b);
        return { t.second, t.first - t.second*(a / b) };
    }

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
