#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

// 0 : -
// 1 : U
// 2 : U U
// 3 : D
// 4 : D D
ll D[101][10][5];
const ll MOD = 1000000007;

int main()
{
    fastio;
    int i, j, k  ;
    int N ;

    cin >> N ;

    for ( i = 0 ; i < 10 ; i ++)
        D[1][i][0] = 1;

    for ( i = 2 ; i <= N ; i ++ ) {
        for ( j = 0 ; j < 10 ; j ++ ) {

            if ( j > 0 ){
                D[i][j][1] += (D[i-1][ j-1 ][3] + D[i-1][ j-1 ][4] + D[i-1][ j-1 ][0]) % MOD;
                D[i][j][2] += D[i-1][ j-1 ][1] % MOD;
            }
            if ( j < 9 ){
                D[i][j][3] += (D[i-1][ j+1 ][2] + D[i-1][ j+1 ][1] + D[i-1][ j+1 ][0]) % MOD;
                D[i][j][4] += D[i-1][ j+1 ][3] % MOD;
            }
        }
    }

    ll ans = 0;

    for ( i = 0 ; i < 10 ; i ++)
        for ( j = 0 ; j < 5 ; j ++)
            ans = ( ans + D[N][i][j] ) % MOD ;

    cout << ans ;

    return 0;
}


