#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int, int> pii;

char A[50][50];
int Y, X;
int D[4][50][50];
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
const int INF = 100000000;

void bfs(pii s, int prev_dir) {
    int ty, tx, d;
    queue<pair<pii, int>> Q;

    for (d = 0 ; d < 4 ; d ++ )
        for ( ty = 0 ; ty < Y ; ty ++ )
            for ( tx = 0 ; tx < X ; tx ++ )
                D[d][ty][tx] = INF;

    Q.emplace(s, prev_dir);
    D[prev_dir][s.first][s.second] = 0;
    while (!Q.empty()) {
        auto [p, prevDir ]= Q.front();
        auto [y, x] = p;
        Q.pop();
        for ( d = 0 ; d < 4 ; d ++ ) {
            if ( prevDir == d ) continue;

            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;
            if ( A[ty][tx] == '#' ) continue;

            if ( D[d][ty][tx] > D[prevDir][y][x] + 1 ) {
                D[d][ty][tx] = D[prevDir][y][x] + 1 ;
                Q.push({{ty, tx}, d});
            }
        }
    }

    // for (d = 0 ; d < 4 ; d ++ ) {
    //     cout << "Prev = " << prev_dir << " / D=" << d << '\n';
    //     for ( ty = 0 ; ty < Y ; ty ++ ) {
    //         for ( tx = 0 ; tx < X ; tx ++ ) {
    //             if ( D[d][ty][tx] >= INF )
    //                 cout << setw(2) << " . ";
    //             else
    //                 cout << setw(2) << D[d][ty][tx] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

}
int getDiff(pii s, pii e) {
    return abs(s.first - e.first) + abs(s.second + e.second);
}

int F(pii s, pii m, pii e) {
    int i, j ;
    int sm[4] ={ INF, INF, INF, INF};
    int se[4] ={ INF, INF, INF, INF};
    int me[4][4]{};
    int em[4][4]{};

    for ( i = 0 ; i <4 ; i ++ )
        for ( j = 0; j < 4 ; j ++ )
            me[i][j] = em[i][j] = INF;

    for ( i = 0 ; i <4 ; i ++ ) {
        bfs(s, i);
        for ( j = 0; j < 4 ; j ++ )
            sm[ j ] = min( sm[j], D[j][m.first][m.second] );
        for ( j = 0; j < 4 ; j ++ )
            se[ j ] = min( se[j], D[j][e.first][e.second] );
    }
    for ( i = 0 ; i <4 ; i ++ ) {
        bfs(m, i);
        for ( j = 0; j < 4 ; j ++ )
            me[ i ][ j ] = min( me[ i ][j], D[j][e.first][e.second] );
    }

    for ( i = 0 ; i <4 ; i ++ ) {
        bfs(e, i);
        for ( j = 0; j < 4 ; j ++ )
            em[ i ][ j ] = min( em[ i ][j], D[j][m.first][m.second] );
    }

    // s -> m -> e
    int ans = INF;
    int d = getDiff(m, e);
    for ( i = 0 ; i <4 ; i ++ ) {
        for ( j = 0; j < 4 ; j ++ ) {
            if ( d == 1 && i == j ) continue;
            ans = min( ans, sm[i] + me[i][j] );
        }
    }
    d = getDiff(e, m);
    for ( i = 0 ; i <4 ; i ++ ) {
        for ( j = 0; j < 4 ; j ++ ) {
            if ( d == 1 && i == j ) continue;
            ans = min( ans, se[i] + em[i][j] );
        }
    }
    return ans >= INF ? -1 : ans;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;

    cin >> Y >> X;
    pii P;
    vector<pii> S;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[ i ][ j ] ;
            if ( A[i][j] == 'S' ) P = {i, j};
            else if ( A[i][j] == 'C' ) S.emplace_back(i, j);
        }
    }

    cout << F(P, S[0], S[1]) << '\n';
    return 0;
}


