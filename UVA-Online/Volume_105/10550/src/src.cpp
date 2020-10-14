#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

int degree(int from, int to, bool ccw)
{
    int d ;

    if ( ccw ) 
        d = 40 - from + to ;
    else
        d = 40 + from - to ;

    return d%40 * 9;
}
void process()
{
    // • turn the dial clockwise 2 full turns
    // • stop at the first number of the combination
    // • turn the dial counter-clockwise 1 full turn
    // • continue turning counter-clockwise until the 2nd number is reached
    // • turn the dial clockwise again until the 3rd number is reached
    // • pull the shank and the lock will open.
    int a, b, c, d ;
    int ans ;
    // 360/40 = 9'
    while ( scanf("%d %d %d %d ", &a, &b, &c, &d) == 4 && (a||b||c||d) )
    {
        ans = 720 ;
        ans += degree(a, b, false );
        ans += 360 ;
        ans += degree(b, c, true );
        ans += degree(c, d, false );

        printf("%d\n", ans);

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


