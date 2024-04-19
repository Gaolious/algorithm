#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 100 ;
int A[ MaxN + 2 ][ MaxN + 2 ];

int main()
{
    fastio;
    int N, M ;
    int x, y, c ;
    int i, j ;

    cin >> N >> M ;

    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= M ; j ++ )
            cin >> A[i][j] ;

    int cnt = 0 ;

    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= M ; j ++ ) {
            if ( A[i][j] < 1) continue;
            cnt += 2 ;
            cnt += max(0, A[i][j] - A[i][j+1]);
            cnt += max(0, A[i][j] - A[i+1][j]);
            cnt += max(0, A[i][j] - A[i][j-1]);
            cnt += max(0, A[i][j] - A[i-1][j]);
        }
    }
    cout << cnt ;
    return 0;
}


