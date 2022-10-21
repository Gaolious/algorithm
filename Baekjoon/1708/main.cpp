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
    Vector2D a1 = a - c ;
    Vector2D b1 = b - c ;
    return ccw2(a1, b1);
}

void process() {
    fastio;
    vector<Vector2D<ll>> P;
    vector<int> convexIdx ;
    int N ;

    cin >> N ;
    P.resize(N);
    for (auto &a: P) cin >> a.x >> a.y ;
    std::sort(P.begin(), P.end());
    convexIdx.push_back(0);
    convexIdx.push_back(1);

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


