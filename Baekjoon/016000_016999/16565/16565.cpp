#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MOD = 10007;

int C[53][53];
int nCr(int n, int r) {
    int &ret = C[n][r];
    if ( ret == 0 ) {
        if ( r == 0 || n == r ) ret = 1;
        else ret = ( nCr(n-1, r-1) + nCr(n-1, r) ) % MOD;
    }
    return ret;
}

int main()
{
    fastio;
    int c ;
    int ret = 0 ;
    int N ;
    cin >> N ;

    for ( int i = 4 ; i <= N ; i+=4 ) {
        c = nCr(13, i/4) * nCr( 52 - i, N - i);
        if ( (i/4) % 2 == 1 ) ret += c;
        else ret -= c ;
        ret = ( ret % MOD + MOD ) % MOD ;
    }
    cout << ret << '\n';
    return 0;
}


