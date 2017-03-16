// 108 - Maximum Sum
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N (101)

int MAX( int a, int b)
{
    if ( a < b ) 
        return b;
    else
        return a; 
}
void process( FILE *fp )
{
    int N;
    int y, x, offset_x;
    int map[MAX_N][MAX_N] = {0,};
    int dp[MAX_N+1][MAX_N+1]={0,};
    
    if ( fscanf(fp, "%d", &N) != 1 )
        return ;
    
    for ( y = 0 ; y < N ; y ++ )
        for ( x = 1 ; x <=N ; x ++ )
        {
            if ( fscanf(fp, "%d", &(map[ y ][ x ]) ) != 1 )
                break;
            dp[y][x] = map[y][x];
        }

    for ( y = 0 ; y < N ; y ++ )
    {
        for ( x = 1 ; x <= N ; x ++ )
            dp[ y ][ x ] = dp[ y ][ x-1 ] + dp[ y ] [ x ];
    }
    
    
#ifndef ONLINE_JUDGE 
    for ( y = 0 ; y < N ; y ++ )
    {
        for ( x = 0 ; x <= N ; x ++ )
            printf("%4d ", map[ y ][ x ] );
        printf("\t");
        for ( x = 0 ; x <= N ; x ++ )
            printf("%4d ", dp[ y ][ x ] );
        printf("\n");
    }
#endif
    
    /**
     * 
     * O(n^4) : basic algoritm
     *      find MAX ( sum of map[y1][x1] ~ map[y2][x2] ) for all y1,y2,x1,x2 
     * 
     * O(n^3) : 
     *      prepare array to find sub sum from x1 to x2.
     * 
     *      Assume that
     *          D[ i ] = sum of array[ 0 .. i ]   for all i   : O(n)
     * 
     *          and then, sum of array[ x1 .. x2 ] is D[ x2 ] - D[ x1 ] : O(n)
     * 
     *      so, 
     *      sum of map[y1][x1] ~ map[y2][x2]  is
     *      
     *      for delta in 1 to N ( interval of x2, x1 )
     *          for start_x in 0 to N-delta
     *              for y in 0 to N          # find max subsum of one dimension array O(n)
     *                  if sum < 0 then sum=0;
     *                  else sum += value
     * 
     *
     */
#ifndef ONLINE_JUDGE 
    int sx, sy, ex, ey , last_y;
#endif
    int max_sum = INT_MIN;
    
    for ( offset_x = 1 ; offset_x <= N ; offset_x ++ )
    {
        for ( x = 0 ; x <= N - offset_x ; x ++ )
        {
            int sum = 0 ;
#ifndef ONLINE_JUDGE 
            last_y = 0;
#endif
            for ( y = 0 ; y < N ; y ++ )
            {
                int t = dp [ y ][ x + offset_x ] - dp[ y ][ x ] ;
                sum +=t ;
                
                if ( sum > max_sum ) 
                {
#ifndef ONLINE_JUDGE 
                    sx = x;
                    sy = last_y;
                    ex = x + offset_x;
                    ey = y;
#endif
                    max_sum = sum;
                }
                
                if ( sum < 0 )
                {
                    sum = 0;
#ifndef ONLINE_JUDGE 
                    last_y = y+1;
#endif
                }
            }
        }
    }

#ifndef ONLINE_JUDGE 
    for ( y=sy ; y<=ey ; y++)
    {
        for ( x=sx+1 ; x<=ex ; x++)
            printf("%5d", map[y][x]);
        printf("\n");
    }
    printf("%d %d %d %d\n", sx, sy, ex, ey );
#endif
    printf("%d\n", max_sum);
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
