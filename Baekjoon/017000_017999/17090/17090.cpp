#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char A[502][502];
char Visited[502][502];

int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
int Y, X;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, d, ty, tx ;
    char c;

    cin >> Y >> X ;
    for ( i = 1 ; i <= Y ; i ++ ) {
        for ( j = 1 ; j <= X ; j ++  ) {
            cin >> c;
            if ( c == 'D' ) A[i][j] = 1;
            else if ( c == 'U' ) A[i][j] = 3;
            else if ( c == 'L' ) A[i][j] = 2;
            else if ( c == 'R' ) A[i][j] = 0;
        }
    }
    queue< pair<int, int> > Q;
    for ( i = 1 ; i <= Y ; i ++ ) {
        Q.emplace(i, 0);
        Q.emplace(i, X+1);
    }
    for ( i = 1 ; i <= X ; i ++ ) {
        Q.emplace(0, i);
        Q.emplace(Y+1, i);
    }

    int ans = 0;

    while ( !Q.empty() ) {
        auto [y, x] = Q.front();
        Q.pop();
        for ( d = 0 ;d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 1 || ty > Y || tx < 1 || tx > X ) continue;
            if ( Visited[ty][tx] ) continue;
            if ( ( d - A[ty][tx] + 4 ) % 4 != 2) continue;
            Visited[ty][tx] = 1;
            ans ++;
            Q.emplace(ty, tx);
        }
    }
    cout << ans << '\n';
    return 0;
}


