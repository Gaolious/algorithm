#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _point
{
    int x, y;
} POINT ;
typedef struct _triangle
{
    POINT p[3];
} TRIANGLE;

int dist(POINT *p1, POINT *p2)
{
    int x = ( p1->x - p2->x ) ;
    int y = ( p1->y - p2->y ) ;
    
    return x*x + y*y;
}
bool is_zero( int v)
{
    if ( v < 0 ) v *= -1;
    
    return ( v < 1.0e-6 );
}

int ccw( POINT *p1, POINT *p2, POINT *p3)
{
    // left : 1
    // right : -1
    // in a line : 0
    
    int temp =  p1->x * p2->y + p2->x * p3->y + p3->x * p1->y ;
    temp = temp -  p1->y * p2->x - p2->y * p3->x - p3->y * p1->x ;
    
    if ( is_zero(temp) ) 
        return 0;
    if ( temp < 0 ) return -1;
    if ( temp > 0 ) return 1;
    return 0;
}

int toDouble(char str[])
{
    int c;
    int n = 0;
    char *p = str;
    
    while ( *p && '0' <= *p && *p <= '9' )
        n = n * 10 + (*p++)-'0';
    
    c = 2;
    if ( *p && *p++ == '.' )
    {
        for ( ; *p && c ; c -- )
            n = n * 10 + (*p++) - '0' ;
    }
    
    for ( ; c > 0 ; c-- ) n *= 10;
    
    return n;
}

void input(FILE *fp)
{
    int i;
    int is_exit;
    int min_x, max_x, min_y, max_y ;
    
    TRIANGLE t;
    char str[6][1024]={0,};
    
    // floating number errorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.....
    
    while ( fscanf(fp, "%s %s %s %s %s %s ", str[0], str[1], str[2], str[3], str[4], str[5] ) == 6 )
    {
        t.p[0].x = toDouble(str[0]);
        t.p[0].y = toDouble(str[1]);
        t.p[1].x = toDouble(str[2]);
        t.p[1].y = toDouble(str[3]);
        t.p[2].x = toDouble(str[4]);
        t.p[2].y = toDouble(str[5]);
    
        if (ccw( t.p+0, t.p+1, t.p+2) < 0 )
        {
            POINT p = t.p[1];
            t.p[1] = t.p[2];
            t.p[2] = p;
        }
        min_x = min_y = 1000000;
        max_x = max_y = -100000;
        for ( i = 0 ; i < 3 ; i ++ )
        {
            if ( t.p[i].x < min_x ) min_x = t.p[i].x;
            if ( t.p[i].x > max_x ) max_x = t.p[i].x;
            if ( t.p[i].y < min_y ) min_y = t.p[i].y;
            if ( t.p[i].y > max_y ) max_y = t.p[i].y;
        }
        if ( min_x % 100 ) min_x += 100;
        if ( min_y % 100 ) min_y += 100;
        
        min_x = (int)(min_x / 100) * 100 ;
        min_y = (int)(min_y / 100) * 100 ;
        max_x = (int)(max_x / 100) * 100 ;
        max_y = (int)(max_y / 100) * 100 ;
        if ( 100 > min_x ) min_x = 100;
        if ( 9900 < max_x ) max_x = 9900;
        if ( 100 > min_y ) min_y = 100;
        if ( 9900 < max_y ) max_y = 9900;
        

        is_exit = 1 ;
        for ( i = 0 ; i < 3 ; i ++)
        {
            if ( !is_zero(t.p[i].x) || !is_zero(t.p[i].y) )
                is_exit = 0;

        }
        if ( is_exit )
            break;
        
        int cnt = 0 ;
        for ( int x = min_x ; x <= max_x ; x +=100 )
        for ( int y = min_y ; y <= max_y ; y +=100 )
        {

            int is_inside = true;
            POINT p = { (int)x, (int)y };
            for ( i = 0 ; i < 3 ; i ++ )
            {
                int d = ccw( &(t.p[( i ) % 3]) , &(t.p[( i + 1 ) % 3]) , &p ) ;

                if ( d < 0 )
                {
                    is_inside = false ;
                    break;
                }
            }

            if ( is_inside)
            {
                // printf("%d %d\n", x, y);
                cnt ++;
            }
        }
        
        printf("%4d\n", cnt);
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
