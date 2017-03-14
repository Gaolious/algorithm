#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _buildings_
{
    int left, height, right ;
} BUILDINGS ;

#define MAX_COORDINATIONS ( 10001 )

// input
BUILDINGS building_left[ MAX_COORDINATIONS ] = {0,};
BUILDINGS building[ MAX_COORDINATIONS ] = {0,};
int nBuildings = 0 ;

// plan sweep.
int x_coordinations [ MAX_COORDINATIONS  * 2 ] = { 0 , };
int nXCoordinations = 0 ;
int yHeight[ MAX_COORDINATIONS  * 2 ] = {0,};

int cmp2( const void *a, const void *b )
{
    if ( *(int *)a < *(int*)b ) return -1;
    else if ( *(int *)a > *(int*)b ) return 1;
    else return 0;
}

int remove_duplicate_elements( int sorted_arr[], int size)
{
    int new_size = 0 ;
    
    for ( int i = 0 ; i < size; i ++ )
    {
        if ( new_size <= 0 )
            new_size ++;
        else if ( sorted_arr[new_size-1] != sorted_arr[ i ] )
            sorted_arr[ new_size++ ] = sorted_arr[ i ];
    }
    
    if ( size > new_size )
        memset( sorted_arr + new_size, 0x00, sizeof(int)*(size-new_size) );

    return new_size ;
}

int getIndex( int left )
{
    int l = 0, r = nXCoordinations-1;
    int m ;
    
    while ( l <= r )
    {
        m = ( l + r + 1 ) / 2 ;
        
        if ( x_coordinations[ m ] == left )
            return m;
        else if ( x_coordinations[ m ] < left )
            l = m + 1 ;
        else 
            r = m - 1 ;
    }
    
    return -1;
}

void setHeight( int left, int right, int height )
{
    int start_idx = getIndex( left );
    
    if ( start_idx < 0 )
        return ;
    
    for ( int  i = start_idx ; i < nXCoordinations && ( left <= x_coordinations[ i ] && x_coordinations[ i ] < right ) ; i ++ )
    {
        if ( yHeight[ i ] < height )
            yHeight[ i ] = height ;
    }
}
void process( FILE *fp )
{
    int left, height, right ;
    int i , prev;
    
    nXCoordinations = 0;
    for ( nBuildings = 0 ; fscanf(fp, "%d %d %d", &left, &height, &right ) == 3 ; nBuildings ++ )
    {
        building[ nBuildings ].left = left ;
        building[ nBuildings ].height = height ;
        building[ nBuildings ].right = right ;
        
        x_coordinations[ nXCoordinations ++ ] = left ;
        x_coordinations[ nXCoordinations ++ ] = right ;
    }
    
    qsort( x_coordinations, nXCoordinations, sizeof(int), cmp2 );
    nXCoordinations = remove_duplicate_elements( x_coordinations, nXCoordinations );
    memset( yHeight, 0x00, sizeof(int)*nXCoordinations);

    
    for ( i = 0 ; i < nBuildings ; i ++ )
        setHeight( building[ i ].left, building[ i ].right, building[ i ].height);
    
    for ( i = 0 ; i < nXCoordinations ; i ++ )
    {
        if ( i == 0 )
            prev = yHeight[ i ] ;
        else if ( prev == yHeight[ i ]  )
            continue ;
        
        if ( i != 0 ) printf(" ");
        printf("%d %d", x_coordinations[ i ], yHeight[ i ] );
        prev = yHeight[ i ] ;
    }
    printf("\n");
    
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
