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
    T dist(const Point &p) {
        return (x-p.x) * (x-p.x) + (y-p.y)*(y-p.y);
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

long long area(Point &a, Point &b, Point &c) {
    return abs((a-c) / (b-c));
}
vector<Point> P;

struct Data {
    int idx1, idx2;
    ll x, y;
    ll d ;
    bool operator < (const Data &b) const {
        if (d != b.d ) return d < b.d ;
        if (x != b.x ) return x < b.x ;
        return y < b.y;
    }

    friend ostream &operator << (ostream &o, Data &ot) {
        o << P[ot.idx1] << ", " << P[ot.idx2];
        return o;
    }
};

int main()
{
    fastio;
    int N ;
    int i, j ;
    int len ;

    cin >> N ;
    vector<Data> M;
    P.resize(N);
    for (auto &p : P) cin >> p;

    for ( i = 0 ; i < P.size() ; i ++ )
        for ( j = i + 1 ; j < P.size() ; j ++ ) {
            M.push_back({i, j, P[i].x+P[j].x, P[i].y + P[j].y, P[i].dist(P[j])});
        }

    sort(M.begin(), M.end());

    ll ret = 0, s1, s2, s3, s4;

    for ( i = 0, j = 1 ; i < M.size() ; i ++ ) {
        for (j = i+1; j < M.size() && M[i].d == M[j].d && M[i].x == M[j].x && M[i].y == M[j].y; j ++ ) {
            s1 = area(P[ M[j].idx1 ], P[M[j].idx2], P[M[i].idx2]);
            if ( s1 > ret ) {
//                cout << M[i] << ' ' << s1 << '\n';
            }
            ret = max(ret, s1);
        }
    }
    cout << ret << '\n';
    return 0;
}


