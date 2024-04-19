#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll D[10+1];
const ll INF = 1000000000ll;
ll F(ll N) {
    ll ret = 0;
    if ( N >= 8 ) {
        ll t = (N-8) % 5;
        ll A[] = {0, 1, 0, 1, 2};
        return A[t] + 2 + (N-8)/5;
    }
    if ( D[N] == INF ) return -1 ;
    return ret + D[N];
}

int main()
{
    fastio;
    int i;
    for ( i = 1 ; i <= 10 ; i ++ ) {
        D[i] = 1000000000ll;
        if ( i-3 >= 0 )
            D[i] = min(D[i-3]+1, D[i]);
        if ( i-5 >= 0 )
            D[i] = min(D[i-5]+1, D[i]);
    }
    ll N;
    cin >> N;
    cout << F(N) << '\n';

    return 0;
}


