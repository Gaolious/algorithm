#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector< vector<int>> A[2];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dump(int idx) {

    for (auto &t: A[idx]) {
        for (auto &n: t) {
            cout << setw(2) << n << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void Rotate(int from, int to, int N, int L, int sy, int sx) {
    if ( N > L ) {
        int s = 1 << (N-1) ;
        Rotate(from, to, N-1, L, sy, sx);
        Rotate(from, to, N-1, L, sy+s, sx);
        Rotate(from, to, N-1, L, sy, sx+s);
        Rotate(from, to, N-1, L, sy+s, sx+s);
        return;
    }
    int x, y, len = 1 << L ;
    for ( y = 0 ; y < len ; y ++ )
        for ( x = 0 ; x < len ; x ++ )
            A[to][sy+y][sx+x] = A[from][sy+(len-1-x)][sx+y];
}
void Reduce(int idx) {
    int i, j, ty, tx, d, cnt;
    int N = A[idx].size();
    vector<pair<int,int>> Q;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( A[idx][i][j] < 1 ) continue;

            cnt = 0 ;
            for ( d = 0 ; d < 4 ; d ++ ) {
                ty = i + dy[d];
                tx = j + dx[d];
                if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;
                if ( A[idx][ty][tx] > 0 )
                    cnt ++;
            }
            if ( cnt < 3 )
                Q.emplace_back(i, j);
        }
    }
    for (auto [y, x]: Q) A[idx][y][x] --;
}
int bfs(int idx) {
    int N = A[0].size();
    int i, j, d, ty, tx, ret, cnt;

    vector V(N, vector<bool>(N, false) );
    queue<pair<int,int>> Q;

    ret = 0 ;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( A[idx][i][j] == 0 || V[i][j] ) continue;
            Q.emplace(i, j);
            V[i][j] = true;
            cnt = 0 ;
            while ( !Q.empty() ) {
                auto [y, x] = Q.front(); Q.pop();
                cnt++;
                for ( d = 0 ; d < 4 ; d ++ ) {
                    ty = y + dy[d];
                    tx = x + dx[d];
                    if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;
                    if ( V[ty][tx] || A[idx][ty][tx] == 0 ) continue;
                    V[ty][tx] = true;
                    Q.emplace(ty, tx);
                }
            }
            ret = max(ret, cnt);
        }
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
    int N, Q, n, i;
    cin >> N >> Q;
    A[0].resize( 1<< N, vector<int>(1<<N, 0));
    A[1].resize( 1<< N, vector<int>(1<<N, 0));
    for (auto &t: A[0])
        for (auto &n: t)
            cin >> n;

    for ( i = 0 ; i < Q ; i ++ ) {
        cin >> n ;
        Rotate(i%2, 1-(i%2), N, n, 0, 0);
        Reduce(1-(i%2));
    }
    int s = 0;
    for (auto &t: A[Q%2])
        for (auto &n: t) s += n;
    cout << s << '\n' << bfs(Q%2) << '\n';
    return 0;
}


