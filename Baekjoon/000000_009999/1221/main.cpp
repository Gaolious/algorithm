#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
struct Point {
    ll x, y, z;
    ll dot() {
        return x*x + y*y + z*z;
    }
};
bool operator < (const Point &a, const Point &b) {
    if ( a.x != b.x ) return a.x < b.x;
    return ( a.y != b.y ) ? a.y < b.y : a.z < b.z;
}
bool operator == (const Point &a, const Point &b) { return a.x == b.x && a.y == b.y && a.z == b.z;}
Point operator - (const Point &a, const Point &b) { return {b.x-a.x, b.y-a.y, b.z-a.z};}
istream &operator >> (istream &in, Point &a) { in >> a.x >> a.y >> a.z ; return in; }
ostream &operator << (ostream &out, Point &a) { out << a.x << ' ' << a.y << ' '<< a.z ; return out; }
ll dist(const Point &a, const Point &b) { return (a-b).dot(); }

const ll MAXN = 1'000'000;
#define SQUARE(x) ( (x) * (x) )

int main()
{
    fastio;
    int N ;
    cin >> N ;

    vector<Point> P(N);

    for (auto &p: P) cin >> p ;
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());

    // for (auto &p: P) cout << p << '\n';
    if ( N <= 1 ) {
        cout << "1\n1";
        return 0;
    }
    ll min_dist = 9 * MAXN * MAXN * MAXN;
    ll cnt = 0;
    map<ll, map<ll, map<ll, ll>>> Map ;


    ll D ;
    int i, j;

    for( j = i = 0 ; i < P.size() ; i ++ ) {
        ll bound_x = (ll)sqrt(min_dist)+2;
        for ( ; j < i && SQUARE(P[i].x - P[j].x) > min_dist; j ++ ) {
            Map[ P[j].x ][ P[j].y ].erase(P[j].z);
            if ( Map[P[j].x][ P[j].y ].empty()) Map[ P[j].x].erase( P[j].y );
            if ( Map[P[j].x].empty()) Map.erase( P[j].x );
        }

        auto sx = Map.lower_bound(P[i].x - bound_x);
        auto ex = Map.upper_bound(P[i].x + bound_x);

        for ( auto xp = sx ; xp != Map.end() && xp != ex ; xp++ ) {
            ll dist_x = SQUARE(xp->first - P[i].x);
            ll bound_y = (ll)sqrt(min_dist - dist_x )+2;

            auto sy = xp->second.lower_bound(P[i].y - bound_y);
            auto ey = xp->second.upper_bound(P[i].y + bound_y);

            for (auto yp = sy ; yp != xp->second.end() && yp != ey ; yp ++ ) {
                ll dist_y = SQUARE(yp->first - P[i].y);
                ll bound_z = (ll)sqrt(min_dist - dist_x - dist_y )+2;

                auto sz = yp->second.lower_bound(P[i].z - bound_z);
                auto ez = yp->second.upper_bound(P[i].z + bound_z);

                for (auto zp = sz ; zp != yp->second.end() && zp != ez ; zp ++ ) {
                    ll dist_z = SQUARE(zp->first - P[i].z);
                    ll d = dist_x + dist_y + dist_z;
                    if ( d < min_dist ) {
                        min_dist = d;
                        cnt = 1;
                    }
                    else if ( d == min_dist ) {
                        cnt ++;
                    }
                }
            }

        }
        Map[ P[i].x ][ P[i].y ][ P[i].z ] = 1;
    }

    cout << min_dist << '\n' << cnt << '\n';
    return 0;
}


