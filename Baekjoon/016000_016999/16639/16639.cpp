#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const ll INF = (1ll << 32) ;
typedef pair<ll, ll> pll ;
pll D[20][20];
string S ;

pll minmax(pll a, pll b) {
    return {min(a.first, b.first), max(a.second, b.second) };
}
pll calc(pll a, pll b, char o) {
    ll t;
    pll ret = { INF, -INF };

    for (auto l : {a.first, a.second}) {
        for (auto r: {b.first, b.second}) {
            if ( o == '+' ) t = l+r;
            else t = ( o == '-' ) ? l-r : l*r;
            ret.first = min(ret.first, t);
            ret.second = max(ret.second, t);
        }
    }
    return ret;
}

pll F(int s, int e) {
    auto &ret = D[s][e];

    int k ;
    if ( ret.first >= INF ) {
        for ( k = s+1 ; k <= e-1 ; k += 2 )
            ret = minmax(ret, calc( F(s, k-1), F(k+1, e), S[k] ) );
    }
    return ret;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    int i, j;

    cin >> N >> S ;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            D[i][j].first = INF, D[i][j].second = -INF;

    for ( i = 0 ; i < N ; i += 2 )
        D[i][i].first = D[i][i].second = S[i] - '0';

    cout << F(0, N-1).second;
    return 0;
}


