#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1'000'000'007ll;

ll p2(ll a, ll x) {
    ll ret = 1;
    while(x > 0 ) {
        if ( x % 2 == 1) ret = (ret * a) % MOD;
        a = (a*a) % MOD;
        x/=2;
    }
    return ret;
}

int main()
{
    fastio;
    int N;
    ll ret, k;

    cin >> N;

    vector<ll> A(N);
    for (auto &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());

    ret = 0;

    for ( int i = 0 ; i < A.size() ; i ++ ) {
        k = 0;
        k = ( k + p2(2, i) ) % MOD ;
        k = ( k - p2(2, A.size()-1-i ) ) % MOD ;
        if ( k < 0 ) k = ( k + MOD) % MOD;
        k = ( A[ i ] % MOD * k ) % MOD;
        ret = (ret + k ) % MOD;
    }
    cout << ret ;
    return 0;
}


