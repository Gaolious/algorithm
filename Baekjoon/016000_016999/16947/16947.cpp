#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN (3000)

vector<vector<int>> A;
vector<bool> Visited;
vector<int> Path;
vector<int> Dist;
vector<bool> Cycle;

bool dfs(int prev, int curr) {

    for (auto nxt : A[curr] ) {
        if ( nxt == prev) continue;

        if ( Visited[nxt] ) {
            for ( int i = curr ; i >= 0 && i != nxt ; i = Path[i] )
                Cycle[ i ] = true;
            Cycle[curr] = Cycle[nxt] = true;
            return true ;
        }

        Visited[nxt] = true;
        Path[nxt] = curr;
        if ( dfs(curr, nxt) )
            return true;
        Visited[nxt] = false;
        Path[nxt] = -1;
    }
    return false;
}
void bfs() {
    int i;
    fill(Dist.begin(), Dist.end(), -1);
    queue<pair<int, int>> Q;
    for ( i = 0 ; i < A.size() ; i ++ ) {
        if ( Cycle[i] ) {
            Q.emplace(i, 0);
            Dist[i] = 0;
        }
    }

    while (!Q.empty()) {
        auto [curr, dist] = Q.front();
        Q.pop();
        for (auto nxt: A[curr]) {
            if ( Dist[nxt] >= 0 ) continue;
            Dist[nxt] = dist + 1;
            Q.emplace(nxt, dist+1);
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
    int N, i, a, b;

    cin >> N;

    A.resize(N);
    Visited.resize(N, false);
    Cycle.resize(N, false);
    Path.resize(N, -1);
    Dist.resize(N);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }

    Visited[0] = true;
    dfs(-1, 0);
    bfs();
    for (auto d: Dist)
        cout << d << ' ';
    return 0;
}


