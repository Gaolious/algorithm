#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE (8)

int board[ SIZE ][ SIZE ] ;
int check[ SIZE ][ SIZE ] ;

int check_col[ SIZE + 1 ];
int diagonal_lt_rb[SIZE * 2 + 1 ];
int diagonal_rt_lb[SIZE * 2 + 1 ];
int max;

void set(int y, int x, int val)
{
    check_col[ x ] = val ;
    diagonal_lt_rb[ y - x + SIZE ] = val ;
    diagonal_rt_lb[ y + x ] = val ;
}
bool is_valid(int y, int x)
{
    if ( check_col[x] ) return false ;

    if ( diagonal_lt_rb[ y - x + SIZE ]  ) return false ;

    if ( diagonal_rt_lb[ y + x ] ) return false ;
    return true ;
}
void recur(int row, int sum)
{
    int i, j ;
    if ( row >= SIZE )
    {
        if ( max < sum ) max = sum ;
        // printf("%d\n", sum);
        // for ( i = 0 ; i < SIZE ; i ++ )
        // {
        //     for ( j = 0 ; j < SIZE; j ++ )
        //         printf("%3d", check[ i ][ j ] );
        //     printf("\n");
        // }
        return ;
    }
    for ( i = 0 ; i < SIZE ; i ++ )
    {
        if ( is_valid( row, i ) )
        {
            check[row][i] = 1 ;
            set( row, i, 1 );
            recur(row+1, sum+board[row][i]);
            set( row, i, 0 );
            check[row][i] = 0 ;
        }
    }
}
void process()
{
    int n ;
    int i, j ;

    scanf("%d ", &n);
    
    while ( n-- )
    {
        for ( i = 0 ; i < SIZE ; i ++ )
            for ( j = 0 ; j < SIZE ; j ++ )
                scanf("%d ", &board[i][j]);

        memset(check_col, 0x00, sizeof( check_col) );
        memset(diagonal_lt_rb, 0x00, sizeof( diagonal_lt_rb) );
        memset(diagonal_rt_lb, 0x00, sizeof( diagonal_rt_lb) );
        max = -1;
        recur(0, 0);
        printf("%5d\n", max);
    }
}

int main() 
{
    process();     

    return 0;
}

