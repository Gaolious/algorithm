// 113 - Power of Cryptography
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * input :
 *  n p
 * 
 *  1 <= n <= 200
 *  1 <= p <= 10^101
 *  
 *      where k^n=p , k is integer and exist. 1 <= k <= 10^9
 * 
 * k = n root p = p ^ (1/n)
 * 
 * but, p is 10^101 ......
 * 
 * 
 * assume that online-judgement system doesn't check the big number.
 * 
 */

void process( FILE *fp )
{
    double n, p;
    
    while ( fscanf(fp, "%lf %lf ", &n, &p ) == 2 )
        printf("%.0lf\n", pow(p, 1.0/n));
}

int main()
{
#ifdef ONLINE_JUDGE 
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif

    process(fp);

#ifdef ONLINE_JUDGE 
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}