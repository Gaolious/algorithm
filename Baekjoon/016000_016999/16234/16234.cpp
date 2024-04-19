#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[50][50];
bool Visited[50][50];
int N, L, R ;

int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
void dump() {
    int i, j ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cout << setw(3) << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
bool bfs() {
    int i, j ;
    int d, ty, tx;
    int head;
    vector< vector<pair<int, int>> > Data;
    memset(Visited, 0, sizeof(Visited));

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( Visited[i][j] ) continue;
            Data.emplace_back( );

            auto &Q = Data.back();

            Q.emplace_back(i, j);
            Visited[i][j] = true;
            head = 0;
            while (head < Q.size() ) {
                auto [y, x] = Q[head++];

                for ( d = 0 ; d < 4 ; d ++ ) {
                    ty = y + dy[d];
                    tx = x + dx[d];
                    if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;
                    if ( Visited[ty][tx] ) continue;
                    if ( abs(A[ty][tx] - A[y][x]) < L) continue;
                    if ( abs(A[ty][tx] - A[y][x]) > R) continue;

                    Visited[ty][tx] = true;
                    Q.emplace_back(ty, tx);
                }
            }
        }
    }

    bool ret = false;
    for (auto &Q : Data) {
        if ( Q.size() < 2 ) continue;
        int s = 0, t ;
        for (auto [y, x] : Q) s += A[y][x];
        t = s / Q.size();
        for (auto [y, x] : Q) A[y][x] = t;
        ret = true;
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;

    cin >> N >> L >> R;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            cin >> A[i][j];

    int ans = 0;
    while (bfs()) {
        ans ++;
        // dump();
    }
    cout << ans ;
    return 0;
}


