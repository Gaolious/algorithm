#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const double EPSILON = 1e-9;
const double PI_LONG = acos(-1);
struct Point {
    double x, y;
    Point(): x(0), y(0){}
    Point(double x, double y): x(x), y(y) {}

    double cross(Point &other) const { return x * other.y - y * other.x; }
    double dot(Point &other) const { return x * other.x + y * other.y; }
    double dist(Point &other) const { auto t = *this - other ; return sqrt(t.x * t.x + t.y * t.y); }

    double angle_rad(Point &other) {
        Point p = other - *this ;
        return atan2 (p.y, p.x);
    }
    double angle_deg(Point &other) {
        return angle_rad(other) * 180.0 / PI_LONG;
    }
    Point operator - (Point &other ) const { return Point{ x - other.x, y - other.y}; }

    bool operator == (Point &other ) const { return abs(x-other.x) < EPSILON && abs(y - other.y ) < EPSILON; }

    bool operator < (Point &other ) const { return abs(y-other.y) < EPSILON ? x < other.x : y < other.y ; }
    bool operator > (Point &other ) const { return abs(y-other.y) < EPSILON ? x > other.x : y > other.y ; }

    bool operator >= (Point &other ) const { return !( *this < other ); }
    bool operator <=(Point &other ) const { return !( *this > other ); }


} ;

int ccw(Point &a, Point &b) {
    double ret = a.cross(b);
    if ( ret < 0 ) return -1; // L
    if ( ret > 0 ) return 1; // R
    return 0;
}
int ccw(Point &a, Point &b, Point &c) {
    Point x = a - c, y = b - c;
    return ccw(x, y);
}


struct Line {
    Point s, e;
    Line(Point &a, Point &b) {
        s = a, e = b;
        if ( s > e )
            swap(s, e);
    }
    double dist( Point &other ) {
        Point a = s - e ;
        Point b = other - e;
        return abs(a.cross(b)) / s.dist(e);
    }
    bool is_cross(Line& other) {
        int a = ccw( s, e, other.s ) * ccw( s, e, other.e );
        int b = ccw( other.s, other.e, s ) * ccw( other.s, other.e, e );
        if ( a == 0 && b == 0 ) {
            // if ( s > e ) swap(s,e);
            // if (other.s > other.e) swap(other.s, other.e);
            return other.s <= e && s <= other.e ;
        }
        return a <= 0 && b <= 0 ;
    }
} ;

vector<Point> convex_hull(vector<Point> &A, bool remove_line = false) {
    if ( A.size() <= 2 ) return A;

    sort(A.begin(), A.end(), [](Point &a, Point &b) {
        return a < b;
    });
    sort(A.begin()+1, A.end(), [&](Point &a, Point &b) {
        int ret = ccw(A[0], a, b);
        if (ret) return ret == 1;
        return a < b;
    });
    vector<Point> ret = { A[0], A[1] };
    int len ;

    for (int i = 2; i < A.size(); i++) {
        while ( (len = ret.size()) >= 2) {
            auto &a = ret[len-2], &b = ret[len-1], &c = A[i];
            int dir = ccw(a, b, c);
            if ( dir < 0 ) {
                ret.pop_back();
                continue;
            }
            if ( remove_line && dir == 0 ) {
                ret.pop_back();
                continue;
            }
            break;
        }
        ret.push_back(A[i]);
    }
    return ret;
}
bool inside_point(vector<Point> &A, Point &p) {
    int len = A.size() ;
    int dir = ccw(A[0], A[1], p);
    for( int i = 1 ; i < len ; i ++ ) {
        if ( dir * ccw(A[i], A[ (i+1) % len ], p) <= 0 )
            return false;
    }
    return true;
}

typedef struct {
    Point sx, sy, ex, ey;
} Rect;


int main()
{
    fastio;
    int T ;
    int N, M ;
    int i, j ;

    cin >> T ;
    while ( T -- ) {
        cin >> N >> M ;

        vector<Point> White(M), Black(N);
        for (auto &p: Black) cin >> p.x >> p.y ;
        for (auto &p: White) cin >> p.x >> p.y ;

        auto ch_white = convex_hull(White, true);
        auto ch_black = convex_hull(Black, true);
        bool possible = true ;

        if ( ch_black.size() > 2 ) {
            for (auto &p : ch_white) {
                if ( inside_point(ch_black, p) )
                    possible = false;
            }
        }
        if ( ch_white.size() > 2 ) {
            for (auto &p : ch_black) {
                if ( inside_point(ch_white, p) )
                    possible = false;
            }
        }

        for ( i = 0 ; i < ch_white.size() && possible ; i ++ ) {
            Line w( ch_white[i], ch_white[ (i+1)%ch_white.size()]);
            for ( j = 0 ; j < ch_black.size() && possible ; j ++ ) {
                Line b( ch_black[j], ch_black[ (j+1)%ch_black.size()]);

                if ( w.is_cross(b) )
                    possible = false ;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}


