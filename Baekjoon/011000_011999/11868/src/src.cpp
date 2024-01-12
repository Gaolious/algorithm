#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

#define MAX_N (100)
void process()
{
    int N ;
    int i, j ;
    int cnt = 0 ;
    unsigned int ans, p[1000];
    scanf("%d ", &N);

    ans = 0;
    for ( i = 0 ; i < N ; i ++ )
    {
        scanf("%d ", p+i);
        ans ^= p[i];
    }
    if ( ans )
    {
        for ( i = 0 ; i < N ; i ++ )
            if ( p[i] >= (ans ^ p[i]) ) cnt ++;
    }

    printf("%d\n", cnt);

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


