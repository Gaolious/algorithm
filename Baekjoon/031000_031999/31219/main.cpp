#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;


typedef int T;
struct Point {
    T x, y;
    Point(): x(0), y(0){}
    Point(T x, T y): x(x), y(y) {}
    T d2(const Point &p) {
        T a = x - p.x, b = y - p.y  ;
        return a*a + b*b;
    }
    long double dist(const Point &p) {
        return sqrt(d2(p));
    }
    friend istream &operator >> (istream &in, Point &p) { in >> p.x >> p.y ; return in;}
};
int main() {
    int N;
    int last, i, a, b, mask;
    int prev, curr;

    long double DIST[10][10]{0};

    vector<Point> P;
    fastio;
    cin >> N ;
    P.resize(N);
    for (auto &p: P) cin >> p;
    for ( a = 0 ; a < N ; a ++ )
        for ( b = a+1 ; b < N ; b ++)
            DIST[a][b] = DIST[b][a] = P[a].dist(P[b]);

    vector<vector<long double>> D(N, vector<long double>(1<<10, 1e12));

    D[0][0] = 0;
    last = 1 << N;
    for ( mask = 0 ; mask < last ; mask ++ ) {
        for ( prev = 0 ; prev < N ; prev ++ ) {
            for ( curr = 0 ; curr < N ; curr ++) {
                if ( 1 & (mask >> curr) ) continue;
                i =  mask ^ (1<<curr);
                D[ curr ][ i ] = min(D[ curr ][ i ], DIST[prev][curr] + D[prev][mask] );
            }
        }
    }
    cout << fixed << setprecision(12) << D[0][ (1<<N) - 1] << '\n';
}