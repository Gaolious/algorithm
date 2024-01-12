#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll M = 1'000'000'007;
const int MaxN = 8;
struct Matrix{
    ll m[MaxN][MaxN];
    Matrix operator *(Matrix o) {
        int i, j, k;
        ll t ;
        Matrix ret = {0, };

        for ( i = 0 ; i < MaxN ; i ++ ) {
            for ( j = 0 ; j < MaxN ; j ++ ) {
                for ( t = 0, k = 0 ; k < MaxN ; k ++ )
                    t = (t + m[i][k] * o.m[k][j]) % M ;
                ret.m[i][j] = t;
            }
        }
        return ret;
    }
    Matrix pow(int n) {
        Matrix ret = {};
        int i ;
        if ( n == 0 ) {
            for ( i = 0 ; i < MaxN ; i ++ )
                ret.m[i][i] = 1;
        }
        else if ( n % 2 == 1 ) {
            ret = pow(n/2) ;
            ret = ret * ret * (*this);
        }
        else {
            ret = pow(n/2);
            ret = ret * ret ;
        }
        return ret;
    }

};
void process() {
    fastio;
    Matrix b = {
        {
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 0, 1},
            {0, 0, 0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 1, 0}
        }
    };
    int D;

    cin >> D ;

    Matrix ret = b.pow(D);
    cout << ret.m[0][0] << '\n';

}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}
