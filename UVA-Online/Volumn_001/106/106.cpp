// 106 - Fermat vs. Pythagoras
/*
 * x^2 + y^2 = z^2 
 *      where 
 *          : x,y,z < N
 *          : x < y < z
 *          : x,y,z is relative prime
 * 
 * 
 * 
 * 10
 * 3^2 + 4^2 = 5^2 
 * 6    8   10
 * 
 * // 9+16=25
 * 
 * out : 1 4
 * 
 * 1 : (x=3 y=4 z=5)
 * 4 :  (1 2 7 9)
 * 
 * 
 * 
 * 
 * z^2 = x^2 + y^2
 * 
 * y^2 = z^2 - x^2
 *     = ( z - x ) ( z + x )
 * 
 * ( a^2 + b^2 )^2  =  2*a^4 + 2*a^2*b^2 + b^4
 *                  = ( a^2 - b^2 )^ 2 + 4*a^2*b^2
 *                  = ( a^2 - b^2 )^ 2 + (2*a*b)^2
 * 
 * condition #1
 * z = a^2+b^2
 * x = a^2-b^2
 * y = 2ab
 * 
 * condition #2
 * a^2 + b^2 < N
 *  a < sqrt(N)
 *  b < sqrt(N)
 * 
 * condition #3
 * sqrt( a^2 + b^2 ) < sqrt(N)
 * 
 */
// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int gcd (int a, int b )
{
    if ( b > 0 )
        return gcd(b, a%b);
    else
        return a;
}

// to print not part of any triples
unsigned char flag[125001] ={0,};

void setFlag(int x)
{
    int a, b;
    // start with index 0
    x--;
    a = x / 8;
    b = x % 8;
    
    flag[ a ] |= (unsigned char)0x01 << b ;
}

int isFlag(int a, int b)
{    
    if ( flag[ a ] & ( (unsigned char)0x01 << b) )
        return 1;
    else
        return 0;
}

void process( FILE *fp )
{
    int N ;
    int max_n ;
    int a, b, max_b;
    int x, y, z, t ;
    int i, no_triple;
    
    while ( fscanf(fp, "%d", &N) == 1 )
    {
        memset( flag, 0x00, sizeof(flag) * sizeof(char) );
        
        int cnt = 0 ;
        if ( N >= 0 )
        {
            max_n = sqrt(N-1);
            
            for ( a=1 ; a <= max_n ; a ++ )
            {
                max_b = sqrt(( N - a*a ));
                
                for ( b = 1 ; b <= max_b ; b++ )
                {
                    x = a*a - b*b ;
                    y = 2*a*b;
                    z = a*a + b*b ;
                    if ( z > N ) break;
                    
                    if ( x*x + y*y == z*z && gcd(x,y) == 1 )
                    {
#ifndef ONLINE_JUDGE 
                        printf("%d^2 + %d^2 = %d^2\n", x, y, z );
#endif
                        cnt ++ ;
                        
                        for (i=1 ; i*z<=N ; i++)
                        {
#ifndef ONLINE_JUDGE 
                            printf("%d %d %d\n", x*i, y*i, z*i);
#endif
                            setFlag( x*i );
                            setFlag( y*i );
                            setFlag( z*i );
                        }
                    }
                }
            }
        }
        
        no_triple = 0;
        
        for ( t=0, a=0 ; t < N ; a ++ )
            for ( b=0 ; t < N && b<8 ; b++, t++ )
            {
                if ( isFlag( a, b ) == 0 )
                    no_triple ++;
            }
        
        printf("%d %d\n", cnt, no_triple );
    }
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
