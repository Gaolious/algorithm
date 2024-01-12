#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    int N, M, R ;
    int i , s, e, cnt ;
    cin >> N >> M >> R ;

    vector<bool> visited(N+1, false);
    vector<int> visitOrder(N+1, 0);
    vector<int> visitDepth(N+1, -1);

    vector<vector<int>> C(N+1, vector<int>() );
    queue<int> Q;

    while ( M -- ) {
        cin >> s >> e ;
        C[s].push_back(e);
        C[e].push_back(s);
    }
    for (auto &conn : C) {
        std::sort(conn.begin(), conn.end());
    }

    cnt = 1 ;
    visited[R] = true ;
    visitOrder[R] = cnt;
    visitDepth[R] = 0;
    Q.push(R);
    while ( !Q.empty() ) {
        int curr = Q.front();
        Q.pop();
        visitOrder[curr] = cnt++;
        for (auto next: C[curr])
        {
            if (visited[next]) continue;
            Q.push(next);
            visitDepth[next] = visitDepth[curr]+1;
            visited[next] = true ;
        }
    }
    ll ret = 0;

    for ( i = 1 ; i <= N ; i ++ )
        ret += (ll)visitDepth[i] * (ll)visitOrder[i];

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


