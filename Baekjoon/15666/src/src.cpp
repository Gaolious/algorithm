#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

int A[10]={0,};
int N, M ;
int S[10]={0,};

void recur(int depth, int s)
{
    int i ;

    if ( depth >= M )
    {
        for ( i = 0 ; i < M ; i ++ )
            printf("%d ", S[i]);
        printf("\n");
        return;
    }
    for ( i = s ; i < N ; i ++ )
    {
        S[depth] = A[i];
        recur(depth+1, i);
    }
}
void process()
{
    int i ;
    
    scanf("%d %d ", &N, &M);
    for ( i = 0 ; i < N ; i ++ )
        scanf("%d ", A+i);
    std::sort(A, A+N);
    int *p = std::unique(A, A+N);
    N = p - A ;
    recur(0, 0);
}

int main() 
{ 
#ifndef ONLINE_JUDGE 
    clock_t t = clock();
#else  
#endif 

    process(); 

#ifndef ONLINE_JUDGE 
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);    
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


