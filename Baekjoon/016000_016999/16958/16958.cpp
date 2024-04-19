#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N, T;

struct Data {
    int s, x, y;
};

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k, d;

    cin >> N >> T ;
    vector<Data> P(N);
    vector<int> D(N);

    for ( auto &p: P)
        cin >> p.s >> p.x >> p.y ;

    auto dist = [&](int a, int b) {
        int ret = abs(P[a].x-P[b].x) + abs(P[a].y-P[b].y);
        if ( P[i].s && P[j].s )
            ret = min(ret, T);
        return ret;
    };
    for ( i = 0 ; i < P.size() ; i ++ ) D[i] = 10000;

    for (i = 0 ; i < P.size() ; i ++ ) {
        if ( P[i].s ) continue;

        for ( j = 0 ; j < P.size() ; j ++ ) {
            if ( !P[j].s || i == j ) continue;
            D[i] = min(D[i], dist(i,j));
        }
    }
    for ( i = 0 ; i < P.size() ; i ++ )
        if ( P[i].s ) D[i] = 0;

    int M ;
    cin >> M ;
    while( M -- ) {
        cin >> j >> i ; i--; j--;
        cout << min( dist(i, j), D[i]+D[j]+T )<< '\n';
    }
    return 0;
}


