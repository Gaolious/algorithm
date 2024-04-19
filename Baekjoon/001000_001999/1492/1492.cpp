#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1'000'000'007;
const int MaxN = 51 ;

ll C[MaxN+1][MaxN+1]={0,};
ll IV[MaxN+1]={0,};

ll POW(ll a, ll x){
    ll ret = 1;
    a %= MOD ;
    while ( x > 0 ) {
        if ( x % 2 == 1 ) ret = (ret * a) % MOD ;
        a = (a*a)%MOD;
        x /= 2;
    }
    return ret;
}
ll faulhaber(long long n, ll k){
    n %= MOD;
    if (!k) return n;

    ll ret, p;
    int i ;

    ret = 0;
    p = 1 ;
    for ( i = 0 ; i <= k ; i ++ ) {
        p = p * (n + 1 - i) % MOD;
        ret = (ret + ( C[k][i] * p % MOD * IV[i + 1] % MOD) ) % MOD;
    }

    return ret % MOD;
}
void process() {
    fastio;
    int N, K ;
    int i, j ;

    for ( i = 0; i <= MaxN ; i ++ )
        IV[ i ] = POW(i, MOD - 2);
    C[0][0] = 1;
    for ( i = 1 ; i <= MaxN ; i ++ ) {
        C[i][0] = 0;
        for ( j = 1 ; j <= i ; j ++ )
            C[i][j] = (C[i-1][j]*j + C[i-1][j-1]) % MOD ;
    }
    cin >> N >> K ;

    cout << faulhaber(N, K) << '\n';
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


