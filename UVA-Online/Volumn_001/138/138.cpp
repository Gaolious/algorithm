// 138 - Street Numbers
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * A computer programmer lives in a street with houses numbered consecutively (from 1) down one side of the street. 
 * 
 * Every evening she walks her dog by leaving her house and randomly turning left or right and walking to the end of the street and back. 
 * 
 * One night she adds up the street numbers of the houses she passes (excluding her own). 
 * 
 *  => Assume that one night she passes N Houses. and N is her house number.
 *     and then Sum Of Houses Number ( 1 ~ N ) is ( N * (N+1) ) / 2.
 * 
 * 
 * The next time she walks the other way she repeats this and finds, to her astonishment, 
 * that the two sums are the same. 
 * 
 *  => Assume that she walks the other way in next time passes M houses, 
 * 
 *  (M * (M+1)) / 2 - ( N * (N-1) ) / 2
 *  
 * 
 * is same.
 * 
 *  ( N^2 + N ) ==  M^2 + M - ( N^2 - N )
 * 
 *  2 * N^2 = M^2 + M.  ( N < M )
 * 
 * Output : N, M
 * 
 * 
 * ex> 6, 8
 * 
 * 2 * 6^2 = 64 + 8
 * 72 = 72
 * 
*/

void process(FILE *fp)
{    
    const char *str = "         6         8\n        35        49\n       204       288\n      1189      1681\n      6930      9800\n     40391     57121\n    235416    332928\n   1372105   1940449\n   7997214  11309768\n  46611179  65918161\n";
    printf("%s", str);
    return;
#if 0    
    unsigned long long int M ;
    int found = 0 ;
    
    for ( M = 8 ; found < 10 ; M ++ )
    {
        unsigned long long int sum = M*M + M ;
        
        if ( sum % 2 != 0 ) continue ;
        
        sum /= 2 ;
        
        unsigned long long int N = (unsigned long long int)sqrt(sum);
        if ( N * N == sum )
        {
            found ++;
            printf("%10lld%10lld\n", N, M );
        }
    }
#endif
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
