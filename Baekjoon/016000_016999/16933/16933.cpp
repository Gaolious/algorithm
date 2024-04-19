#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[11][1000][1000];
char A[1000][1000];
const int inf = 10000000;
struct Data {
    int y, x, k, dist;
    Data(int y, int x, int k, int dist) : y(y), x(x), k(k), dist(dist) {}
};
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
int Y, X, K;

void bfs() {
    int d, ty, tx, tk, dist;
    queue<Data> Q;
    Q.emplace(0, 0, 0, 1);
    D[0][0][0] = 1;
    while (!Q.empty()) {
        auto curr = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = curr.y + dy[d];
            tx = curr.x + dx[d];
            tk = curr.k ;
            dist = curr.dist + 1;

            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;

            if ( A[ty][tx] == '1' ) {
                tk ++;
                if ( dist % 2 == 1 ) dist ++;
            }

            if ( tk > K)
                continue;



            if ( D[tk][ty][tx] < 0 || D[tk][ty][tx] > dist ) {
                D[tk][ty][tx] = dist;
                Q.emplace(ty, tx, tk, dist);
            }
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
    int i, j, min_dist;

    cin >> Y >> X >> K ;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    memset(D, -1, sizeof(D));

    bfs();

    for ( min_dist=inf, i = 0 ; i <= K ; i ++ )
        min_dist = min(min_dist, D[i][Y-1][X-1] < 0 ? inf : D[i][Y-1][X-1]);
    if ( min_dist < inf )
        cout << min_dist << '\n';
    else
        cout << "-1\n";
    return 0;
}


