#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X (2048)
#define MAX_Y (2048)
#define MIN_X (0)
#define MIN_Y (0)

int px, py;
int cnt ;

void squares( int x, int y, int k)
{
    int sx, ex, sy, ey ;

    sx = x - k;
    sy = y - k;
    ex = x + k;
    ey = y + k;

    if ( k < 1 ) return;

    // if ( sx < MIN_X || sx > MAX_X || sy < MIN_Y || sy > MAX_Y  ) return ;
    // if ( ex < MIN_X || ex > MAX_X || ey < MIN_Y || ey > MAX_Y  ) return ;
    
    // printf("(%d, %d) - (%d, %d)\n", sx, sy, ex, ey);

    if ( ex >= px && px >= sx && ey >= py && py >= sy )
        cnt++;

    if ( px <= x && py <= y )
        squares( sx, sy, k / 2 );

    if ( px >= x && py <= y )
        squares( ex, sy, k / 2 );

    if ( px <= x && py >= y )
        squares( sx, ey, k / 2 );

    if ( px >= x && py >= y )
        squares( ex, ey, k / 2 );
}

void process(FILE *fp)
{
    int x, y, k;

    x = ( 2048 + 1 ) / 2;
    y = ( 2048 + 1 ) / 2;
    k = 500;

    while( fscanf(fp, "%d %d %d ", &k, &px, &py) == 3 )
    {
        if( k == 0 && px == 0 && py == 0 ) break;
        cnt = 0 ;
        squares(x, y, k);
        printf("%3d\n", cnt);
    }

}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}