#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int D[4][100][100];
char A[100][100];
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
int Y, X;
struct Pt {
    int y, x, d;
};
const int inf = 100000000;

void bfs(Pt s, Pt e) {
    int d, v ;

    queue<Pt> Q;
    Q.push(s);
    for ( d = 0 ; d < 4 ; d ++)
        D[d][s.y][s.x] = 0;

    while ( !Q.empty() ) {
        auto curr = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            Pt nxt = {
                curr.y + dy[d],
                curr.x + dx[d],
                d
            };

            if ( nxt.y < 0 || nxt.x < 0 || nxt.y >= Y || nxt.x >= X )
                continue;
            if ( A[nxt.y][nxt.x] == '*' )
                continue;

            v = 0;
            if ( curr.d >= 0 ) {
                if ( (curr.d - nxt.d + 4 ) % 2 == 1 )
                    v = D[curr.d][curr.y][curr.x] + 1;
                else
                    v = D[curr.d][curr.y][curr.x];
            }

            if ( D[nxt.d][nxt.y][nxt.x] < 0 || D[nxt.d][nxt.y][nxt.x] > v) {
                D[nxt.d][nxt.y][nxt.x] = v;
                Q.push(nxt);
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
    int i, j;
    cin >> X >> Y ;
    vector<Pt> C;

    memset(D, -1, sizeof(D));

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[i][j];
            if ( A[i][j] == 'C' )
                C.push_back({i, j, -1});
        }
    }
    bfs(C[0], C[1]);

    j = inf;
    for ( i = 0 ; i < 4 ; i ++ )
        j = min(j, D[i][ C[1].y ][ C[1].x ] < 0 ? inf : D[i][ C[1].y ][ C[1].x ]);
    cout << j << '\n';

    return 0;
}


