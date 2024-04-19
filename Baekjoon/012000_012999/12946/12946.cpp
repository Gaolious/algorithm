#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 50 ;

int dy[] = {-1, -1, 0, 1, 1, 0};
int dx[] = {0, 1, 1, 0, -1, -1};
char Color[MaxN+1][MaxN+1]{};
int N;
vector<string> A;
int ans = 0 ;

void F(int y, int x) {
    int ty, tx, d, c ;
    if (ans >= 3 )
        return ;

    c = 0;
    for ( d = 0 ; d < 6 ; d++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || tx < 0 || ty >= N || tx >= N )
            continue;
        c |= Color[ty][tx] ;
    }
    if ( c == 3 ) {
        ans = max(ans, 3);
        return ;
    }
    else if ( c == 2 ) {
        Color[y][x] = 1;
        ans = max(ans, 2);
    }
    else if ( c == 1 ) {
        Color[y][x] = 2;
        ans = max(ans, 2);
    }
    else {
        Color[y][x] = 1;
        ans = max(ans, 1);
    }

    for ( d = 0 ; d < 6 && ans < 3; d++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || tx < 0 || ty >= N || tx >= N )
            continue;
        if ( Color[ty][tx] == 0 && A[ty][tx] == 'X')
            F(ty, tx);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;

    cin >> N ;
    A.resize(N);
    for (auto &a : A) cin >> a;

    ans = 0;

    for ( int i = 0 ; i < N && ans < 3 ; i ++ )
        for ( int j = 0 ; j < N && ans < 3 ; j ++ )
            if ( Color[i][j] == 0 && A[i][j] == 'X' )
                F(i, j);
    cout << ans << "\n";
    return 0;
}


