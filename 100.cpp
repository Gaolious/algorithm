#include <stdio.h>
#include <stdlib.h>

const unsigned int MAX_Cache_SIZE = 1000000;
static int Cache[MAX_Cache_SIZE]={0,};

int get_recursive( unsigned int n )
{
    if ( n == 1 )
        return 1;
    else if ( n < MAX_Cache_SIZE )
    {
        if ( Cache[ n ] == 0 )
        {
            if ( n % 2 == 0 )
                Cache[ n ] = get_recursive( n / 2 ) + 1;
            else
                Cache[ n ] = get_recursive( n + (n+1)/2 ) + 2 ;
        }
        return Cache[ n ] ;
    }
    else
    {
        if ( n % 2 == 0 ) 
            return get_recursive( n / 2 ) + 1 ;
        else
            return get_recursive( n + (n+1)/2 ) + 2 ;
    }
}
int main()
{
    int i ;
    unsigned int s, e;
    unsigned int n1, n2;
    unsigned int max;
    unsigned int t;
    while ( fscanf(stdin, "%u %u", &n1, &n2 ) == 2 )
    {
        max = 0 ;
        if ( n1 < n2 ) s = n1, e = n2;
        else s = n2, e = n1;

        for ( i = s ; i <= e ; i ++)
        {
            t = get_recursive(i) ;
            if ( t > max ) max = t;
        }
        printf("%u %u %u\n", n1, n2, max);
    }
    return 0;
}
