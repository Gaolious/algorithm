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

ll D[40][40];
void process() {
    int i, j;
    int R, C, W, ans;

    D[0][1] = 1;
    for ( i = 0 ; i < 40 ; i ++ ) {
        D[i][1] = 1;
        for ( j = 1 ; j <= i ; j ++ ) {
            D[i][j] = D[i-1][j-1] + D[i-1][j];
        }
    }
//    for ( i = 0 ; i < 10 ; i ++ ) {
//        for ( j = 0 ; j <= i ; j ++ )
//            cout << D[ i ][ j ] << ' ';
//        cout << '\n';
//    }
    cin >> R >> C >> W;
    ans = 0 ;
    for ( i = R ; i < R+W ; i ++ ) {
        for ( j = 0 ; j <= i-R ; j ++ ) {
//            cout << "i : " << i << ", j : " << j << '\n';
            ans += D[ i ][ C+j ] ;
        }
    }
    cout << ans << '\n';
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


