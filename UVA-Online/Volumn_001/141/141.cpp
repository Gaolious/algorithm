#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN (50)
typedef struct _map
{
    unsigned char arr[ 313 ] ;
} MAP;

void set( MAP *map, int n, int x, int y, int sign)
{
    int pos = ( y - 1 ) * n + ( x - 1 );
    
    int idx = pos / 8 ;
    int offset = pos % 8;
    
    unsigned char mask = ( 0x1 << offset ) & 0xFF ;
    
    if (sign)
        map->arr[idx] |= mask ;
    else
        map->arr[idx] &= ~mask;
}
int get( MAP *map, int n, int x, int y)
{
    int pos = ( y - 1 ) * n + ( x - 1 );
    
    int idx = pos / 8 ;
    int offset = pos % 8;
    
    if ( map->arr[idx] & ( ( 0x1 << offset ) & 0xFF ) )
        return 1;
    else
        return 0;
}
int is_equal(MAP *src_map, MAP *dest_map)
{
    return memcmp(src_map->arr, dest_map->arr, sizeof(src_map->arr)) == 0;
}

void rotate( MAP *src_map, MAP *dest_map, int n)
{
    // x, y => n-x
    // 
    int y, x ;
    for ( y = 1 ; y <= n ; y ++)
        for ( x = 1 ; x <= n ; x ++)
        {
            if ( get(src_map, n, x, y ) )
                set( dest_map, n, n-y+1, x, 1);
        }
            
}
void print( MAP *map, int n)
{
    int y, x ;
    for ( y = 1 ; y <= n ; y ++)
    {
        for ( x = 1 ; x <= n ; x ++)
        {
            if ( get(map, n, x, y ) )    
                printf("%2c", '*');
            else
                printf("%2c", '-');
        }
        printf("\n");
    }
}
void input(FILE *fp)
{
    int n;
    
    while ( fscanf(fp, "%d ", &n) == 1 )
    {
        int i, j, k;
        int x, y;
        char c;
        MAP map[2 * 50][4]={0,};
        int bFound = 0 ;
        
        if ( n == 0 )
            break;
        
        for ( i = 0 ; i < n*2 ; i ++)
        {
            fscanf(fp, "%d %d %c ", &x, &y, &c);
            if ( bFound == 1 )
                continue;
            if ( i > 0 )
                map[i][0] = map[i-1][0];
            if ( c == '+' )
                set( map[i] + 0, n, x, y, 1);
            else
                set( map[i] + 0, n, x, y, 0);
            
            for ( j = 0 ; j < i-1 && bFound == 0 ; j ++)
                for ( k = 0 ; k < 4 ; k ++)
                {
                    if ( is_equal(map[i] + 0, map[j] + k ) )
                    {
                        bFound = 1;
                        break;
                    }
                }
            
            if ( bFound == 1 )
            {
                printf("Player %d wins on move %d\n", 2 - i%2, i+1);
                continue;
            }
            //printf("Input : \n");
            // print(map[i] + 0, n );
            
            for ( j=1 ; j<4 ; j++)
            {
                //printf("\nRotate:\n");
                rotate( map[i]+j-1, map[i]+j, n);
                //print(map[i] + j, n );
            }
        }
        
        if ( !bFound )
            printf("Draw\n");
    }
}

int main()
{
#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif
    input(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
