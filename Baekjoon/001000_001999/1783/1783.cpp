#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 2, 1, -1, -2};
int dx[] = { 1, 2, 2, 1};
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

vector<vector<int>> A;
int bestMove = -1;

void dump() {
    for ( int i = 0 ; i < Y ; i ++ ) {
        for ( int j = 0 ; j < X ; j ++ )
            cout << setw(2) << A[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
int ans (int y, int x ) {
    if ( y == 1 ) return 1;
    if ( y == 2 ) {
        if ( X <= 2 ) return 1;
        if ( X <= 4 ) return 2;
        if ( X <= 6 ) return 3;
        return 4;
    }
    if ( X <= 4 ) return X;
    if ( X <= 5 ) return 4;
    return X-2;
}
void dfs(int y, int x, int mask, int step) {
    int ty, tx;
    if ( step >= 5 && mask != 0xf ) return;
    bestMove = max(step, bestMove);

    for ( int d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( !valid(ty,tx) ) continue;
        dfs(ty, tx, mask | (1<<d) , step+1);
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> Y >> X ;
    cout << ans(Y, X) << '\n';
    return 0;
    // for ( Y = 1 ; Y <= 15 ; Y ++ ) {
    //     for( X = 1 ; X <= 15 ; X ++ ) {
    //         bestMove = -1;
    //         dfs(0, 0, 0, 1);
    //         if ( bestMove != ans(Y,X) )
    //             cout << "Y=" << Y << ", X=" << X << " : " << bestMove << " - " << ans(Y, X) << '\n';
    //
    //     }
    // }
    // return 0;
}


