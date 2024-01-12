#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Point {
    int x, y;
};
struct Data {
    int idx;
    Point p;
};
bool operator < (const Point &a, const Point &b) { return (a.x != b.x) ? a.x < b.x : a.y < b.y; }
bool operator < (const Data &a, const Data &b) { return a.p < b.p; }
bool operator == (const Point &a, const Point &b) { return a.x == b.x && a.y < b.y; }
Point operator - (const Point &a, const Point &b) {
    return Point {a.x-b.x , a.y-b.y};
}

int operator / (const Point &a, const Point &b) { return a.x*b.y - a.y*b.x; }

int ccw(const Point &a, const Point &b) {
    int ret = a / b;
    return (ret>0) - (ret<0); // Left:-1, Right:1
}

int ccw(const Data &a, const Data &b, const Data &c) {
    return ccw(b.p-a.p, c.p-a.p);
}
int ccw(const Point &a, const Point &b, const Point &c) {
    return ccw(b-a, c-a);
}
int dist(const Point &a, const Point b) {
    Point c = a - b;
    return c.x*c.x + c.y*c.y;
}
int dist(const Data &a, const Data b) {
    return dist(a.p, b.p);
}
int main()
{
    fastio;
    int T, N, i;
    cin >> T;
    while ( T-- ) {
        cin >> N ;
        vector<Data> D(N);
        for ( i = 0 ; i < N ; i ++ ) {
            D[i].idx = i;
            cin >> D[i].p.x >> D[i].p.y ;
        }

        sort(D.begin(), D.end(), [](Data &a, Data &b) {
            return a < b;
        });

        sort(D.begin()+1, D.end(), [&](Data &a, Data &b) {
            int ret = ccw(D[0], a, b);
            if (ret) return ret == 1;
            return dist(D[0], a) < dist(D[0], b);
        });
        for ( i = D.size() - 1 ; i > 0 ; ) {
            if ( ccw(D[0], D[i], D[i-1]) == 0) i--;
            else break;
        }
        reverse(D.begin() + i, D.end());
        for ( auto &p: D )
            cout << p.idx << ' ' ;
        cout << '\n';
    }
    return 0;
}


