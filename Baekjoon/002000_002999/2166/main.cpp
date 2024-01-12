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
T ccw2(Vector2D<T> &a, Vector2D<T> &b) {
    return a.cross(b);
//    T ret = a.cross(b);
//    if ( ret < 0 ) return ret;
//    else if ( ret > 0 ) return 1;
//    else return 0;
}
template <typename T>
T ccw3(Vector2D<T> &a, Vector2D<T> &b, Vector2D<T> &c) {
    Vector2D a1 = a - c ;
    Vector2D b1 = b - c ;
    return ccw2(a1, b1);
}

void process() {
    fastio;
    int N, i ;
    ll area = 0, t ;
    cin >> N ;
    vector< Vector2D<ll> > P(N);
    for (auto &[x, y]: P)
        cin >> x >> y ;

    for ( i = 1 ; i < N - 1 ; i ++  )
        area += ccw3(P[0], P[i], P[i+1]);

    area = abs(area);
    cout << area/2 << '.' << (area&1 ? 5 : 0 ) << endl;
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


