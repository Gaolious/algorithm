#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <queue>

#define MAX_SIZE (10)

typedef struct _data 
{
    char horizonal[MAX_SIZE + 1];
    char vertical[MAX_SIZE + 1];
    int len_horizonal ;
    int len_vertical ;
    int offset_horizonal;
    int offset_vertical;
} DATA;

int getOffset( DATA *pData )
{
    int i, j;
    pData->len_horizonal = strlen(pData->horizonal);
    pData->len_vertical = strlen(pData->vertical);

    for (i = 0 ; i < pData->len_horizonal ; i++)
    {
        for ( j = 0 ; j < pData->len_vertical ; j ++)
        if ( pData->horizonal[ i ] == pData->vertical[ j ] )
        {
            pData->offset_horizonal = i ;
            pData->offset_vertical = j ;
            return 1;
        }
    }
    return -1;
}
#define MIN(a, b) ( (a) > (b) ? (b) : (a) )
#define MAX(a, b) ( (a) < (b) ? (b) : (a) )

void print_string(char str[], int len, int y, int x, char map[MAX_SIZE*2 + 1][MAX_SIZE*2 + 3 + 1], int is_horizonal)
{
    int dx, dy ;
    
    dy = y ;
    dx = x ;

    for ( int i = 0 ; i < len ; i ++)
    {
        map[ dy ][ dx ] = str[ i ];

        if ( is_horizonal ) dx ++;
        else dy ++;
    }
}

// use array map
// void print_word(DATA *p1, DATA *p2)
// {
//     int offset_y ;
//     int sy1, sy2, ey1, ey2 , sy, ey;

//     int ex ;
//     int x, y ;

//     offset_y = MAX( p1->offset_vertical, p2->offset_vertical );

//     sy1 = offset_y - p1->offset_vertical ;
//     sy2 = offset_y - p2->offset_vertical;
//     ey1 = offset_y + p1->len_vertical - p1->offset_vertical ;
//     ey2 = offset_y + p2->len_vertical - p2->offset_vertical ;

//     sy = MIN(sy1, sy2);
//     ey = MAX(ey1, ey2);

//     char map[MAX_SIZE * 2 + 1 ][ MAX_SIZE * 2 + 1 + 3 ]={0,};

//     ex = p1->len_horizonal + 3 + p2->len_horizonal ;
    
//     // char str[], int len, int y, int x, char map[MAX_SIZE*2 + 1][MAX_SIZE*2 + 1], int is_horizonal
//     print_string(
//         p1->vertical, p1->len_vertical, 
//         sy1, p1->offset_horizonal, 
//         map, 0
//     );

//     print_string(
//         p1->horizonal, p1->len_horizonal, 
//         sy1 + p1->offset_vertical, 0,
//         map, 1
//     );

//     print_string(
//         p2->vertical, p2->len_vertical, 
//         sy2, p2->offset_horizonal + p1->len_horizonal + 3, 
//         map, 0
//     );

//     print_string(
//         p2->horizonal, p2->len_horizonal, 
//         sy2 + p2->offset_vertical, p1->len_horizonal + 3,
//         map, 1
//     );

//     for ( y = 0 ; y < ey ; y ++ )
//     {
//         for ( x = MAX_SIZE * 2 + 1 + 3 - 1 ; x >= 0 && map[y][x] == 0 ; x -- );
//         if ( x < 0 ) continue ;

//         for ( ; x >= 0 ; x -- )
//         if ( map[y][x] == 0 ) map[y][x] = ' ';

//         printf("%s\n", map[y]);
//     }
// }

void padding(int n)
{
    for( int i = 0 ;i < n ; i ++)
        printf(" ");
}
int offset(int n)
{
    if ( n > 0 ) return n+1;
    else return 0;
}
void print_word(DATA *p1, DATA *p2)
{

    int offset_y ;
    int sy1, sy2, ey1, ey2 , sy, ey;

    int ex ;
    int x, y ;

    offset_y = MAX( p1->offset_vertical, p2->offset_vertical );

    sy1 = offset_y - p1->offset_vertical ;
    sy2 = offset_y - p2->offset_vertical;
    ey1 = offset_y + p1->len_vertical - p1->offset_vertical ;
    ey2 = offset_y + p2->len_vertical - p2->offset_vertical ;

    sy = MIN(sy1, sy2);
    ey = MAX(ey1, ey2);

    for ( y = 0 ; y < ey ; y ++ )
    {
        // 1.
        // first character
        if ( sy1 <= y && y < ey1 )
        {
            if ( y - sy1 == p1->offset_vertical ) printf("%s", p1->horizonal);
            else padding(p1->offset_horizonal), printf("%c", p1->vertical[ y - sy1 ]);
        }
            // printf("|");
        // 2.
        if ( sy2 <= y && y < ey2 )
        {
            // blanks
            if ( sy1 <= y && y < ey1 )
            {
                if ( y - sy1 == p1->offset_vertical ) padding(3);
                else padding(p1->len_horizonal - p1->offset_horizonal + 3 - 1);
            }
            else padding( p1->len_horizonal + 3);
            
            // printf("|");

            // secondary character
            if ( y - sy2 == p2->offset_vertical ) printf("%s\n", p2->horizonal);
            else padding(p2->offset_horizonal), printf("%c\n", p2->vertical[ y - sy2 ]);
        }
        else printf("\n");
    }
}

void process(FILE *fp)
{
    DATA p1={0,}, p2={0,} ;
    int first = 0 ;

    while ( fscanf(fp, "%s ", p1.horizonal) == 1 && p1.horizonal[0] != '#' )
    {
        fscanf(fp, "%s %s %s ", p1.vertical, p2.horizonal, p2.vertical);
        if ( first != 0 )
            printf("\n"); 
        first = 1;

        if ( getOffset( &p1 ) < 0 || getOffset(&p2) < 0 )
            printf("Unable to make two crosses\n");
        else
            print_word(&p1, &p2);
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