#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = 1500;
int PreSum[MaxN][MaxN];
int Y, X, K;
int L[2][MaxN]; // sum 1 ~ L
int R[2][MaxN]; // sum R ~ X
int U[2][MaxN]; // sum 1 ~ U
int D[2][MaxN]; // sum D ~ Y

int S(int sy, int sx) {
    int ey = sy + K - 1, ex = sx + K - 1 ;
    int t = PreSum[ey][ex] ;
    if ( sy > 0 ) t -= PreSum[sy-1][ex];
    if ( sx > 0 ) t -= PreSum[ey][sx-1];
    if ( sy > 0 && sx > 0 ) t += PreSum[sy-1][sx-1];
    return t;
}
void MAX(int &a, int b) {
    a = max(a, b);
}

void input() {
    int i, j;
    cin >> Y >> X >> K ;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> PreSum[i][j];
            if ( i ) PreSum[i][j] += PreSum[i-1][j];
            if ( j ) PreSum[i][j] += PreSum[i][j-1];
            if ( i && j ) PreSum[i][j] -= PreSum[i-1][j-1];
        }
    }
}
void dump(const char *s, int a[], int n) {
    int i;
    cout << s << " : ";
    for ( i = 0 ; i < n ; i ++ ) cout << a[i] << ' ' ;
    cout << '\n';
}

void preUpSide() {
    int sy, sx, ey, ex;
    int left[MaxN]{}, right[MaxN]{};
    int cumLeft[MaxN]{}, cumRight[MaxN]{};

    for ( sy = 0 ; sy <= Y - K; sy ++ ) {
        ey = sy + K - 1 ;
        for ( sx = 0 ; sx <= X - K; sx ++ ) {
            ex = sx + K - 1 ;
            left[ex] = right[sx] = S(sy, sx);
        }

        for ( sx = 0 ; sx < X ; sx ++) {
            MAX(left[sx], sx==0 ? left[sx] : left[sx-1]);
            MAX( cumLeft[sx], left[sx]);
        }
        for ( sx = X-1 ; sx >=0 ; sx--) {
            MAX(right[sx], sx == X-1 ? right[sx] : right[sx+1]);
            MAX(cumRight[sx], right[sx]);
        }
        for ( sx = 0 ; sx < X-1 ; sx ++) {
            // single
            MAX(U[0][ey], max(cumLeft[sx], cumRight[sx+1]));
            // double
            MAX(U[1][ey], cumLeft[sx] + cumRight[sx+1]);
            if ( sy > 0 )
                MAX(U[1][ey], U[0][sy-1] + max(left[sx], right[sx+1]) );
        }
    }
}
void preDownSide() {
    int sy, sx, ey, ex;
    int left[MaxN]{}, right[MaxN]{};
    int cumLeft[MaxN]{}, cumRight[MaxN]{};

    for ( sy = Y-K ; sy >= 0 ; sy -- ) {
        ey = sy + K - 1 ;
        for ( sx = 0 ; sx <= X - K; sx ++ ) {
            ex = sx + K - 1 ;
            left[ex] = right[sx] = S(sy, sx);
        }

        for ( sx = 0 ; sx < X ; sx ++) {
            MAX(left[sx], sx==0 ? left[sx] : left[sx-1]);
            MAX( cumLeft[sx], left[sx]);
        }
        for ( sx = X-1 ; sx >=0 ; sx--) {
            MAX(right[sx], sx == X-1 ? right[sx] : right[sx+1]);
            MAX(cumRight[sx], right[sx]);
        }

        for ( sx = 0 ; sx < X-1 ; sx ++) {
            // single
            MAX(D[0][sy], max(cumLeft[sx], cumRight[sx+1]));
            // double
            MAX(D[1][sy], cumLeft[sx] + cumRight[sx+1]);
            if ( ey < Y - 1 )
                MAX(D[1][sy], D[0][ey+1] + max(left[sx], right[sx+1]) );
        }
    }
}

void preLeftSide() {
    int sy, sx, ey, ex;
    int up[MaxN]{}, down[MaxN]{};
    int cumUp[MaxN]{}, cumDown[MaxN]{};

    for ( sx = 0 ; sx <= X - K; sx ++ ) {
        ex = sx + K - 1 ;
        for ( sy = 0 ; sy <= Y - K; sy ++ ) {
            ey = sy + K - 1 ;
            up[ey] = down[sy] = S(sy, sx);
        }

        for ( sy = 0 ; sy < Y ; sy ++ ) {
            MAX(up[sy], sy==0 ? up[sy] : up[sy-1]);
            MAX( cumUp[sy], up[sy]);
        }
        for ( sy = Y-1 ; sy >= 0 ; sy-- ) {
            MAX(down[sy], sy == Y-1 ? down[sy] : down[sy+1]);
            MAX(cumDown[sy], down[sy]);
        }

        for ( sy = 0 ; sy < Y-1 ; sy ++ ) {
            // single
            MAX(L[0][ex], max(cumUp[sy], cumDown[sy+1]));
            // double
            MAX(L[1][ex], cumUp[sy] + cumDown[sy+1]);
            if ( sx > 0 )
                MAX(L[1][ex], L[0][sx-1] + max(up[sy], down[sy+1]) );
        }
    }
}
void preRightSide() {
    int sy, sx, ey, ex;
    int up[MaxN]{}, down[MaxN]{};
    int cumUp[MaxN]{}, cumDown[MaxN]{};

    for ( sx = X - K ; sx >= 0 ; sx -- ) {
        ex = sx + K - 1 ;
        for ( sy = 0 ; sy <= Y - K; sy ++ ) {
            ey = sy + K - 1 ;
            up[ey] = down[sy] = S(sy, sx);
        }

        for ( sy = 0 ; sy < Y ; sy ++ ) {
            MAX(up[sy], sy==0 ? up[sy] : up[sy-1]);
            MAX( cumUp[sy], up[sy]);
        }
        for ( sy = Y-1 ; sy >= 0 ; sy-- ) {
            MAX(down[sy], sy == Y-1 ? down[sy] : down[sy+1]);
            MAX(cumDown[sy], down[sy]);
        }

        for ( sy = 0 ; sy < Y-1 ; sy ++ ) {
            // single
            MAX(R[0][sx], max(cumUp[sy], cumDown[sy+1]));
            // double
            MAX(R[1][sx], cumUp[sy] + cumDown[sy+1]);
            if ( ex < X - 1 )
                MAX(R[1][sx], R[0][ex+1] + max(up[sy], down[sy+1]) );
        }
    }
}
void pre() {
    preUpSide();
    preDownSide();
    preLeftSide();
    preRightSide();

    int sy, sx;

    for ( sy = 1 ; sy < Y ; sy ++) {
        MAX(U[0][sy], U[0][sy-1]);
        MAX(U[1][sy], U[1][sy-1]);
    }
    for ( sy = Y-2 ; sy >= 0 ; sy --) {
        MAX(D[0][sy], D[0][sy+1]);
        MAX(D[1][sy], D[1][sy+1]);
    }
    for ( sx = 1 ; sx < X ; sx ++ ) {
        MAX(L[0][sx], L[0][sx-1]);
        MAX(L[1][sx], L[1][sx-1]);
    }
    for ( sx = X-2 ; sx >= 0 ; sx -- ) {
        MAX(R[0][sx], R[0][sx+1]);
        MAX(R[1][sx], R[1][sx+1]);
    }
}

int main()
{
    fastio;
    int y, x, i, ret;

    input();
    pre();

    ret = 0;
    for ( i = 0 ; i < 2 ; i ++ ) {
        for ( x = 0 ; x < X-1 ; x ++ )
            MAX(ret, L[i][x] + R[1-i][x+1]);
        for ( y = 0 ; y < Y-1 ; y ++ )
            MAX(ret, U[i][y] + D[1-i][y+1]);
    }
    cout << ret ;
    return 0;
}


