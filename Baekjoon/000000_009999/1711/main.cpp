#include <bits/stdc++.h>
#include <unordered_map>

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
template <typename T> T GCD( T a, T b ) {
    return b > 0 ? GCD(b, a % b) : a;
}

struct Point {
    ll x, y;
    bool operator == (const Point& p) const {
        return y == p.y && x == p.x ;
    }
    bool operator < (const Point& p) const {
        return y == p.y ? x < p.x : y < p.y;
    }
};
void process() {
    fastio;
    int N ;
    int i, j ;
    ll x, y;
    vector<Point> P ;
    Point p;
    int ret ;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> x >> y ;
        P.push_back(Point{x, y});
    }
    ret = 0 ;
    for ( i = 0 ; i < N ; i ++ ) {
        map<Point, int> cache;
        for ( j = 0 ; j < N ; j ++ ) {
            if ( i == j ) continue;
            p = Point{ P[j].x - P[i].x, P[j].y - P[i].y };
            ll g = GCD(abs(p.x), abs(p.y) );
            p.x /= g, p.y/= g;
            cache[p]++;
        }
        for (auto a: cache) {
            p = Point{ -a.first.y, a.first.x};
            ret += cache[p] * a.second;
        }
    }
    cout << ret << endl;
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


