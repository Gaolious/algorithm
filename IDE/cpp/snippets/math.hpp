
namespace Math
{
    class Point 
    {
    public : 
        double x, y ;

        double dist(Point &p)
        {
            double x = p.x - this->x ;
            double y = p.y - this->y ;
            return sqrt( x*x + y*y );
        }
        double dot(Point &p) 
        {
            return p.x * this->x + p.y * this->y ;
        }
        double cross(Point &p) 
        {
            return this->x * p.y - p.x * this->y;
        }

        Point operator - (Point &p)
        {
            Point ret ;
            ret.x = this->x - p.x ;
            ret.y = this->y - p.y ;
            return ret;
        }
        Point operator = (const Point &p)
        {
            this->x = p.x ;
            this->y = p.y ;
        }

        double area(Point &a, Point &b)
        {
            Point p1, p2 ;
            p1 = a - *this;
            p2 = b - *this ;
            return fabs(p1.cross(p2)) / 2.0 ;
        }
        double angle_sin(Point &left, Point &right)
        {
            double S = this->area(left, right);
            return asin(2.0 * S / this->dist(left) / this->dist(right));
        }
        double angle_cos(Point &left, Point &right)
        {
            //         p1
            //         o 
            //        /A\
            //    c  /   \  b
            //      /     \  
            //     /B     C\
            //    o---------o
            //  p2     a     p3
            //      
            // c = cosA * b + cosB * a 
            // a = cosB * c + cosC * b
            // b = cosA * c + cosC * a

            // c^2 = cosA * b * c + cosB * a * c   (1)
            // a^2 = cosB * c * a + cosC * b * a   (2)
            // b^2 = cosA * b * c + cosC * b * a   (3)
            // (1)-(2)-(3) 
            // => c^2 - a^2 - b^2 = -2 * cosC * b * a
            //        a^2 + b^2 - c^2
            // cosC = ---------------------
            //            2 * b * a
            double a, b, c ;
            b = this->dist(left);
            c = this->dist(right);
            a = left.dist(right);

            return acos((b*b + c*c - a*a) / ( 2.0 * b * c )) ;
        }

        static double circumcicleR(double a, double b, double c, double area)
        {
            // circumcircle Radius
            //         p1
            //         o 
            //        /A\
            //    c  /   \  b
            //      /  o  \  
            //     /B     C\
            //    o---------o
            //  p2     a     p3

            // angle A (p2-p1-p3) x 2 = angle A'(p2-o-p3)
            // sin(A) = (a/2) / (R)
            // S = sin(A) * b * c / 2 = a*b*c / (4*R)
            // R = (a*b*c)/(4*S)
            return (a*b*c) / ( 4.0 * area) ;
        }
        static double incircleR(double a, double b, double c, double area)
        {
            // incircle Radius
            //         p1
            //         o 
            //        /A\
            //    c  /   \  b
            //      /  o  \  
            //     /B     C\
            //    o---------o
            //  p2     a     p3
            // area = 1/2 * r * (a+b+c)
            return area * 2 / (a+b+c) ;
        }
    };
};



// void process()
// {
//     Math::Point p1, p2, p3 ;
//     scanf("%lf %lf ", &p1.x, &p1.y );
//     scanf("%lf %lf ", &p2.x, &p2.y );
//     scanf("%lf %lf ", &p3.x, &p3.y );


//     double a = p2.dist(p3);
//     double b = p3.dist(p1);
//     double c = p1.dist(p2);
//     double S = p1.area(p2, p3);
//     double R = Math::Point::circumcicleR( a, b, c, S);

//     double A = p1.angle_cos(p2, p3 ) * 2.0;
//     double B = p2.angle_cos(p1, p3 ) * 2.0;
//     double C = p3.angle_cos(p1, p2 ) * 2.0;

//     double g = Util::gcd(A, Util::gcd(B,C));
//     double n = 2.0 * M_PI / g ;

//     printf("%.12lf\n", n * R * R * sin(g) / 2.0);
// }
