#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<ll, ll> pii;
istream & operator >> (istream &in, pii &o) {
    in >> o.first >> o.second ;
    return in;
}

const ll inf = 2100000000;
int dist(pii a, pii b) {
    return abs(a.first-b.first) + abs(a.second - b.second);
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    vector<pii> pos(8);
    int i, j, k;
    ll D[10][10];

    for ( i = 0 ; i < 8 ; i ++ )
        cin >> pos[i];

    for ( i = 0 ; i < 8 ; i ++ )
        for ( j = 0 ; j < 8 ; j ++ )
            D[ i ][ j ] = inf ;

    for ( i = 0 ; i < 8 ; i ++ )
        for ( j = i + 1 ; j < 8 ; j ++ )
            D[i][j] = D[j][i] = dist(pos[i], pos[j]);
    for ( i = 2 ; i < 8 ; i += 2 ) {
        D[i][i+1] = min(D[i][i+1], 10ll);
        D[i+1][i] = min(D[i+1][i], 10ll);
    }
    for ( k = 0 ; k < 8 ; k ++ )
        for ( i = 0 ; i < 8 ; i ++ )
            for ( j = 0 ; j < 8 ; j ++ )
                if ( D[i][k] + D[k][j] < D[i][j] )
                    D[i][j] = D[i][k] + D[k][j];

    cout << D[0][1] ;
    return 0;
}


