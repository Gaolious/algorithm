#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[200'001][26];
char S[200'001];

int main()
{
    fastio;
    int L, N ;
    int s, e, i, j, ans ;
    char c ;

    cin >> S ;
    L = strlen(S);
    for ( i = 0 ; i < L ; i ++) {
        for ( j = 0 ; i > 0 && j < 26 ; j ++ )
            A[i][j] = A[i-1][j];
        A[i][ S[i] - 'a' ] ++;
    }

    cin >> N ;
    while ( N -- ) {
        cin >> c >> s >> e ;

        ans = A[e][c-'a'];
        if (s > 0)
            ans -= A[s-1][c-'a'];
        cout << ans << '\n';
    }
    return 0;
}


