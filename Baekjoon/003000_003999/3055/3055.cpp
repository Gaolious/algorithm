#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int, int> pii ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int MaxN = 50 ;
const int INF = 100000000;
char A[MaxN][MaxN];
int W[MaxN][MaxN];
int B[MaxN][MaxN];
int Y, X ;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
void bfs_water(vector<pii> &init) {
    int ty, tx, d;
    queue<pair<int, pii> > Q;
    memset(W, -1, sizeof(W));
    for (auto [y,x]: init) {
        W[y][x] = 0 ;
        Q.push({ 0, {y,x}});
    }
    while ( !Q.empty() ) {
        auto [step, p] = Q.front();
        Q.pop();
        for ( d = 0 ; d < 8 ; d +=2 ) {
            ty = p.first + dy[d];
            tx = p.second + dx[d];
            if ( !valid(ty, tx) ) continue;
            if ( A[ty][tx] == 'D' ) continue;
            if ( A[ty][tx] == 'X' ) continue;
            if ( W[ty][tx] == -1 ) {
                W[ty][tx] = W[p.first][p.second] + 1;
                Q.push({step+1, {ty,tx}});
            }
        }
    }
}
void bfs_beaver(pii init) {
    int ty, tx, d;
    queue<pair<int, pii> > Q;
    memset(B, -1, sizeof(B));
    B[init.first][init.second] = 0 ;
    Q.emplace( 0, init);
    while ( !Q.empty() ) {
        auto [step, p] = Q.front();
        Q.pop();
        for ( d = 0 ; d < 8 ; d +=2 ) {
            ty = p.first + dy[d];
            tx = p.second + dx[d];
            if ( !valid(ty, tx) ) continue;
            if ( A[ty][tx] == 'X' ) continue;
            if ( W[ty][tx] >= 0 && W[ty][tx] <= step+1 ) continue;
            if ( B[ty][tx] == -1 ) {
                B[ty][tx] = B[p.first][p.second] + 1;
                Q.push({step+1, {ty,tx}});
            }
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    vector<pii> water;
    pii beaver;
    vector<pii> D;
    cin >> Y >> X ;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[i][j];
            if ( A[ i ][ j ] == '*' ) water.emplace_back(i, j);
            if ( A[ i ][ j ] == 'S' ) beaver = {i, j};
            if ( A[ i ][ j ] == 'D' ) D.emplace_back(i, j);
        }

    bfs_water(water);
    bfs_beaver(beaver);
    int ans = Y*X+1;
    for (auto [y,x]: D) ans = min(ans, B[y][x]);
    if ( ans < 0) cout<< "KAKTUS\n";
    else cout << ans << '\n';
    return 0;
}


