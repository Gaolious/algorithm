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

void process() {
    int A[7]{}, B[7]{};
    int i, n;
    double win = 0.0, lose = 0.0, draw, p1, p2;
    for ( i = 0 ; i < 6 ; i ++ ) { cin >> n ; A[n]++; }
    for ( i = 0 ; i < 6 ; i ++ ) { cin >> n ; B[n]++; }
    for ( i = 1 ; i <= 6 ; i ++ ) {
        A[i] += A[i-1];
        B[i] += B[i-1];
    }

    for ( i = 2 ; i <= 6 ; i ++ ) {
        p1 = (double)(A[i] - A[i-1])/6.0 ;
        p2 = (double)(B[i-1])/6.0 ;
        win += p1 * p2 ;
    }

    for ( i = 2 ; i <= 6 ; i ++ ) {
        p1 = (double)(B[i] - B[i-1])/6.0 ;
        p2 = (double)(A[i-1])/6.0 ;
        lose += p1 * p2 ;
    }
    draw = 1.0 - (win + lose);

    double ans = win / (1.0-draw);
    // P = win + draw * win + draw^2 * win + draw^3 * win + ...
    //   = win + draw ( win + draw * win + draw^2 * win + ... )
    //   = win + draw ( P )
    // P - draw*P = win
    // P = win / (1-draw)

    cout << setprecision(5) << fixed << ans << '\n';
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


