#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char B[201][201];
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, M ;
    int ans = 0;
    int i, j, k, a, b;

    cin >> N >> M ;
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b ;
        B[a][b] = B[b][a] = 1;
    }

    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = i+1 ; j <= N ; j ++ ) {
            if ( B[i][j] ) continue;
            for ( k = j+1 ; k <= N ; k ++ ) {
                if ( B[i][k] ) continue;
                if ( B[j][k] ) continue;
                ans ++;
            }
        }
    }
    cout << ans ;
    return 0;
}


