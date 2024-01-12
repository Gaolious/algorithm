#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<bool> visited;
vector<int> visitOrder;
vector<int> visitDepth;
vector<vector<int>> C;
int visitCount ;

void dfs(int start, int depth) {
    visited[start] = true ;
    visitDepth[start] = depth;
    visitOrder[start] = visitCount++;

    for (auto next: C[start]) {
        if (visited[next]) continue;
        dfs(next, depth+1);
    }
}
void process() {
    fastio;
    int N, M, R ;
    int i , s, e, cnt ;
    cin >> N >> M >> R ;

    visited.resize(N+1, false);
    visitOrder.resize(N+1, 0);
    visitDepth.resize(N+1, -1);
    C.resize(N+1, vector<int>());

    while ( M -- ) {
        cin >> s >> e ;
        C[s].push_back(e);
        C[e].push_back(s);
    }
    for (auto &conn : C) {
        std::sort(conn.begin(), conn.end(), greater<int>());
    }

    visitCount = 1;
    dfs(R, 0);

//    for ( i = 1 ; i <= N ; i ++ ) {
//        cout << visitDepth[i] << '\n';
//    }
    ll ret = 0 ;
    for ( i = 1 ; i <= N ; i ++ )
    {
        ret += (ll)visitDepth[i] * visitOrder[i];
    }
    cout << ret << endl;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


