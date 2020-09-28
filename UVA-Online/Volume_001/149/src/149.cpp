#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON  (1.0e-6)
#define PI (3.14159265)
#define R2T( A ) ( (A) * 57.295779513 )
#define T2R( A ) ( (A) * 0.01745329252 )

const double DEGREE_01 = 0.01 * PI / 180;

typedef struct _pt 
{
    double x, y;
} P ;
typedef struct _pt_list_
{
    double x, y;
    double dist ;
    double min_angle;
    double max_angle;
    unsigned char is_visible ;
} PT_LIST ;

void getAngle( P *p, double r, double *ret_dist, double *ret_rad_1, double *ret_rad_2)
{
    double x = p->x ;
    double y = p->y ;
    double c2 = (x*x + y*y) ;
    double c = sqrt(c2);
    double r2 = r*r ;
    double a2 = c2 - r2 ;
    double angle = asin( r / c );
    double rad_1 = atan2( y, x );

    *ret_rad_1 = rad_1 - angle + PI;
    *ret_rad_2 = rad_1 + angle + PI;
    
    *ret_dist = c ;
}

void getPointsWithCircle( P *p, P *c, double r, double *ret_dist, double *ret_rad_1, double *ret_rad_2)
{
    P p1 ;
    int x = (int)(c->x);
    int y = (int)(c->y);

    p1.x = p->x - c->x ;
    p1.y = p->y - c->y ;

    getAngle( &p1, r, ret_dist, ret_rad_1, ret_rad_2);

    p1.x = p->x + c->x ;
    p1.y = p->y + c->y ;
}

int comp( const void *_a, const void *_b)
{
    PT_LIST *a = (PT_LIST *)_a;
    PT_LIST *b = (PT_LIST *)_b;

    if ( a->dist > b->dist )
        return 1;
    if ( a->dist < b->dist )
        return -1;

    if ( a->max_angle > b->max_angle ) 
        return 1;

    if ( a->min_angle < b->min_angle ) 
        return -1;


    return 0;
}


int comp2( const void *_a, const void *_b)
{
    PT_LIST *a = (PT_LIST *)_a;
    PT_LIST *b = (PT_LIST *)_b;

    if ( a->max_angle > b->max_angle ) 
        return 1;

    if ( a->min_angle < b->min_angle ) 
        return -1;


    return 0;
}

int is_inside(PT_LIST *a, PT_LIST *b)
{
    if ( a->min_angle >= b->min_angle && b->min_angle >= a->max_angle )
        return 1;
    if ( a->min_angle <= b->min_angle && b->min_angle <= a->max_angle )
        return 1;

        
    if ( a->min_angle >= b->max_angle && b->max_angle >= a->max_angle )
        return 1;
    if ( a->min_angle <= b->max_angle && b->max_angle <= a->max_angle )
        return 1;

    return 0;
}

int angle_diff( double a1, double b1, double offset )
{
    double val = fabs( a1 - b1 ) ;

    val = val > 2*PI - val ? 2*PI - val : val ;

    return ( val < offset );
}

int is_beside(PT_LIST *a, PT_LIST *b, double offset)
{
    double v ;
    if ( angle_diff(a->min_angle, b->min_angle, offset) )
        return 1;
    if ( angle_diff(a->min_angle, b->max_angle, offset) )
        return 1;
    if ( angle_diff(a->max_angle, b->min_angle, offset) )
        return 1;
    if ( angle_diff(a->max_angle, b->max_angle, offset) )
        return 1;
    return 0;
}

void process(FILE *fp)
{
    double diameter, x, y;
    double radius ;

    P observer ;
    
    while ( fscanf(fp, "%lf %lf %lf ", &diameter, &(observer.x), &(observer.y) ) == 3 )
    {
        PT_LIST points[ 41 * 41 ] = { 0, } ;
        int nPoints = 0 ;

        if ( fabs(diameter) < EPSILON && fabs(observer.x) < EPSILON && fabs(observer.y) < EPSILON )
            break;

        radius = diameter / 2.0L ;
        
        for ( y = -20 ; y < 20 ; y ++ )
        for ( x = -20 ; x < 20 ; x ++ )
        {
            double rad1, rad2, dist;
            P c = { x, y };
            getPointsWithCircle( &observer, &c, radius, &dist, &rad1, &rad2 );

            if ( angle_diff(rad1, rad2, DEGREE_01 ) ) 
                continue ;
            // printf("(%g, %g) : %lf , (%lf, %lf)\n", x, y, fabs(rad1 - rad2), rad1, rad2);

            points[ nPoints ].x = x ;
            points[ nPoints ].y = y ;
            points[ nPoints ].dist = dist ;
            points[ nPoints ].min_angle = rad1 ;
            points[ nPoints ].max_angle = rad2 ;
            points[ nPoints ].is_visible = 1 ;
            
            nPoints ++;
            
            // printf("P(%.3lf, %.3lf) - C(%.3lf, %.3lf, %.3lf)\n", 
            //     observer.x, observer.y, 
            //     c.x, c.y, radius
            // );
            // printf(" => rad1: %.3lf(%.3lf)\n", rad1, R2T(rad1) );
            // printf(" => rad2: %.3lf(%.3lf)\n", rad2, R2T(rad2) );
        }

        // qsort(points, nPoints, sizeof(PT_LIST), comp2);

        // for ( int i = 0 ; i < nPoints ; i ++)
        //     printf("(%+3g, %+3g) : D(%6.2lf), Min(%6.5lf), Max(%6.5lf), Min(%6.5lf), Max(%6.5lf)\n", 
        //         points[i].x, 
        //         points[i].y, 
        //         points[i].dist, 
        //         points[i].min_angle, 
        //         points[i].max_angle,
        //         R2T(points[i].min_angle), 
        //         R2T(points[i].max_angle)
        //     );
        // printf("Observer : (%6.2lf, %6.2lf)\n", observer.x, observer.y);
        qsort(points, nPoints, sizeof(PT_LIST), comp);
        // for ( int i = 0 ; i < nPoints ; i ++)
        //     printf("inserted[%4d] (%3g, %3g) : D(%6.2lf), Min(%6.5lf), Max(%6.5lf), Min(%6.5lf), Max(%6.5lf)\n", 
        //         i,
        //         points[i].x, 
        //         points[i].y, 
        //         points[i].dist, 
        //         points[i].min_angle, 
        //         points[i].max_angle,
        //         R2T(points[i].min_angle), 
        //         R2T(points[i].max_angle)
        //     );

        int i, j;

        for ( i = 1 ; i < nPoints; i ++ )
        {
            int included = 0;
            for ( j = 0 ; j < i ; j ++)
            {
                if ( is_inside(points + j, points + i ) || is_beside( points + j, points + i, DEGREE_01) ) 
                {
                    // printf("(%g,%g)|(%lf,%lf) is delete the (%g,%g)|(%lf,%lf)\n", 
                    //     points[j].x, points[j].y, points[j].min_angle, points[j].max_angle,
                    //     points[i].x, points[i].y, points[i].min_angle, points[i].max_angle
                    // );
                    included = 1;
                    break;
                }
            }

            if ( included )
                points[i].is_visible = 0;
        }

        
        // qsort(points, nPoints, sizeof(PT_LIST), comp2);

        int cnt = 0 ;
        for ( int i = 0 ; i < nPoints ; i ++)
        if ( points[ i ].is_visible )
        {
                // printf("finally (%3g, %3g) : D(%6.2lf), Min(%6.5lf), Max(%6.5lf), Min(%6.5lf), Max(%6.5lf)\n", 
                //     points[i].x, 
                //     points[i].y, 
                //     points[i].dist, 
                //     points[i].min_angle, 
                //     points[i].max_angle,
                //     R2T(points[i].min_angle), 
                //     R2T(points[i].max_angle)
                // );
                cnt ++;
        }
        printf("%d\n", cnt);

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