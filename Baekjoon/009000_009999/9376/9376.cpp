#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int,int> Pt;

#define MaxN (100)

char M[MaxN][MaxN];
int DP[3][MaxN][MaxN];
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
int Y, X;
const int inf = 10000000;

void dump(int A[MaxN][MaxN]) {
    int i, j;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] < 0 )
                cout << '.';
            else
                cout << A[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
void dump(char A[MaxN][MaxN]) {
    int i, j;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cout << A[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
void bfs(Pt prisoner, int D[MaxN][MaxN] ) {
    int d, ty, tx, v;
    queue<Pt> Q;
    Q.emplace(prisoner);
    if ( M[prisoner.first][prisoner.second] == '#' )
        D[prisoner.first][prisoner.second] = 1;
    else
        D[prisoner.first][prisoner.second] = 0;

    while ( !Q.empty() ) {
        auto [y, x] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;
            if ( M[ty][tx] == '*') continue;
            v = D[y][x] + ( M[ty][tx] == '#' ? 1 : 0 );
            if ( D[ty][tx] < 0 || D[ty][tx] > v ) {
                D[ty][tx] = v;
                Q.emplace(ty, tx);
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
    int T, y, x, v;
    int i, j, ret1, ret2, ret3;
    vector<Pt> Prisoner;

    cin >> T;
    while ( T-- ) {
        Prisoner.clear();
        memset(M, -1, sizeof(M));
        memset(DP, -1, sizeof(DP));

        cin >> Y >> X ;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                cin >> M[ i ][ j ] ;

                if ( M[i][j] == '$' )
                    Prisoner.emplace_back(i,j);
            }
        }

        for ( y = 0 ; y < Y ; y ++ ) {
            if ( M[y][0] != '*' ) bfs({y, 0}, DP[0]);
            if ( M[y][X-1] != '*' ) bfs({y, X-1}, DP[0]);
        }
        for ( x = 0 ; x < X ; x ++ ) {
            if ( M[0][x] != '*' ) bfs({0, x}, DP[0]);
            if ( M[Y-1][x] != '*' ) bfs({Y-1, x}, DP[0]);
        }

        bfs(Prisoner[0], DP[1]);
        bfs(Prisoner[1], DP[2]);
        ret1 = ret2 = ret3 = inf;

        for ( y = 0 ; y < Y ; y ++ ) {
            for ( x = 0 ; x < X ; x ++ ) {
                if ( DP[0][y][x] >= 0 && DP[1][y][x] >= 0 && DP[2][y][x] >= 0 ) {
                    v = DP[0][y][x] + DP[1][y][x] + DP[2][y][x] ;
                    if ( M[y][x] == '#' ) v = v - 2;
                    ret3 = min(ret3, v);
                }
                if ( DP[0][y][x] >= 0 && DP[1][y][x] >= 0 ) {
                    v = DP[0][y][x] + DP[1][y][x];
                    if ( M[y][x] == '#' ) v = v - 1;
                    ret1 = min(ret1, v);
                }
                if ( DP[0][y][x] >= 0 && DP[2][y][x] >= 0 ) {
                    v = DP[0][y][x] + DP[2][y][x];
                    if ( M[y][x] == '#' ) v = v - 1;
                    ret2 = min(ret2, v);
                }
            }
        }
        cout << min( ret1 + ret2, ret3) << '\n';
    }

    return 0;
}


