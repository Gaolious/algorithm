#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
ll flip(ll a, ll N) { return N - a - 1; }
pll rotate(pll a, ll N, int cnt) {
    if ( cnt % 4 == 1 ) return {a.second, flip(a.first, N)};
    else if ( cnt % 4 == 2 ) return {flip(a.first, N), flip(a.second, N)};
    else if ( cnt % 4 == 3 ) return {flip(a.second, N), a.first};
    else if ( cnt % 4 == 0 ) return a;
}
long double run(const int N) {
    int M, r;
    cin >> M ;
    long double ret = -1.0;
    pll p1, p2;

    vector<pll> A(M);
    for (auto &[y,x] : A) cin >> y >> x ;

    for (r = 0 ; r < 3 ; r ++ ) {
        for (bool flipX : { false, true }) {
            for ( bool flipY: {false, true }) {
                long double avg = 0.0l;
                for (auto &[y, x]: A) {
                    p1 = { (y-1)/N, (y-1)%N };
                    p2 = { (x-1)/N, (x-1)%N };
                    p2 = rotate(p2 ,N, r+1);

                    if ( flipX ) p2.second = flip(p2.second, N);
                    if ( flipY ) p2.first = flip(p2.first, N);

                    avg += 1 + abs(p1.first - p2.first) + abs(p1.second - p2.second);
                }
                avg /= M ;
                if ( ret < 0 || ret > avg ) ret = avg;
            }
        }
    }
    return ret;
}
void process() {
    int N;
    int i ;
    for ( i = 1 ; cin >> N && N ; i ++) {
        if ( i > 1 ) cout << '\n';
        cout << "Scenario " << i << ": smallest average = " << setprecision(4) << fixed << run(N) << "\n";
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


