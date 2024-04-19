#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
unsigned char A[50][50];
int D[10][50][50];
int T[2048][50][50]{};

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N, M;
const int INF = 1000000;
vector<pair<int, int>> Pos;

void bfs( int y, int x, int idx ) {
    int ty, tx, d;

    queue<pair<int, int>> Q;

    Q.emplace(y, x);
    D[idx][y][x] = 0;

    while ( !Q.empty() ) {
        auto [cy, cx] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = cy + dy[d];
            tx = cx + dx[d];
            if ( ty < 0 || tx < 0 || ty >= N || tx >= N )
                continue;
            if ( A[ty][tx] == '1' )
                continue;

            if ( D[idx][ty][tx] < 0 || D[idx][cy][cx] > D[idx][ty][tx] + 1 ) {

                D[idx][ty][tx] = D[idx][cy][cx] + 1;
                Q.emplace(ty, tx);
            }
        }
    }
}
void dump(int src[50][50]) {
    int i, j ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cout << setw(2) << src[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool merge(int src[50][50], int dest[50][50]) {
    int i, j ;
    bool pass = true ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( A[i][j] == '1' )
                continue;

            if ( src[i][j] >= 0 ) {
                if ( dest[i][j] < 0 || dest[i][j] > src[i][j] )
                    dest[i][j] = src[i][j];
            }

            if ( dest[i][j] < 0 && A[i][j] == '0' )
                pass = false;
        }
    }

    return pass;
}

int apply(int idx) {
    int k;
    int i, j ;
    int ret = INF;
    int cnt;

    for ( k = 1 ; k < 2048 ; k ++ ) {
        if ( __builtin_popcount(k) > M )
            continue;
        if ( !( (1 << idx ) & k ) )
            continue;

        if ( !merge(D[idx], T[k]) )
            continue;

        cnt = -1;
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                if (A[i][j] == '1')
                    continue;
                if (A[i][j] == '2' && ( Pos[idx].first != i || Pos[idx].second != j ))
                    continue;
                cnt = max(cnt, T[k][i][j]);
            }
        }
        if ( cnt > -1 )
            ret = min(ret, cnt);
    }
    return ret;
}

int F() {
    int i, j;
    int ret = INF;
    memset(T, -1, sizeof(T));
    for ( i = 0 ; i < Pos.size() ; i ++ )
        ret = min(ret, apply(i));

    return ret >= INF ? -1 : ret;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    int i, j, k;

    memset(D, -1, sizeof(D));

    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> A[i][j];
            if ( A[i][j] == '2' )
                Pos.emplace_back(i, j);
        }
    }

    for ( i = 0 ; i < Pos.size() ; i ++ )
        bfs(Pos[i].first, Pos[i].second, i);

    cout << F() << '\n';

    return 0;
}


