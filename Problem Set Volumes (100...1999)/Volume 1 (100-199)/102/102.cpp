/**
    brown, green and clear bottles
 * 
 * 
 The first character of the string represents the color associated with the first bin, the second character
of the string represents the color associated with the second bin, and the third character represents the
color associated with the third bin.
The integer indicating the minimum number of bottle movements should follow the string.
If more than one order of brown, green, and clear bins yields the minimum number of movements
then the alphabetically first string representing a minimal configuration should be printed.
 * 
 * 
1 2 3 
4 5 6 
7 8 9
B C G

12 15 18
 * 
 * 
 * 2 3 4 5 7 9
 *   5 9 14 21 30
 * B : 2+3, 4+7
 * C : 3, 4+5+, 9
 * G : 2,5,

 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process( FILE *fp )
{
    int n ;
    int data [ 9 ] = { 0, };
    int i, j ;
    
    int sum[3]={0,};
    char bin[] = "BGC" ;
    int map[6][3] = {
        { 0, 2, 1 },
        { 0, 1, 2 },
        { 2, 0, 1 },
        { 2, 1, 0 },
        { 1, 0, 2 },
        { 1, 2, 0 },
    };
    int minMoves ;
    int moves;
    int minIndex;
    do
    {
        for ( i = 0 ; i < 9 ; i ++ )
            if ( fscanf(fp, "%d ", data + i ) != 1 )
                return ;

        for ( i = 0 ; i < 3 ; i ++ )
        {
            sum [ i ] = 0 ;
            for ( j = 0; j < 3 ; j ++ )
                sum[ i ] += data[ i * 3 + j ] ;
        }
        
        minMoves = -1;
        minIndex = -1 ;
        
        for ( i = 0 ; i < 6 ; i ++ )
        {
            moves = sum[0] + sum[1] + sum[2] ;
            
            for ( j = 0 ; j < 3 ; j ++ )
                moves -= data[ map[i][j] + j*3 ];
            if ( minMoves < 0 || minMoves > moves )
            {
                minIndex = i ;
                minMoves = moves;
            }
        }
        
        if ( minIndex >= 0 )
        {
            for ( i = 0 ; i < 3 ; i ++ )
                printf("%c", bin[ map[minIndex][i] ]);
            printf(" %d\n", minMoves);
        }
    } while ( 1 );
    
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
