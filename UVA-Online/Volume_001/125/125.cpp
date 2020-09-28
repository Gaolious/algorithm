// 125 - Numbering Paths
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (30)

int print_matrix(int m[][MAX_N], int n, int repeat)
{
    
    printf("matrix for city %d\n", repeat );
    for ( int i = 0 ; i <= n ; i ++ )
    {
        for ( int j = 0 ; j <= n ; j ++)
        {
            printf("%d", m[i][j]);
            if ( j != n ) printf(" ");
        }
        printf("\n");
    }
}
void process( FILE *fp )
{
    int count;
    int r = 0 ;
    while (fscanf(fp, "%d ", &count) == 1 )
    {
        int map[MAX_N][MAX_N]={0,};
        int i, j, k;
        int n = -1;
        
        for ( i = 0 ; i < count ; i ++ )
        {
            if ( fscanf(fp, "%d %d ", &j, &k) != 2 ) 
                return;
            
            map[ j ][ k ] = 1 ;
            if ( n < 0 || n < j ) n = j ;
            if ( n < 0 || n < k ) n = k ;
        }
        
        for ( k = 0 ; k <= n ; k ++)
            for ( i = 0 ; i <= n ; i ++)
                for ( j = 0 ; j <=n ; j ++)
                    if ( map[i][k] != 0 && map[k][j] != 0)
                    {
                        if ( map[i][k] < 0 || map[k][j] < 0 )
                            map[ i ][ j ] = -1;
                        else
                            map[ i ][ j ] += map[i][k] * map[k][j];
                        
                        // k -> k is possible. it is cycle.
                        // so, if i->k and k->j is each connected then infinity.
                        if ( map[k][k] != 0 )
                        {
                            if ( map[i][k] != 0 && map[k][j] != 0 )
                                map[i][j] = -1;
                        }
                        
                    }
                    
        print_matrix(map, n, r++);
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