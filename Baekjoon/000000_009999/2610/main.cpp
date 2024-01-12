#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

int D[100+1][100+1]={0,};
const int INF = 0x3f3f3f3f;
int P[100+1]={0,};

int Parent(int i) {
    return i == P[i] ? i : P[i] = Parent(P[i]);
}
void Union(int x, int y) {
    x = Parent(x);
    y = Parent(y);
    if ( x == y) return ;
    P[x] = y;
}

void process() {
    fastio ;
    int N ;
    int M, a, b ;
    int i, j, k ;

    cin >> N >> M ;
    for ( i = 1 ; i <= N ; i ++ ) {
        for (j = 1; j <= N; j++) {
            D[i][j] = INF ;
        }
        P[i] = i ;
    }
    for ( i = 0 ; i < M ; i ++ )
    {
        cin >> a >> b ;
        D[a][b] = D[b][a] = 1;
    }

    for ( k = 1 ; k <= N ; k ++ )
        for ( i = 1 ; i <= N ; i ++ )
            for ( j = 1 ; j <= N ; j ++ )
                if ( D[i][j] > D[i][k] + D[k][j] )
                    D[i][j] = D[i][k] + D[k][j] ;

    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            if ( D[i][j] < INF )
                Union(i,j);

    priority_queue<pair<int,int>> Q;
    vector<int> ans ;
    vector<bool> visited(N+1, false);

    for ( i = 1 ; i <= N ; i ++) {
        int maxTime = 0;
        for (j = 1 ; j <= N ; j ++) {
            if ( i == j || D[i][j] >= INF) continue;
            maxTime = max(maxTime, D[i][j]);
        }
        Q.push({-maxTime, i});
    }

    while (!Q.empty() ) {
        int curr = Q.top().second;
        int p = Parent(curr);
        Q.pop();
        if ( visited[p] ) continue;
        ans.push_back(curr);
        visited[p] = true ;
    }

    std::sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for ( i = 0 ; i < ans.size() ; i ++)
        cout << ans[i] << endl;
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


