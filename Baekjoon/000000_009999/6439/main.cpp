#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
template <typename T>
struct Vector2D {
    T x, y ;
    T cross(Vector2D &other) {
        return x * other.y - y * other.x;
    }
    Vector2D operator -(Vector2D &other ) {
        Vector2D ret = Vector2D{ x - other.x, y - other.y};
        return ret;
    }
    bool operator ==(Vector2D &other ) { return ( x == other.x && y == other.y ); }
    bool operator <(Vector2D &other ) {
        return y == other.y ? x < other.x : y < other.y ;
    }
    bool operator <=(Vector2D &other ) {
        return y == other.y ? x <= other.x : y <= other.y ;
    }
    bool operator > (Vector2D &other ) {
        return y == other.y ? x > other.x : y > other.y ;
    }
    bool operator >= (Vector2D &other ) {
        return y == other.y ? x >= other.x : y >= other.y ;
    }
};
template <typename T>
int ccw2(Vector2D<T> &a, Vector2D<T> &b) {
    T ret = a.cross(b);
    if ( ret < 0 ) return -1;
    else if ( ret > 0 ) return 1;
    else return 0;
}
template <typename T>
int ccw3(Vector2D<T> &a, Vector2D<T> &b, Vector2D<T> &c) {
    Vector2D a1 = a - c;
    Vector2D b1 = b - c;
    return ccw2(a1, b1);
}

template <typename T>
struct Line {
    Vector2D<T> s, e ;
    Line(T x1, T y1, T x2, T y2) {
        s.x = x1, s.y = y1 ;
        e.x = x2, e.y = y2 ;
        if ( s > e ) swap(s, e);
    }
    bool is_cross(Line& other) {
        int a = ccw3( s, e, other.s ) * ccw3( s, e, other.e );
        int b = ccw3( other.s, other.e, s ) * ccw3( other.s, other.e, e );
        if ( a == 0 && b == 0 ) {
            if ( s > e ) swap(s,e);
            if (other.s > other.e) swap(other.s, other.e);
            return other.s <= e && s <= other.e ;
        }
        return a <= 0 && b <= 0 ;
    }
    T dx() { return s.x - e.x ; }
    T dy() { return s.y - e.y ; }
    T det() { return s.x * e.y - s.y * e.x ; }
};
template <typename T>
struct Rect {
    Vector2D<T> s, e ;
    Rect(T sx, T sy, T ex, T ey) {
        s.x = min(sx, ex), s.y = min(sy, ey) ;
        e.x = max(sx, ex), e.y = max(sy, ey) ;
    }
    bool is_inside(Vector2D<T> p) {
        vector<Vector2D<T>> lines = {
                Vector2D<T> {s.x, s.y},
                Vector2D<T> {e.x, s.y},
                Vector2D<T> {e.x, e.y},
                Vector2D<T> {s.x, e.y},
                Vector2D<T> {s.x, s.y},
        };
        int i ;
        for ( i = 0 ; i < 4 ; i ++ ) {
            if ( ccw3( lines[i], lines[i+1], p) < 0 )
                return false;
        }
        return true ;
    }
    bool is_cross( Line<T> &line ) {
        if (is_inside(line.s) || is_inside(line.e) )
            return true ;
        vector<Line<T>> lines = {
                {s.x, s.y, e.x, s.y},
                {e.x, s.y, e.x, e.y},
                {e.x, e.y, s.x, e.y},
                {s.x, e.y, s.x, s.y},
        };
        for ( auto &r: lines ) {
            if (r.is_cross(line)) return true ;
        }
        return false;
    }
    T dx() { return s.x - e.x ; }
    T dy() { return s.y - e.y ; }
    T det() { return s.x * e.y - s.y * e.x ; }
};
void process() {
    fastio;
    int T ;
    int sx, sy, ex, ey;
    cin >> T ;
    while ( T -- ) {
        cin >> sx >> sy >> ex >> ey ;
        Line<int> line(sx, sy, ex, ey) ;

        cin >> sx >> sy >> ex >> ey ;
        Rect<int> rect(sx, sy, ex, ey);
        if ( rect.is_cross(line) )
            cout << "T\n";
        else
            cout << "F\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


