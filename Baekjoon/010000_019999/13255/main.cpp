# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

#define BUFF_LEN ( 1<< 21 )

const int MaxN = 1'000'000;
double D[ 7 ] = {0, };

void process() {
    int i, j ;
    int N ;
    double D[6]={0,}, S, t;
    scanf("%d ", &N);
    S = 0.0;

    for ( i = 1 ; i <= N ; i ++ ) {
        t = D[ i % 6 ] ;
        D[ i % 6 ] = S/6.0 + 1.0 ;
        S += D[ i % 6 ] - t ;
    }
    printf("%.12f\n", D[N%6]);

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


