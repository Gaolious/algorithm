#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process(int Case) {
    int i, j, k ;
    ll H, W, S;
    cin >> H >> W >> S;
    vector<vector<ll>> A(H+1, vector<ll>(W+1));
    for ( i = 1 ; i <= H ; i ++ ) {
        for ( j = 1 ; j <= W ; j ++ ) {
            cin >> A[i][j];
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }
    int ans = 0 ;
    for (i = 1; i <= H; i++) {
        for (j = 1; j <= W; j++) {
            for (k = 0; i + k <= H && j + k <= W; k++) {
                if ( A[i+k][j+k] - A[i-1][j+k] - A[i+k][j-1] + A[i-1][j-1] < S)
                    ans ++;
            }
        }
    }
    cout << ans ;
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
