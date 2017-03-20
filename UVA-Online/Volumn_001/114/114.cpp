// 113 - Simulation Wizardry

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * input :
Your program should simulate one game of pinball. There are several input lines that describe the
game. The first line gives integers m and n, separated by a space. This describes a cartesian grid where
1 ≤ x ≤ m and 1 ≤ y ≤ n on which the game is “played”. It will be the case that 2 < m < 51 and
2 < n < 51. The next line gives the integer cost for hitting a wall. The next line gives the number of
bumpers, an integer p ≥ 0.
The next p lines give the x position, y position, value, and cost, of each bumper, as four integers
per line separated by space(s). The x and y positions of all bumpers will be in the range of the grid.
The value and cost may be any integer (i.e., they may be negative; a negative cost adds lifetime to a
ball that hits the bumper).
The remaining lines of the file represent the balls. Each line represents one ball, and contains four
integers separated by space(s): the initial x and y position of the ball, the direction of movement, and
its lifetime. The position will be in range (and not on top of any bumper or wall). The direction will
be one of four values: 0 for increasing x (right), 1 for increasing y (up), 2 for decreasing x (left), and 3
for decreasing y (down). The lifetime will be some positive integer.
 * 
 * Input :
 *      m, n                1 <= x <= m, 1 <= y <= n ???
 *                          2 < m < 51, 2 < n < 51
 *      cost                for hitting wall.
 *      p                   number of bumpers.
 * 
 *      x, y, v, cost       for each bumpers. (p)
 * 
 *      x,y,dir,lifetime    0 +x, 1 +y, 2 -x, 3 -y
 * 
 * 
 */
typedef struct _bumpers_
{
    int value;
    int cost ;
} BUMPER ;
void process( FILE *fp )
{
    int grid[ 52 ][ 52 ] ={0,};

    int m, n ;
    int wall_cost ;
    BUMPER bumpers[ 48 * 48 + 1 ]={0,};
    int p;
    int x, y ;
    int i ;
    
    if ( fscanf(fp, "%d %d ", &m, &n ) != 2 ) return ;
    if ( fscanf(fp, "%d ", &wall_cost) != 1 ) return ;
    if ( fscanf(fp, "%d ", &p) != 1 ) return ;
    
    for ( y = 0 ; y < 52 ; y ++ )
        for ( x = 0 ; x < 52 ; x ++ )
                grid [ y ][ x ] = -1;
        
    for ( i = 0 ; i < p ; i ++ )
    {
        if ( fscanf(fp, "%d %d %d %d ", &(x), &(y), &(bumpers[i].value), &(bumpers[i].cost) ) != 4 ) return ;
        grid[ y ][ x ] = i ;
    }
    
    int sx, sy, dir, lifetime;
    int nx, ny ;
                // +x, +y, -x, -y : curr
                // -y, +x, +y, -x : next
    int dx [] = { 1, 0, -1, 0 };
    int dy [] = { 0, 1, 0, -1 };
    int total_value = 0 ;
    
    while ( fscanf(fp, "%d %d %d %d ", &sx, &sy, &dir, &lifetime) == 4 )
    {
        int value = 0 ;
        
        while( --lifetime > 0 )
        {
            nx = sx + dx[ (dir ) % 4 ];
            ny = sy + dy[ (dir ) % 4 ];
            
            if ( nx <= 1 || ny <= 1 || nx >= m || ny >= n )
            {
                lifetime -= wall_cost ;
                dir = ( dir - 1 + 4) % 4 ;
                continue;
            }
            if ( grid[ ny ][ nx ] != -1 )
            {
                lifetime -= bumpers[ grid[ ny ][ nx ] ].cost ;
                value += bumpers[ grid[ ny ][ nx ] ].value;
                dir = ( dir - 1 + 4) % 4 ;
                continue;                
            }
            
            sx = nx;
            sy = ny;
        }
        printf("%d\n", value );
        total_value += value;
    }
    printf("%d\n", total_value );
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