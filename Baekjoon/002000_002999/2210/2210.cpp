#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[5][5];
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
bitset<1000000> D;
int T[] = { 0, 10, 100, 1000, 10000, 100000, 1000000};

void F(int y, int x, int depth, int score) {
    int ty, tx;

    if ( depth >= 5 ) {
        D.set(score);
        return;
    }
    for ( int d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || tx < 0 || ty >= 5 || tx >= 5 ) continue;
        F(ty, tx, depth+1, score * 10 + A[ty][tx]);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 5 ; j ++ )
            cin >> A[ i ][ j ] ;

    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 5 ; j ++ )
            F(i, j, 0, A[i][j]);

    cout << D.count();

    return 0;
}


