#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

vector<vector<char>> A;
vector<vector<int>> G;
vector<int> C;

int bfs(int y, int x, int groupNo) {
    int ty, tx, d;
    int cnt = 0;
    queue<pii> Q;
    Q.emplace(y, x);
    G[y][x] = groupNo;
    while ( !Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        cnt++;
        for ( d = 0 ; d < 8 ; d += 2 ) {
            ty = curr.first + dy[d];
            tx = curr.second + dx[d];
            if ( !valid(ty,tx) || G[ty][tx] != -1 || A[ty][tx] != '1' )
                continue;
            G[ty][tx] = groupNo;
            Q.emplace(ty, tx);
        }
    }
    return cnt;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, g;

    cin >>  Y >> X ;
    A.resize(Y, vector<char>(X));
    G.resize(Y, vector<int>(X, -1));
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    for ( g = 0, i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            if ( G[i][j] == -1 && A[i][j] == '1' ) {
                C.push_back( bfs(i, j, g++) );
            }
    int ans = 0;
    for (auto c: C) ans = max(ans, c);

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] == '1' ) continue;

            vector<int> tmp ;
            for ( int d = 0 ; d < 8 ; d += 2 ) {
                int ty = i + dy[d];
                int tx = j + dx[d];
                if ( !valid(ty,tx) ) continue;
                if ( G[ty][tx] == -1 ) continue;

                tmp.push_back(G[ty][tx]);
            }
            if (tmp.empty()) continue;

            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            int s = 0 ;
            for (auto gn: tmp) s += C[gn];
            ans = max(ans, s+1);
        }
    cout << ans << '\n';
    return 0;
}


