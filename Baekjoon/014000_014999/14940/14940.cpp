#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char A[1000][1000];
int O[1000][1000];

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

int main() {
    int x, y;
    int N, M ;
    int i, j, d;
    int tx, ty;
    queue<pair<int, int>> Q;

    fastio;

    cin >> N >> M ;
    for (i = 0 ; i < N ; i ++) {
        for ( j = 0 ; j < M ; j ++) {
            cin >> A[i][j];
            if ( A[i][j] == '2' ) {
                Q.emplace(i, j);
                A[i][j] = 0;
            }
        }
    }

    while ( !Q.empty() ) {
        auto now = Q.front();
        Q.pop();
        x = now.second, y = now.first;
        for ( d = 0 ; d < 4 ; d ++ ) {
            tx = x + dx[d];
            ty = y + dy[d];
            if ( tx < 0 || tx >= M || ty < 0 || ty >= N) continue;
            if ( A[ty][tx] != '1') continue;
            Q.emplace(ty, tx);
            O[ty][tx] = O[y][x] + 1;
            A[ty][tx] = 0;
        }
    }

    for (i = 0 ; i < N ; i ++) {
        for ( j = 0 ; j < M ; j ++) {
            if ( A[i][j] == '1' && O[i][j] == 0 ) {
                cout << -1 << ' ';
            }
            else
                cout << O[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


