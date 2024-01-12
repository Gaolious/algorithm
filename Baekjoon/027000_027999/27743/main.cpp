#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
//typedef unsigned long long  int ull;

using namespace std;

const ll MOD = 1000000007ull;

ll P(ll a, ll n) {
    ll ret = 1ull ;
    while ( n > 0 ) {
        if ( n % 2 ) ret = ( ret * a ) % MOD ;
        n /= 2;
        a = ( a * a ) % MOD;
    }
    return ret;
}

int main()
{
    fastio;
    ll N, M, ans ;

    cin >> N >> M ;

    if ( M == 1 ) {
        ans = P(2, N) % MOD ;
        ans = ( ans - 1 + MOD ) % MOD ;
    }
    else {
        ans = M * P(2, N + 1) % MOD;
        ans = (ans - 2 * M + MOD) % MOD;
        ans = (ans - 1 + MOD ) % MOD;
    }

    cout << (ans + MOD ) % MOD << '\n';

    return 0;
}


