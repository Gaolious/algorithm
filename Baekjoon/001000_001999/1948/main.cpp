#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#ifdef AJAVA_DEBUG
#define MAXN (10'000)
#else
#define MAXN (10'000)
#endif

vector<pair<int,int>> Edge[MAXN+1];
vector<pair<int,int>> RevEdge[MAXN+1];
char flag[MAXN];
int dg[MAXN];

int main()
{
    fastio;
    int N, M, a, b, c, S, E;
    cin >> N >> M ;
    while (M--) {
        cin >> a >> b >> c ;
        Edge[a].push_back({b, c});
        RevEdge[b].push_back({a, c});
        dg[b]++;
    }
    cin >> S >> E ;

    vector<int> D(N+1, 0);
    queue<int> Q;

    Q.push(S);

    for ( ; !Q.empty(); Q.pop()) {
        auto curr = Q.front();

        for (auto [next, cost] : Edge[curr] ) {
            D[next] = max(D[next], D[curr] + cost );
            if ( --dg[next] == 0)
                Q.push(next);
        }
    }
    cout << D[E] << '\n' ;

    Q.push(E);
    int ret = 0;
    for ( ; !Q.empty(); Q.pop()) {
        auto curr = Q.front();

        for (auto [next, cost] : RevEdge[curr] ) {
            if ( D[curr] == D[next] + cost ) {
                ret ++;
                if (flag[next] == 0) {
                    Q.push(next);
                    flag[next] = 1;
                }
            }
        }
    }
    cout << ret << '\n' ;
#ifdef AJAVA_DEBUG
    int i;
    for ( i = 0 ; i <= N ; i ++ )
        cout << setw(4) << i ;
    cout << '\n';
    for ( i = 0 ; i <= N ; i ++ )
        cout << setw(4) <<D[i] ;
    cout << '\n';
#endif
    return 0;
}


