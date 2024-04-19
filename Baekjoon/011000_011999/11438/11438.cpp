#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<int> depth;
vector<vector<int>> parent;

void process() {
    fastio;

    int N, M, i, a, b, j ;
    cin >> N ;
    vector<vector<int>> A(N+1, vector<int>());
    queue<int> Q;
    depth.resize(N+1, -1);
    parent.resize(N+1, vector<int>(19, -1));

    for ( i = 0 ; i < N - 1 ; i ++ ) {
        cin >> a >> b ;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    Q.push(1);
    parent[1][0] = -1;
    depth[1] = 0;

    while ( !Q.empty() ) {
        auto root = Q.front();
        Q.pop();
        for( auto next: A[root]) {
            if ( depth[next] >= 0 ) continue;
            parent[next][0] = root;
            depth[next] = depth[root]+1;
            Q.push(next);
        }
    }
    for ( i = 0 ; i < 18 ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            if ( parent[j][i] != -1 )
                parent[j][i+1] = parent[ parent[j][i] ][i];

    cin >> M ;

    while ( M -- ) {
        cin >> a >> b ;
        if ( depth[a] > depth[b] ) swap(a,b);
        int diff = depth[b] - depth[a];
        for( j = 0 ; diff ; j++){
            if(diff % 2) b = parent[b][j];
            diff /= 2;
        }

        if ( a != b ) {
            for(j=18; j>=0 && a != b ; j--){
                if(parent[a][j] != -1 && parent[a][j] != parent[b][j]){
                    a = parent[a][j];
                    b = parent[b][j];
                }
            }
            a = parent[b][0];
        }
        cout << a << '\n';
    }

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



