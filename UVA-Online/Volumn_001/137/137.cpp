// 137 - Polygons
// helpful site : GeoGebra - Free Online Geometry Tool
// https://www.math10.com/en/geometry/geogebra/geogebra.html

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1.0e-6
#define RADIAN_2_THETA (180.0L / M_PI)

struct vector2
{
    double x, y;
    vector2( double _x, double _y) : x(_x), y(_y){}
    vector2(){}
    
    double size() const { return sqrt( x*x + y*y ); }
    double dot( const vector2 &o ) const { return x * o.x +  y * o.y ; }
    double cross( const vector2 &o ) const { return x * o.y - y * o.x ; }
    double dist( const vector2 &o ) const { return sqrt( (x-o.x) * (x-o.x) + (y-o.y)*(y-o.y)) ; }
};
inline vector2 operator -( const vector2 &lhs, const vector2 &rhs )
{
    vector2 ret ;
    ret.x = lhs.x - rhs.x ;
    ret.y = lhs.y - rhs.y ;
    return ret;
}
inline bool operator ==( const vector2 &lhs, const vector2 &rhs )
{
    double x = lhs.x - rhs.x ;
    double y = lhs.y - rhs.y ;
    
    return ( fabs(x) < EPSILON && fabs(y) < EPSILON );
}
inline double dot( vector2 a, vector2 b )
{
    return a.dot(b);
}
inline double cross( vector2 a, vector2 b )
{
    return a.cross(b);
}
/// vector(a->b) , vector(a->c)
inline double cross( vector2 a, vector2 b, vector2 c )
{
    return cross( b-a, c-a);
}

// negative : b is clockwise of a
// positive : b is counter clockwise of a
inline int ccw( vector2 a, vector2 b, vector2 c )
{
    double r = cross( b-a, c-a);
    return r < 0 ? -1 : // right-side
            r > 0 ? 1 : // left-side
                0; // in-a-line
}
inline double Theta(vector2 a, vector2 b )
{
    return acos( dot(a,b) / ( a.size() * b.size() )) * RADIAN_2_THETA;
}
inline double Theta(vector2 a, vector2 b, vector2 c )
{
    return Theta( b-a, c-a ) ;
}

// line l1 : p1->p2, 
// line l2 : p3->p4
inline bool IsBetween( double v1, double v2, double v)
{
    return ( v1 < v2 ) ? ( v1 <= v && v <= v2 ): ( v2 <= v && v <= v1 );
}
double min(double a, double b) { return a < b ? a : b ; }
double max(double a, double b) { return a > b ? a : b ; }

bool IsEquationX( vector2 p1, vector2 p2)
{
    return ( fabs(p2.x-p1.x) < EPSILON ) ;
}
bool IsEquationY( vector2 p1, vector2 p2)
{
    return ( fabs(p2.y-p1.y) < EPSILON ) ;
}

bool GetX_byEquation( vector2 p1, vector2 p2 , double y, double &x)
{
    double a, b;
    if ( fabs(p2.x-p1.x) < EPSILON )
    {
        if ( y < p1.y && y < p2.y ) return false;
        if ( y > p1.y && y > p2.y ) return false;
        x = p1.x;
        return true;
    }
    else if ( fabs(p2.y-p1.y) < EPSILON )
    {
        return false;
    }
    else
    {
        a = ( p2.y - p1.y ) / ( p2.x - p1.x );
        b = p1.y -  p1.x * a;
        // y = a*x + b
        x = ( y - b) / a ;
        return true ;
    }

}
bool GetY_byEquation( vector2 p1, vector2 p2 , double x, double &y)
{
    double a, b;
    if ( fabs(p2.x-p1.x) < EPSILON )
    {
        return false;
    }
    else if ( fabs(p2.y-p1.y) < EPSILON )
    {
        if ( x < p1.x && x < p2.x ) return false;
        if ( x > p1.x && x > p2.x ) return false;
        y = p1.y;
        return true;
    }
    else
    {
        a = ( p2.y - p1.y ) / ( p2.x - p1.x );
        b = p1.y -  p1.x * a;
        y = a*x + b;
        return true ;
    }
}
inline bool intersection( vector2 p1, vector2 p2, vector2 p3, vector2 p4, vector2 &p)
{
    double a1, b1, a2, b2 ;
        
    double x, y ;
    if ( IsEquationX(p1,p2)) 
    {
        x = p1.x;
        if ( GetY_byEquation( p3, p4, x, y) == false ) 
            return false;
    }
    else if ( IsEquationY(p1,p2) ) 
    {
        y = p1.y;
        if ( GetX_byEquation( p3, p4, y, x) == false ) 
            return false;
    }
    else if ( IsEquationX(p3,p4) ) 
    {
        x = p3.x;
        if ( GetY_byEquation( p1, p2, x, y) == false ) 
            return false;
    }
    else if ( IsEquationY(p3,p4) )
    {
        y = p3.y;
        if ( GetX_byEquation( p1, p2, y, x) == false ) 
            return false;
    }
    else
    {
        a1 = fabs(p2.x-p1.x) < EPSILON ? 0.0 :  ( p2.y - p1.y ) / ( p2.x - p1.x );
        b1 = p1.y -  p1.x * a1;

        a2 = fabs(p4.x-p3.x) < EPSILON ? 0.0 :  ( p4.y - p3.y ) / ( p4.x - p3.x );
        b2 = p3.y -  p3.x * a2;
    
       if ( fabs(a1-a2) < EPSILON )
        {
            return false;
        }

        // a1x+b1 = a2*x+b2
        // x(a1-a2) = b2-b1
        x = (b2-b1) / (a1-a2);
        y = x * a1 + b1 ;
    }
    p.x = x;
    p.y = y;
        
    return IsBetween( p1.x, p2.x, x ) && 
            IsBetween( p3.x, p4.x, x ) &&
            IsBetween( p1.y, p2.y, y ) &&
            IsBetween( p3.y, p4.y, y )  ;
    
}

bool in_polygon( vector2 points[], int size, vector2 p)
{
    for ( int i = 1 ; i <= size; i ++)
    {
        double dir = ccw(points[(i-1) % size], points[i % size], p );
        if ( dir < 0 )
            return false;
    }
    return true;
}

int convex_hull( vector2 points[], int size)
{
    int i, j;

    for ( i = 1 ; i < size ; i ++ )
    {
        if ( points[ i - 1 ].dist( points[ i ] ) < EPSILON )
        {
            for ( j=i+1 ; j<size ; j++)
                points[j-1] = points[j];
            i--;
            size--;
        }
    }
    for ( i = 1 ; i < size; i ++)
    { 
        for ( j = i + 1 ; j < size ; j ++ )
        {
            double dir = ccw(points[i-1], points[i], points[j] );

            if ( dir > 0 )
            {
                continue;
            }
            else if ( dir < 0 )
            {
                vector2 t = points[ i ] ;
                points[ i ] = points[ j ] ;
                points[ j ] = t ;
                continue;
            }
            else
            {
                double d1 = points[i-1].dist( points[i] );
                double d2 = points[i-1].dist( points[j] );
                
                if ( d2 < d1 )
                {
                    vector2 t = points[ i ] ;
                    points[ i ] = points[ j ] ;
                    points[ j ] = t ;
                    continue;
                }
            }
        }

        if ( ccw(points[i-1], points[i], points[0] ) < 0 )
            return i;
    }
    return size;
}

int qsort_cmp( const void *a, const void *b)
{
    vector2 *p1 = (vector2 *)a;
    vector2 *p2 = (vector2 *)b;
    
    if ( p1->y < p2->y ) return -1;
    if ( p1->y > p2->y ) return 1;
    
    if ( p1->x < p2->x ) return -1;
    if ( p1->x > p2->x ) return 1;
    
    return 0;
}
void addPolygon( vector2 poly[], int &size, vector2 p)
{
    for ( int t = 0 ; t < size ; t ++ )
    if ( poly[ t ] == p )
        return ;
    poly[ size ++ ] = p;
}

double area( vector2 poly[], int poly_size)
{
    double sum = 0 ;
    
    for ( int i = 1 ; i < poly_size - 1 ; i ++ )
    {
        double s = cross( poly[0], poly[i], poly[ i+1 ] ) / 2.0;
        
        sum += fabs( s );
    }
    return sum;
}

void process(FILE *fp)
{    
    while ( !feof(fp) )
    {
        vector2 poly1[10000];
        vector2 poly2[10000];
        vector2 poly3[10000];
        int nPoly1, nPoly2, nPoly3;
        int i, j ;
        
        if ( fscanf(fp, "%d ", &nPoly1 ) != 1 || nPoly1 == 0 ) break;
        for ( i = 0 ; i < nPoly1 ; i ++)
            fscanf(fp, "%lf %lf ", &(poly1[i].x) , &(poly1[i].y) );

        if ( fscanf(fp, "%d ", &nPoly2 ) != 1 || nPoly2 == 0 ) break ;
        for ( i = 0 ; i < nPoly2 ; i ++)
            fscanf(fp, "%lf %lf ", &(poly2[i].x) , &(poly2[i].y) );

        qsort( (void *)(poly1), nPoly1, sizeof(vector2), qsort_cmp );
        nPoly1 = convex_hull(poly1, nPoly1);

        qsort( (void *)(poly2), nPoly2, sizeof(vector2), qsort_cmp );
        nPoly2 = convex_hull(poly2, nPoly2);
        
        nPoly3=0;
        double area1, area2 ;
        area1 = area( poly1, nPoly1);
        area2 = area( poly2, nPoly2);
        

        vector2 p;
        for ( i = 0 ; i <= nPoly1 ; i ++ )
        {
            for ( j = 0 ; j<=nPoly2 ; j ++ )
            if ( intersection( poly1[ (i+0) % nPoly1 ], poly1[ (i+1) % nPoly1 ], poly2[ (j+0) % nPoly2 ], poly2[ (j+1) % nPoly2 ], p ) )
                addPolygon( poly3, nPoly3, p );
        }        
        
        for ( i = 0 ; i < nPoly1 ; i ++ )
        if ( in_polygon( poly2, nPoly2, poly1[i] ) ) 
            addPolygon( poly3, nPoly3, poly1[i] );
        
        for ( i = 0 ; i < nPoly2 ; i ++ )
        if ( in_polygon( poly1, nPoly1, poly2[i] ) ) 
            addPolygon( poly3, nPoly3, poly2[i] );
        
        qsort( (void *)(poly3), nPoly3, sizeof(vector2), qsort_cmp );
        nPoly3 = convex_hull(poly3, nPoly3);

        printf("%8.2lf", area1 + area2 - area( poly3, nPoly3) * 2 );
    }
    printf("\n");
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
