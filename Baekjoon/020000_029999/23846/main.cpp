#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

long double D[456+1][3000+1][4]={0,};
long double P(int k, int n, int r ) {
    if ( k <= 0 ) return 0.0;
    if ( n <= 0 ) return 1.0 ;
    long double &ret = D[k][n][r];
    if ( ret < 0 ) {
        if ( r == 2 ) {
            ret = 0.5 * P(k-1, n-1, 3) + 0.5 * P(k, n-1, 3);
        } else {
            ret = P(k-1, n, 2) / 3 * 2 + P(k, n-1, 3) / 3 ;
        }
    }
    return ret;
}
void process() {
    int N, K, i, j, k ;
    long double r, ret ;
    fscanf(stdin, "%d %d ", &N, &K);
    for ( i = 0 ; i <= K ; i ++ )
        for ( j = 0 ; j <= N ; j ++ )
            for ( k = 0 ; k < 4 ; k ++ )
                D[i][j][k] = -1;
//    printf("3 : %.12Lf\n", P(K, N, 3));
//    printf("2 : %.12Lf\n", P(K, N, 2));
//    printf("1 : %.12Lf\n", P(K, N, 1));
    printf("%.12Lf\n", P(K, N, 3));
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


