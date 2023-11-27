#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

#define MAX_N (40000)
void process()
{
    int N, A[30];
    int i, j, k ;
    int T, t ;
    int max_n = 0;
    int D[MAX_N+1]={0,};

    scanf("%d ", &N);
    for ( i = 0 ; i < N ; i ++ )
        scanf("%d ", A+i);
    
    D[0] = 1 ;
    for ( i = 0 ; i < N ; i ++ )
    {
        for ( j = max_n ; j>= 0 ; j -- )
        if ( D[j] == 1 && j + A[i] <= MAX_N)
        {
            D[j + A[i] ] = 1 ;
            max_n = max(j+A[i], max_n);
        }
    }
    
    bool found ;

    scanf("%d ", &T);
    while (T--)
    {
        found = false ;

        scanf("%d ", &t);
        
        for ( i = t ; i <= max_n ; i ++ )
        if ( D[i] == 1 && D[i-t] == 1 )
        {
            found = true; break;
        }
        printf("%c ", ( found ) ? 'Y' : 'N' );
    }
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


