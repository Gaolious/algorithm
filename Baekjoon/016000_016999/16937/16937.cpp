#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[100][2];
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int W, H, N;
    int i, j, k, m, ans;

    cin >> H >> W >> N ;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[i][0] >> A[i][1];

    ans = 0;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = i + 1 ; j < N ; j ++ )
            for ( k = 0 ; k < 2 ; k ++ )
                for ( m = 0 ; m < 2 ; m ++ ) {
                    if ( max(A[i][k], A[j][m]) <= W && A[i][1-k] + A[j][1-m] <= H )
                        ans = max(ans, A[i][0]*A[i][1] + A[j][0]*A[j][1]);
                    if ( A[i][k] + A[j][m] <= W && max( A[i][1-k], A[j][1-m]) <= H )
                        ans = max(ans, A[i][0]*A[i][1] + A[j][0]*A[j][1]);
                }
    cout << ans;

    return 0;
}


