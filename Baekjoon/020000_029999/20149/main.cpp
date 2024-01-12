#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const long double EPSILON = 1e-12;
const long double PI_LONG = acos(-1);
#define IS_ZERO(x) ( abs(x) < EPSILON )
typedef long double T;
// Point
struct Point {
    T x, y;
    Point(): x(0), y(0){}
    Point(T x, T y): x(x), y(y) {}
    T dist(const Point &p) {
        T ret = (x-p.x) * (x-p.x) + (y-p.y)*(y-p.y);
        return sqrt(ret);
    }
};
Point operator + (const Point &a, const Point &b) { return Point {a.x+b.x , a.y+b.y}; }
Point operator - (const Point &a, const Point &b) { return Point {a.x-b.x , a.y-b.y}; }
T operator * (const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; } // dot
T operator / (const Point &a, const Point &b) { return a.x*b.y - a.y*b.x; } // cross
Point operator * (const Point &a, T b) { return Point{a.x * b, a.y * b}; }
Point operator / (const Point &a, T b) { return Point{a.x / b, a.y / b}; }

bool operator == (const Point &a, const Point &b) { return IS_ZERO(a.x-b.x) && IS_ZERO(a.y - b.y); }
bool operator < (const Point &a, const Point &b) { return IS_ZERO(a.y - b.y) ? a.x < b.x : a.y < b.y; }
bool operator <= (const Point &a, const Point &b) { return (a==b) || (IS_ZERO(a.y - b.y) ? a.x < b.x : a.y < b.y); }
bool operator > (const Point &a, const Point &b) { return !(a<=b); }
bool operator >= (const Point &a, const Point &b) { return !(a<b); }

int ccw(const Point &a, const Point &b) {
    long double ret = a / b;
    return (ret>0) - (ret<0); // Left:-1, Right:1
}

int ccw(const Point &a, const Point &b, const Point &c) {
    return ccw(a-c, b-c);
}

long double area(Point &a, Point &b, Point &c) {
    long double ret = (a-c) / (b-c);
    return abs(ret) / 2.0;
}

// Line
struct Line {
    Point s, e;
    Line(Point &a, Point &b): s(a), e(b) { if ( s > e ) swap(s, e); }
    T dist( Point &p ) { return abs( (s-e) / (p-e) ) / s.dist(e); }
    bool is_cross(const Line& o) {
        int a = ccw( s, e, o.s ) * ccw( s, e, o.e );
        int b = ccw( o.s, o.e, s ) * ccw( o.s, o.e, e );
        return ( a == 0 && b == 0 ) ? o.s <= e && s <= o.e : a <= 0 && b <= 0 ;
    }
    bool is_cross(const Line &o, Point &p) {
        if ( !is_cross(o) ) return false;

        T dx1 = e.x - s.x, dy1 = e.y - s.y ;
        T dx2 = o.e.x - o.s.x, dy2 = o.e.y - o.s.y ;
        if (dx1 == dx2 && dy1 == dy2 ) {
            T x = min( max(s.x, e.x), max(o.s.x, o.e.x)) - max( min(s.x, e.x), min(o.s.x, o.e.x));
            T y = min( max(s.y, e.y), max(o.s.y, o.e.y)) - max( min(s.y, e.y), min(o.s.y, o.e.y));
            if ( x > 0 || y > 0 ) return false ;
            if ( s == o.s || s == o.e )
                p.x = s.x, p.y = s.y;
            else
                p.x = e.x, p.y = e.y;
            return true;
        }

        auto px = (s.x * e.y - s.y * e.x) * (o.s.x - o.e.x) - (s.x - e.x) * (o.s.x * o.e.y - o.s.y * o.e.x);
        auto py = (s.x * e.y - s.y * e.x) * (o.s.y - o.e.y) - (s.y - e.y) * (o.s.x * o.e.y - o.s.y * o.e.x);
        auto t  = (s.x - e.x) * (o.s.y - o.e.y) - (s.y - e.y) * (o.s.x - o.e.x);

        p.x = (double)px / (double)t;
        p.y = (double)py / (double)t;

        // long double d = (e - s) / (o.e - o.s);
        // if ( abs(d) < EPSILON) return false;
        // p = s + (e - s) * ( (o.s - s) / (o.e - o.s) / d ) ;
        // return true;
    }
    T dx() { return e.x - s.x; }
    T dy() { return e.y - s.y; }
    T det() { return s.x * e.y - s.y * e.x ; }
};

struct ConvexHull {
    vector<Point> ch;
    void build(vector<Point> &A, bool remove_line) {
        ch.clear();

        if ( A.size() < 2 ) {
            for (auto p:A) ch.push_back(p);
            return ;
        }

        sort(A.begin(), A.end(), [](Point &a, Point &b) {
            return a < b;
        });
        sort(A.begin()+1, A.end(), [&](Point &a, Point &b) {
            int ret = ccw(A[0], a, b);
            if (ret) return ret == 1;
            return a < b;
        });
        ch = { A[0], A[1] };

        for (int i = 2; i < A.size(); i++) {
            while ( ch.size() >= 2) {
                int dir = ccw(ch[ch.size()-2], ch.back(), A[i]);
                if ( dir < 0 || (remove_line && dir == 0)) {
                    ch.pop_back();
                    continue;
                }
                break;
            }
            ch.push_back(A[i]);
        }
    }
    T area() const {
        T ret = 0 ;
        int i, j;
        for ( j = i = 0 ; i < ch.size() ; i ++ ) {
            j = (j+1) % ch.size();
            ret += ch[i] / ch[j];
        }
        return abs(ret) / 2.0;
    }
    bool contain (const Point &p) {
        int len = ch.size() ;
        int dir = ccw(ch[0], ch[1], p);
        for( int i = 1 ; i < len ; i ++ ) {
            if ( dir * ccw(ch[i], ch[ (i+1) % len ], p) <= 0 )
                return false;
        }
        return true;
    }
    size_t size() const { return ch.size() ; }
};

int main()
{
    fastio;
    Point s1, e1, s2, e2, p;
    cin >> s1.x >> s1.y >> e1.x >> e1.y ;
    cin >> s2.x >> s2.y >> e2.x >> e2.y ;
    Line a(s1, e1), b(s2, e2);
    if ( a.is_cross(b) ) {
        cout << "1\n";
        if ( a.is_cross(b, p) )
            cout << fixed << setprecision(10) << p.x << ' ' << p.y << '\n';
    }
    else
        cout << "0\n";
    return 0;
}


