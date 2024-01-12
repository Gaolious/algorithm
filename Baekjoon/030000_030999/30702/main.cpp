#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define H (50)
#define W (50)

char A[H][W+1];
char B[H][W+1];
char T[H][W+1];

int N, M ;

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

bool fill_and_check(int y, int x) {
    int tx, ty;
    int d;
    queue<pair<int,int>> Q;

    Q.emplace(y, x);
    T[y][x] = 1;

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = p.first + dy[d];
            tx = p.second + dx[d];
            if ( tx < 0 || tx >= M || ty < 0 || ty >= N ) continue;
            if ( A[y][x] != A[ty][tx] ) continue;
            if ( T[ty][tx] != 0 ) continue;
            if ( B[ty][tx] != B[y][x]) return false;
            Q.emplace(ty, tx);
            T[ty][tx] = 1;
        }
    }
    return true;
}
int main()
{
    fastio;
    int i, j ;
    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ )
        cin >> A[i];
    for ( i = 0 ; i < N ; i ++ )
        cin >> B[i];

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            if ( T[i][j] == 0 && !fill_and_check(i, j) ) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}


