#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int X[10001];
int Y[10001];
int Z[10001];
struct Point {
    int x, y, z;
    Point(): x(0), y(0), z(0){}
    Point(int x, int y, int z): x(x), y(y), z(z){}
};
istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y >> p.z;
    return in;
}
int main()
{
    fastio;
    Point s, e;
    int N, i, j ;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++) {
        cin >> s >> e ;
        for ( j=s.x ; j< e.x ; j ++) X[j] ++;
        for ( j=s.y ; j< e.y ; j ++) Y[j] ++;
        for ( j=s.z ; j< e.z ; j ++) Z[j] ++;
    }
    int x=0, y=0, z=0;
    for ( i = 0 ; i <= 10000 ; i ++) x += X[i] ==N ? 1 : 0;
    for ( i = 0 ; i <= 10000 ; i ++) y += Y[i] ==N ? 1 : 0;
    for ( i = 0 ; i <= 10000 ; i ++) z += Z[i] ==N ? 1 : 0;
    cout << x * y * z << '\n';
    return 0;
}


