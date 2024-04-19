#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

const int MaxN = 20;
int N, S;
int A[MaxN]={0,};
int MinS[MaxN]={0,};
int MaxS[MaxN]={0,};
int F(int idx, int cumS) {
    int ret = 0 ;

    if ( A[idx] + cumS == S )
        ret ++ ;
    if ( idx < N - 1 && cumS + MinS[idx] <= S && S <= cumS + MaxS[idx]) {
        ret += F(idx + 1, cumS);
    }
    if ( idx < N - 1 && cumS + MinS[idx] + A[idx] <= S && S <= cumS + MaxS[idx] + A[idx]) {
        ret += F(idx+1, cumS + A[idx]);
    }
    return ret ;
}
void process() {
    int i;

    scanf("%d %d ", &N, &S);
    for ( i = 0 ; i < N ; i ++ ) {
        scanf("%d ", A+i);
    }

    for ( i = N-2 ; i >= 0 ; i -- ) {
        MinS[ i ] = min( 0, MinS[i+1]) + min(0, A[i+1]);
        MaxS[ i ] = max( 0, MaxS[i+1]) + max(0, A[i+1]);
    }
    printf("%d\n", F(0,0));
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


