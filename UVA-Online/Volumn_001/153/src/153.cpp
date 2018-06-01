#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int number_of_perms(int size, int cum[])
{
    // to avoid overflow
    int a[31 + 1]={0,};
    int n ;
    int i, j, k ;

    n = 0;
    for ( i = 1 ; i <= size ; i ++)
        a[ n++ ] = i;

    for ( i = 0 ; i < 26 ; i ++ )
    if ( cum[i] > 0 )
    {
        for ( j = cum[i] ; j>1 ; j -- )
        {
            int u = j;
            for ( k = 1 ; u > 1 && k < n ; k ++)
            if ( a[k] > 1 )
            {
                int g = gcd( a[k], u );
                if ( g > 1 )
                {
                    a[k] = a[k] / g ;
                    u = u / g ;
                }
            }
        }
    }

    int ret = 1;
    for ( k = 1 ; k < n ; k ++)
        ret *= ( a[k] > 1 ? a[k] : 1) ;

    return ret;
}

int find(char str[], int len, int cum[])
{
    int cnt = 0 ;
    int i ;

    if ( len < 0 )
        return cnt;

    //        * * * * *
    // curr : b a c a a    
    //        ^          => a ( a*2, b*1, c*1 ) : 4! / 2! 1! 1! => 12 
    //                      a * * * * => number of previous perms is 12
    //                      b * * * * => curr.
    // curr : b a c a a    
    //          ^        => pass
    // curr : b a c a a    
    //            ^      => a ( a*1, c*1 ) : 2! / 1! 1!
    //                      b a a * * => number of previous perms is 2
    //                      b a c * * => curr.
    //                      ------------------------------------------
    //  sum of previous perms is 14. so current order of perm is 15.
    for ( i = 0 ; i < str[0]-'a' ; i ++ )
    if ( cum[i] > 0 )
    {
        cum[ i ] --;
        cnt += number_of_perms(len - 1, cum) ;
        cum[ i ] ++;
    }

    cum[ str[0] - 'a' ]--;
    cnt += find(str+1, len-1, cum);
    
    return cnt;
}
void process(FILE *fp)
{
    char str[30+1]={0,};

    while ( fscanf(fp, "%s ", str ) == 1 && str[0] != '#' )
    {
        int len = strlen(str);
        int cum[256] = {0, };
        int i;

        for ( i = 0 ; i < len ; i ++)
            cum[ str[i]-'a' ] ++;
        
        printf("%10d\n", find( str, len, cum) + 1 );
    }
}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}