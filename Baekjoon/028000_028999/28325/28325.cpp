#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MAXN (250'000)
//#define MAXN (25)

ll C[MAXN];
ll D[2][MAXN];
int N ;

int main()
{
    fastio;
    int i ;
    ll prev, ret = 0 ;
    cin >> N ;
    for( i = 0 ; i < N ; i ++ ) cin >> C[ i ] ;

    D[0][0] = 1; // live in
    D[1][0] = 0; // not

    for ( i = 1 ; i < N ; i ++ ) {
        D[0][i] = D[1][i-1] + 1;
        D[1][i] = max( D[1][i-1], D[0][i-1]) + C[i];
    }
    ret = D[1][N-1];


    memset(D, 0, sizeof(D));
    D[0][0] = 0; // live in
    D[1][0] = C[0]; // not

    for ( i = 1 ; i < N ; i ++ ) {
        D[0][i] = D[1][i-1] + 1;
        D[1][i] = max( D[1][i-1], D[0][i-1]) + C[i];
    }
    ret = max(ret, max(D[0][N-1], D[1][N-1]));
    cout << ret;
    return 0;
}


