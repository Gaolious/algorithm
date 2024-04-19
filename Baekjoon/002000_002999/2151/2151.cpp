#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
// int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
// string strD[] = {
//     "→", "↘", "↓", "↙", "←", "↖", "↑", "↗"
// };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0};
string strD[] = {
    "→","↓", "←", "↑",
};
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

#define BIT(k) ( 1 << ( k ) )
#define BIT_CHECK(v, k) ( (v) & BIT(k) )
#define BIT_SET(v, k) ( (v) |= BIT(k) )
struct Data {
    int y, x, dir;
};

vector<vector<int>> D;
vector<vector<int>> V;
vector<vector<char>> A;
void dump() {
    int i, j;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] == '*' )
                cout << setw(2) << '*';
            else
                cout << setw(2) << D[i][j] ;
            cout << ' ';
        }
        cout << '\n';
    }
}
void bfs(int yp, int xp) {
    int d, ty, tx;
    queue<Data> Q;

    for ( d = 0 ; d < 4 ; d ++ ) {
        D[yp][xp] = -1;
        Q.push({yp, xp, d});
    }

    while( !Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        ty = curr.y + dy[ curr.dir ];
        tx = curr.x + dx[ curr.dir ];
        // cout << '\n';
        // cout << "Curr Y=" << curr.y << ", X=" << curr.x << ", d=" << strD[curr.dir] << '\n';
        // dump();

        while ( valid(ty, tx) && A[ty][tx] != '*') {
            if (D[ty][tx] > D[curr.y][curr.x] + 1 ) {
                D[ty][tx] = min(D[ty][tx], D[curr.y][curr.x] + 1 );
                if ( A[ty][tx] == '!' ) {
                    if ( !BIT_CHECK(V[ty][tx], (curr.dir+1)%4 ) ) {
                        // cout << "added ty=" << ty <<", tx=" << tx << ", d=" << strD[(curr.dir+2)%8] << '\n';
                        Q.push({ty, tx, ( curr.dir + 1 ) % 4});
                        BIT_SET(V[ty][tx], (curr.dir+1)%4 );
                    }
                    if ( !BIT_CHECK(V[ty][tx], (curr.dir+3)%4 ) ) {
                        // cout << "added ty=" << ty <<", tx=" << tx << ", d=" << strD[(curr.dir+6)%8] << '\n';
                        Q.push({ty, tx, ( curr.dir + 3 ) % 4});
                        BIT_SET(V[ty][tx], (curr.dir+3)%4 );
                    }
                }
            }
            ty += dy[curr.dir];
            tx += dx[curr.dir];
        }
    }
    // dump();

}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    cin >> Y ; X =Y ;
    D.resize(Y, vector<int>(X, Y*X));
    A.resize(Y, vector<char>(X));
    V.resize(Y, vector<int>(X, 0));

    vector<pii> gate;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++) {
            cin >> A[i][j];
            if ( A[i][j] == '#' ) gate.emplace_back(i, j);
        }

    bfs(gate[0].first, gate[0].second);
    cout << D[gate[1].first][gate[1].second] << '\n';;
    return 0;
}


