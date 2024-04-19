#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const long double EPSILON = 1e-12;
const long double PI_LONG = acos(-1);
#define IS_ZERO(x) ( abs(x) < EPSILON )
typedef long long T;
// Point
struct Point {
    T x, y;
    Point(): x(0), y(0){}
    Point(T x, T y): x(x), y(y) {}
    T d2(const Point &p) {
        return (x-p.x) * (x-p.x) + (y-p.y)*(y-p.y);
    }
    long double dist(const Point &p) {
        return sqrt(d2(p));
    }
};
Point operator + (const Point &a, const Point &b) { return Point {a.x+b.x , a.y+b.y}; }
Point operator - (const Point &a, const Point &b) { return Point {a.x-b.x , a.y-b.y}; }
T operator * (const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; } // dot
T operator / (const Point &a, const Point &b) { return a.x*b.y - a.y*b.x; } // cross
Point operator * (const Point &a, T b) { return Point{a.x * b, a.y * b}; }
Point operator / (const Point &a, T b) { return Point{a.x / b, a.y / b}; }

istream &operator >> (istream &in, Point &p) { in >> p.x >> p.y ; return in;}
ostream &operator << (ostream &o, Point &p) { o << p.x << ' ' << p.y; return o; }

bool operator == (const Point &a, const Point &b) { return IS_ZERO(a.x-b.x) && IS_ZERO(a.y - b.y); }
bool operator < (const Point &a, const Point &b) { return IS_ZERO(a.y - b.y) ? a.x < b.x : a.y < b.y; }
bool operator <= (const Point &a, const Point &b) { return (a==b) || (IS_ZERO(a.y - b.y) ? a.x < b.x : a.y < b.y); }
bool operator > (const Point &a, const Point &b) { return !(b<=a); }
bool operator >= (const Point &a, const Point &b) { return !(b<a); }

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
        long double d = (e - s) / (o.e - o.s);
        if ( abs(d) < EPSILON) return false;
        p = s + (e - s) * ( (o.s - s) / (o.e - o.s) / d ) ;
        return true;
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
    Point &p(int idx) {
        return ch[ idx % ch.size() ];
    }
    pair<Point, Point> rotate_calipers() {
        long double ret = p(0).dist(p(1));
        int idx1 = 0, idx2 = 1;
        for ( int i = 0, j = 0, k = 1 ; i < 2*ch.size() ; i ++ ) {
            switch ( ccw( p(j+1) - p(j),  p(k) - p(k+1)) ) {
                case -1: k++; break;
                case 1: j++; break;
                case 0: j++; k++; break;
            }

            auto d = p(j).dist(p(k));
            if ( d > ret ) {
                idx1 = j, idx2 = k ;
                ret = d ;
            }
        }
        return {p(idx1), p(idx2)};
    }
};

int main()
{
    fastio;
    int T ;

    int C ;
    cin >> T ;
    while ( T-- ) {
        ConvexHull H;

        cin >> C ;

        vector<Point> P(C);

        for (auto &p: P) cin >> p;

        H.build(P, false);

        long double ret = H.p(0).dist(H.p(1));
        int idx1 = 0, idx2 = 1;

        Point p0(0,0);
        for ( int i = 0, j = 0, k = 1 ; i < 2*H.ch.size() ; i ++ ) {
            switch ( ccw( H.p(j+1) - H.p(j),  H.p(k) - H.p(k+1)) ) {
                case -1:
                    k++;
                break;
                case 1:
                    j++;
                break;
                case 0:
                    j++;
                    k++;
                break;
            }

            auto d = H.p(j).dist(H.p(k));
            if ( d > ret ) {
                idx1 = j, idx2 = k ;
                ret = d ;
            }
        }
        // cout << setprecision(0) << ret;
        cout << H.p(idx1) << ' ' << H.p(idx2) << '\n';
    }
    return 0;
}


