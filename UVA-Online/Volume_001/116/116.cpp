// 116 - Unidirectional TSP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * dp.
 */

#define MAX_SIZE (100)

void process( FILE *fp )
{
    int size_y, size_x ;
    
    while ( fscanf(fp, "%d %d ", &size_y, &size_x ) == 2  )
    {
        int bestPath[ MAX_SIZE ] = {size_y+1,};
        int map[ MAX_SIZE ][ MAX_SIZE ] = {0, };
        int path[ MAX_SIZE ][ MAX_SIZE ] ={0 ,};
        int y, x, dir ;
        
        for ( y = 0 ; y < size_y ; y ++)
            for ( x = 0 ; x < size_x ; x ++)
                if ( fscanf(fp, "%d ", &(map[y][x])) != 1 ) 
                    return ;
        
        for ( x = size_x - 2 ; x >= 0 ; x --)
        {
            for ( y = 0 ; y < size_y ; y ++ )
            {
                int y_min_value=-1 ;
                int y_min_index=-1;
                for ( dir = -1 ; dir <= 1 ; dir ++)
                {
                    int y_idx = ( y + dir + size_y ) % size_y ;
                    int v = map[ y ][ x ] + map[ y_idx ][ x + 1 ];
                    
                    if ( y_min_index < 0 || y_min_value > v || ( y_min_value == v && y_min_index > y_idx ) )
                    {
                        y_min_value = v ;
                        y_min_index = y_idx;
                    }
                }
                
                map[y][x] = y_min_value ;
                path[y][x] = y_min_index;
            }
        }
        
        int min_value = map[0][0];
        for ( y = 1 ; y < size_y ; y ++)
            if ( min_value > map[y][0] )
                min_value = map[y][0];
        
        for ( y = 0 ; y < size_y ; y ++)
        if ( min_value == map[y][0])
        {
            int y_pos;
            for ( x=0, y_pos = y ; x < size_x ; y_pos = path[ y_pos ][ x ], x++ )
            {
                if ( bestPath[ x ] >  y_pos )
                {
                    for ( ; x < size_x ; y_pos = path[ y_pos ][ x ], x ++ )
                        bestPath[ x ] = y_pos;
                    break;
                }
                else if ( bestPath[ x ] >  y_pos )
                    break;
            }
            break;
        }
        
        for ( x = 0 ; x < size_x ; x ++)
        {
            printf("%d", bestPath[ x ] + 1);
            if ( x < size_x - 1 )
                printf(" ");
            else
                printf("\n");
        }
        printf("%d\n", min_value);
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
