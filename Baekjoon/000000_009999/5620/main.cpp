#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

using Point = pair<int, int> ;
#define X first
#define Y second
const ll INF = 10000000000;

vector<Point> P ;

ll dist(Point a, Point b) {
    ll x = (a.X - b.X);
    ll y = (a.Y - b.Y);
    return x*x + y*y;
}
ll dist(int a, int b) {
    ll t = (a-b);
    return t*t;
}
void unique( vector<int> &p ) {
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
}
int main()
{
    fastio;
    int N, i, j ;
    ll ans;
    ll ans2;
    vector<int> px, py, *axis;

    cin >> N ;
    P.resize(N);

    for(auto &a: P)
    {
        cin >> a.X >> a.Y ;
        px.push_back(a.X);
        py.push_back(a.Y);
    }
    unique(px);
    unique(py);

    vector<vector<int>> points;

    if (px.size() < py.size())
    {
        std::sort(P.begin(), P.end(), [&](Point a, Point b) { return a.X < b.X ; });
        points.resize(px.size());
        i = 0;
        for (auto &p: P ) {
            while (i < px.size() && p.X != px[i]) i ++;
            points[i].push_back(p.Y);
        }
        axis = &px;
    }
    else {
        std::sort(P.begin(), P.end(), [&](Point a, Point b) { return a.Y < b.Y ; });
        points.resize(py.size());
        i = 0;
        for (auto &p: P ) {
            while (i < py.size() && p.Y != py[i]) i ++;
            points[i].push_back(p.X);
        }
        axis = &py;
    }

    ans = dist(P[0], P[1]);
    for ( i = 0 ; i < points.size() ; i ++ )
    {
        unique(points[i]);
        for ( j = 1 ; j < points[i].size() ; j ++ )
            ans = min(ans, dist(points[i][j-1], points[i][j]));
    }

    int x1, x2, y1, y2;

    for (i = 0 ; i < (*axis).size() - 1 ; i ++ ) {
        y1 = (*axis)[i];

        for ( j = i + 1 ; j < (*axis).size() ; j ++ ) {
            y2 = (*axis)[j];

            if ( dist( y1, y2) >= ans ) break;

            for ( auto p : points[i])
            {
                x1 = p ;
                ans2 = sqrt(ans) + 1;
                auto lb = std::lower_bound(points[j].begin(), points[j].end(), x1 - ans2 );
                auto ub = std::upper_bound(points[j].begin(), points[j].end(), x1 + ans2 );

                for ( auto k= lb ; k != ub ; k ++ ) {
                    x2 = *k ;
                    auto t = dist(Point{ x1, y1}, Point{ x2, y2});
                    if ( t < ans )
                    {
                        ans = t;
//                        cout << "(" << x1 << ", " << y1 << ") - "
//                             << "(" << x2 << ", " << y2 << ") : " << ans << "\n";
                    }

                }
            }

        }
    }
    cout << ans  << '\n';
//
//    ans = INF;
//
//    for ( i = 0 ; i < P.size() ; i ++ ) {
//        for ( j = 0 ; j < P.size() ; j ++ ) {
//            if ( i != j ) {
//                auto t = dist(P[i], P[j]);
//                if (t < ans) {
//                    ans = t;
//                    if (ans <= 633602) {
//                        x1 = P[i].X;
//                        y1 = P[i].Y;
//                        x2 = P[j].X;
//                        y2 = P[j].Y;
//
//                        cout << "(" << x1 << ", " << y1 << ") - "
//                             << "(" << x2 << ", " << y2 << ") : " << ans << "\n";
//                    }
//                }
//            }
//        }
//    }
}


