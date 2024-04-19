#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, i;
    ll ret, v ;
    cin >> N;
    vector<ll> V(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> V[ i ] ;
    }
    v = 0;
    ret = 0;
    for ( i = N - 1 ; i >= 0 ; i -- ) {
        v = min( v + 1 , V[i]);
        ret += v;
    }
    cout << ret ;
    return 0;
}


