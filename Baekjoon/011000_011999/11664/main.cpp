#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;
const long double PI = acos(-1);

using namespace std;
struct Point {
    long double x, y, z;
    Point(): x(0), y(0), z(0) {}
    Point(long double x, long double y, long double z): x(x), y(y), z(z) {}

    Point operator - (Point o) const {return {x-o.x, y-o.y, z-o.z};}
    Point operator + (Point o) const {return {x+o.x, y+o.y, z+o.z};}
    Point operator / (long double n) const {return {x/n, y/n, z/n};}
    Point operator * (long double n) const {return {x*n, y*n, z*n};}
    long double size() const { return sqrt( x*x + y*y + z*z); }

    long double dist(Point o) const { return (*this - o).size(); }
    Point cross(Point o) {
        return {
            y*o.z - z*o.y,
            z*o.x - x*o.z,
            x*o.y - y*o.x,
        };
    }
    long double inner(Point o) {
        return x*o.x + y*o.y + z*o.z;
    }
    Point normalize() {
        auto s = size();
        if ( s > 0 )
            return {x/s, y/s, z/s};
        else
            return {x,y,z};
    }
};
int sign(long double v) {
    if ( v < 0 ) return -1;
    if ( v > 0 ) return 1;
    return 0;
}
long double area(Point a, Point b, Point c) {
    Point p1 = b - a;
    Point p2 = c - a;
    return p1.cross(p2).size() / 2.0 ;
}
istream & operator >> (istream &in, Point &p) {
    in >> p.x >> p.y >> p.z ;
    return in;
}
void process1() {

    Point l, r, c, m;
    cin >> l >> r >> c ;
    long double ld= l.dist(c), rd = r.dist(c), md;
    long double ret = min(ld, rd);

    for ( int i = 0 ; i < 1000000 ; i ++ ) {
        m = (l+r)/2.0l;
        md = m.dist(c);
        ret = min(ret, md);
        if ( ld < rd ) {
            rd = md;
            r = m;
        } else {
            ld = md;
            l = m;
        }
    }
    cout << setprecision(16) << ret << '\n';
}
void process2() {
    Point a, b, c;
    cin >> a >> b >> c ;

    Point AB = b-a;
    Point BA = a-b;
    Point AC = c-a;
    Point BC = c-b;

    /*
     *
     *              C
     *             +
     *
     *
     *
     *  +----------------------+
     * A           p            B
     *    p = AB.inner(AC)
     */
    auto inner_ab_ac = AB.inner(AC);
    auto inner_ab_bc = AB.inner(BC);

    if ( sign(inner_ab_ac) * sign(inner_ab_bc) <= 0 ) {
        Point AB2 = AB.cross(AC) / AB.size();
        cout << setprecision(16) << AB2.size();
    }
    else {
        cout << setprecision(16) << min( a.dist(c), b.dist(c) );
    }
}
int main()
{
    fastio;
    // process1();  # 8.774964387392122
    process2();
    return 0;
}


