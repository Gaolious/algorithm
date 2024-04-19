#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = 500;

ll D[MaxN+2][MaxN+2];
ll S[MaxN+2][MaxN+2];
const int MOD = 1'000'000'007ll;

int main()
{
    fastio;
    int N, E;
    int n, e, i;

    cin >> N >> E;

    // cout << F(N, E) << '\n';

    D[1][0] = 1;

    for ( n = 2 ; n <= N ; n ++ ) {

        for ( e = 0 ; e <= N ; e ++ ) {
            D[n][e] = D[n-1][e-1] ;
            for ( i = 1 ; i <= n-2 ; i ++ ) {
                D[n][e] += D[i][e] * D[n-1-i][e] % MOD ;
                D[n][e] %= MOD;
            }
            for ( i = 1 ; i <= n-2 ; i ++ ) {
                D[n][e] += D[i][e] * (S[n-1-i][n-2] - S[n-1-i][e] + MOD) * 2ll % MOD ;
                D[n][e] %= MOD;
            }
        }

        for ( e = 0 ; e <= N ; e ++ ) {
            S[n][e] = (e==0 ? 0 : S[n][e-1]) + D[n][e];
            S[n][e] %= MOD;
        }
    }
    cout << D[N][E] << '\n';

    // for ( n = 0 ; n <= N ; n ++ ) {
    //     for ( e = 0 ; e <= E ; e ++ ) {
    //         cout << D[n][e] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}


