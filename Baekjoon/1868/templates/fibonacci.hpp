#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_FIBONACCI_HPP
#define BOJ_FIBONACCI_HPP

template <typename T> class Zeckendorf {
    // 제켄도르프의 정리(Zeckendorf's theorem)
    vector<T> F;
public :

    Zeckendorf() {}
    void generate_fibonacci(T maxN) {
        int i;
        if ( 2 <= maxN ) F.push_back(2);
        if ( 3 <= maxN ) F.push_back(3);
        if ( maxN >= 4 ) {
            for ( i = 2 ; ; i ++ )
            {
                F.push_back(F[i-1] + F[i-2]);
                if ( F[i-1] + F[i-2] >= maxN ) break;
            }
        }
    }

    int lower(int l, int r, T v) {
        int m, ret = 0 ;
        while ( l <= r ) {
            m = ( l + r ) / 2 ;
            if ( F[m] == v ) return m;
            if ( F[m] < v ) {
                ret = m ;
                l = m + 1 ;
            }
            else {
                r = m - 1 ;
            }
        }
        return ret ;
    }

    T answer(T N) {
        //  idx :   1   2   3   4   5   6   7   8   9   10   11   12   13   14   15
        //  val :      -1  -1       -1          -1                     -1
        //  val :               4-3     6-5 7-5     9-8 10-8 11-8 12-8      14-13
        //  val :               1       1   2       1   2    3    1=[4]     1
        //                        <-------------------------------^^^^^

        if ( N < 2 ) return -1;
        int nF = (int)this->F.size();

        T ret = lower(0, nF, N);
        if ( F[ret] == N ) {
            return -1;
        }
        else {
            T v = answer(N - F[ret]);
            return ( v < 0 ) ? N - F[ret] : v ;
        }
    }
};
#endif //BOJ_FIBONACCI_HPP
