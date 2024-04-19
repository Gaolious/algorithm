#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int Y = 8;
const int X = 8;
char A[Y][X]{};

typedef pair<int, int> Pt;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1, 0};
void MoveWall() {
    int i, j;
    for ( i = Y-1 ; i >= 0 ; i -- )
        for ( j = 0 ; j < X ; j ++ )
            A[i][j] = ( i > 0 && A[i-1][j] == '#' ) ? '#' : '.';
}
void Dump(int idx) {
    int i, j;
    cout << "moveWall " << idx << '\n';
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ )
            cout << A[i][j];
        cout << '\n';
    }
    cout << '\n';
}

bool bfs(queue<Pt> &CQ, queue<Pt> &NQ) {
    int d, ty, tx;

    while ( !CQ.empty() ) {
        auto [y, x] = CQ.front();
        CQ.pop();
        if ( A[y][x] == '#' )
            continue;

        if ( y == 0 && x == X-1 )
            return true;
        for ( d = 0 ; d<9 ; d++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0|| tx<0 || ty>=Y || tx >= X || A[ty][tx] == '#' ) continue;
            NQ.emplace(ty, tx);
        }
    }
    return false;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    queue<Pt> Q[2];

    int i, j;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    Q[0].emplace(Y-1, 0);
    for ( i = 0 ; i < 33 ; i ++ ) {
        // Dump(i);
        if ( bfs( Q[ i % 2], Q[ 1 - (i%2) ]) ) {
            cout << "1\n";
            return 0;
        }

        if ( Q[ 1 - (i%2) ].empty() ) break;
        MoveWall();
    }
    cout << "0\n";

    return 0;
}


