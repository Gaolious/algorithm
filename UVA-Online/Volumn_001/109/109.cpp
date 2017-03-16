// 109 - SCUD Busters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _points_
{
    double x, y ;
} POINT;

#define MAX_KINGDOM ( 20 )
#define MAX_COORDINATIONS ( 100 )

POINT kingdoms [ MAX_KINGDOM ][ MAX_COORDINATIONS ] = { 0, };
double area[ MAX_KINGDOM ]={0,};
int Coordinations[ MAX_KINGDOM ]={0,};
int nKingdoms = 0;

int qsort_cmp( const void *a, const void *b)
{
    POINT *p1 = ( POINT *)a ;
    POINT *p2 = ( POINT *)b ;
    
    if ( p1->y < p2->y ) return -1 ;
    else if ( p1->y > p2->y ) return 1 ;
    
    if ( p1->x < p2->x ) return -1 ;
    else if ( p1->x > p2->x ) return 1 ;
    
    return 0;
}

/**
 * 
 * @param p1
 * @param p2
 * @param p3
 * @return 
 *  positive : left side
 *  negative : right side
 */
double CCW( POINT p1, POINT p2, POINT p3)
{
    double ret = ( p1.x * p2.y + p2.x * p3.y + p3.x * p1.y ) - ( p1.y * p2.x + p2.y * p3.x + p3.y * p1.x ) ;
    return ret / 2.0;
}

/**
 * p1, p2, p3 is in a line.
 * 
 * @param p1
 * @param p2
 * @param p3
 * @return 
 *      1 : remove p2.
 *      2 : remove p3.
 */
int check_inline_with_rotate( POINT p1, POINT p2, POINT p3)
{
   POINT p1prime ;
   POINT p2prime ;
   POINT p3prime ;
   POINT rotate_p3 ;

   double c1, c2 ;
   
   double cos90 = 0.0L;
   double sin90 = 1.0L;
   
   p1prime.x = p1.x - p2.x ;
   p1prime.y = p1.y - p2.y ;
   
   p2prime.x = 0.0L ;
   p2prime.y = 0.0L ;
   
   p3prime.x = p3.x - p2.x ;
   p3prime.y = p3.y - p2.y ;
   
   rotate_p3.x = p3prime.x * cos90 - p3prime.y * sin90 ;
   rotate_p3.y = p3prime.x * sin90 + p3prime.y * cos90 ;
   
   c1 = CCW( rotate_p3, p2prime, p1prime );
   c2 = CCW( rotate_p3, p2prime, p3prime );
   
   if ( c1 < 0 && c2 > 0 ) return 1 ;
   if ( c1 > 0 && c2 < 0 ) return 1 ;

   if ( c1 < 0 && c2 < 0 ) return 2 ;
   
   return 0;
}
int convex_hull(POINT points[], int size)
{
    qsort( (void *)(points), size, sizeof(POINT), qsort_cmp );
    
    POINT t;
    int i, j;
    double ret ;
    
    for ( i = 1 ; i < size ; i ++ )
    {
        for ( j = i + 1 ; j < size ; j ++ )
        {
            ret = CCW( points[i-1], points[i], points[j] );
            
            if ( ret < 0 ) 
            {
                t = points[ j ] ;
                points[ j ] = points[ i ] ;
                points[ i ] = t ;
            }
            else if ( ret > 0 ) 
                continue ;
            else 
            {
                int check = check_inline_with_rotate( points[i-1], points[i], points[j]);
                
                if ( check == 1 ) // remove i
                {
                    points[ i ] = points[ size-1 ];
                    j=i;
                    size --;
                    continue ;
                }
                else if ( check == 2 )
                {
                    points[ j ] = points[ size - 1 ];
                    j--;
                    size--;
                    continue ;
                }
                else
                {
                    // nothing
                }
            }
        }
        
        ret = CCW( points[i-1], points[i], points[0] );
        if ( ret < 0)
        {
            memset( points + i , 0x00, sizeof(POINT) * ( size - i - 1 ));
            return i;
        }
        
    }
    
    return size;
    
    
}

double get_area( POINT points[], int size)
{
    int i;
    double area = 0, t ;

    for ( i = 2 ; i < size ; i ++ )
    {
        t = CCW( points[0] , points[ i-1 ], points[ i ] );
        
        if ( t < 0 ) 
            area -= t;
        else
            area += t;
    }
    
    return area;
}

void input(FILE *fp)
{
    int nCoord ;
    int i ;
    
    for ( nKingdoms = 0 ; fscanf(fp, "%d", &nCoord) == 1 ; nKingdoms ++)
    {
        if ( nCoord == -1 ) break;

        for ( i = 0 ; i < nCoord ; i ++ )
        {
            if ( fscanf(fp, "%lf %lf", &(kingdoms[ nKingdoms ][ i ].x), &(kingdoms[ nKingdoms ][ i ].y) ) != 2) 
                break;
        }
        
        nCoord = convex_hull( kingdoms[ nKingdoms ], nCoord );
        Coordinations[ nKingdoms ] = nCoord ;
#ifndef ONLINE_JUDGE 
        printf("Coordinations : %d\n", nCoord );
        for ( i = 0 ; i < nCoord ; i ++ )
            printf("%lf %lf\n", kingdoms[ nKingdoms ][ i ].x, kingdoms[ nKingdoms ][ i ].y);
        printf("\n");
#endif
        
        area[ nKingdoms ] = get_area( kingdoms[ nKingdoms ], nCoord );
#ifndef ONLINE_JUDGE 
        printf("\nArea #%d : %lf\n", nKingdoms, area[nKingdoms] );
#endif
    }
}
void process( FILE *fp )
{
    input(fp);
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
