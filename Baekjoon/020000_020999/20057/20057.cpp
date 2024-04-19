#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int SpreadRatio[4][10][3] = {
    {
        {1, -1, 1}, {-1, -1, 1},
        {1, 0, 7}, {-1, 0, 7},
        {2, 0, 2}, {-2, 0, 2},
        {1, 1, 10}, {-1, 1, 10},
        {0, 2, 5}, {0, 1, 0}
    },
};
vector<vector<int>> A;
int N;

int Move(int y, int x, int d) {
    int T = A[y][x], i, outside = 0, moved = 0;
    int ty, tx, m;

    if ( A[y][x] > 0 ) {
        for ( i = 0 ; i < 10 ; i ++ ) {
            ty = y + SpreadRatio[d][i][0];
            tx = x + SpreadRatio[d][i][1];
            if ( i < 9)
                m = T * SpreadRatio[d][i][2] / 100;
            else
                m = A[y][x] - outside - moved;

            if ( ty < 0 || tx < 0 || ty >= N || tx >= N )
                outside += m;
            else {
                A[ty][tx] += m ;
                moved += m;
            }
        }
        A[y][x] = 0;
    }
    return outside;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i, j, d, len, y, x;
    fastio;
    cin >> N ;
    A.resize(N, vector<int>(N, 0));
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            cin >> A[ i ][ j ] ;

    for ( i = 1 ; i < 4 ; i ++ )
        for ( j = 0 ; j < 10 ; j ++ ) {
            SpreadRatio[i][j][0] = SpreadRatio[i-1][j][1];
            SpreadRatio[i][j][1] = -SpreadRatio[i-1][j][0];
            SpreadRatio[i][j][2] = SpreadRatio[i-1][j][2];
        }

    x = y = N / 2;

    d = 2, len=1;
    int ans = 0 ;
    while ( y != 0 || x != 0 ) {
        for ( i = 0 ; i < len && (y != 0 || x != 0 ); i ++ )
            ans += Move(y += dy[d], x += dx[d], d);

        if ( y == 0 && x == 0 ) break;
        d = ( d + 3 ) % 4;

        for ( i = 0 ; i < len && (y != 0 || x != 0 ); i ++ )
            ans += Move(y += dy[d], x += dx[d], d);

        d = ( d + 3 ) % 4;
        len ++;
    }
    cout << ans << '\n';
    return 0;
}


