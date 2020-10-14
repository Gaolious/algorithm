#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;


#define MAX_N (100)
void process()
{
    char c;
    bool s = true ;
    while ( (c = getchar()) > 0 )
    {
        if ( c == '"' )
        {
            if ( s ) putchar('`'),putchar('`'), s=false;
            else putchar('\''),putchar('\''), s=true;
        }
        else putchar(c);
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


