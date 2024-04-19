#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int dy[] = { -2, -2, 0, 0, 2, 2};
int dx[] = { -1, 1, -2, 2, -1, 1};
int D[201][201];
struct Data {
    int y, x, dist;
    Data(int y, int x, int dist):y(y), x(x), dist(dist){}
};
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    int sy, sx, ey, ex, d, ty, tx;
    queue<Data> Q;
    memset(D, -1, sizeof(D));

    cin >> N >> sy >> sx >> ey >> ex;

    Q.emplace(sy, sx, 0);
    D[sy][sx] = 0;

    while ( !Q.empty() ) {
        auto [y, x, dist] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 6 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;
            if ( D[ty][tx] < 0 || D[ty][tx] > dist + 1 ) {
                D[ty][tx] = dist + 1;
                Q.emplace(ty, tx, dist+1);
            }
        }
    }
    cout << D[ey][ex] << '\n';
    return 0;
}


