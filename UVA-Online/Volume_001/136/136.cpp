#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_N 1500
unsigned long long int min( unsigned long long int a, unsigned long long int b )
{
    return a < b ? a : b ;
}
unsigned long long int min( unsigned long long int a, unsigned long long int b, unsigned long long int c )
{
    return min( a, min(b,c));
}

void process(FILE *fp)
{    
    unsigned long long int number[ MAX_N ]={1,};
    int number_count ;
    int nIdx2, nIdx3, nIdx5;
    
    nIdx2 = nIdx3 = nIdx5 = 0 ;
    for ( number_count = 1 ; number_count < MAX_N ; number_count ++ )
    {
        unsigned long long int n2 = number[ nIdx2 ] * 2 ;
        unsigned long long int n3 = number[ nIdx3 ] * 3 ;
        unsigned long long int n5 = number[ nIdx5 ] * 5 ;
        
        unsigned long long int N = min( n2, n3, n5);
        number[ number_count ] = N ;
        
        while (number[nIdx2] * 2 <= N && nIdx2 < number_count ) nIdx2++;
        while (number[nIdx3] * 3 <= N && nIdx3 < number_count ) nIdx3++;
        while (number[nIdx5] * 5 <= N && nIdx5 < number_count ) nIdx5++;
    }
    
    printf("The 1500'th ugly number is %lld.\n", number[ MAX_N - 1 ]);
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
