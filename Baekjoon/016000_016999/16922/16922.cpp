#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char D[2][1001]{};
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, n, ans  ;
    cin >> n ;
    D[1][0] = 1;
    for ( i = 0 ; i < n ; i ++ ) {
        memset(D[ i % 2 ], 0, sizeof(D[0]));

        for ( auto k : {1, 5, 10, 50})
            for ( j = 50*n ; j >=k ; j -- )
                if ( D[1 - (i%2)][j-k] )
                    D[(i%2)][j] = 1;
    }

    ans = 0 ;
    for ( i = 1 ; i <= 50*n ; i ++)
        ans += D[1 - (n%2)][i];
    cout << ans ;
    return 0;
}


