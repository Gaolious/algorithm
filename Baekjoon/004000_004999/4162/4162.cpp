#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

#define P2(x) ( (x)*(x) )
#define PM2(a, b) ( ( (a) + (b) ) * ( (a) - (b) ) )

struct Data {
    long double x, y, r;
    long double dist(Data &o) {
        long double xx = (x-o.x)*(x-o.x);
        long double yy = (y-o.y)*(y-o.y);
        return sqrt(xx+yy);
    }
};
vector<bool> Visit;
vector<Data> A;
long double sy = 1000.0, ey = 1000.0;
bool ans = true;

void F(int curr) {
    if ( Visit[curr] || !ans ) return;
    Visit[curr] = true;
    for ( int i = 0 ; i < A.size() ; i ++ )
        if ( A[curr].dist(A[i]) < A[curr].r + A[i].r )
            F(i);
    if ( A[curr].y - A[curr].r < 0 ) {
        ans = false;
        return;
    }
    if ( A[curr].x - A[curr].r < 0.0l )
        sy = min(sy, A[curr].y - sqrt( PM2(A[curr].r, A[curr].x) ) );
    if ( A[curr].x + A[curr].r > 1000.0l )
        ey = min(ey, A[curr].y - sqrt( PM2(A[curr].r, 1000.0l - A[curr].x) ) );
}
void process() {
    int N, i;
    cin >> N ;

    A.resize(N);
    Visit.resize(N);

    for (auto &[x,y,r] : A) cin >> x >> y >> r ;

    for ( i = 0 ; i < N ; i ++ ) {
        if ( A[i].y + A[i].r > 1000.0 )
            F(i);
    }
    if ( ans ) {
        cout << setprecision(2) << fixed;
        cout << 0.0 << ' ' << sy << ' ' << 1000.0 << ' ' << ey << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


