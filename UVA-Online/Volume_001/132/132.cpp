// 132 - Bumpy Objects
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * An object "can be rotated" to stand stably 
 * if two vertices can be found that can be joined by a straight line that does not intersect the object, 
 * and, when this line is horizontal, the center of mass lines above the line and strictly between its endpoints. 
 * 
 * There are typically many stable positions and each is defined by one of these lines known as its base line. 
 * 
 * A base line, and its associated "stable position", is identified by the *(highest numbered vertex)* touched by that line

 * Write a program that will determine the stable position that has the lowest numbered base line.
 * 
 * The numbering from 1 to n proceeds consecutively in a clockwise direction.
 * 

 * EX> 
 *      Object2
 *      4 3
 *      3 2 5 2 6 1 7 1 6 3 4 7 1 1 2 1 0 0
 * 
 *   +---+---+---+---+---+---+---+---+---+
 * 8 |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 7 |   |   |   |   | 6 |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 6 |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 5 |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 4 |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 3 |   |   |   |   | C |   | 5 |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 2 |   |   |   |   |   | 2 |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 1 |   | 7 | 8 | 1 |   |   | 3 | 4 |   |
 *   +---+---+---+---+---+---+---+---+---+
 * 0 |   |   |   |   |   |   |   |   |   |
 *   +---+---+---+---+---+---+---+---+---+
 *     0   1   2   3   4   5   6   7   8
 * 
 * 
 * Base line #1 : vertex(4) - vertex(5) - vertex(6) : highest numbered vertex(6)
 * Base line #2 : vertex(6) - vertex(7) : highest numbered vertex(7)
 * Base line #3 : vertex(7) - vertex(8) - vertex(1) - vertex(3) - vertex(4)  : highest numbered vertex(8)
 * 
 * 
 * So, Output is minimum of ( 6, 7, 8 ) => 6.
*
*/

class POINT
{
public:
    int idx;
    double x, y ;
    POINT (){}
    POINT(double x, double y) { this->x=x; this->y=y;}
    POINT(int idx, double x, double y) { this->idx = idx; this->x=x; this->y=y;}
    POINT(const POINT &p) { this->idx = p.idx ; this->x = p.x; this->y = p.y; }
    
    POINT operator - ( const POINT &p) const
    {
        return POINT( this->x - p.x , this->y - p.y );
    }
    double size() 
    {
        return sqrt( this->x * this->x + this->y * this->y );
    }
    void swap( POINT &p)
    {
        POINT t = POINT( p );
        p = *this;
        *this = t;
    }
    double distance(POINT p)
    {
        return (*this - p).size();
    }
    static double dotProd( POINT a, POINT b)
    {
        return a.x * b.x + a.y * b.y ;
    }
    static double dotProd( POINT basis, POINT a, POINT b)
    {
        return POINT::dotProd(a-basis, b-basis);
    }    
    static double crossProd(POINT a, POINT b)
    {
        return a.x * b.y - a.y * b.x ;
    }
    static double crossProd( POINT basis, POINT a, POINT b)
    {
        return POINT::crossProd( a-basis, b-basis );
    }
};

int qsort_cmp( const void *a, const void *b)
{
    POINT *p1 = (POINT *)a;
    POINT *p2 = (POINT *)b;
    
    if ( p1->y < p2->y ) return -1;
    if ( p1->y > p2->y ) return 1;
    
    if ( p1->x < p2->x ) return -1;
    if ( p1->x > p2->x ) return 1;
    
    if ( p1->idx < p2->idx ) return -1;
    if ( p1->idx > p2->idx ) return 1;
    
    return 0;
}

int convex_hull( POINT points[], int size)
{
    int i, j;
//    for ( i = 1 ; i < size; i ++)
//    {
//        if ( points[i].x == points[i-1].x && points[i].y == points[i-1].y )
//        {
//            if ( points[i].idx > points[i-1].idx )
//                points[i-1].swap(points[i]);
//            for ( j = i+1 ; j < size ; j++)
//                points[j-1].swap(points[j]);
//            size--;
//            i--;
//        }
//    }
//        
    for ( i = 1 ; i < size; i ++)
    {
        for ( j = i + 1 ; j < size ; j ++ )
        {
            double ccw = POINT::crossProd(points[i-1], points[i], points[j] );
//            
//            printf("(%lf,%lf)(%d) (%lf,%lf)(%d) (%lf,%lf)(%d) : %lf\n", 
//                    points[i-1].x, points[i-1].y, i-1,
//                    points[i].x, points[i].y, i,
//                    points[j].x, points[j].y, j,
//                    ccw
//                    );
            if ( ccw > 0 )
            {
                continue;
            }
            else if ( ccw < 0 )
            {
                points[ i ].swap( points[j] );
                continue;
            }
            else
            {
                double d1 = points[i-1].distance( points[i] );
                double d2 = points[i-1].distance( points[j] );
                
                if ( d2 < d1 ) 
                {
                    points[ i ].swap( points[j] );
                    continue;
                }
            }
        }
        
        if ( POINT::crossProd(points[i-1], points[i], points[0] ) < 0 )
            return i;
    }
    return size;
}
void print_inputs(POINT p[], int size, POINT c)
{
    int i, j, k;
    
    int max_y=c.y, max_x=c.x ;
    
    for ( i = 0 ; i < size ; i ++ )
    {
        if ( max_x < 0 || max_x < p[i].x ) max_x = p[i].x;
        if ( max_y < 0 || max_y < p[i].x ) max_y = p[i].y;
    }
    
    for ( i = max_y + 2 ; i >= 0 ; i -- )
    {
        printf("  ");
        for ( j = 0 ; j <= max_x + 1 ; j ++ )
            printf("+-");
        printf("+\n");
        
        printf("%2d", i);
        
        for ( j = 0 ; j <= max_x + 1 ; j ++ )
        {
            int idx = -1;
            
            for ( k = 0 ; k < size ; k ++)
                if ( p[k].x == j && p[k].y == i )
                {
                    idx = p[k].idx;
                    break;
                }
            
            if ( c.x == j && c.y == i )
                printf("|*");
            else if ( idx >= 0 )
                printf("|%d", idx);
            else
                printf("| ");
        }
        printf("|\n");
    }
    printf("  ");
    for ( j = 0 ; j <= max_x + 1 ; j ++ )
        printf("+-");
    printf("+\n");
    printf("  ");
    for ( j = 0 ; j <= max_x + 1 ; j ++ )
        printf("%2d", j);
    printf("\n");
}
void process( FILE *fp )
{
    char name[21]={0,};
    
    while ( fscanf(fp, "%s ", name ) == 1 && strcmp(name, "#" ) != 0 )
    {
        POINT center ;
        POINT points[1024];
        int nCoords = 0 ;
        
        int x, y ;
        int i;
        
        if ( fscanf(fp, "%d %d ", &x, &y) != 2 )
            return;
        center = POINT(x,y);
        
        for ( nCoords = 0 ; fscanf(fp, "%d %d ", &x, &y) == 2 && ( x || y ) ; nCoords ++)
            points[ nCoords ] = POINT(nCoords+1, x,y);
        
        //print_inputs(points, nCoords,center);
        
        qsort( (void *)(points), nCoords, sizeof(POINT), qsort_cmp );
                
        nCoords = convex_hull( points, nCoords );

//        printf("\n---------------------------------------------------------------\n");
//
//        for ( i = 0 ; i < nCoords ; i ++ )
//        {
//            printf("[%d] : (%lf,%lf)\n", points[i].idx, points[i].x, points[i].y );
//        }
//        
        
        int start, end ;
        int min_idx = -1;
        
        for ( start = 0 ; start < nCoords ; start ++)
        {
            double dot1 = POINT::dotProd( points[( start + nCoords ) % nCoords], points[( start + 1 + nCoords ) % nCoords], center );
            double dot2 = POINT::dotProd( points[( start + 1 + nCoords ) % nCoords], points[( start + nCoords ) % nCoords], center );
            
            if ( dot1 >= 0 && dot2 >= 0 )
            {
                int high_idx = -1 ;
                
                for ( i = 0 ; i < nCoords ; i ++ )
                {
                    double t=POINT::crossProd( points[( start + nCoords ) % nCoords], points[( start + 1 + nCoords ) % nCoords], points[i] ) ;
                    if ( t < 0 ) t *= -1;
                    if ( t < 1.0e-6 ) 
                    {
                        if ( high_idx < 0 || high_idx < points[ i ].idx )
                            high_idx = points[i].idx;
                        
                    }
                }
                
                if ( min_idx < 0 || high_idx < min_idx )
                {
//                    printf("Updated : point(%d), point(%d)\n", 
//                            points[ ( start + nCoords ) % nCoords ].idx, 
//                            points[ ( start + nCoords + 1 ) % nCoords ].idx
//                            );
                    min_idx = high_idx;
                }
            }
        }
        
        
        printf("%-20s%d\n", name, min_idx);
        
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