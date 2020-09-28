#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int ICON = 1;
const int WINDOW = 2;
typedef struct _point
{
    int x, y;
} POINT ;
typedef struct _rect
{
    POINT s, e;
} RECT;

double dist(POINT *p1, POINT *p2)
{
    double x = (double)( p1->x - p2->x ) ;
    double y = (double)( p1->y - p2->y );
    return x*x + y*y;
}
bool inside( POINT *p, RECT *r)
{
    return r->s.x <= p->x && p->x <= r->e.x &&
            r->s.y <= p->y && p->y <= r->e.y;
}

bool find_region( RECT r[], int n, POINT *p )
{
    int i;
    
    for ( i = n - 1 ; i >= 0 ; i -- )
    {
        if ( inside( p, r+i ) )
        {
//            printf("%d : (%d,%d) is inside of (%d,%d)-(%d,%d)\n", 
//                    i, 
//                    p->x, p->y, 
//                    r[i].s.x, r[i].s.y, 
//                    r[i].e.x, r[i].e.y );
            printf("%c\n", i + 'A' );
                    
            return true;
        }
    }
    return false;
}

bool find_point( POINT pt[], int n, POINT *p )
{
    int i;
    double min = -1;
    int points[50]={0,};
    int nPoints =0;
    
    for ( i = 0 ; i < n ; i ++ )
    {
        if (pt[i].x<0) continue;
        
        if ( i == 33 -1  )
        {
            int a  = 0;
            a = 1;
        }
        double d = dist(p, pt + i);
        if ( min < 0 || d < min )
        {
            min = d ;
            nPoints = 0;
        }
        
        if ( d <= min )
            points[ nPoints ++ ] = i ;
    }
    
    for ( i = 0 ; i < nPoints ; i ++)
        printf("%3d", points[i]+1);
    printf("\n");
    return true;
}

void input(FILE *fp)
{
    RECT region[26]={0,};
    POINT point[50]={0,};
    
    char type;
    POINT p;
    int nRect=0, nPoint=0;
    int remove = 0 ;
    
    for ( ; fscanf(fp, "%c ", &type) == 1 ; )
    {
        if ( type == '#' )
            break;
        
        if ( type == 'I' )
        {
            fscanf(fp, "%d %d ", &(point[nPoint].x), &(point[nPoint].y) );
            nPoint++;
        }
        else if ( type == 'R' )
        {
            fscanf(fp, "%d %d %d %d ", &(region[nRect].s.x), &(region[nRect].s.y), &(region[nRect].e.x), &(region[nRect].e.y) );
            nRect++;
        }
        else if ( type == 'M')
        {
            if (remove == 0 )
            {
                remove = 1 ;
                for ( int i = 0 ; i < nRect ; i ++)
                    for ( int j = 0 ; j < nPoint ; j ++)
                        if ( inside( point + j , region + i) )
                        {
                            point[j].x = point[j].y = -9999999;
                        }
            }
            fscanf(fp, "%d %d ", &(p.x), &(p.y) );
            if ( find_region(region, nRect, &p) )
                continue ;
            if ( find_point(point, nPoint, &p) )
                continue;
        }
        else
            break;
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
