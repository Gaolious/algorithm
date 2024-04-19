#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int PreSum[22][22];
int N ;
int S(int sy, int sx, int ey, int ex ) {
    if ( sy <= ey && sx <= ex )
        return PreSum[ey][ex] - PreSum[sy-1][ex] - PreSum[ey][sx-1] + PreSum[sy-1][sx-1];
    return 0;
}

int min(int a, int b, int c, int d, int e) {
    return min(min(min(a,b), min(c,d)), e);
}
int max(int a, int b, int c, int d, int e) {
    return max( max( max(a,b), max(c,d) ), e);
}
int SA(int y, int x, int d1, int d2) {
    int s = S(1, 1, N, N);
    int row, minX, maxX;
    int a1,a2,a3,a4;
    int d;

    a1 = S(1, 1, y-1, x+d1);
    a2 = S(1, x+d1+1, y-d1+d2, N);
    a3 = S(y, 1, N, x+d2-1);
    a4 = S(y-d1+d2+1, x+d2, N, N);

    // 5선거구
    for ( row = y-d1 ; row <= y + d2 ; row ++ ) {
        if ( y-d1 <= row && row <= y-1 ) {
            minX = -row + (y+x);
            maxX = x + d1;
            a1 -= S(row, minX, row, maxX);
        }
        else {
            minX = row + (x-y);
            maxX = x + d2 - 1;
            a3 -= S(row, minX, row, maxX);
        }
        if ( y-d1 <= row && row <= y-d1+d2 ) {
            minX = x + d1 + 1;
            maxX = row + (x-y+d1*2);
            a2 -= S(row, minX, row, maxX);
        }
        else {
            maxX = -row + (y+x+d2*2);
            minX = x+d2;
            a4 -= S(row, minX, row, maxX);
        }
    }
    int t = s - a1 - a2 - a3 - a4;
    return max(a1, a2, a3, a4, t) - min(a1, a2, a3, a4, t);
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, d1, d2 ;
    cin >> N;
    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= N ; j ++ ) {
            cin >> PreSum[i][j];
            PreSum[i][j] += PreSum[i][j-1] + PreSum[i-1][j] - PreSum[i-1][j-1];
        }
    }
    int ans = 10000000;

    for (d1=1 ; d1 < N ; d1 ++ )
        for ( d2 = 1 ; 1+d1+d2 < N ; d2 ++ )
            for ( i = 1 + d1 ; i+d2 <= N ; i ++ )
                for ( j = 1 ; j+d1+d2 <= N ; j ++ )
                    ans = min(ans, SA(i, j, d1, d2));
    cout << ans ;
    return 0;
}


