#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;

#ifndef BOJ_COMBINATION_H
#define BOJ_COMBINATION_H

namespace NCR{
    namespace FACTORIAL {
        template <typename T> T nCr( T n, T r) {
            T ret = 1, j, i ;
            j = max(n-r, r);
            for ( i = n ; i > j ; i --)
                ret *= i ;
            for ( i = n-j ; i > 1 ; i --)
                ret /= i;
            return ret;
        };
        template <typename T> T nCr( T n, T r, T m) {
            T ret = 1, j, i ;
            j = max(n-r, r);
            for ( i = n ; i > j ; i --)
                ret *= i ;
            for ( i = n-j ; i > 1 ; i --)
                ret /= i;
            return ret % m;
        };
    };
    namespace FERMAT {
        // m is prime
        template <typename T> T nCr( T n, T r, T m) {
            T i, a, b, min_r, max_r ;
            a = b = 1;
            min_r = min(n-r, r);
            max_r = max(n-r, r);
            for ( i = n ; i > max_r ; i -- )
                a = ( a * i ) % m ;
            for ( i = 2 ; i <= min_r ; i ++ )
                b = ( b * i ) % m ;

            return a * mul(b, m-2, m) % m ;
        }
    }
    namespace INVERSE {
        // m is prime
        template <typename T> class NCR {
            vector<T> F ;
            vector<T> INV ;
            T M ;
        public:

            NCR( T N, T m ) {
                this->F.resize(N+1);
                this->INV.resize(N+1);
                this->M = m ;
                this->F[0] = this->F[1] = 1;
                this->INV[0] = this->INV[1] = 1;

                for (T i = 2; i <= N ; i++)
                    this->F[i] = this->F[i-1] * i % this->M ;
                for (T i = 2; i <= N ; i++)
                    this->INV[i] = - ( this->M / i ) * this->INV[ this->M % i ] % this->M ;
                for (T i = 2; i <= N ; i++)
                    this->INV[i] = this->INV[ i - 1 ] * ( (this->INV[i] + this->M) % this->M ) % this->M ;
            }
            T nCr( T n, T r) {
                return this->F[ n ] * this->INV[r] % this->M * this->INV[ n - r ] % this->M ;
            }
        };
    }

};

#endif //BOJ_COMBINATION_H
