#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    int R, C, T;
    int r1, r2;
    int A[50][50]={0,};
    int i, j;
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int d, tx, ty;

    r1 = r2 = 0 ;

    cin >> R >> C >> T;
    for ( i = 0 ; i < R ; i ++ )
        for ( j = 0 ; j < C ; j ++ )
        {
            cin >> A[i][j];
            if ( A[i][j] == - 1 )
                (r1 == 0 ? r1 : r2 ) = i ;
        }

    while ( T -- ) {
        int B[50][50]={0,};

        for ( i = 0 ; i < R ; i ++ ) {
            for ( j = 0 ; j < C ; j ++ ) {
                if ( A[i][j] < 5 ) continue;
                int t = A[i][j]/5;
                for ( d = 0 ; d < 4 ; d ++ ) {
                    tx = j + dx[d];
                    ty = i + dy[d];
                    if ( tx < 0 || tx >= C || ty < 0 || ty >= R || A[ty][tx] < 0) continue;

                    B[ty][tx] += t;
                    A[i][j] -= t;
                }
            }
        }

        for ( i = 0 ; i < R ; i ++ )
            for (j = 0; j < C; j++)
                if ( B[i][j] > 0 )
                    A[i][j] += B[i][j];

        for ( j=0, i=r1-1 ; i > 0 ; i --) A[i][j] = A[i-1][j];
        for ( i=0, j=0; j < C - 1; j++) A[i][j] = A[i][j+1];
        for ( i=0, j=C-1; i < r1 ; i ++ ) A[i][j] = A[i+1][j];
        for ( i=r1, j=C-1; j > 1; j--) A[i][j] = A[i][j-1];
        A[r1][1] = 0;

        for ( i=r2+1, j=0; i < R - 1; i ++ ) A[i][j] = A[i+1][j];
        for ( i=R-1, j=0; j < C - 1; j++) A[i][j] = A[i][j+1];
        for ( j=C-1, i=R-1 ; i > r2 ; i --) A[i][j] = A[i-1][j];
        for ( i=r2, j=C-1; j > 1 ; j--) A[i][j] = A[i][j-1];
        A[r2][1] = 0;

//        for ( i = 0, printf("\n") ; i < R ; i ++, printf("\n") ) for ( j = 0 ; j < C ; j ++ ) printf("%3d ", A[i][j]);
    }
    int ret = 0 ;
    for ( i = 0 ; i < R ; i ++ ) {
        for ( j = 0 ; j < C ; j ++ ) {
            ret += max(0, A[i][j]);
        }
    }
    cout << ret << endl;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


