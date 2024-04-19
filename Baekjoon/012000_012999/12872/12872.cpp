#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const ll MOD = 1000000007;
vector< vector<ll>> D;

ll N, M, P;

ll F(ll useCnt, ll len) {
    if ( len == P )
        return useCnt == N;

    auto &ret = D[ useCnt ][ len ];
    if ( ret < 0 ) {
        ret = 0;
        if ( useCnt < N )
            ret += F(useCnt + 1 , len + 1) * (N - useCnt) ;
        if ( useCnt > M )
            ret += F(useCnt, len + 1 ) * ( useCnt - M ) ;
    }
    return ret % MOD;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> N >> M >> P ;
    D.resize(N+1, vector<ll>(P+1, -1));

    cout << F(0, 0) << '\n';
    return 0;
}


