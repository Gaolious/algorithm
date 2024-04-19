#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = ( 1 << 15 );
int A[15];
int N, L, R, X;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    int i, j, mx, mn, s;

    cin >> N >> L >> R >> X;


    for ( i = 0 ; i < N ; i ++ )
        cin >> A[i];

    int ans = 0 ;
    for ( i = (1<<N) - 1 ; i > 0 ; i -- ) {
        mn = 10000000, mx = 0, s = 0;
        for ( j = 0 ; j < N ; j ++ ) {
            if ( i & ( 1 << j ) ) {
                mn = min(mn, A[j] );
                mx = max(mx, A[j] );
                s += A[j];
            }
        }
        if ( mx - mn >= X && L <= s && s <= R ) ans ++;
    }
    cout << ans ;
    return 0;
}


