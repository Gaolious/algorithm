#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MaxN (50)
char Map[MaxN][MaxN];
int A[11][11];
int Y, X;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
int D[11][ 2048 + 1 ]; // 0:robot, 1~N:dust
const int INF = 1000000000;

struct Pt {
    int y, x;
};
vector<Pt> P;

void bfs(int idx) {
    queue<Pt> Q;
    int d, ty, tx;
    int C[MaxN][MaxN];
    memset(C, -1, sizeof(C));

    Q.push(P[idx]);
    C[ P[idx].y ][ P[idx].x ] = 0;

    while (!Q.empty()) {
        auto [y,x] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;
            if ( Map[ty][tx] == 'x' ) continue;

            if ( C[ty][tx] < 0 || C[ty][tx] > C[y][x] + 1 ) {
                C[ty][tx] = C[y][x] + 1;
                Q.push({ty, tx});
            }
        }
    }

    for ( int i = 0 ; i < P.size(); i ++ )
        A[ idx ][ i ] = C[ P[i].y ][ P[i].x ];
}
bool Input() {
    int i, j;

    memset(Map, -1, sizeof(Map));
    memset(A, -1, sizeof(A));
    memset(D, -1, sizeof(D));
    P.clear();

    cin >> X >> Y;
    if ( X == 0 && Y == 0 )
        return false;
    P.push_back({0, 0});

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> Map[i][j];
            if ( Map[i][j] == 'o')
                P[0] = {i, j};
            else if ( Map[i][j] == '*')
                P.push_back({i, j});
        }
    return true;
}
int Output(int s, int mask) {
    if ( !mask )
        return INF;

    int i, bit, tmp;
    auto &ret = D[s][mask];
    if ( ret < 0 ) {
        ret = INF;
        for ( i = 0 ; i < P.size() ; i ++ ) {
            bit = 1 << i ;
            if ( i == s ) continue;
            if ( A[s][i] < 0 ) continue;
            if ( bit & mask ) {
                tmp = Output(i, mask & ( ~( 1<<s )) );
                if ( ret < 0 || ret > tmp + A[s][i] )
                    ret = tmp + A[s][i];
            }
        }
    }
    return ret;
}
void dump_dist() {
    int i, j;

    for ( i = 0 ; i < P.size() ; i ++ ) {
        for ( j = 0 ; j < P.size() ; j ++ ) {
            cout << setw(3) << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;

    while ( Input() ) {
        for ( i = 0 ; i < P.size() ; i ++ )
            bfs(i);

        for ( i = 0 ; i < P.size() ; i ++ )
            for ( j = 0 ; j < P.size() ; j ++ )
                D[i][ (1<<j) | (1<<i) ] = A[i][j] < 0 ? INF : A[i][j];

        auto ret = Output(0, ( 1 << P.size()) - 1);
        cout << ( ret >= INF ? -1 : ret) << '\n';
    }

    return 0;
}


