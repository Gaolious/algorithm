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
    Vector2D a1 = a - c ;
    Vector2D b1 = b - c ;
    return ccw2(a1, b1);
}

template <typename T>
struct Line {
    Vector2D<T> s, e ;
    bool is_cross(Line& other ) {
        int r1 = ccw3( s, e, other.s );
        int r2 = ccw3( s, e, other.e );
        int r3 = ccw3( other.s, other.e, s );
        int r4 = ccw3( other.s, other.e, e );

        if ( min(s.x, e.x) > max(other.s.x, other.e.x) ) return false ;
        if ( min(s.y, e.y) > max(other.s.y, other.e.y) ) return false ;

        if ( max(s.x, e.x) < min(other.s.x, other.e.x) ) return false ;
        if ( max(s.y, e.y) < min(other.s.y, other.e.y) ) return false ;

        return ( r1 * r2 <= 0 && r3*r4 <= 0);
    }
};

void process() {
    fastio;
    Line<ll> a, b ;
    cin >> a.s.x >> a.s.y >> a.e.x >> a.e.y;
    cin >> b.s.x >> b.s.y >> b.e.x >> b.e.y;

    if ( a.is_cross(b) )
        cout << "1\n";
    else
        cout << "0\n";
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


