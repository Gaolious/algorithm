#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN (50)

int Y, X;
char A[MaxN][MaxN];
int D[MaxN][MaxN];
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, d, ty, tx, ret;

    memset(D, -1, sizeof(D));
    queue<pair<int,int>> Q;

    cin >> Y >> X;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[i][j];

            if ( A[i][j] == '1' ) {
                D[i][j] = 0;
                Q.emplace(i, j);
            }
        }
    }

    while ( !Q.empty() ) {
        auto [y, x] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 8 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X )
                continue;
            if ( D[ty][tx] < 0 || D[ty][tx] > D[y][x] + 1) {
                D[ty][tx] = D[y][x]+1;
                Q.emplace(ty, tx);
            }
        }
    }
    
    ret = 0;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            ret = max(ret, D[i][j]);
        }
    }
    cout << ret << '\n';
    return 0;
}