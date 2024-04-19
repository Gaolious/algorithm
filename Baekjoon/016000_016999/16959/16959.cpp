#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;


using namespace std;
int A[101];
int N ;
// [pieceType1][y,x] ~ [pieceType2][y,x] 로 가는데 최소비용.

int D[301][301];
int ans[2][3];
const int ROOK = 0 ; // +
const int BISHOP = 1 ; // X
const int KNIGHT = 2 ; // J

#define IDX( y, x, rot ) (  ( (rot) * N + (y) ) * N + (x) )

int lenDxy[] = {4, 4, 8};
int dy[][10] = {
    {0, 1, 0, -1},
    {1, 1, -1, -1},
    {2, 2, -2, -2, 1, 1, -1, -1},
};
int dx[][10] = {
    {1, 0, -1, 0},
    {1, -1, 1, -1},
    {-1, 1, -1, 1, -2, 2, -2, 2},
};

const int INF = 1000000;
int Index[101];
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int y1, x1, t1, y2, x2, t2;
    int i, j, k, d, dist, ty, tx;

    cin >> N ;

    for ( i = 0 ; i < N*N ; i ++ ) {
        cin >> A[i] ;
        Index[A[i]] = i ;
    }

    for ( t1 = 0 ; t1 < 3 ; t1 ++ )
        for ( y1 = 0 ; y1 < N ; y1 ++ )
            for ( x1 = 0 ; x1 < N ; x1 ++ )
                for ( t2 = 0 ; t2 < 3 ; t2 ++ )
                    for ( y2 = 0 ; y2 < N ; y2 ++ )
                        for ( x2 = 0 ; x2 < N ; x2 ++ )
                            D[IDX(y1, x1, t1)][ IDX(y2, x2, t2) ] = INF;

    for ( t1 = 0 ; t1 < 3 ; t1 ++ )
        for ( y1 = 0 ; y1 < N ; y1 ++ )
            for ( x1 = 0 ; x1 < N ; x1 ++ )
                for ( t2 = 0 ; t2 < 3 ; t2 ++ )
                    D[IDX(y1, x1, t1)][ IDX(y1, x1, t2) ] = 1;

    for ( t1 = 0 ; t1 < 3 ; t1 ++ )
        for ( y1 = 0 ; y1 < N ; y1 ++ )
            for ( x1 = 0 ; x1 < N ; x1 ++ )
                for ( d = 0 ; d < lenDxy[t1] ; d ++ ) {
                    ty = y1, tx = x1;

                    dist = 1;

                    while ( true ) {
                        ty += dy[t1][d];
                        tx += dx[t1][d];
                        if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) break;
                        D[ IDX(y1, x1, t1) ][ IDX(ty, tx, t1) ] = dist ;
                        if ( t1 == 2 ) dist ++;
                    }
                }

    for ( k = 0 ; k < N*N*3 ; k ++ )
        for ( i = 0 ; i < N*N*3 ; i ++ )
            for ( j = 0 ; j < N*N*3 ; j ++ )
                D[i][j] = min( D[i][j], D[i][k] + D[k][j]);

    for ( t1 = 0 ; t1 < 3 ; t1 ++ ) ans[1][t1] = 0;

    y1 = Index[1] / N ;
    x1 = Index[1] % N ;

    for ( i = 2 ; i <= N*N ; i ++ ) {
        y2 = Index[i] / N ;
        x2 = Index[i] % N ;
        for ( j = 0 ; j < 3 ; j ++ ) ans[i%2][j] = INF;

        for ( t1 = 0 ; t1 < 3 ; t1 ++ )
            for ( t2 = 0 ; t2 < 3 ; t2 ++ )
                ans[i%2][t2] = min( ans[i%2][t2], ans[1-(i%2)][t1] + D[ IDX(y1, x1, t1) ][ IDX(y2, x2, t2 ) ] );
        y1 = y2;
        x1 = x2;
    }

    int ret = INF;
    for ( t1 = 0 ; t1 < 3 ; t1 ++ )
        ret = min(ret,  ans[N%2][t1]);
    cout << ret << '\n';
}


