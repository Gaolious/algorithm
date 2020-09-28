// 118 Mutant Flatworld Explorers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_N (50)

void process( FILE *fp )
{
    int size_y, size_x ;
    
                // E, S, W, N      <- L,  -> R
    int dx [] ={1, 0, -1, 0};
    int dy [] ={0, -1, 0, 1};
    int dc [] ={'E','S','W','N'};
    
    if ( fscanf(fp, "%d %d ", &size_x, &size_y ) == 2 )
    {
        int map[ MAX_N + 1][ MAX_N + 1] = {0,};
        char c ;
        int cx, cy, cd;
        int nx, ny, nd;
        char in[101]={0,};

        while ( fscanf(fp, "%d %d %c %s ", &cx, &cy, &c, in ) == 4 )
        {
            switch ( c )
            {
                case 'E' : cd = 0 ; break;
                case 'S' : cd = 1 ; break;
                case 'W' : cd = 2 ; break;
                case 'N' : cd = 3 ; break;
            }
        
            int i ;
            int len = strlen(in);
            int error = 0 ;
            
            for ( i = 0 ; i < len ; i ++)
            {
                nx = cx;
                ny = cy;
                nd = cd;

                switch ( in[i] )
                {
                    case 'L' : 
                        nd = ( cd - 1 + 4 ) % 4 ;
                        break;
                    case 'R' : 
                        nd = ( cd + 1 + 4 ) % 4 ;
                        break;
                    case 'F' : 
                        nx = cx + dx[ nd ];
                        ny = cy + dy[ nd ];
                        break;
                }

                //printf("(%d,%d,%d) => %c =>(%d,%d,%d)\n", cx, cy, cd, in[i], nx, ny, nd);
                if ( nx < 0 || ny < 0 || ny > size_y || nx > size_x )
                {
                    if ( map[ cy ][ cx ] == 0 )
                    {
                        map[ cy ][ cx ] = 1;
                        error = 1;
                        break;
                    }

                }
                else 
                {
                    cx = nx ;
                    cy = ny;
                    cd = nd ;
                }
            }
            
            printf("%d %d %c", cx, cy, dc[cd]);
            if ( error ) printf(" LOST");
            printf("\n");
        }

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
