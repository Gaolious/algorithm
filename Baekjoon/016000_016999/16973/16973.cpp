#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int S[1000][1000];
char A[1000][1000];
int C[1000][1000];
int Y, X;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int Sum(int sy, int sx, int w, int h) {
    int ey = sy + h - 1;
    int ex = sx + w - 1;
    int ret = S[ey][ex] ;

    if ( sy > 0 ) ret -= S[sy-1][ex];
    if ( sx > 0 ) ret -= S[ey][sx-1];
    if ( sy > 0 && sx > 0 ) ret += S[sy-1][sx-1];
    return ret;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, d, ty, tx ;
    int w, h, sy, sx, ey, ex;

    cin >> Y >> X;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[ i ][ j ] ;
            S[i][j] = A[i][j] == '1' ? 1 : 0;
            if ( i > 0 ) S[i][j] += S[i-1][j] ;
            if ( j > 0 ) S[i][j] += S[i][j-1] ;
            if ( i > 0 && j > 0 ) S[i][j] -= S[i-1][j-1] ;
        }
    }

    cin >> h >> w >> sy >> sx >> ey >> ex ;
    sy --; sx --; ey --; ex --;

    queue<pair<int, int>> Q;
    memset(C, -1, sizeof(C));
    Q.emplace(sy, sx);
    C[sy][sx] = 0;

    while ( !Q.empty() ) {
        auto [y, x] = Q.front();
        Q.pop();

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty + h > Y || tx + w > X)
                continue;
            if ( Sum(ty, tx, w, h) > 0) continue;
            if ( C[ty][tx] < 0 || C[ty][tx] > C[y][x] + 1 ) {
                C[ty][tx] = C[y][x] + 1;
                Q.emplace(ty, tx);
            }
        }
    }
    cout << C[ey][ex] << '\n';
    return 0;
}


