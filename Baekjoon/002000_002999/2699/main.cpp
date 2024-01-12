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
struct Line {
    Point p1, p2;
    Line(Point &a, Point &b): p1(a), p2(b){}

    double dist( Point &other ) {
        Point a = p1 - p2 ;
        Point b = other - p2;
        return abs(a.cross(b)) / p1.dist(p2);
    }

} ;

typedef struct {
    Point sx, sy, ex, ey;
} Rect;

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

vector<Point> convex_hull(vector<Point> A, bool remove_line = false) {

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

int main()
{
    fastio;
    int P, i;
    cin >> P ;
    while ( P -- ) {
        int N ;
        cin >> N ;
        vector<Point> A(N);
        for (auto &p: A) cin >> p.x >> p.y ;

        auto ch = convex_hull(A, true);
        int sp = 0;
        for ( i = 1 ; i < ch.size() ; i ++ ) {
            if ( ch[i].y > ch[sp].y || ( !(ch[i].y < ch[sp].y) && ch[i].x < ch[sp].x )) {
                sp = i;
            }
        }

        cout << ch.size() << '\n';
        for ( i = sp ; ;  ) {
            cout << ch[i].x << ' ' << ch[i].y << '\n';
            i = ( i + ch.size() - 1) % ch.size();
            if ( i == sp ) break;
        }
    }
    return 0;
}


