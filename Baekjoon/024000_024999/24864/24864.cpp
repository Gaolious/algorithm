#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 998244353ll;

ll nCr( ll n, ll r) {
    ll i, a, b, min_r, max_r ;
    a = b = 1;
    min_r = min(n-r, r);
    max_r = max(n-r, r);
    for ( i = n ; i > max_r ; i -- )
        a = ( a * i ) % MOD ;
    for ( i = 2 ; i <= min_r ; i ++ )
        b = ( b * i ) % MOD ;

    return a * mul(b, MOD-2, m) % MOD ;
}
int main()
{
    fastio;

    return 0;
}


