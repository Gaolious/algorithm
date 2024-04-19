#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

unordered_set<ll> C;
ll V[] = {
    100000000ll, 10000000ll, 1000000ll,
    100000ll, 10000ll, 1000ll,
    100ll, 10ll, 1ll,
};
ll P = 1000000000ll;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<ll, int>> Q;

ll Swap(ll src, int from, int to) {
    ll ret = src ;
    ret -= ( ( src / V[to] ) % 10 ) * V[to];
    ret += ( ( src / V[to] ) % 10 ) * V[from];
    ret += P * to;
    return ret;
}

void Move(ll src, int step) {
    int d, ty, tx, c, pos, y, x;
    ll dest;

    pos = ( src / P ) % 10ll ;
    src -= pos * P;

    y = pos / 3 ;
    x = pos % 3 ;

    for ( d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || tx < 0 || ty >= 3 || tx >= 3 ) continue;

        dest = Swap(src, pos, (ty*3+tx) );
        if ( C.emplace(dest).second ) {
            Q.emplace(dest, step);
        }
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, n, idx = 0;
    ll src;
    for ( src=0, i = 0 ; i < 3 ; i ++ ) {
        for ( j = 0 ; j < 3 ; j ++ ) {
            cin >> n ;
            src = src * 10 + n ;
            if ( n == 0 ) idx = (i*3+j);
        }
    }
    src += P * idx ;

    C.emplace(src);
    Q.emplace(src,  0);

    while ( !Q.empty() ) {
        auto [curr, step] = Q.front();

        if ( curr == 8123456780ll ) {
            cout << step ;
            return 0;
        }
        Q.pop();
        Move(curr, step+1 );
    }

    cout << "-1\n";
    return 0;
}


