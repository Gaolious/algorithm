#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    ll N, R;
    ll i;
    ll ret = 0, a;
    vector<ll> divisors;

    cin >> N >> R ;

    for (i = 1 ; i * i <= N - R ; i ++ ) {
        if ( (N-R) % i != 0 ) continue;
        a = i ;
        if ( N % a == R ) ret += a ;
        if ( i * i < N-R ) {
            a = (N-R) / i ;
            if ( N % a == R ) ret += a ;
        }
    }
    cout << ret << '\n';
    return 0;
}


