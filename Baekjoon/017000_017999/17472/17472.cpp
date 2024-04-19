#include <bits/stdc++.h>
#include <pstl/algorithm_fwd.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int, int> pii;

char Map[10][10];
int GroupCheck[10][10]={};
vector<vector<pii>> Group;
int Y, X;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};

int bridges[10][10];

void bfs() {
    int i, j, d, ty, tx, head ;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( GroupCheck[i][j] != -1 || Map[i][j] == '0' )
                continue;

            GroupCheck[i][j] = Group.size();
            Group.emplace_back();
            Group.back().emplace_back(i, j);
            head = 0;

            while ( head < Group.back().size() ) {
                auto [y,x] = Group.back()[head++];
                for ( d = 0 ; d < 4; d ++ ) {
                    ty = y + dy[d];
                    tx = x + dx[d];
                    if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) continue;
                    if ( GroupCheck[ty][tx] != -1 ) continue;
                    if ( Map[ty][tx] == '0') continue;
                    GroupCheck[ty][tx] = GroupCheck[i][j];
                    Group.back().emplace_back(ty, tx);
                }
            }
        }
    }
}
void genBridges() {
    int groupNo, i, j, d, len, ty, tx, from, to ;

    for ( groupNo = 0 ; groupNo < Group.size() ; groupNo ++ ) {
        for (auto p : Group[groupNo]) {
            for ( d = 0 ; d < 4 ; d ++ ) {
                ty = p.first;
                tx = p.second;
                len = 0;
                while ( true ) {
                    ty += dy[d];
                    tx += dx[d];
                    if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) break;
                    if ( GroupCheck[ty][tx] == -1 ) {
                        len++;
                        continue;
                    }
                    if ( GroupCheck[ty][tx] != GroupCheck[p.first][p.second] && len >= 2 ) {
                        from = GroupCheck[p.first][p.second];
                        to = GroupCheck[ty][tx];
                        if ( bridges[ from ][ to ] < 0 || len < bridges[from][to] )
                            bridges[from][to] = bridges[to][from] = len ;
                    }
                    break;
                }
            }
        }
    }
}

vector<int> P;
int Find(int i) {
    return P[i] = ( P[i] == i ) ? i : Find(P[i]);
}
void Merge(int from, int to) {
    int x = Find(from);
    int y = Find(to);
    if ( x < y ) swap(x, y);
    P[x] = y;
}
int getDist() {
    int i, j ;

    int N = Group.size();
    priority_queue<pair<int, pii>> Q;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = i + 1 ; j < N ; j ++ )
            if ( bridges[i][j] > 0 )
                Q.push({-bridges[i][j], {i,j}});

    P.resize(N);
    for ( i = 0 ; i < N ; i ++ ) P [ i ] = i ;
    int ans = 0;

    while ( !Q.empty() ) {
        auto [dist, pp] = Q.top();
        Q.pop();
        if ( Find(pp.first) == Find(pp.second ) ) continue;
        Merge(pp.first, pp.second);
        ans -= dist;
    }

    for ( i = 1 ; i < N ; i ++ )
        if ( Find(0) != Find(i) )
            return -1;
    return ans;
}
int main() {
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, N;
    char c;

    cin >> Y >> X;
    memset(GroupCheck, -1, sizeof(GroupCheck));
    memset(bridges, -1, sizeof(bridges));

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> Map[i][j];

    bfs();
    genBridges();
    cout << getDist() << '\n';
    return 0;
}


