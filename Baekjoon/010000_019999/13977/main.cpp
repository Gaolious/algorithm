#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const ll MaxN = 4'000'000;
const ll MOD = 1'000'000'007;
ll F[MaxN + 1];
void setF(){
    F[0] = 1;
    for ( ll i = 1 ; i <= MaxN ; i ++ ) {
        F[i] = ( F[i-1] * i ) % MOD ;
    }
}
ll power(ll a, ll n) {
    ll ret = 1;
    while ( n ) {
        if ( n & 1 )
            ret = ( ret * a ) % MOD ;
        n /= 2 ;
        a = ( a * a ) % MOD ;
    }
    return ret;
}

int main()
{
    fastio;
    ll N, M, K, ret ;
    setF();

    cin >> M ;
    while (M--) {

        cin >> N >> K ;
        ret = power((F[N-K] * F[K]) % MOD , MOD - 2) * F[N] % MOD ;
        cout << ret << '\n';
    }
    return 0;
}


