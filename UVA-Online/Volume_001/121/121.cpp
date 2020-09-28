// 121 Pipe Fitters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SQRT3 (1.732051L)
#define COS60 (0.5L)
#define SIN60 (0.866025L) // sqrt(3)/2
#define ONE_OVER_SIN60 (1.154701L)

int getGridCount(double x, double y)
{
    return (int)(x) * (int)(y);
}
int getSkewCount(double x, double y)
{
    /**
     * O O O
     *  O O O
     * O O O 
     * 
     * 2r = 1
     * y=1 : 2r
     * y=2 : r + SIN60 + r
     * y=3 : r + SIN60 * 2 + r
     * 
     * y=n : 1 + SIN60 * (n-1) <= y 
     * ( y - 1 ) / SIN60 + 1 = N
     */
    int nXCnt_odd = (int)(x);
    int nXCnt_even = x >= nXCnt_odd+0.5L ? nXCnt_odd : nXCnt_odd-1 ;
    
    int nYCnt=(int)( ( y - 1 ) * ONE_OVER_SIN60 + 1 );
    
    return nXCnt_odd * ( (nYCnt+1) / 2 ) + nXCnt_even * ( nYCnt / 2 );
}
int _max( int a, int b )
{
    if ( a > b ) return a;
    else return b;
}

void process(FILE *fp)
{
    double x, y;
    
    while ( fscanf(fp, "%lf %lf ", &x, &y ) == 2 )
    {
        int grid = getGridCount(x,y);
        int skew = _max( getSkewCount(x,y), getSkewCount(y,x) );
        
        if ( grid >= skew )
            printf("%d grid\n", grid );
        else
            printf("%d skew\n", skew );
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
